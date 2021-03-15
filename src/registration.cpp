/**
 * SPDX-FileCopyrightText: 2021 Tobias Fella <fella@posteo.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "registration.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

#include <connection.h>

using namespace Quotient;

Registration::Registration()
{
    QTcpServer *server = new QTcpServer(this);
    server->listen(QHostAddress("127.0.0.1"), 20847);
    connect(server, &QTcpServer::newConnection, this, [=]() {
        auto conn = server->nextPendingConnection();
        connect(conn, &QIODevice::readyRead, this, [=](){
            QString code = QStringLiteral("HTTP/1.0 200\nContent-type: text/html\n\n<html><head><script src=\"https://www.google.com/recaptcha/api.js\" async defer></script></head><body style=\"background: #00000000\"><center><div class=\"g-recaptcha\" data-sitekey=\"%1\"></div></center></body></html>").arg(m_recaptchaSiteKey);
            conn->write(code.toLatin1(), code.length());
            conn->close();
        });        
    });

    connect(this, &Registration::homeserverChanged, this, &Registration::testHomeserver);
}

void Registration::setRecaptchaResponse(const QString &recaptchaResponse)
{
    m_recaptchaResponse = recaptchaResponse;
    Q_EMIT recaptchaResponseChanged();
}

QString Registration::recaptchaResponse() const
{
    return m_recaptchaResponse;
}

void Registration::setRecaptchaSiteKey(const QString &recaptchaSiteKey)
{
    m_recaptchaSiteKey = recaptchaSiteKey;
    Q_EMIT recaptchaSiteKeyChanged();
}

QString Registration::recaptchaSiteKey() const
{
    return m_recaptchaSiteKey;
}

QVector<QVector<QString>> Registration::flows(const QString &homeserver) const
{
    Connection *connection = new Connection();
    connection->setHomeserver(QUrl(homeserver));
    auto job = connection->callApi<NeochatRegisterJob>("user", none, "", "", "", "", false);
    connect(job, &BaseJob::result, this, [=](){
        qDebug() << job->rawData();
    });
    return QVector<QVector<QString>>();
}

void Registration::registerAccount(const QString &homeserver, const QString &username, const QString &email, const QString &password)
{
    Connection *connection = new Connection();
    connection->setHomeserver(QUrl(homeserver));
    auto job = connection->callApi<NeochatRegisterJob>("user", none, username, password, "TODO", "TODO DisplayName", false);
    connect(job, &BaseJob::result, this, [=](){
        int selectedFlow = -1;
        auto data = job->jsonData();
        QJsonArray flows = data["flows"].toArray();
        for(int i = 0; i < flows.size(); i++) {
            if(flows[i].toObject()["stages"].toArray().contains("m.login.email.identity") != email.isEmpty())  {
                selectedFlow = i; // Currently, we select a flow based on whether the user set an email address, since that *should* be enough for now
                break;
            }
        }
        if(selectedFlow == -1) {
            //TODO: error handling            
        }
        QJsonArray completed = data["completed"].toArray();
        QString currentStage = flows[selectedFlow].toObject()["stages"].toArray()[completed.size()].toString();
    });
}

auto queryToRegister(const QString& kind)
{
    BaseJob::Query _q;
    addParam<IfNotEmpty>(_q, QStringLiteral("kind"), kind);
    return _q;
}

void Registration::setTermsName(const QString& termsName)
{
    m_termsName = termsName;
    Q_EMIT termsNameChanged();
}

void Registration::setTermsUrl(const QString& termsUrl)
{
    m_termsUrl = termsUrl;
    Q_EMIT termsUrlChanged();
}

QString Registration::termsName() const
{
    return m_termsName;
}

QString Registration::termsUrl() const
{
    return m_termsUrl;
}

QString Registration::homeserver() const
{
    return m_homeserver;
}

void Registration::setHomeserver(const QString& url)
{
    m_homeserver = url;
    Q_EMIT homeserverChanged();
}

void Registration::testHomeserver()
{
    setTesting(true);
    setHomeserverAvailable(false);
    if (m_connection) {
        delete m_connection;
        m_connection = nullptr;
    }

    m_connection = new Connection(this);
    m_connection->resolveServer(QStringLiteral("@user:") + m_homeserver);

    connect(m_connection, &Connection::loginFlowsChanged, this, [=](){
        NeochatRegisterJob *job = m_connection->callApi<NeochatRegisterJob>(QStringLiteral("user"), QJsonObject(), QStringLiteral("user"), QString(), QString(), QString(), false);
        connect(job, &BaseJob::result, this, [=](){
            setHomeserverAvailable((job->error() == BaseJob::StatusCode::Unauthorised) || (job->error() == BaseJob::StatusCode::IncorrectRequest));
            setTesting(false);
        });
    });
}

bool Registration::homeserverAvailable() const
{
    return m_homeserverAvailable;
}

void Registration::setHomeserverAvailable(bool available)
{
    m_homeserverAvailable = available;
    Q_EMIT homeserverAvailableChanged();
}

void Registration::setTesting(bool testing)
{
    m_testing = testing;
    Q_EMIT testingChanged();
}

bool Registration::testing() const
{
    return m_testing;
}

NeochatRegisterJob::NeochatRegisterJob(const QString& kind,
                         const Omittable<QJsonObject>& auth,
                         const QString& username, const QString& password,
                         const QString& deviceId,
                         const QString& initialDeviceDisplayName,
                         Omittable<bool> inhibitLogin)
    : BaseJob(HttpVerb::Post, QStringLiteral("RegisterJob"),
              QStringLiteral("/_matrix/client/r0/register"),
              queryToRegister(kind), {}, false)
{
    QJsonObject _data;
    addParam<IfNotEmpty>(_data, QStringLiteral("auth"), auth);
    addParam<IfNotEmpty>(_data, QStringLiteral("username"), username);
    addParam<IfNotEmpty>(_data, QStringLiteral("password"), password);
    addParam<IfNotEmpty>(_data, QStringLiteral("device_id"), deviceId);
    addParam<IfNotEmpty>(_data, QStringLiteral("initial_device_display_name"),
                         initialDeviceDisplayName);
    addParam<IfNotEmpty>(_data, QStringLiteral("inhibit_login"), inhibitLogin);
    setRequestData(std::move(_data));
    addExpectedKey("user_id");
}

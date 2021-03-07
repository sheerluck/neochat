/**
 * SPDX-FileCopyrightText: 2021 Tobias Fella <fella@posteo.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include <QObject>
#include <QString>
#include <QVector>
#include <QJsonObject>

#include <jobs/basejob.h>
#include <util.h>

class Registration : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString recaptchaSiteKey READ recaptchaSiteKey WRITE setRecaptchaSiteKey NOTIFY recaptchaSiteKeyChanged)
    Q_PROPERTY(QString recaptchaResponse READ recaptchaResponse WRITE setRecaptchaResponse NOTIFY recaptchaResponseChanged)
    Q_PROPERTY(QString termsName READ termsName WRITE setTermsName NOTIFY termsNameChanged)
    Q_PROPERTY(QString termsUrl READ termsUrl WRITE setTermsUrl NOTIFY termsUrlChanged)
    
public:
    
    static Registration &instance()
    {
        static Registration _instance;
        return _instance;
    }

    Q_INVOKABLE void registerAccount(const QString &homeserver, const QString &username, const QString &email, const QString &password);
    Q_INVOKABLE QVector<QVector<QString>> flows(const QString &homeserver) const;

    void setRecaptchaSiteKey(const QString &recaptchaSiteKey);
    QString recaptchaSiteKey() const;
    
    void setRecaptchaResponse(const QString &response);
    QString recaptchaResponse() const;
    
    void setTermsName(const QString &termsname);
    QString termsName() const;
    
    void setTermsUrl(const QString &termsUrl);
    QString termsUrl() const;

Q_SIGNALS:
    void recaptchaSiteKeyChanged();
    void recaptchaResponseChanged();
    void termsNameChanged();
    void termsUrlChanged();
private:
    QString m_recaptchaSiteKey = "6LcgI54UAAAAABGdGmruw6DdOocFpYVdjYBRe4zb";
    QString m_recaptchaResponse;
    QString m_termsName;
    QString m_termsUrl;
    
    Registration();
};

class NeochatRegisterJob : public Quotient::BaseJob
{
public:
    explicit NeochatRegisterJob(const QString& kind = QStringLiteral("user"),
                         const Quotient::Omittable<QJsonObject>& auth = Quotient::none,
                         const QString& username = {},
                         const QString& password = {},
                         const QString& deviceId = {},
                         const QString& initialDeviceDisplayName = {},
                         Quotient::Omittable<bool> inhibitLogin = Quotient::none);

    QString userId() const { return loadFromJson<QString>(QStringLiteral("user_id")); }

    QString accessToken() const
    {
        return loadFromJson<QString>(QStringLiteral("access_token"));
    }

    QString homeServer() const
    {
        return loadFromJson<QString>(QStringLiteral("home_server"));
    }

    QString deviceId() const { return loadFromJson<QString>(QStringLiteral("device_id")); }
};
    

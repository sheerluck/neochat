/**
 * SPDX-FileCopyrightText: Tobias Fella <fella@posteo.de>
 *
 * SPDX-LicenseIdentifier: GPL-2.0-or-later
 */

#include "roommanager.h"

#include "neochatconfig.h"

#include "controller.h"

RoomManager::RoomManager()
{
    m_actionsHandler = new ActionsHandler(this);

    connect(&Controller::instance(), &Controller::activeConnectionChanged, this, [=](){
        if(Controller::instance().activeConnection() == nullptr) {
            return;
        }
        
        m_actionsHandler->setConnection(Controller::instance().activeConnection());
        
        KConfig config("neochatrc");
        KConfigGroup initialRoomsGroup(&config, "initialRooms");
        QString roomString = initialRoomsGroup.readEntry(Controller::instance().activeConnection()->userId(), QString());
        if(roomString != QString()) {
            NeoChatRoom *room = dynamic_cast<NeoChatRoom *>(Controller::instance().activeConnection()->room(roomString));
            setCurrentRoom(room);
        }
    });
}

void RoomManager::setCurrentRoom(NeoChatRoom* currentRoom)
{
    qDebug() << currentRoom;
    KConfig config("neochatrc");
    KConfigGroup initialRoomsGroup(&config, "initialRooms");

    bool _hasOpenRoom = hasOpenRoom();

    if(!currentRoom) {
        m_currentRoom = std::nullopt;
        initialRoomsGroup.deleteEntry(Controller::instance().activeConnection()->userId());
    } else {
        m_currentRoom = currentRoom;
        Q_EMIT currentRoomChanged();
    }
    if(_hasOpenRoom != hasOpenRoom()) {
        qDebug() << "CHANGED";
        Q_EMIT hasOpenRoomChanged();        
    }
    
    m_actionsHandler->setRoom(currentRoom);
    initialRoomsGroup.writeEntry(Controller::instance().activeConnection()->userId(), currentRoom->id());
}

NeoChatRoom *RoomManager::currentRoom() const
{
    return *m_currentRoom;
}

bool RoomManager::hasOpenRoom() const
{
    return m_currentRoom.has_value();
}

ActionsHandler *RoomManager::actionsHandler() const
{
    return m_actionsHandler;
}

void RoomManager::openRoomAndEvent(NeoChatRoom *room, const QString &event)
{
    setCurrentRoom(room);
    Q_EMIT showEvent(event);
}

void RoomManager::resetCurrentRoom()
{
    if(hasOpenRoom()) {
        m_currentRoom = std::nullopt;
        Q_EMIT hasOpenRoomChanged();
    }
}


/**
 * SPDX-FileCopyrightText: Tobias Fella <fella@posteo.de>
 *
 * SPDX-LicenseIdentifier: GPL-2.0-or-later
 */

#pragma once

#include <QObject>

#include <optional>

#include "neochatroom.h"
#include "actionshandler.h"

class RoomManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(NeoChatRoom *currentRoom READ currentRoom WRITE setCurrentRoom RESET resetCurrentRoom NOTIFY currentRoomChanged)
    Q_PROPERTY(bool hasOpenRoom READ hasOpenRoom NOTIFY hasOpenRoomChanged)
    Q_PROPERTY(ActionsHandler *actionsHandler READ actionsHandler CONSTANT)

public:
    static RoomManager &instance() {
        static RoomManager _instance;
        return _instance;
    }

    NeoChatRoom *currentRoom() const;
    void setCurrentRoom(NeoChatRoom *currentRoom);

    bool hasOpenRoom() const;
    
    void resetCurrentRoom();

    ActionsHandler *actionsHandler() const;
    
    Q_INVOKABLE void openRoomAndEvent(NeoChatRoom *room, const QString &event);

Q_SIGNALS:
    void currentRoomChanged();
    void hasOpenRoomChanged();
    void showEvent(const QString &event);
    void openWindow(const NeoChatRoom *room);
    
private:
    RoomManager();

    std::optional<NeoChatRoom *> m_currentRoom = std::nullopt;
    ActionsHandler *m_actionsHandler;    
};

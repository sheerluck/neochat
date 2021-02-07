/**
 * SPDX-FileCopyrightText: 2018-2020 Black Hat <bhat@encom.eu.org>
 * SPDX-FileCopyrightText: 2020 Carl Schwan <carl@carlschwan.eu>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

import QtQuick 2.14
import QtQuick.Controls 2.14 as QQC2

import org.kde.kirigami 2.12 as Kirigami

Kirigami.GlobalDrawer {
    contentItem.implicitWidth: root.columnWidth
    isMenu: true
    actions: [
        Kirigami.Action {
            text: i18n("Explore rooms")
            icon.name: "compass"
            onTriggered: pushReplaceLayer("qrc:/imports/NeoChat/Page/JoinRoomPage.qml", {"connection": Controller.activeConnection})
            enabled: pageStack.layers.currentItem.title !== i18n("Explore Rooms") && Controller.accountCount > 0
        },
        Kirigami.Action {
            text: i18n("Start a Chat")
            icon.name: "irc-join-channel"
            onTriggered: pushReplaceLayer("qrc:/imports/NeoChat/Page/StartChatPage.qml", {"connection": Controller.activeConnection})
            enabled: pageStack.layers.currentItem.title !== i18n("Start a Chat") && Controller.accountCount > 0
        },
        Kirigami.Action {
            text: i18n("Create a Room")
            icon.name: "irc-join-channel"
            onTriggered: {
                let dialog = createRoomDialog.createObject(root.overlay);
                dialog.open();
            }
            shortcut: StandardKey.New
            enabled: pageStack.layers.currentItem.title !== i18n("Start a Chat") && Controller.accountCount > 0
        },
        Kirigami.Action {
            text: i18n("Accounts")
            icon.name: "im-user"
            onTriggered: pushReplaceLayer("qrc:/imports/NeoChat/Page/AccountsPage.qml")
            enabled: pageStack.layers.currentItem.title !== i18n("Accounts") && Controller.accountCount > 0

        },
        Kirigami.Action {
            text: i18n("Devices")
            iconName: "network-connect"
            onTriggered: pageStack.layers.push("qrc:/imports/NeoChat/Page/DevicesPage.qml")
            enabled: pageStack.layers.currentItem.title !== i18n("Devices") && Controller.accountCount > 0
        },
        Kirigami.Action {
            text: i18n("Settings")
            icon.name: "settings-configure"
            onTriggered: pushReplaceLayer("qrc:/imports/NeoChat/Page/SettingsPage.qml")
            enabled: pageStack.layers.currentItem.title !== i18n("Settings")
            shortcut: StandardKey.Preferences
        },
        Kirigami.Action {
            text: i18n("About Neochat")
            icon.name: "help-about"
            onTriggered: pushReplaceLayer(aboutPage)
            enabled: pageStack.layers.currentItem.title !== i18n("About")
        },
        Kirigami.Action {
            text: i18n("Logout")
            icon.name: "list-remove-user"
            enabled: Controller.accountCount > 0
            onTriggered: Controller.logout(Controller.activeConnection, true)
        },
        Kirigami.Action {
            text: i18n("Quit")
            icon.name: "gtk-quit"
            shortcut: StandardKey.Quit
            onTriggered: Qt.quit()
        }
    ]
}

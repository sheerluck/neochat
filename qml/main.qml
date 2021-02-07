/**
 * SPDX-FileCopyrightText: 2018-2020 Black Hat <bhat@encom.eu.org>
 * SPDX-FileCopyrightText: 2020 Carl Schwan <carl@carlschwan.eu>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

import QtQuick 2.14
import QtQuick.Controls 2.14 as QQC2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.14

import org.kde.kirigami 2.12 as Kirigami

import org.kde.neochat 1.0
import NeoChat.Component 1.0
import NeoChat.Panel 1.0
import NeoChat.Dialog 1.0
import NeoChat.Page 1.0
import NeoChat.Menu 1.0 as Menu

Kirigami.ApplicationWindow {
    id: root

    property int columnWidth: Kirigami.Units.gridUnit * 13

    minimumWidth: Kirigami.Units.gridUnit * 15
    minimumHeight: Kirigami.Units.gridUnit * 20

    wideScreen: width > columnWidth * 5

    onClosing: Controller.saveWindowGeometry(root)

    pageStack.initialPage: LoadingPage {}

    Connections {
        target: root.quitAction
        function onTriggered() {
            Qt.quit()
        }
    }
    
    Connections {
        target: RoomManager
        function onOpenWindow(room) {
            const secondaryWindow = roomWindow.createObject(applicationWindow(), {currentRoom: room});
            secondaryWindow.show();
        }
    }

    // This timer allows to batch update the window size change to reduce
    // the io load and also work around the fact that x/y/width/height are
    // changed when loading the page and overwrite the saved geometry from
    // the previous session.
    Timer {
        id: saveWindowGeometryTimer
        interval: 1000
        onTriggered: Controller.saveWindowGeometry(root)
    }

    onWidthChanged: saveWindowGeometryTimer.restart()
    onHeightChanged: saveWindowGeometryTimer.restart()
    onXChanged: saveWindowGeometryTimer.restart()
    onYChanged: saveWindowGeometryTimer.restart()

    function pushReplaceLayer(page, args) {
        if (pageStack.layers.depth === 2) {
            pageStack.layers.replace(page, args);
        } else {
            pageStack.layers.push(page, args);
        }
    }

    contextDrawer: RoomDrawer {
        contentItem.implicitWidth: columnWidth
        enabled: RoomManager.hasOpenRoom && pageStack.layers.depth < 2 && pageStack.depth < 3
        modal: !root.wideScreen || !enabled
        room: RoomManager.currentRoom
        handleVisible: enabled
    }

    globalDrawer: Menu.GlobalDrawer { }

    Component {
        id: aboutPage
        Kirigami.AboutPage {
            aboutData: Controller.aboutData
        }
    }

    pageStack.initialPage: LoadingPage {}

    Connections {
        target: Controller

        function onInitiated() {
            if (Controller.accountCount === 0) {
                pageStack.replace("qrc:/imports/NeoChat/Page/WelcomePage.qml", {});
            } else {
                pageStack.replace("qrc:/imports/NeoChat/Page/RoomListPage.qml", {'activeConnection': Controller.activeConnection});
            }
        }


        function onConnectionAdded() {
            if (Controller.accountCount === 1) {
                if (Controller.busy) {
                    pageStack.replace("qrc:/imports/NeoChat/Page/LoadingPage.qml");
                } else {
                    pageStack.replace(roomListComponent);
                }
            }
        }

        function onRoomJoined(roomId) {
            RoomManager.currentRoom = Controller.activeConnection.room(roomId);
        }

        function onConnectionDropped() {
            if (Controller.accountCount === 0) {
                pageStack.clear();
                pageStack.replace("qrc:/imports/NeoChat/Page/WelcomePage.qml");
            }
        }

        function onGlobalErrorOccured(error, detail) {
            showPassiveNotification(error + ": " + detail)
        }

        function onShowWindow() {
            root.show()
            root.raise()
            root.requestActivate()
        }

        function onUserConsentRequired(url) {
            consentSheet.url = url
            consentSheet.open()
        }
    }

    Connections {
        target: Controller.activeConnection
        onDirectChatAvailable: {
            RoomManager.currentRoom = Controller.activeConnection.room(directChat.id)
        }
    }

    Kirigami.OverlaySheet {
        id: consentSheet

        property string url: ""

        header: Kirigami.Heading {
            text: i18n("User consent")
        }

        QQC2.Label {
            id: label

            text: i18n("Your homeserver requires you to agree to its terms and conditions before being able to use it. Please click the button below to read them.")
            wrapMode: Text.WordWrap
            width: parent.width
        }
        footer: QQC2.Button {
            text: i18n("Open")
            onClicked: Qt.openUrlExternally(consentSheet.url)
        }
    }

    Component {
        id: createRoomDialog

        CreateRoomDialog {}
    }

    Component {
        id: roomWindow
        RoomWindow {}
    }

    function handleLink(link, currentRoom) {
        if (link.startsWith("https://matrix.to/")) {
            var content = link.replace("https://matrix.to/#/", "").replace(/\?.*/, "")
            if(content.match("^[#!]")) {
                if(content.includes("/")) {
                    var result = content.match("([!#].*:.*)/(\\$.*)")
                    if(!result) {
                        return
                    }
                    RoomManager.openRoomAndEvent(Controller.activeConnection.room(result[1]), result[2])
                } else {
                    RoomManager.currentRoom = Controller.activeConnection.room(content)
                }
            } else if(content.match("^@")) {
                let dialog = userDialog.createObject(root.overlay, {room: currentRoom, user: currentRoom.user(content)})
                dialog.open()
                console.log(dialog.user)
            }
        } else {
            Qt.openUrlExternally(link)
        }
    }

    Component {
        id: userDialog
        UserDetailDialog { }
    }
}

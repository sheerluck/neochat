/**
 * SPDX-FileCopyrightText: 2019-2020 Black Hat <bhat@encom.eu.org>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0
import Qt.labs.platform 1.0 as Platform
import QtMultimedia 5.12
import org.kde.kirigami 2.13 as Kirigami

import org.kde.neochat 1.0
import NeoChat.Setting 1.0

import NeoChat.Component 1.0
import NeoChat.Dialog 1.0
import NeoChat.Menu.Timeline 1.0
import org.kde.kcoreaddons 1.0 as KCA

Control {
    id: root

    Layout.fillWidth: true

    Audio {
        id: audio
        source: currentRoom.urlToMxcUrl(content.url)
        autoLoad: false
    }

    contentItem: ColumnLayout {
        RowLayout {
            ToolButton {
                icon.name: audio.playbackState == Audio.PlayingState ? "media-playback-pause" : "media-playback-start"

                onClicked: {
                    if (audio.playbackState == Audio.PlayingState) {
                        audio.pause()
                    } else {
                        audio.play()
                    }
                }
            }
            Label {
                text: model.display
            }
        }
        RowLayout {
            visible: audio.hasAudio
            Layout.leftMargin: Kirigami.Units.largeSpacing
            Layout.rightMargin: Kirigami.Units.largeSpacing
            // Server doesn't support seeking, so use ProgressBar instead of Slider :(
            ProgressBar {
                from: 0
                to: audio.duration
                value: audio.position
            }

            Label {
                text: KCA.Format.formatDuration(audio.position) + "/" + KCA.Format.formatDuration(audio.duration)
            }
        }
    }
}

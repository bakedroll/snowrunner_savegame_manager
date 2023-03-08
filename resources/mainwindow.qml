import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.1

Window {
    width: 640
    height: 480
    minimumWidth: 300
    minimumHeight: 300
    visible: !context.errorNoSavegamePath
    title: "Snowrunner Savegame Manager"

    MessageDialog {
        title: "Error"
        text: "Could not find the savegame filepath."
        icon: StandardIcon.Critical
        visible: context.errorNoSavegamePath

        onAccepted: Qt.quit()

        Component.onCompleted: {
            x = Screen.width / 2 - width / 2
            y = Screen.height / 2 - height / 2
        }
    }

    Loader {
        active: context.isUserIdWindowVisible
        sourceComponent: Window {
            title: "User ID"
            width: 300
            height: 300
            minimumWidth: 200
            minimumHeight: 200
            visible: true
            modality: Qt.WindowModal
            flags: Qt.WindowStaysOnTopHint

            ColumnLayout {
                spacing: 5
                anchors.fill: parent
                anchors.margins: 5

                Text {
                    text: "Please select your Steam user ID:"
                    font.bold: true
                    font.pixelSize: 14
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                }
                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    border.color: "darkgrey"
                    border.width: 1

                    ScrollView {
                        anchors.fill: parent
                        anchors.margins: 5
                        ScrollBar.vertical.policy: ScrollBar.AsNeeded
                        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

                        ListView {
                            width: parent.width

                            clip: true
                            model: context.steamUserIds
                            delegate: Rectangle {
                                width: parent.width
                                height: 20
                                Text {
                                    text: modelData
                                    font.pixelSize: 14
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    enabled: true
                                    hoverEnabled: true
                                    onEntered: parent.color = "lightgray"
                                    onExited: parent.color = "transparent"
                                    onClicked: context.setCurrentSteamUserId(modelData)
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ColumnLayout {
        spacing: 5
        anchors.margins: 5
        anchors.fill: parent

        RowLayout {
            visible: context.isUserIdBarVisible
            height: 50
            Layout.fillHeight: false
            Layout.fillWidth: true

            Button {
                text: "Change..."
                onClicked: context.setIsUserIdWindowVisible(true)
            }
            Text {
                text: "Steam UserID: " + context.selectedUserId
            }
        }

        ScrollView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            ScrollBar.vertical.policy: ScrollBar.AsNeeded
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

            ListView {
                width: parent.width

                clip: true
                model: context.snapshotItems
                delegate: Text {
                    text: modelData.test()
                    font.pixelSize: 24
                    padding: 16
                }
            }
        }

        RowLayout {
            height: 50
            Layout.fillHeight: false
            Layout.fillWidth: true

            spacing: 5

            Button {
                text: "Create snapshot"
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                text: "Restore snapshop"
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                text: "Delete snapshop"
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }
}

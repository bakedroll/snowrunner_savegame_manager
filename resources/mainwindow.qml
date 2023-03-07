import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Window {
    width: 640
    height: 480
    minimumWidth: 300
    minimumHeight: 300
    visible: true
    title: "Snowrunner Savegame Manager"

    ColumnLayout {
        spacing: 5
        anchors.margins: 5
        anchors.fill: parent

        ListView {
            Layout.fillHeight: true
            Layout.fillWidth: true

            clip: true
            model: ["Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6"]
            delegate: Text {
                text: modelData
                font.pixelSize: 24
                padding: 16
            }
        }

        RowLayout {
            height: 50
            Layout.fillHeight: false
            Layout.fillWidth: true

            spacing: 5

            Button {
                text: "Save snapshot"
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

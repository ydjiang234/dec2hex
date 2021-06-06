import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Dec2Hex")

    RowLayout {

        anchors.fill: parent

        ListView {
            id: listView
            implicitWidth: 200
            implicitHeight: 500
            model: backend.history
            delegate: Rectangle {
                width: listView.width
                border.width: 2
                border.color: red
                Text {
                text: modelData
                }
            }
        }

        ColumnLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            TextInput {
                Layout.alignment: Qt.AlignCenter
                id: tbInput
                text: backend.input
                onTextChanged: backend.input = text;
            }

            Button {
                Layout.alignment: Qt.AlignCenter
                id:btConvert
                text: qsTr("Convert")
                onClicked: {
                    backend.convertNew()
                    tbOutput.text = backend.output
                }
            }

            TextEdit {
                Layout.alignment: Qt.AlignCenter
                id: tbOutput
                text: backend.output
                readOnly: true
                wrapMode: Text.WordWrap
                selectByMouse: true
                selectByKeyboard: true
            }

        }
    }
}

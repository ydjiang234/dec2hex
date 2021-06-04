import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Dec2Hex")

    ColumnLayout {
        anchors.fill: parent
        TextInput {
            Layout.alignment: Qt.AlignCenter
            id: tbInput
            text: backend.input;
        }

        Text {
            Layout.alignment: Qt.AlignCenter
            id: tbOutput
            text: backend.output;
        }

    }
}

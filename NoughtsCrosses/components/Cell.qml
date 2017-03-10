import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Rectangle {
    id: cell
    property int orderNumber: modelData
    z: -1
    border { width: borderWidth; color: styledBorder }
    color: "transparent"
    Layout.fillWidth: true
    Layout.fillHeight: true
    Layout.topMargin: (modelData == 0 || modelData == 1 || modelData == 2) ? -borderWidth : 0
    Layout.leftMargin: (modelData == 0 || modelData == 3 || modelData == 6) ? -borderWidth : 0
    Layout.rightMargin: (modelData == 2 || modelData == 5 || modelData == 8) ? -borderWidth : 0
    Layout.bottomMargin: (modelData == 6 || modelData == 7 || modelData == 8) ? -borderWidth : 0
    states: [
        State {
            name: "hovered"
            PropertyChanges {
                target: cell
                color: "#06b3f7"
            }
        }
    ]
    transitions: [
        Transition {
            ColorAnimation {
                duration: 1000
            }
        }
    ]

    Loader {
        id: sign
        anchors.fill: parent
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onHoveredChanged: {
            if (containsMouse) {
                cell.state = "hovered"
            } else {
                cell.state = "default"
            }
        }
        onClicked: {
            sign.source = "qrc:/components/CrossSign.qml"
            enabled = false
            cell.state = "default"
        }
    }
}

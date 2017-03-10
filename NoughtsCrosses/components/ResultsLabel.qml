import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Pane {
    property alias text: label.text
    property alias color: label.color
    property alias horizontalAlignment: label.horizontalAlignment
    background: Rectangle { color: "transparent" }

    FontLoader {
        id: griffy
        source: "qrc:/fonts/Griffy-Regular.ttf"
    }

    Label {
        id: label
        anchors.fill: parent
        font { pixelSize: 40; family: griffy.name; bold: true }
    }
}

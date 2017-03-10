import QtQuick 2.7
import QtQuick.Controls 2.1

Button {
    id: button
    font { pixelSize: 40; family: font.name; bold: true }
    background: Rectangle {
        border.color: "black"
        color: down ? "gray" : "transparent"
        radius: 10
    }
    CustomFont { id: font }
}

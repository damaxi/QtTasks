import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Label {
    id: label
    font { pixelSize: 40; family: font.name; bold: true }

    CustomFont { id: font }
}

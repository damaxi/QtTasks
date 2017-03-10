import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Canvas {
    anchors.fill: parent
    onPaint: {
        var ctx = getContext("2d")
        ctx.lineWidth = 20
        ctx.strokeStyle = "blue"
        ctx.beginPath()
        ctx.ellipse(25, 25, width - 50, height - 50)
        ctx.stroke()
    }
}

import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Canvas {
    anchors.fill: parent
    onPaint: {
        var ctx = getContext("2d")
        ctx.lineWidth = 20
        ctx.strokeStyle = "red"
        ctx.beginPath()
        ctx.moveTo(25, 25)
        ctx.lineTo(width - 25, height - 25)
        ctx.stroke()

        ctx.beginPath()
        ctx.moveTo(width - 25, 25)
        ctx.lineTo(25, height - 25)
        ctx.stroke()
    }
}

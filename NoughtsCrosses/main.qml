import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 640
    minimumWidth: width
    minimumHeight: height
    title: qsTr("Noughts and Crosses")

    background: Image {
        id: paperBackground
        source: "qrc:/img/paper.png"
        fillMode: Image.PreserveAspectCrop
    }

    Canvas {
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d")

                    // setup the stroke
                    ctx.strokeStyle = "red"

                    // create a path
                    ctx.beginPath()
                    ctx.moveTo(50,50)
                    ctx.lineTo(150,50)

                    // stroke path
                    ctx.stroke()
        }
    }
}

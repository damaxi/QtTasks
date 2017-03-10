import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import "components" as Custom

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 720
    minimumWidth: width
    minimumHeight: height
    title: qsTr("Noughts and Crosses")
    property alias styledBorder: style.border
    property alias borderWidth: style.borderWidth
    property int crossesWins: 0
    property int noughtsWins: 0
    function drawGame() {
        popup.resultLabelState = "draw"
        endGame()
    }

    function endGame() {
        popup.open()
    }

    background: Image {
        id: paperBackground
        source: "qrc:/img/paper.png"
        fillMode: Image.PreserveAspectCrop
    }

    QtObject {
        id: style
        property color border: "#64aedb"
        property int borderWidth: 10
    }

    ColumnLayout {
        anchors.fill: parent
         RowLayout {
            Layout.fillWidth: true
            Layout.minimumHeight: window.height / 9

            Custom.ResultsLabel {
                text: qsTr("Turn:")
                Layout.leftMargin: 20
            }
            Custom.ResultsLabel {
                text: qsTr("%1").arg(engine.player)
            }
            Custom.ResultsLabel {
                Layout.fillWidth: true
            }
            Custom.ResultsLabel {
                text: qsTr("Score:")
            }
            Custom.ResultsLabel {
                text: "%1".arg(crossesWins)
                color: "red"
                Layout.margins: 5
            }
            Custom.ResultsLabel {
                text: "%1".arg(noughtsWins)
                color: "blue"
                Layout.rightMargin: 20
            }
        }
        Pane {
            z: 1
            Layout.bottomMargin: -style.borderWidth
            Layout.fillWidth: true
            background: Rectangle {
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "white" }
                    GradientStop { position: 1.0; color: style.border }
                }
            }
        }
        GridLayout {
            columns: 3
            rows: 3
            columnSpacing: 0
            rowSpacing: 0
            Layout.fillWidth: true
            Layout.fillHeight: true
            Repeater {
                id: grid
                function redraw() {
                    for (var i = 0; i < model; ++i) {
                        itemAt(i).reset()
                    }
                }

                model: engine.maxSize()
                Custom.Cell {}
            }
        }
    }

    Custom.EndGamePopup {
        id: popup
        onClosed: {
            grid.redraw()
            if (engine.player == "crosses" && resultLabelState == "default")
                ++crossesWins
            else if (resultLabelState == "default")
                ++noughtsWins

            resultLabelState = "default"
            engine.reset()
        }
    }
}

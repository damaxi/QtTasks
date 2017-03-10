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
            }
            Custom.ResultsLabel {
                text: qsTr("blue")
            }
            Custom.ResultsLabel {
                Layout.fillWidth: true
            }
            Custom.ResultsLabel {
                text: qsTr("Score:")
            }
            Custom.ResultsLabel {
                text: "0"
                color: "red"
            }
            Custom.ResultsLabel {
                text: "0"
                color: "blue"
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
                model: 9
                Custom.Cell {}
            }
        }
    }
}

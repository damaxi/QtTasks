import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Popup {
    id: resultPopup
    property alias resultLabelState: resultLabel.state
    width: parent.width / 2
    height:  parent.height / 4
    x: window.width / 4
    y: window.height / 4
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    background: Rectangle {
        border { color: "black"; width: 2 }
        color: "white"
        radius: 10
    }

    ColumnLayout {
        anchors.fill: parent

        ResultsLabel {
            id: resultLabel
            text: qsTr("%1 wins!").arg(engine.player)
            Layout.alignment: Qt.AlignHCenter
            states: [
                State {
                    name: "draw"
                    PropertyChanges {
                        target: resultLabel
                        text: qsTr("Draw!")
                    }
                }
            ]
        }

        ResultsButton {
            text: qsTr("Ok")
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                resultPopup.close()
            }
        }
    }
}

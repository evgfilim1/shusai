import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

Item {
    property alias addButton: addBtn
    ListView {

        id: eventList
        anchors.fill: parent
        anchors.bottomMargin: 50
        model: ListModel {
            ListElement {
                name: "День рождение @mymedia"
            }
            ListElement {
                name: "Купить хлеб"
            }
            ListElement {
                name: "Купить подарок"
            }
            ListElement {
                name: "mac book pro 15 на нг"
            }
        }
        delegate: Rectangle {
            //            anchors.fill: parent
            id: listDelegate
            width: parent.width
            height: 40
            color: "transparent"
            state: "nonHover"

            MouseArea {
                id: mArea
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: {

                }
                onEntered: {
                    eventList.currentIndex = index
                    parent.state = "hover"
                }
                onExited: {
                    parent.state = "nonHover"
                    eventList.currentIndex = -1
                }
            }

            radius: 10
            Text {
                id: listText
                anchors.fill: parent
                anchors.margins: 20
                text: name
                verticalAlignment: Text.AlignVCenter
                color: Material.color(enumAccent, Material.Shade700)
            }
            transitions: Transition {
                ColorAnimation {
                    duration: 50
                }
            }
            states: [
                State {
                    name: "hover"
                    PropertyChanges {
                        target: listDelegate
                        color: Material.color(enumPrimary, Material.Shade400)
                    }
                    PropertyChanges {
                        target: listText
                        color: "white"
                    }
                },
                State {
                    name: "nonHover"
                    PropertyChanges {
                        target: listDelegate
                        color: "transparent"
                    }
                    PropertyChanges {
                        target: listText
                        color: Material.color(enumPrimary, Material.Shade700)
                    }
                }
            ]
        }
    }
    Button {
        id: addBtn
        anchors.top: eventList.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        highlighted: true
        text: "Добавить"
    }
}

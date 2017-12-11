import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

Item {

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
            width: parent.width
            height: 40
            color: eventList.currentIndex == index ? Material.color(
                                                         enumPrimary,
                                                         Material.Shade400) : "transparent"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    eventList.currentIndex = index
                }
            }

            radius: 10
            Text {
                anchors.fill: parent
                anchors.margins: 20
                text: name
                verticalAlignment: Text.AlignVCenter
                color: eventList.currentIndex == index ? "white" : Material.color(
                                                             enumAccent,
                                                             Material.Shade700)
            }
        }
    }
    Button {
        anchors.top: eventList.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        highlighted: true
        text: "Добавить"
    }
}

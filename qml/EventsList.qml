import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    ListView{
        anchors.fill: parent

        model: ListModel {
            ListElement {
                name: "Bill Smith"

            }
            ListElement {
                name: "John Brown"

            }
            ListElement {
                name: "Sam Wise"

            }
        }
        delegate: Text {
                text: name
            }
    }
}

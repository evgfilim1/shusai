import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Shusai")

    GridLayout{
        rows: 2
        columns: 2
        anchors.fill: parent
        flow:  width > height ? GridLayout.LeftToRight : GridLayout.TopToBottom
        anchors.margins: 20

        EventsList{
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        EventsCalendar{
            Layout.fillWidth: true
            Layout.fillHeight: true
        }


    }


}

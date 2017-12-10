import QtQuick 2.0
import QtQuick.Controls 2.2
//import QtQuick.Controls.Styles 1.4
import Qt.labs.calendar 1.0
import QtQuick.Layouts 1.3


Item {
    GridLayout {
        anchors.fill: parent
        columns: 2
        rows:2

        Rectangle{

            Text{

                anchors.fill: parent
                text:"December"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Layout.fillWidth: true
            Layout.column: 1
            Layout.row: 1
            Layout.preferredHeight: 40
        }

        DayOfWeekRow {
            locale: grid.locale

            Layout.column: 1
            Layout.row: 2
            Layout.fillWidth: true
        }

        WeekNumberColumn {
            month: grid.month
            year: grid.year
            locale: grid.locale

            Layout.fillHeight: true
        }

        MonthGrid {

            id: grid
            month: Calendar.December
            year: 2017
            locale: Qt.locale("ru_RU")

            Layout.fillWidth: true
            Layout.fillHeight: true
            delegate:Rectangle{
                color: "transparent"
                Rectangle{
                    anchors.fill: parent
                    color: "red"
                    Text {

                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        opacity: model.month === grid.month ? 1 : 0.3
                        text: model.day
                    }
                }
            }
        }
    }

}

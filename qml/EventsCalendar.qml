import QtQuick 2.9
import QtQuick.Controls 2.2
//import QtQuick.Controls.Styles 1.4
import Qt.labs.calendar 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

Item {
    id: calendar
    property date currentDate: new Date()
    GridLayout {
        anchors.fill: parent
        columns: 2
        rows: 2

        Rectangle {
            color: "transparent"

            ComboBox {
                id: comboMonth
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.right: comboYear.left
                anchors.rightMargin: 3
                model: ListModel {
                    ListElement {
                        text: "Январь"
                    }
                    ListElement {
                        text: "Февраль"
                    }
                    ListElement {
                        text: "Март"
                    }
                    ListElement {
                        text: "Апрель"
                    }
                    ListElement {
                        text: "Май"
                    }
                    ListElement {
                        text: "Июнь"
                    }
                    ListElement {
                        text: "Июль"
                    }
                    ListElement {
                        text: "Август"
                    }
                    ListElement {
                        text: "Сентябрь"
                    }
                    ListElement {
                        text: "Октябрь"
                    }
                    ListElement {
                        text: "Ноябрь"
                    }
                    ListElement {
                        text: "Декабрь"
                    }
                }
            }
            ComboBox {
                id: comboYear
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                model: yearsList
                ListModel {
                    id: yearsList
                }
                Component.onCompleted: {
                    for (var i = 2017; i < 2022; i++) {
                        yearsList.append({
                                             text: i
                                         })
                    }
                }
            }

            function formatText(count, modelData) {
                var data = count === 12 ? modelData + 1 : modelData
                return data.toString().length < 2 ? "0" + data : data
            }
            Component {
                id: delegateComponent

                Label {
                    text: modelData
                    opacity: 1.0 - Math.abs(
                                 Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Layout.fillWidth: true
            Layout.column: 1
            Layout.row: 1
            Layout.preferredHeight: 60
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
            delegate: Text {
                text: model.weekNumber
                font.bold: true
                color: Material.accent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        MonthGrid {

            id: grid
            month: Calendar.December
            year: 2017
            locale: Qt.locale("ru_RU")

            Layout.fillWidth: true
            Layout.fillHeight: true
            delegate: Rectangle {
                color: "transparent"

                Rectangle {
                    anchors.fill: parent
                    color: (model.date.toLocaleDateString(
                                ) == calendar.currentDate.toLocaleDateString(
                                )) ? Material.primary : "transparent"
                    radius: 3
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (model.month === grid.month) {
                                calendar.currentDate = model.date
                            }
                        }
                    }

                    Text {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        opacity: model.month === grid.month ? 1 : 0.3
                        text: model.day
                        color: (model.date.toLocaleDateString(
                                    ) != calendar.currentDate.toLocaleDateString(
                                    )) ? Material.color(
                                             enumAccent,
                                             Material.Shade800) : "white"
                    }
                }
            }
        }
    }
}

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

import DataManager

ApplicationWindow {
    visible: true
    width: 600
    height: 200
    title: "Array"
    minimumWidth: 320
       minimumHeight: 200

    background: Rectangle {
            gradient: Gradient {
                GradientStop { position: 0; color: "#34D0BA" }
                GradientStop { position: 1; color: "#E667AF" }
            }
        }


    DataManager {
        id: dataManager
    }



    Flickable {
        anchors.fill: parent
        contentWidth: ApplicationWindow.width
        contentHeight: columnLayout.height

        ColumnLayout {
            id: columnLayout
            spacing: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter

            TextField {
                id: inputField
                placeholderText: "Enter value"
                width: 100
                anchors.top: parent.top
                    anchors.topMargin: 5
                background: Rectangle {
                        implicitWidth: 200
                        implicitHeight: 40
                    }
                Layout.alignment: Qt.AlignHCenter
                Keys.onReturnPressed: {
                    if (inputField.text !== "") {
                        dataManager.appendValue(inputField.text)
                        inputField.text = ""
                    }
                }
            }

            Repeater {
                model: dataManager.dataArray.length
                Rectangle {
                    color: "orange"
                    width: 300
                    radius: 10

                    RowLayout {
                        spacing: 10
                        anchors.fill: parent

                        Rectangle {
                            width: 40
                            height: 30
                            color: "pink"
                            radius: 10

                            RowLayout {
                                anchors.centerIn: parent

                                Button {
                                    text: qsTr("X")
                                    onClicked: {
                                        dataManager.removeValue(index)
                                    }

                                    background: Rectangle {
                                        color: button.hovered ? "#21be2b" : "transparent"
                                        border.color: "#21be2b"
                                        radius: 10
                                    }
                                }
                            }

                        }

                        Text {
                            id: text
                            text: dataManager.dataArray[index]
                            Layout.fillWidth: true
                            verticalAlignment: Text.AlignVCenter
                            Layout.alignment: Qt.AlignHCenter
                            wrapMode: Text.Wrap
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }
                    height: Math.max(text.height + 20, 40)
                }
            }

        }
    }
}

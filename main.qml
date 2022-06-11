import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import UriAAA 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QAbstractListModel sample")

    //    ItemDataList_AAA {
    //        id: itemDataListAAA
    //    }

    ListModel_AAA {
        id: listModelAAA
        itemDataList: list_AAA
    }

    ColumnLayout {
        anchors {
            fill: parent
            margins: 0
        }
        spacing: 10

        RowLayout {
            spacing: 10

            ScrollView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                background: Rectangle {
                    color: "lightcyan"
                }

                ListView {
                    model: listModelAAA
                    clip: true

                    delegate: Row {
                        spacing: 10

                        CheckBox {
                            checked: model.roleBool
                            onClicked: {
                                model.roleBool = checked
                            }
                        }

                        Label {
                            text: model.roleInt
                            width: 30
                        }

                        Label {
                            text: model.roleFloat.toFixed(10)
                            width: 100
                        }

                        Label {
                            text: model.roleDouble
                            width: 60
                        }

                        TextField {
                            text: model.roleString
                            width: 100

                            onTextEdited: {
                                model.roleString = text
                            }
                        }

                    }
                }

            }

            ScrollView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                background: Rectangle {
                    color: "lightgreen"
                }

                ListView {
                    model: listModelAAA
                    clip: true

                    delegate: Row {
                        spacing: 10

                        CheckBox {
                            checked: model.roleBool
                            onClicked: {
                                model.roleBool = checked
                            }
                        }

                        Label {
                            text: model.roleInt
                            width: 30
                        }

                        Label {
                            text: model.roleFloat
                            width: 200
                        }

                        Label {
                            text: model.roleDouble
                            width: 60
                        }

                        TextField {
                            text: model.roleString
                            width: 100

                            onTextEdited: {
                                model.roleString = text
                            }
                        }



                    }
                }

            }
        }


        RowLayout {
            spacing: 10

            Button {
                text:"Create Dummy Data"
                onClicked: list_AAA.createDummyData()
            }

            Button {
                text: "Remove All"
                onClicked: list_AAA.removeAll()
            }

            Button {
                text: "Remove Checked Items"
                onClicked: {
                    var count = list_AAA.getCount();
                    for(var i = count-1; i>=0; i--)
                    {
                        if(list_AAA.isChecked(i))
                        {
                            list_AAA.removeAt(i);
                        }
                    }

                }
            }
        }
    }
}

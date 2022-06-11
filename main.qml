import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import UriAAA 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    ItemDataList_AAA {
//        id: itemDataListAAA
//    }

    ListModel_AAA {
        id: listModelAAA
        itemDataList: list_AAA
    }


        ScrollView {
            anchors {
                fill: parent
                margins: 0
            }

            ListView {
                model: listModelAAA
                clip: true

                delegate: Row {
                    spacing: 10

                    Label {
                        text: model.roleString
                    }
                }
            }

        }


}

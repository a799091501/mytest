import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Window 2.2

Window {
    visible: true;
    width: 720
    height: 1920
    //title: qsTr("Hello World");
    Item{
        id:tab1;
        visible: false;
        anchors.fill: parent;
        Rectangle{
            id:qname;
            width:180;
            height: 270;
            x:432
            y: 234
            color:"transparent";
            Text {
                anchors.centerIn: parent;
                font.pixelSize: 21;
                font.bold: true;
                text:qsTr("Please input question:");
                horizontalAlignment: Text.AlignHCenter
            }
        }
        Rectangle{
            id:aname;
            width:180;
            height: 270;
            x:290
            y:268
            color:"transparent";
            Text {
                anchors.centerIn: parent;
                font.pixelSize: 21;
                font.bold:true;
                text:qsTr("Please input answer:");
                horizontalAlignment: Text.AlignHCenter
                anchors.verticalCenterOffset: 361
                anchors.horizontalCenterOffset: 154
            }
        }

        Rectangle {
            id: input1
            x: 276
            y: 837
            width: 513
            height: 148
            border.color: "black";
            TextInput {
                width:513*3/4;
                height: 148*2/3;
                horizontalAlignment: Text.AlignLeft
                anchors.centerIn: input1;
                wrapMode: TextInput.WrapAnywhere;
            }
        }

        Rectangle {
            id: input2
            x: 270
            y: 491
            width: 513
            height: 148
            border.color: "black";
            TextInput {
                width: 513*3/4
                height: 148*2/3
                horizontalAlignment: Text.AlignLeft
                wrapMode: TextInput.WrapAnywhere
                anchors.centerIn: parent
                cursorVisible: true;
            }
        }

         Button{
             visible:true;
             x: 414
             y: 1200
             width: 216
             height: 107
            Text {
                anchors.centerIn: parent;
                text: qsTr("finish")
                font.bold: true;
            }
            onClicked: {
                Qt.quit();
            }
        }

    }
    Item{
        id:tab2;
        visible:true ;
        anchors.fill:parent;
        Rectangle{
            id:showquestion;
            width: 1080;
            height:1920*1/4;
            Text{
                id:questiontext;
                width: 1080*3/4;
                height:480*3/4;
                text:"text";
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                //anchors.rightMargin: -718
              //  horizontalAlignment: Text.AlignLeft
                //anchors.fill:parent;
                anchors.centerIn: parent;
            }
        }
        Rectangle{
            id:showanswer;
            width:showquestion.width;
            height:parent.height*1/2;
            border.color: "black";
            anchors.top: showquestion.bottom;
            MouseArea{
                anchors.fill:showanswer;
                visible: false;
            }

            Text {
                id: answertext
                text: qsTr("text");
                width:parent.width-108;
                height: parent.height-192;
                x: showanswer.x+54;
                y: 92
            }
        }
        Row{
            x: 72
            anchors.verticalCenterOffset: 66
            anchors.verticalCenter: parent.verticalCenter
            anchors.topMargin: 212
            anchors.top: showanswer.bottom
            spacing: 180;
            Button{
                id:good;
                text: "Good";
                width: 192
                height:108;
            }
            Button{
                id:soso;
                text:"So_So";
                width:good.width;
                height:good.height;
            }
            Button{
                id:bad;
                text: "Bad";
                width:good.width;
                height:good.height;
            }
        }
    }
}

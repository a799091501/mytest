import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import io.qt.myexe2.client 1.0
import io.qt.myexe2.backend 1.0

Window {
    id:big_brother;
    visible: true;
    width: 1080
    height: 720
    //title: qsTr("Hello World");
    StackLayout{
        visible: false;
        id:myexe2;
        width: parent.width;
        height:parent.height*15/16;
        y:parent.height*1/16;
        currentIndex: 0;

        Item{
            id:tab1;
            // visible: true;
            anchors.fill: parent;
            Rectangle{
                id:side1;
                width:parent.width;
                height: parent.height*2/5;

                //x:432
                //: 234
                // color:"transparent";
                Rectangle {
                    id:qname;
                    width: parent.width;
                    height:parent.height*1/3;
                    Text {
                        anchors.centerIn: parent;
                        font.pixelSize: 21;
                        font.bold: true;
                        text:qsTr("Please input question:");
                        horizontalAlignment: Text.AlignHCenter
                    }
                    Rectangle{
                        id:side1B;
                        anchors.top:qname.bottom;
                        width: parent.width;
                        height: side1.height*2/3;
                        Rectangle {
                            id: input1
                            //x: 276
                            // y: 837
                            width: parent.width*4/5;
                            height:parent.height*4/5;
                            anchors.centerIn:side1B ;
                            border.color: "black";
                            TextInput {
                                id:text1;
                                width:input1.width*3/4;
                                height: input1.height*2/3;
                                //horizontalAlignment: Text.AlignLeft
                                anchors.centerIn: input1;
                                wrapMode: TextInput.WrapAnywhere;

                            }
                        }
                    }
                }


            }


            Rectangle{
                id:side2;
                width:tab1.width;
                height: tab1.height*2/5;
                anchors.top:side1.bottom;
                //x:432
                //: 234
                // color:"transparent";
                Rectangle {
                    id:aname;
                    width: parent.width;
                    height:parent.height*1/3;
                    Text {
                        anchors.centerIn: parent;
                        font.pixelSize: 21;
                        font.bold: true;
                        text:qsTr("Please input answer:");
                        horizontalAlignment: Text.AlignHCenter
                    }
                    Rectangle{
                        id:side2B;
                        anchors.top:aname.bottom;
                        width: parent.width;
                        height: side2.height*2/3;
                        Rectangle {
                            id: input2
                            //x: 276
                            // y: 837
                            width: parent.width*4/5;
                            height:parent.height*4/5;
                            anchors.centerIn:side2B ;
                            border.color: "black";
                            TextInput {
                                id :text2;
                                width:input2.width*3/4;
                                height: input2.height*2/3;
                                //horizontalAlignment: Text.AlignLeft
                                anchors.centerIn: input2;
                                wrapMode: TextInput.WrapAnywhere;
                            }
                        }
                    }
                }


            }


            /*Rectangle{
                id:aname;
                width:parent.width;
                height: parent.height*2/5*1/3;
                //x:290
                y:2/5
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
    */
            Myclient{
                id:mClient;


            }
           QandA{
               id:my_QandA;
               q:text1.text;
               a:text2.text;
            }

            Rectangle{
                id:side3;
                width: tab1.width;
                height: tab1.height*1/5;
                anchors.top:side2.bottom;
                Button{
                    visible:true;
                    width:parent.width*1/4;
                    height:parent.height*2/3;
                    anchors.centerIn: parent;
                    Text {

                        anchors.centerIn: parent;
                        text: qsTr("finish")
                        font.bold: true;
                    }
                    onClicked: {
                        //  Qt.quit();
                        // console.log(text1.text);
                        mClient.addQandA(my_QandA.q,my_QandA.a,1);
                        //mClient.readQandA();
                    }
                }

            }
        }

        Item{
            id:tab2;
            //    visible:false;
            anchors.fill:parent;
           // my_QandA.findjs();
            Rectangle{
                id:showquestion;
                //anchors.top:bar.bottom;
                width: myexe2.width;
                height:myexe2.height*1/4;
                Text{
                    id:questiontext;
                    width: showquestion.width*3/4;
                    height:showquestion.height*3/4;
                    //text:mClient.showq();
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
                    //text: qsTr(mClient.showa());
                    width:parent.width*9/10;
                    height: parent.height*4/5;
                    anchors.centerIn: parent;
                }
            }
            Rectangle{
                id:lastside;
                anchors.top: showanswer.bottom;
                width: myexe2.width;
                height:myexe2.height*1/4;
                Row{
                    //width:myexe2.width*4/8;
                    //   x: 72
                    // anchors.verticalCenterOffset: 82
                    //anchors.verticalCenter: parent.verticalCenter
                    // anchors.topMargin: 228

                    anchors.centerIn: parent;
                    spacing: 150;
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

    }
    TabBar{
        id:bar;
        visible: false;
        width:myexe2.width;
        height:myexe2.height*1/16;
        TabButton
        {
            id:add;
         text: qsTr("Add")
         onClicked: {
             myexe2.currentIndex=0;
         }
        }
        TabButton{
            id:review;
            text:qsTr("review");
            onClicked: {
                myexe2.currentIndex=1;
                my_QandA.q=mClient.showq();
                my_QandA.a=mClient.showa();
                answertext.text=my_QandA.a;
                console.log(answertext.text);
            }
        }
    }
    Button{
        id:hello;
        text:qsTr("Hello!");
        width: big_brother.width*1/2;
        height: big_brother.height*1/2;
        anchors.centerIn: myexe2;
        visible: true;
        onClicked: {
            mClient.readQandA();
            bar.visible=1;
            myexe2.visible=1;
            hello.visible=0;
        }
    }
    }

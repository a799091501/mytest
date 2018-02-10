#include"myexe2.h"
#include<QString>
#include<QDir>
#include<QJsonDocument>
#include<QJsonArray>
#include<iostream>
void client::addQandA(QString q,QString a,bool status)
{
    QDir dir("C:/Users/THINK/Documents/myexe2/data");
    QFile file(dir.filePath("data.json"));
  //  file.setFileName("test.json");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QString val=file.readAll();

    QJsonDocument d=QJsonDocument::fromJson(val.toUtf8());
    //QJsonObject currentjson=d.object();
    //int num = currentjson.sumquestion;
    QJsonObject json;
    json.insert("question",q);
    json.insert("answer",a);
    json.insert("apperance",status);
    QJsonArray array=d.array();
    array.push_back(json);
    QJsonDocument md(array);
    file.remove();
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    file.write(md.toJson());
    file.close();
   QandA tmpQandA(q,a,status);
    mQandAVec.push_back(tmpQandA);
}

void client::readQandA()
{
    using namespace std;
    //QDir dir(mFile);
    QFile file("C:/Users/THINK/Documents/myexe2/data/data.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val=file.readAll();
    file.close();
    QJsonDocument d=QJsonDocument::fromJson(val.toUtf8());
    //QJsonObject json=d.object();
    //QString q,a;
    QJsonArray array=d.array();
    /*QDir dir("C:/Users/THINK/Documents/myexe2/data");
    QFile fileA(dir.filePath("test1.json"));
  //  file.setFileName("test.json");
    fileA.open(QIODevice::ReadWrite | QIODevice::Text);
    fileA.write(d.toJson());
    fileA.close();
    //std::cerr<<1;
    //qDebug()<<"1";*/
    for(int i=0;i<array.size();i++)
    {
        QJsonObject json=array.at(i).toObject();
        QandA tmpQandA(json.value("question").toString(),json.value("answer").toString(),json.value("apperance").toBool());
        //std::cout<<tmpQandA.apperance;
        if(tmpQandA.apperance==1)
        mQandAVec.push_back(tmpQandA);
        qDebug("readString = %s",qPrintable(tmpQandA.a));
    }
}

void client::SosoInsert()
{
    if(mQandAVec.size()<=num+6)mQandAVec.push_back(mQandAVec[num-1]),mQandAVec[mQandAVec.size()-1].today_times=2;
    else mQandAVec.insert(num+6,mQandAVec[num-1]),mQandAVec[num+6].today_times=2;
}
void client::BadInsert()
{
    if(mQandAVec.size()<=num+3)mQandAVec.push_back(mQandAVec[num-1]),mQandAVec[mQandAVec.size()-1].today_times=3;
    else mQandAVec.insert(num+3,mQandAVec[num-1]),mQandAVec[num+3].today_times=3;
}

void client::GoodInsert()
{
    if(mQandAVec[num-1].today_times<=1)return;
    else mQandAVec[num-1].today_times--;
    if(mQandAVec.size()<=num+6)mQandAVec.push_back(mQandAVec[num-1]),mQandAVec[mQandAVec.size()-1].today_times=mQandAVec[num-1].today_times;
    else mQandAVec.insert(num+6,mQandAVec[num-1]),mQandAVec[mQandAVec.size()-1].today_times=mQandAVec[num-1].today_times;
}

/*void client::findjs()
{
    QDir dir("C:/Users/THINK/Documents/myexe2/data");
    foreach (QFileInfo mfi, dir.entryInfoList())
    {
        if(mfi.fileName()=="."||mfi.fileName()=="..")continue;
        else if(mfi.isFile())
        {
            readQandA(mfi.fileName());
        }
    }
}*/


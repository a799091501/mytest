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
    file.write(md.toJson());
    file.close();
    QandA tmpQandA(q,a,status);
    QandA* temp=&tmpQandA;
    mQandAVec.push_back(temp);
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
    ///QString q,a;
    QJsonArray array=d.array();
    std::cerr<<1;
    //qDebug()<<"1";
    for(int i=0;i<array.size();i++)
    {
        QJsonObject json=array.at(i).toObject();
        QandA tmpQandA(json.value("question").toString(),json.value("answer").toString(),json.value("apperance").toBool());
        QandA* t=&tmpQandA;
        //std::cout<<tmpQandA.apperance;
        if(tmpQandA.apperance==1)
        mQandAVec.push_back(t);
        qDebug("readString = %s",qPrintable(t->a));
    }
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


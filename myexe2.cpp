#include"myexe2.h"
#include<QString>
#include<QDir>
#include<QJsonDocument>
#include<QJsonArray>
#include<QDebug>
void client::addQandA(QString q,QString a,bool status) const
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
}

void client::readQandA()
{
    //QDir dir(mFile);
    QFile file("C:/Users/THINK/Documents/myexe2/data");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val=file.readAll();
    file.close();
    QJsonDocument d=QJsonDocument::fromJson(val.toUtf8());
    //QJsonObject json=d.object();
    ///QString q,a;
    QJsonArray array=d.array();
    for(int i=0;i<array.size();i++)
    {
        QJsonObject json=array.at(i).toObject();
        qDebug()<<json.value("question").toString();
        qDebug()<<json.value("answer").toString();
        qDebug()<<json.value("apperance").toBool();
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


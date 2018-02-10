#ifndef MYEXE2_H
#define MYEXE2_H

#include<QObject>
#include<QString>
#include<QFile>
#include<QJsonObject>
#include<QIODevice>
#include<QDir>
#include<QVector>
#include<iostream>
class QandA
{
    //Q_GADGET;

    /*Q_OBJECT
    Q_PROPERTY(QString q READ showq WRITE setquestion)
    Q_PROPERTY(QString a READ showa WRITE setanswer)
    Q_PROPERTY(int today_times READ times WRITE settimes)
    Q_PROPERTY(bool apperance READ hasApperance WRITE setApperance )*/


public:
    QString q;
    QString a;
    int today_times;
    bool apperance;
    QJsonObject mJs;
    QandA(){}
    QandA(QString newq,QString  newa,bool s)
    {
        q=newq;
        a=newa;
        today_times=1;
        apperance=s;
    }
    //void setJs(){QFile file("/data/01.json");}
    void setquestion(QString tmpQ){q=tmpQ;}
    void setanswer(QString tmpA){a=tmpA;}
    void settimes(int newtime){today_times=newtime;}
    QString showq(){return q;}
    QString showa(){return a;}
    int times(){return today_times;}
    bool hasApperance(){return apperance;}
    void setApperance(bool a){apperance=a;}
    void judge(int status)
    {
        if(status==0)setApperance(0);
        else today_times=status;
    }

    //void setQandA();A
    ~QandA(){

    }

};

class client:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int num READ getnum WRITE setNum)
    Q_PROPERTY(bool sign READ getsign WRITE setSign )

public:
    int changednum;
    int getchangednum(){return changednum;}
    void setChangednum(int p){changednum=p;}
    //int showa(){return a;}
    int num;
    int getnum(){return num;}
    void setNum(int a){num=a;}
    bool sign;
    bool getsign(){return sign;}
    void setSign(bool a){sign=a;}
    client(){};
    ~client(){};
    Q_INVOKABLE void addQandA(QString,QString,bool);
    Q_INVOKABLE  void readQandA();
    //Q_INVOKABLE void findjs();
    QVector<QandA>mQandAVec;
    Q_INVOKABLE bool judge(){return (num==mQandAVec.size())?1:0;}
    Q_INVOKABLE QString showa(int p){std::cerr<<p; return mQandAVec[p].a;}
    Q_INVOKABLE QString showq(int p){std::cerr<<p; return mQandAVec[p].q;}
    Q_INVOKABLE void SosoInsert();
    Q_INVOKABLE void BadInsert();
    Q_INVOKABLE void GoodInsert();

    //void addQandA(const &QJsonObject);
};
#endif // MYEXE2_H

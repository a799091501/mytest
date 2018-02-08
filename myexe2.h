#ifndef MYEXE2_H
#define MYEXE2_H

#include<QObject>
#include<QString>
#include<QFile>
#include<QJsonObject>
#include<QIODevice>
#include<QDir>
#include<QVector>

class QandA:public QObject
{
    //Q_GADGET;

    Q_OBJECT
    Q_PROPERTY(QString q READ showq WRITE setquestion)
    Q_PROPERTY(QString a READ showa WRITE setanswer)
    Q_PROPERTY(int today_times READ times WRITE settimes)
    Q_PROPERTY(bool apperance READ hasApperance WRITE setApperance )
private:
    QString q;
    QString a;
    int today_times;
    bool apperance;
    QJsonObject mJs;

public:
    QandA(){}
    /*QandA(QString &newq,QString &newa)
    {
        q=newq;
        a=newa;
        today_times=1;
        apperance=1;
    }*/
    //void setJs(){QFile file("/data/01.json");}
    void setquestion(QString tmpQ){q=tmpQ;}
    void setanswer(QString tmpA){a=tmpA;}
    void settimes(int newtime){today_times=newtime;}
    QString showq()const{return q;}
    QString showa() const{return a;}
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
public:
    Q_INVOKABLE void addQandA(QString,QString,bool)const;
    Q_INVOKABLE  void readQandA();
    //Q_INVOKABLE void findjs();
    QVector<QandA*>mQandAVec;
};
#endif // MYEXE2_H

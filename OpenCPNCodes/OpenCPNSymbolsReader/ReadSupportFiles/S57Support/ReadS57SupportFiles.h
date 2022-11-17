#ifndef READS57SUPPORTFILES_H
#define READS57SUPPORTFILES_H

#include <QObject>
#include <QApplication>
#include <QDebug>
#include <QVector>
#include <QStringList>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <iostream>
#include <QList>


typedef struct SymbolIdentification{
    QString MIdentifier="";
    int RecordId=0;
    short status=0;
    QString Temp="";
}Identification;

typedef struct SymbolDefination{
    QString SymbolName="";
    QString DataType="";
    ushort PivotX,  /* Pivot point column no. */
           PivotY,  /* Pivot point row no */
           Width,   /* Width of the bounding box. */
           Height,  /* Height of the bounding box. */
           ULeftC,     /* Upper Left Column No. */
           ULeftR,     /* Upper Left Row No. */
           MinDist, /* Min dist b/w pattern symbols */
           MaxDist; /* Max dist b/w pattern symbols */
}Defination;

typedef struct SymbolDescription{
    QString SymbolDesc="";
}Description;

typedef struct SymbolColorReference{
    /* Symbol Colour Reference*/
    QString Color="";
    ushort ColorIndex=0;
}ColorRef;

class ReadS57SupportFiles : public QObject
{
    Q_OBJECT
public:
    explicit ReadS57SupportFiles(QObject *parent = nullptr);

public slots:
    void readS57SymbolsFile();
    QMap<QString,QStringList> getS57Symbols();
signals:

private slots:
    void processLineData(QString Data);


    void initialiseData(QString Sym, QStringList lst);
private:
    QString path="";
    QMap<QString,QStringList> SymbolData;
    QStringList List;



    Identification Iden;
    Defination Def;
    Description Desc;
    ColorRef ClrRef;


};

#endif // READS57SUPPORTFILES_H

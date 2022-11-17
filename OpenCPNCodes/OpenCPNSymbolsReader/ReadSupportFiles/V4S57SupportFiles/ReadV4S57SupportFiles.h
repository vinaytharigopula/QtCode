#ifndef READV4S57SUPPORTFILES_H
#define READV4S57SUPPORTFILES_H

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

#include "V4S57ColorCalibLib.h"
#include "V4S57LookUpTableLibrary.h"
#include "V4S57SymbolLibrary.h"


//#include "openCPNS57Attributes.h"
//#include "OpenCPNS57Objects.h"


class ReadV4S57SupportFiles : public QObject
{
    Q_OBJECT
public:
    explicit ReadV4S57SupportFiles(QObject *parent = nullptr);

signals:

public slots:
    void readVersion4_S57Data_File();

//    void readOPENCPN_S57Attributes_File();
//    void readOPENCPN_S57ObjectClass_File();
private slots:
//    void processLineData(QString Data);
//    void categoriseDataBasedOnCommand(QStringList DataList);

    void processLineData(QString Data);
    void categoriseDataBasedOnCommand(QStringList DataList);
private:
    QString path="";
    QString SymbolsVSupportFileName="";
    QString SymbolsRSupportFileName="";

    QString ColorCalibSupportFileName="";

    QString plainBoundariesLukupTblFileName="";
    QString symbolisedBoundryLukupTblFileName="";
    QString linesLukupTblFileName="";
    QString SimplifiedLukupTblFileName="";
    QString paperChartLukupTblFileName="";


    QString AttributeFileName="";

    QString ObjectClassFileName="";



    QVector<QString> FileRawData;
    QStringList SourceDataList;


    V4S57ColorCalibLib S57ColorCalibLib;
    V4S57LookUpTableLibrary S57LukupTbleLib;

    V4S57SymbolLibrary  S57SymLib;


//    openCPNS57Attributes S57Atrr;
//    OpenCPNS57Objects S57ObjectClass;
};

#endif // READV4S57SUPPORTFILES_H

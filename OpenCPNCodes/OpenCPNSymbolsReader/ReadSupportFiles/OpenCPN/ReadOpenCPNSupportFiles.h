#ifndef READOPENCPNSUPPORTFILES_H
#define READOPENCPNSUPPORTFILES_H

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

#include "OpenCPNS57SymbolLibrary.h"
#include "OpenCPNS57ColorCalibLibrary.h"
#include "OpenCPNS57LookUpTableLibrary.h"

#include "openCPNS57Attributes.h"
#include "OpenCPNS57Objects.h"


class ReadOpenCPNSupportFiles : public QObject
{
    Q_OBJECT
public:
    explicit ReadOpenCPNSupportFiles(QObject *parent = nullptr);
    ~ReadOpenCPNSupportFiles();


public slots:
    void readOPENCPN_S57Data562_File();

    void readOPENCPN_S57Attributes_File();
    void readOPENCPN_S57ObjectClass_File();
private slots:
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



    OpenCPNS57SymbolLibrary S57CPNSymLib;
    OpenCPNS57ColorCalibLibrary S57CPNColorCalibLib;
    OpenCPNS57LookUpTableLibrary S57CPNLukupTbleLib;

    openCPNS57Attributes S57Atrr;
    OpenCPNS57Objects S57ObjectClass;
};

#endif // READOPENCPNSUPPORTFILES_H

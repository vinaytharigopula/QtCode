#ifndef S57DRAWSYMBOLS_H
#define S57DRAWSYMBOLS_H

#include <QWidget>
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
#include <QPolygon>
#include <QPaintEvent>
#include <QPainter>

#include "../ReadSupportFiles/S57Support/ReadS57SupportFiles.h"


class S57DrawSymbols : public QObject
{
    Q_OBJECT
public:
    explicit S57DrawSymbols(QObject *parent = nullptr);

public slots:
    void setSymbolData(QMap<QString,QStringList> Data);
    void setS57SymbolInstrnDataMap(QMap<QString,SymbolAllData> SymInstrn);
    void paint(QPaintEvent *event, QPainter *painter, QString Symbol);
signals:

protected:
 //   void paintEvent(QPaintEvent *event) override;

private slots:


    void processSymbolInstrnData(QString Symbol, SymbolAllData SymInstrnData, QPaintEvent *event, QPainter *painter);
    void onDrawLine(SymVectrData VecData, QPaintEvent *event, QPainter *painter);
    void onDrawPolygon(SymVectrData VecData, QPaintEvent *event, QPainter *painter);
    void onDrawCircle(SymVectrData VecData, QPaintEvent *event, QPainter *painter);
    void onDrawArc(SymVectrData VecData, QPaintEvent *event, QPainter *painter);
    QPointF scaleTheCoordinates(QPointF P);
private:

    double fscale;

     QMap<QString,QStringList> SymbolData;

     QPen Pen1;
     QPen Pen2;

     QMap<QString,SymbolAllData> SymbolInstrnDataMap;

     SymIdentification SymblIden;
     SymDefination SymblDef;
     SymDescription SymblDesc;
     SymColorRef SymblClrRef;
     QVector<SymColorRef> ClrRefVec;
     SymVectorData SymblVctrData;
     QVector<SymVectrData> SymblVectrDataVec;

     SymAllData SymblInstrnData;

     QPaintEvent *event;
     QPainter *painter;

     QPointF ScreenCoordinates,DiagAOI;

};

#endif // S57DRAWSYMBOLS_H

#ifndef OPENCPNS57COLORCALIBLIBRARY_H
#define OPENCPNS57COLORCALIBLIBRARY_H

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
//#include <QPoint>



class rgbPoint : public QObject
{
    Q_OBJECT
public:
    rgbPoint(QString SName="",double R=0.0,double G=0.0,double B=0.0,QString ClrName="");
    rgbPoint(const rgbPoint& t);
    rgbPoint operator=(const rgbPoint& t);
    ~rgbPoint() {
        clear();
    }
public slots:
    QString getSymName();
    double getRValue();
    double getGValue();
    double getBValue();
    QString getClrName();

    void setSymName(QString S);
    void setRValue(double r);
    void setGValue(double g);
    void setBValue(double b);
    void setClrName(QString S);
    void setData(QString SymName,double r,double g,double b,QString ClrName);

    void printData();
    void clear();
private:
    QString SymName="";
    double r=0.0;
    double g=0.0;
    double b=0.0;
    QString ClrName="";

};


class rgbStructure : public QObject
{
    Q_OBJECT
public:
    rgbStructure() {}

    rgbStructure(const rgbStructure& t){
        this->rgbPointList=t.rgbPointList;
    }
    rgbStructure operator=(const rgbStructure& t){
        rgbStructure res;
        res.rgbPointList=t.rgbPointList;
        return res;
    }

    ~rgbStructure() {
        clearrgbPoint();
    }

    void appendrgbPoint(rgbPoint P){
        rgbPointList.append(P);
    }
    void clearrgbPoint(){
        rgbPointList.clear();
    }

    QList<rgbPoint> getrgbPointList(){
        return rgbPointList;
    }
    void printrgbPointList(){
        foreach (rgbPoint var, rgbPointList) {
            var.printData();
        }
    }

private:
    QList<rgbPoint> rgbPointList;
};

class OpenCPNS57ColorCalibLibrary : public QObject
{
    Q_OBJECT
public:
    explicit OpenCPNS57ColorCalibLibrary(QObject *parent = nullptr);
    ~OpenCPNS57ColorCalibLibrary();
public slots:
    QMap<QString,QStringList> getColorCalibDataMap();
    void appendColorCalibData(QString ColorName, QStringList List);
    void clear();

    void writeDataIntoSupportFile(QString path, QString Name);
signals:

private:
    QMap<QString,QStringList> ColorCalibDataMap;
    QMap<QString,rgbStructure> rgbColorList;


};

#endif // OPENCPNS57COLORCALIBLIBRARY_H

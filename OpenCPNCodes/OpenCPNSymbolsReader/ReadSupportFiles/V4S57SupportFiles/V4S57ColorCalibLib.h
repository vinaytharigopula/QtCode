#ifndef V4S57COLORCALIBLIB_H
#define V4S57COLORCALIBLIB_H

#include <QObject>



#include "../OpenCPN/OpenCPNS57ColorCalibLibrary.h"

class V4S57ColorCalibLib : public QObject
{
    Q_OBJECT
public:
    explicit V4S57ColorCalibLib(QObject *parent = nullptr);

    ~V4S57ColorCalibLib();
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

#endif // V4S57COLORCALIBLIB_H

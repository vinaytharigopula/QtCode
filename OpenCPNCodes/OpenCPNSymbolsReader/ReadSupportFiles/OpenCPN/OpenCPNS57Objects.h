#ifndef OPENCPNS57OBJECTS_H
#define OPENCPNS57OBJECTS_H

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

class OpenCPNS57Objects : public QObject
{
    Q_OBJECT
public:
    explicit OpenCPNS57Objects(QObject *parent = nullptr);
    ~OpenCPNS57Objects();
public slots:
    void clearObjectClassData();
    void appendObjectClassData(QString data);
    void writeObjectClassSupportFile(QString path, QString Name);
signals:


private:
    QString Special;

    QVector<QString> ObjectClasses;
    QString Final;

};

#endif // OPENCPNS57OBJECTS_H

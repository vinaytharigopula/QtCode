#ifndef OPENCPNS57ATTRIBUTES_H
#define OPENCPNS57ATTRIBUTES_H

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

class openCPNS57Attributes : public QObject
{
    Q_OBJECT
public:
    explicit openCPNS57Attributes(QObject *parent = nullptr);
    ~openCPNS57Attributes();

public slots:
    void clearAtrrData();
    void appendAttributeData(QString data);
    void writeAtrrSupportFile(QString path, QString Name);

private:

    QString Special;

    QVector<QString> AtrrVec;
    QString Final;
};

#endif // OPENCPNS57ATTRIBUTES_H

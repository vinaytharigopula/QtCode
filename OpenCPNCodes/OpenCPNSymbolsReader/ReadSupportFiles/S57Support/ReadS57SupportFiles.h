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


private:
    QString path="";
    QMap<QString,QStringList> SymbolData;
    QStringList List;

};

#endif // READS57SUPPORTFILES_H

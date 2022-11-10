#ifndef READSUPPORTFILEDATA_H
#define READSUPPORTFILEDATA_H

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

class ReadSupportFileData : public QObject
{
    Q_OBJECT
public:
    explicit ReadSupportFileData(QObject *parent = nullptr);

public slots:
    void readFileData();
signals:

private slots:
    void processLine(QString Data);

    void categoriseData(QStringList List);
    void categoriseColorsData(QStringList list);
    void categoriseLookUpTableData(QStringList list);
    void categoriseSymbolData(QStringList list);
    void categorisePatternData(QStringList list);
    void categoriseLineData(QStringList list);
    void writeSymbolsDataToText(QString FileName);
    void prepareListFor_PlainBoundaries(QStringList list);
private:
    QStringList SourceData;
    QVector<QStringList> SourceDataVec;

//    QVector<QStringList> SourceSymVec;
    QMap<QString,QStringList> SymbolDataMap;


    QMap<QString,QStringList> PatternDataMap;


    QMap<QString,QStringList> LineDataMap;


    QString numOfSpaces;

};

#endif // READSUPPORTFILEDATA_H

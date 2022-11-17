#ifndef V4S57LOOKUPTABLELIBRARY_H
#define V4S57LOOKUPTABLELIBRARY_H

#include <QObject>


#include "../OpenCPN/OpenCPNS57LookUpTableLibrary.h"

class V4S57LookUpTableLibrary : public QObject
{
    Q_OBJECT
public:
    explicit V4S57LookUpTableLibrary(QObject *parent = nullptr);

    ~V4S57LookUpTableLibrary();
signals:

public slots:

    void appendLookUpTbleData(QString Type,QStringList List);
    void clear();


    QVector<LookupTable> getPlainBoundariesVec();
    QVector<LookupTable> getSymbolisedBoundryVec();
    QVector<LookupTable> getLinesVec();
    QVector<LookupTable> getSimplifiedVec();
    QVector<LookupTable> getPaperChartVec();


    void writePlainBoundariesData(QString path, QString Name);
    void writesymbolisedBoundaryData(QString path, QString Name);
    void writelinesData(QString path, QString Name);
    void writeSimplifiedData(QString path, QString Name);
    void writepaperChartData(QString path, QString Name);

private slots:
    void writeLukTblIntoSupportFile(QString path, QString Name,QVector<LookupTable> DataVec);
private:
    //LookupTable
    QVector<LookupTable> plainBoundariesVec;
    QVector<LookupTable> symbolisedBoundryVec;
    QVector<LookupTable> linesVec;
    QVector<LookupTable> simplifiedVec;
    QVector<LookupTable> paperChartVec;

    QStringList S57LukTblLib;
};

#endif // V4S57LOOKUPTABLELIBRARY_H

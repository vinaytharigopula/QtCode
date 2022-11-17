#ifndef V4S57SYMBOLLIBRARY_H
#define V4S57SYMBOLLIBRARY_H

#include <QObject>
#include "../OpenCPN/OpenCPNS57SymbolLibrary.h"

class V4S57SymbolLibrary : public QObject
{
    Q_OBJECT
public:
    explicit V4S57SymbolLibrary(QObject *parent = nullptr);

    ~V4S57SymbolLibrary();
signals:
public slots:

    void clear();

    void appendLibrary(QString SymName, QStringList List);

    QMap<QString,QStringList> getVSymbolDataMap();
    void appendVSymbolData(QString SymName, QStringList List);
    void clearVSymbol();

    QMap<QString,QStringList> getRSymbolDataMap();
    void appendRSymbolData(QString SymName, QStringList List);
    void clearRSymbol();




    QMap<QString,QStringList> getVPatternDataMap();
    void appendVPatternData(QString PatName, QStringList List);
    void clearVPattern();

    QMap<QString,QStringList> getRPatternDataMap();
    void appendRPatternData(QString PatName, QStringList List);
    void clearRPattern();



    QMap<QString,QStringList> getVLineDataMap();
    void appendVLineData(QString LineName, QStringList List);
    void clearVLine();

    QMap<QString,QStringList> getRLineDataMap();
    void appendRLineData(QString LineName, QStringList List);
    void clearRLine();



    void writeVDataIntoSupportFile(QString path, QString Name);
    void writeRDataIntoSupportFile(QString path, QString Name);
private slots:

    void appendSymbolData(QString SymName, QStringList List);
    void appendPatternData(QString PatName, QStringList List);
    void appendLineData(QString LineName, QStringList List);
private:
    QMap<QString,QStringList> SymbolDataMap_V;
    QMap<QString,QStringList> SymbolDataMap_R;

    QMap<QString,QStringList> PatternDataMap_V;
    QMap<QString,QStringList> PatternDataMap_R;

    QMap<QString,QStringList> LineDataMap_V;
    QMap<QString,QStringList> LineDataMap_R;


    //QPlainTextEdit S57SymbLib;//S57SymbLib1.dat
    QStringList S57SymbLib;

    QString Space="";

};

#endif // V4S57SYMBOLLIBRARY_H

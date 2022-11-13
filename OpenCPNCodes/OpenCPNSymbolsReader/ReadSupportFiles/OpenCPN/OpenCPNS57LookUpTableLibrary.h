#ifndef OPENCPNS57LOOKUPTABLELIBRARY_H
#define OPENCPNS57LOOKUPTABLELIBRARY_H

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


class LookupTable : public QObject
{
    Q_OBJECT
public:
    LookupTable(QString ObjN="",QString AttrC="",QString SymInst="",QString DispPri="",QString radr="",QString dispCat="",QString VGrp="") {
        this->ObjName=ObjN;//1.field
        this->AttrCombi=AttrC;//2.field
        this->SymInstrn=SymInst;//3.field
        this->DispPriority=DispPri;//4.field

        this->radar=radr;
        this->dispCat=dispCat;
        this->viewingGrp=VGrp;
    }

    LookupTable(const LookupTable& t){
        this->ObjName=t.ObjName;//1.field
        this->AttrCombi=t.AttrCombi;//2.field
        this->SymInstrn=t.SymInstrn;//3.field
        this->DispPriority=t.DispPriority;//4.field

        this->radar=t.radar;
        this->dispCat=t.dispCat;
        this->viewingGrp=t.viewingGrp;
    }

    void setData(QString ObjN="",QString AttrC="",QString SymInst="",QString DispPri="",QString radr="",QString dispCat="",QString VGrp=""){
        this->ObjName=ObjN;//1.field
        this->AttrCombi=AttrC;//2.field
        this->SymInstrn=SymInst;//3.field
        this->DispPriority=DispPri;//4.field

        this->radar=radr;
        this->dispCat=dispCat;
        this->viewingGrp=VGrp;
    }

    LookupTable getData(){
        LookupTable res(this->ObjName,this->AttrCombi,this->SymInstrn,this->DispPriority,this->radar,this->dispCat,this->viewingGrp);
        return res;
    }


    LookupTable operator=(const LookupTable& t){
        LookupTable res(this->ObjName,this->AttrCombi,this->SymInstrn,this->DispPriority,this->radar,this->dispCat,this->viewingGrp);
        return res;
    }

    QString printData(){
        QString Data=QString(ObjName+AttrCombi+SymInstrn+DispPriority+radar+dispCat+viewingGrp);
        //qDebug()<<Data;
        return Data;
    }


    ~LookupTable() {}
//private:
    QString ObjName="";//1.field
    QString AttrCombi="";//2.field
    QString SymInstrn="";//3.field
    QString DispPriority="";//4.field

    QString radar="";
    QString dispCat="";
    QString viewingGrp="";

};

class OpenCPNS57LookUpTableLibrary : public QObject
{
    Q_OBJECT
public:
    explicit OpenCPNS57LookUpTableLibrary(QObject *parent = nullptr);
    ~OpenCPNS57LookUpTableLibrary();

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

#endif // OPENCPNS57LOOKUPTABLELIBRARY_H

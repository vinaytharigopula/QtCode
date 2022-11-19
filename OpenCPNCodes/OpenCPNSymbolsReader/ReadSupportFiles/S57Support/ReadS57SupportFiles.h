#ifndef READS57SUPPORTFILES_H
#define READS57SUPPORTFILES_H

#include <QObject>
#include <QApplication>
#include <QDebug>
#include <QVector>
#include <QStringList>
#include <QPolygonF>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <iostream>
#include <QList>


typedef struct SymIdentification{
    QString MIdentifier="";
    int RecordId=0;
    short status=0;
    QString Temp="";

    void clear(){
        MIdentifier="";
        RecordId=0;
        status=0;
        Temp="";
    }
    QString printData(){
        QString Temp;
        Temp.append("Identifier:"+MIdentifier);
        Temp.append(",RecordId:"+QString::number(RecordId));
        Temp.append(",status:"+QString::number(status));
        return Temp;
    }

}SymIdentify;

typedef struct SymDefination{
    QString SymbolName="";
    QString SymbolType=""; /* V- vector Data & R - Raster Data */

    QString PatternFillType=""; /* Type of Fill Pattern */
    QString PatternSymbSpacing=""; /* Pattern Symbol Spacing */

    ushort PivotX=0,  /* Pivot point column no. */
    PivotY=0,  /* Pivot point row no */
    Width=0,   /* Width of the bounding box. */
    Height=0,  /* Height of the bounding box. */
    ULeftC=0,     /* Upper Left Column No. */
    ULeftR=0,     /* Upper Left Row No. */
    MinDist=0, /* Min dist b/w pattern symbols */
    MaxDist=0; /* Max dist b/w pattern symbols */

    void clear(){
        SymbolName="";
        SymbolType="";

        PatternFillType="";
        PatternSymbSpacing="";
        PivotX=0,
                PivotY=0,
                Width=0,
                Height=0,
                ULeftC=0,
                ULeftR=0,
                MinDist=0,
                MaxDist=0;
    }
    QString printData(){
        QString Temp;
        Temp.append("SymbolName:"+SymbolName);
        Temp.append("SymbolType:"+SymbolType);

        Temp.append("PaternFillType:"+PatternFillType);
        Temp.append("PaternSymbSpacing:"+PatternSymbSpacing);


        Temp.append(",PvtX:"+QString::number(PivotX));
        Temp.append(",PvtY:"+QString::number(PivotY));
        Temp.append(",Width:"+QString::number(Width));
        Temp.append(",Height:"+QString::number(Height));
        Temp.append(",ULeftC:"+QString::number(ULeftC));
        Temp.append(",ULeftR:"+QString::number(ULeftR));
        Temp.append(",MinDist:"+QString::number(MinDist));
        Temp.append(",MaxDist:"+QString::number(MaxDist));
        return Temp;
    }

}SymDefn;

typedef struct SymDescription{
    QString SymbolDesc="";
    void clear(){
        SymbolDesc="";
    }
    QString printData(){
        QString Temp;
        Temp.append("Desc:"+SymbolDesc);
        return Temp;
    }

}SymDescrpn;

typedef struct SymColorReference{
    /* Symbol Colour Reference*/
    QString Color="";
    QString ColorIndex="";

    void clear(){
        Color="";
        ColorIndex="";
    }
    QString printData(){
        QString Temp;
        Temp.append("Color:"+Color);
        Temp.append(",ColorIndex:"+ColorIndex);
        return Temp;
    }
}SymColorRef;

typedef struct SymVectorData{
    QString VecColorIndex="";
    ushort PenWidth=1;
    int radius=0;
    //type of the vector
    ushort VecFill;	   /* 0 - No fill, 1 - filled       */
    ushort VecType=0; /* 0-Line , 1 - Arc , 2-Circle, 3 - Poly , 4-Symbol */
    ushort VecTransparent=0;
    QPointF PenUpPt;
    QPointF PenDownPt;
    QPolygonF PenDownPoly;

    void clear(){
        VecColorIndex="";
        PenWidth=1;
        radius=0;
        PenUpPt=QPointF(0,0);
        PenDownPt=QPointF(0,0);
        PenDownPoly.clear();
    }

    QString printData(){
        QString Temp;
        Temp.append("VecColorIndex:"+VecColorIndex);
        Temp.append(",PenWidth:"+QString::number(PenWidth));
        Temp.append(",radius:"+QString::number(radius));
        Temp.append(",VecFill:"+QString::number(VecFill));
        Temp.append(",VecType:"+QString::number(VecType));
        Temp.append(",VecTransparent:"+QString::number(VecTransparent));
        Temp.append(",PenUpPt:("+QString::number(PenUpPt.x())+","+QString::number(PenUpPt.y())+")");
        Temp.append(",PenDownPt:("+QString::number(PenDownPt.x())+","+QString::number(PenDownPt.y())+")");

        Temp.append(",PenDownPoly:"+QString::number(PenDownPoly.size())+":");
        foreach (QPointF var, PenDownPoly) {
            Temp.append("("+QString::number(var.x())+","+QString::number(var.y())+"),");
        }
        return Temp;
    }

}SymVectrData;

typedef struct SymbolAllData{
    SymIdentify SymblIdentify;
    SymDefn SymblDefn;

    SymDescrpn SymblDesc;
    SymColorRef SymblClrRefs;
    QVector<SymColorRef> ClrRefVec;
    SymVectrData SymblVectrData;
    QVector<SymVectrData> SymblVectrDataVec;

    void clear(){
        SymblIdentify.clear();
        SymblDefn.clear();
        SymblDesc.clear();
        SymblClrRefs.clear();
        ClrRefVec.clear();
        SymblVectrData.clear();
        SymblVectrDataVec.clear();
    }
    QString printData(){
        QString Temp="";
        Temp.append(SymblIdentify.printData());
        Temp.append("\n");
        Temp.append(SymblDefn.printData());
        Temp.append("\n");
        Temp.append(SymblDesc.printData());
        Temp.append("\n");
        foreach (SymColorRef var, ClrRefVec) {
            Temp.append(var.printData());
        }
        Temp.append("\n");

        foreach (SymVectrData var, SymblVectrDataVec) {
            Temp.append(var.printData());
        }
        Temp.append("\n");
        return Temp;
    }
}SymAllData;

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


    void initialiseData(QString Sym, QStringList lst);
    void processSymbolVectorData(QStringList DataList);
    void saveDataInSymbolData();
    void processSymbolIdentificationData(QString Data);
    void processSymbolExpositionData(QString Data);
    void processSymbolColRefData(QString Data);
private:
    QString path="";
    QMap<QString,QStringList> SymbolData;
    QStringList List;

    SymVectorData SymblVctrData;

    SymIdentification SymblIden;
    SymDefination SymblDef;
    SymDescription SymblDesc;
    SymColorRef SymblClrRef;

    SymAllData SymblInstrnData;
    QVector<SymAllData> SymblInstrnDataVec;
    QMap<QString,SymbolAllData> SymbolInstrnDataMap;

};

#endif // READS57SUPPORTFILES_H

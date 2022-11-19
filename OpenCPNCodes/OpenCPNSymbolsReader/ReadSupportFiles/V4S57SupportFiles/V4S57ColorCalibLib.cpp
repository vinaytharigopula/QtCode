#include "V4S57ColorCalibLib.h"




V4S57ColorCalibLib::V4S57ColorCalibLib(QObject *parent) : QObject(parent)
{

}
V4S57ColorCalibLib::~V4S57ColorCalibLib()
{
    clear();
}
QMap<QString, QStringList> V4S57ColorCalibLib::getColorCalibDataMap(){
    return ColorCalibDataMap;
}

void V4S57ColorCalibLib::appendColorCalibData(QString ColorName, QStringList List)
{
    QString SplitChar="\u001F";

    QString Data="";

    QStringList rgbList;
    rgbStructure rgbStrctList;
    rgbPoint rgbPt;

    foreach(QString Val,List){
        Data=Val;
        Data=Data.mid(9,Val.length());
        Data=Data.remove("\n");

        if(Val.contains("CCIE   ")){
            //CCIE   30NODTA0.2800\u001F0.3100\u001F45.00\u001Fgrey\u001F\n
            rgbList=Data.split(SplitChar);

            //qDebug()<<rgbList;


            rgbPt.clear();

            QString temp="";
            if(rgbList.size()>3){
                temp=rgbList.at(0);

                QString SymName=temp.mid(0,5);
                double rval=temp.midRef(6,temp.length()).toDouble();
                double gval=rgbList.at(1).toDouble();
                double bval=rgbList.at(2).toDouble();
                QString Clrname=rgbList.at(3);

                //qDebug()<<SymName<<rval<<gval<<bval<<Clrname;

                rgbPt.setData(SymName,rval,gval,bval,Clrname);

                rgbStrctList.appendrgbPoint(rgbPt);
                //rgbStrctList.printrgbPointList();
            }
        }
    }

    ColorCalibDataMap.insert(ColorName,List);
    rgbColorList.insert(ColorName,rgbStrctList);

    //qDebug()<<rgbColorList.size()<<ColorName<<endl;

}

void V4S57ColorCalibLib::clear()
{
    ColorCalibDataMap.clear();
    rgbColorList.clear();
}

void V4S57ColorCalibLib::writeDataIntoSupportFile(QString path, QString Name)
{

    //qDebug()<<"writeDataIntoSupportFile"<<rgbColorList.size()<<ColorCalibDataMap.size();

    QMapIterator<QString,rgbStructure> i(rgbColorList);
    while (i.hasNext()) {
        i.next();

        rgbStructure rgnStr=i.value();

        //qDebug()<<i.key()<<rgnStr.getrgbPointList().size();

        foreach (rgbPoint var, rgnStr.getrgbPointList()) {
            //var.printData();
        }
    }

}

#include "OpenCPNS57ColorCalibLibrary.h"



rgbPoint::rgbPoint(QString SName, double R, double G, double B, QString ClrName) {
    this->SymName=SName;
    this->r=R;
    this->g=G;
    this->b=B;
    this->ClrName=ClrName;
}
rgbPoint::rgbPoint(const rgbPoint& t){
    this->SymName=t.SymName;
    this->r=t.r;
    this->g=t.g;
    this->b=t.b;
    this->ClrName=t.ClrName;
}
rgbPoint rgbPoint::operator=(const rgbPoint& t){
    rgbPoint res;
    res.SymName=t.SymName;
    res.r=t.r;
    res.g=t.g;
    res.b=t.b;
    res.ClrName=t.ClrName;
    return res;
}


QString rgbPoint::getSymName(){ return SymName;}
double rgbPoint::getRValue(){ return r;}
double rgbPoint::getGValue(){ return g;}
double rgbPoint::getBValue(){ return b;}
QString rgbPoint::getClrName(){ return ClrName;}

void rgbPoint::setSymName(QString Name){ this->SymName=Name;}
void rgbPoint::setRValue(double r){ this->r=r;}
void rgbPoint::setGValue(double g){ this->g=g;}
void rgbPoint::setBValue(double b){ this->b=b;}
void rgbPoint::setClrName(QString Name){ this->ClrName=Name;}

void rgbPoint::setData(QString SymName, double r, double g, double b, QString ClrName){
    this->SymName=SymName;
    this->r=r;
    this->g=g;
    this->b=b;
    this->ClrName=ClrName;
}

void rgbPoint::printData(){
    qDebug()<<SymName<<r<<g<<b<<ClrName;
}

void rgbPoint::clear(){
    SymName="";
    r=0.0;
    g=0.0;
    b=0.0;
    ClrName="";
}








OpenCPNS57ColorCalibLibrary::OpenCPNS57ColorCalibLibrary(QObject *parent) : QObject(parent)
{

}


QMap<QString,QStringList> OpenCPNS57ColorCalibLibrary::getColorCalibDataMap(){
    return ColorCalibDataMap;
}
void OpenCPNS57ColorCalibLibrary::appendColorCalibData(QString ColorName, QStringList List){


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
            }
        }
    }

    ColorCalibDataMap.insert(ColorName,List);
    rgbColorList.insert(ColorName,rgbStrctList);

    //qDebug()<<ColorName<<endl<<List<<endl;
}

void OpenCPNS57ColorCalibLibrary::clear(){
    ColorCalibDataMap.clear();
    rgbColorList.clear();
}

void OpenCPNS57ColorCalibLibrary::writeDataIntoSupportFile(QString path,QString Name){


}
OpenCPNS57ColorCalibLibrary::~OpenCPNS57ColorCalibLibrary()
{
    clear();
}
//S57CPNColorCalibLib

#include "ReadS57SupportFiles.h"

ReadS57SupportFiles::ReadS57SupportFiles(QObject *parent) : QObject(parent)
{
    path="./MyResource/Data/MyOutPut/cairstyle";
}
QMap<QString,QStringList> ReadS57SupportFiles::getS57Symbols(){
    return SymbolData;
}


void ReadS57SupportFiles::readS57SymbolsFile(){
    List.clear();
    SymbolData.clear();
    SymblInstrnData.clear();
    SymblInstrnDataVec.clear();
    SymbolInstrnDataMap.clear();

    QString filePath="";

    filePath=path+"/S52SymbLib1.dat";


    // Open File
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // Start Reading the File
    while (!file.atEnd()) {
        QString line = file.readLine();

        processLineData(line);
    }

//    //    qDebug()<<SymblInstrnDataVec.size();
//        foreach (SymAllData sym, SymblInstrnDataVec) {
//            SymAllData SymInstrnData=sym;
//            //if(SymInstrnData.SymblDefn.SymbolFullName.contains(".SYM")){
//                qDebug()<<SymInstrnData.printData();
//                qDebug()<<"============================";
//           // }
//        }


    qDebug()<<SymbolInstrnDataMap.size()<<"@@@@@@@@@@@@@@@@@@@@@@@";



    QMapIterator<QString,SymbolAllData> i(SymbolInstrnDataMap);

    SymAllData SymInstrnData;
    while (i.hasNext()) {
        i.next();


        qDebug()<<i.key()<<"***********************";
        SymInstrnData=i.value();
        //if(SymInstrnData.SymblDefn.SymbolFullName.contains(".SYM")){


        qDebug()<<SymInstrnData.printData();
        qDebug()<<"============================";
        // }
    }


}
void ReadS57SupportFiles::processLineData(QString Data){

    if((Data.contains("/* Symbol description */"))||(Data.contains("static char *ppszSymb[] = {"))){

    }else{
        Data=Data.trimmed();
        //qDebug()<<Data;


        if(Data.length()>2){
            List.append(Data);
        }else{
            // \n Found so new Data
            if(List.size()>1){
                QString SymName=List.at(0);

                List.removeFirst();
                SymbolData.insert(SymName,List);

                initialiseData(SymName,List);
            }

            List.clear();
        }
    }




    //qDebug()<<Data;

}


void ReadS57SupportFiles::initialiseData(QString Sym,QStringList lst){

    QString Temp="";

    //qDebug()<<Sym<<lst<<endl;

    SymblInstrnData.clear();

    foreach (QString Data, lst){
        // Symbol Identification
        if(Data.contains("SYMB")){
            processSymbolIdentificationData(Data);
        }else if(Data.contains("SYMD")){// Symbol Defination
            //Data=Data.simplified();
            //qDebug()<<Sym<<Data;

            SymblDef.SymbolName=Data.mid(9,8);
            SymblDef.SymbolType=Data.mid(17,1);
            Temp=Data.mid(18,5);
            SymblDef.PivotX=atoi(Temp.toLatin1());
            Temp=Data.mid(23,5);
            SymblDef.PivotY=atoi(Temp.toLatin1());
            Temp=Data.mid(28,5);
            SymblDef.Width=atoi(Temp.toLatin1());
            Temp=Data.mid(33,5);
            SymblDef.Height=atoi(Temp.toLatin1());
            Temp=Data.mid(39,5);
            SymblDef.ULeftC=atoi(Temp.toLatin1());
            Temp=Data.mid(43,5);
            SymblDef.ULeftR=atoi(Temp.toLatin1());

            //qDebug()<<SymbolName<<DataType<<PivotX<<PivotY<<Width<<Height<<ULeftC<<ULeftR;
            SymblInstrnData.SymblDefn=SymblDef;
        }else if(Data.contains("SXPO")){// Symbol Exposition
            processSymbolExpositionData(Data);
        }else if(Data.contains("SCRF")){// Symbol Colour Reference
            processSymbolColRefData(Data);
        }else if(Data.contains("SVCT")){// Symbol Vector Info
            //Data=Data.simplified();

            QString MainData=Data.mid(9,Data.length());
            QStringList DList=MainData.split(";");
            if(DList.last().length()<2){
                DList.removeLast();
            }
            processSymbolVectorData(DList);
            SymblInstrnData.SymblVectrDataVec.append(SymblVctrData);
        }



        if(Data.contains("LNST")){        /*Linestyle Identifier */
            processSymbolIdentificationData(Data);
        }else if(Data.contains("LIND")){    /* Linestyle Definition */
            //Data=Data.simplified();
            //qDebug()<<Sym<<Data;

            SymblDef.SymbolName=Data.mid(9,8);
            Temp=Data.mid(17,5);
            SymblDef.PivotX=atoi(Temp.toLatin1());
            Temp=Data.mid(22,5);
            SymblDef.PivotY=atoi(Temp.toLatin1());
            Temp=Data.mid(27,5);
            SymblDef.Width=atoi(Temp.toLatin1());
            Temp=Data.mid(32,5);
            SymblDef.Height=atoi(Temp.toLatin1());
            Temp=Data.mid(38,5);
            SymblDef.ULeftC=atoi(Temp.toLatin1());
            Temp=Data.mid(42,5);
            SymblDef.ULeftR=atoi(Temp.toLatin1());

            //qDebug()<<SymbolName<<DataType<<PivotX<<PivotY<<Width<<Height<<ULeftC<<ULeftR;
            SymblInstrnData.SymblDefn=SymblDef;
        }else if(Data.contains("LXPO")){   /* Linstyle Exposition */
            processSymbolExpositionData(Data);
        }else if(Data.contains("LCRF")){   /* Linstyle Colour Reference */
            processSymbolColRefData(Data);
        }else if(Data.contains("LVCT")){   /* Linstyle Vector Data */
            //Data=Data.simplified();

            QString MainData=Data.mid(9,Data.length());
            QStringList DList=MainData.split(";");
            if(DList.last().length()<2){
                DList.removeLast();
            }
            processSymbolVectorData(DList);
            SymblInstrnData.SymblVectrDataVec.append(SymblVctrData);
        }


        if(Data.contains("PATT")){              /* Pattern Identifier */
            processSymbolIdentificationData(Data);
        }else if(Data.contains("PATD")){        /* Pattern Definition */
            //Data=Data.simplified();
            //qDebug()<<Sym<<Data;

            SymblDef.SymbolName=Data.mid(9,8);  /* Name of pattern */
            SymblDef.SymbolType=Data.mid(17,1); /*Type of Pattern */

            SymblDef.PatternFillType=Data.mid(18,3); /* Pattern Fill Type */
            SymblDef.PatternSymbSpacing=Data.mid(21,3); /* Pattern Symbol spacing */

            Temp=Data.mid(24,5);
            SymblDef.MinDist=atoi(Temp.toLatin1());/* Min Distance between Pttrn symbols */
            Temp=Data.mid(29,5);
            SymblDef.MaxDist=atoi(Temp.toLatin1());/* Max Distance between Pttrn symbols */
            Temp=Data.mid(34,5);
            SymblDef.PivotX=atoi(Temp.toLatin1());
            Temp=Data.mid(39,5);
            SymblDef.PivotY=atoi(Temp.toLatin1());
            Temp=Data.mid(44,5);
            SymblDef.Width=atoi(Temp.toLatin1());
            Temp=Data.mid(49,5);
            SymblDef.Height=atoi(Temp.toLatin1());
            Temp=Data.mid(54,5);
            SymblDef.ULeftC=atoi(Temp.toLatin1());
            Temp=Data.mid(59,5);
            SymblDef.ULeftR=atoi(Temp.toLatin1());

            SymblInstrnData.SymblDefn=SymblDef;
            //qDebug()<<SymbolName<<DataType<<PivotX<<PivotY<<Width<<Height<<ULeftC<<ULeftR;

        }else if(Data.contains("PXPO")){/* Pattern Exposition */
            processSymbolExpositionData(Data);
        }else if(Data.contains("PCRF")){/* Pattern Colour Reference */
            processSymbolColRefData(Data);
        }else if(Data.contains("PBTM")){/* Pattern Bitmap*/

        }else if(Data.contains("PVCT")){/* Pattern Vector*/
            //Data=Data.simplified();

            QString MainData=Data.mid(9,Data.length());
            QStringList DList=MainData.split(";");
            if(DList.last().length()<2){
                DList.removeLast();
            }
            processSymbolVectorData(DList);
            SymblInstrnData.SymblVectrDataVec.append(SymblVctrData);
        }


    }

    SymblInstrnDataVec.append(SymblInstrnData);
    //qDebug()<<SymblInstrnData.printData();
    SymbolInstrnDataMap.insert(Sym,SymblInstrnData);


    //qDebug()<<"**********************************************************";
}


void ReadS57SupportFiles::processSymbolIdentificationData(QString Data){
    //Data=Data.simplified();


    QString Temp="";
    SymblIden.MIdentifier=Data.mid(9,2);
    SymblIden.RecordId=Data.midRef(11,5).toInt();
    Temp=Data.mid(16,3);
    if(Temp.contains("NIL")){
        SymblIden.status=0;
    }else if(Temp.contains("ADD")){
        SymblIden.status=1;
    }else if(Temp.contains("MOD")){
        SymblIden.status=1;
    }else if(Temp.contains("DEL")){
        SymblIden.status=2;
    }

    SymblInstrnData.SymblIdentify=SymblIden;
    //qDebug()<<Data<<Sym<<MIdentifier<<RecordId<<Temp<<status;


}
void ReadS57SupportFiles::processSymbolColRefData(QString Data){
    //Data=Data.simplified();
    QString Str=Data.mid(9,Data.length());

    //            QVector<SymColorRef> ClrRefVec;
    //qDebug()<<Str<<Data;
    if(Str.length()>6){
        //qDebug()<<Str<<Data;
        //qDebug()<<"_----------------";
        QString Tempr="";
        for (int i=0;i<Str.length() ;i+=6 ) {
            Tempr=Str.mid(i,6);
            if(Tempr.length()==6){
                //qDebug()<<Tempr;
                SymblClrRef.Color=Tempr.mid(1,5).simplified();
                SymblClrRef.ColorIndex=Tempr.mid(0,1);
                SymblInstrnData.ClrRefVec.append(SymblClrRef);
            }
        }
    }else{
        SymblClrRef.Color=Str.mid(1,5).simplified();
        SymblClrRef.ColorIndex=Str.mid(0,1);
        //qDebug()<<ClrRef.printData();
        SymblInstrnData.ClrRefVec.append(SymblClrRef);
    }
    SymblInstrnData.SymblClrRefs=SymblClrRef;


    //ColorIndex
    //qDebug()<<Sym<<Data<<Color;
}

void ReadS57SupportFiles::processSymbolExpositionData(QString Data){
    //Data=Data.simplified();
    //qDebug()<<Sym<<Data;
    SymblDesc.SymbolDesc=Data.mid(9,Data.length());
    //qDebug()<<SymbDesc;
    SymblInstrnData.SymblDesc=SymblDesc;
}

void ReadS57SupportFiles::processSymbolVectorData(QStringList DataList){
    //"SVCT   31SPA;SW1;PU1264,789;PD1264,1291;"


    SymblVctrData.clear();


    QString Temp="";

    //qDebug()<<DataList.size()<<DataList;

    foreach (QString var, DataList) {
        if(var.contains("SP")){/* color of the symbol/Line/Area.*/
            SymblVctrData.VecColorIndex=var.mid(2,var.length());
        }
        if(var.contains("SW")){/* Width of the line */
            SymblVctrData.PenWidth=var.midRef(2,var.length()).toUShort();
        }
        if(var.contains("CI")){/* vector is a Circle */
            SymblVctrData.radius=var.midRef(2,var.length()).toUShort();
            SymblVctrData.VecType=2;


        }
        if(var.contains("PM")){ /* vector type is a polygon */
            SymblVctrData.VecType=3;
        }
        if(var.contains("EP")){/* EP */
            SymblVctrData.VecType=3;
            SymblVctrData.VecFill=0;

        }
        if(var.contains("FP")){    /* FP (Fill the polygon with specified color. */
            SymblVctrData.VecFill=0;

        }
        if(var.contains("ST")){ /* transparency */
            SymblVctrData.VecTransparent = atoi(var.mid(19,2).toLatin1());//atoi (pszToken + 2);
        }
        if(var.contains("PU")){ /* Pen UP */
            Temp=var.mid(2,var.length());
            QStringList List;
            List=Temp.split(",");
            if(List.size()==2){
                SymblVctrData.PenUpPt=QPointF(List.at(0).toDouble(),List.at(1).toDouble());
            }
        }
        if((var.length()>4)&&var.contains("PD")){ /* Pen Down */
            Temp=var.mid(2,var.length());
            QStringList List;
            List=Temp.split(",");
            if(List.size()==2){
                SymblVctrData.PenDownPt=QPointF(List.at(0).toDouble(),List.at(1).toDouble());
            }else if(List.size()>=2){
                //qDebug()<<List.size()<<"++++++++++++++++++++++++++++++";
                for (int p=0;p<List.size();p+=2 ) {
                    //qDebug()<<List.at(p)<<List.at(p+1);
                    SymblVctrData.PenDownPoly.append(QPointF(List.at(p).toDouble(),List.at(p+1).toDouble()));
                }
            }
        }
        if(var.contains("AA")){/* Arc Angle */
            SymblVctrData.VecType=1;
        }
        if(var.contains("SC")){/* SymbolName, Orientation */
            SymblVctrData.VecType=4;

            qDebug()<<DataList;
        }
        if(var.contains("ST")){/* SymbolName, Orientation */

        }
        if(var.contains("FP")){

        }

        //PM//ST

        //qDebug()<<ColorIndex<<PenWidth<<radius<<PenUpPt<<PenDownPt<<PenDownPoly;
    }
    //  SymblVctrData.printData();
    //    qDebug()<<DataList;



}

void ReadS57SupportFiles::saveDataInSymbolData(){
    //

    //    SymblInstrnData.SymblIdentify=SymblIden;
    //    SymblInstrnData.SymblDefn=SymblDef;
    //    SymblInstrnData.SymblDesc=SymblDesc;
    //    SymblInstrnData.SymblClrRefs=SymblClrRef;
    //    SymblInstrnData.SymblVectrDataVec.append(SymblVctrData);

    //

}

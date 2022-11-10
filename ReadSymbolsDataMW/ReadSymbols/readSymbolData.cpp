#include "readSymbolData.h"


readSymbolData::readSymbolData(QObject *parent) : QObject(parent)
{

}

readSymbolData::~readSymbolData()
{

}

void readSymbolData::readSymbolsTextFile(){
    QString Path="G:/CAIR/CAIRGISLibs_28-06-2022/CAIRGISLibs_28-06-2022/src/CAIRGIS/MapLegend_Prashanth/Support/S52SymbLib1.dat";

    QFile file(Path);
    QString line;

    QString ext="";
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line.clear();

            line=QString(stream.readLine()).simplified();
            if(line.contains("/* Symbol description */") ){

            }else if(line.contains("static char *ppszSymb[] = {")){

            }else{
                loadSymbols(line);
            }
        }
    }
    file.close();


    processSymbolsData();
}
void readSymbolData::loadSymbols(QString Data){
    //qDebug()<<"1:"<<Data;
    if(Data.count()==0){
        if(SymbolDataList.size()>0){
            QString SymbolName=SymbolDataList.at(0);
            SymbolDataList.removeFirst();
            SymbolMap.insert(SymbolName,SymbolDataList);
        }
        SymbolDataList.clear();
        SymbolData.clear();
    }else{
        if(Data.contains(".LIN")||Data.contains(".SYM")||Data.contains(".PAT")){
            //qDebug()<<" Symobls Data Starts here ***************************";
            SymbolDataList.clear();

            SymbolDataList.append(Data);
        }else{
            SymbolDataList.append(Data);
        }
    }
}
void readSymbolData::processSymbolsData(){
    QStringList DataList;
    DataList.clear();
    QMapIterator<QString, QStringList> iter(SymbolMap);
    while(iter.hasNext()){
        iter.next();

        if(iter.key().contains(".SYM")){
            readSymbolFields(iter.key(),iter.value());
        }else if(iter.key().contains(".LIN")){
            readLINEFields(iter.key(),iter.value());
        }


    }
}


void readSymbolData::readSymbolFields(QString Data,QStringList DataList){
    //qDebug()<<DataList;

    foreach (QString Var, DataList) {
        if (Var.contains("SYMB")){/* Symbol Identifier field */
            readSymbolField_SYMB(Var);
        }else if (Var.contains("SYMD")){/* Symbol definition field */
            readSymbolField_SYMD(Var);
        }else if (Var.contains("SXPO")){/* Symbol Exposition Field */
            readSymbolField_SXPO(Var);
        }else if (Var.contains("SCRF")){/* Symbol Colour Reference Field */
            readSymbolField_SCRF(Var);
        }else if (Var.contains("SVCT")){/* Symbol Vector Field */
            readSymbolField_SVCT(Var);
        }







    }
}

void readSymbolData::readSymbolField_SYMB(QString Data){
    //qDebug()<<Data;
    Sym_Symb.m_szMID=Data.mid(9,2);
    Sym_Symb.m_usRCID=(short)atoi(Data.mid(11,5).toLatin1());
    Sym_Symb.m_ucStatus=getSymbolFieldStatus(Data.mid(16,3));
}
ushort readSymbolData::getSymbolFieldStatus(QString S){
    ushort ucStatus = 0; /* variable for storing the status value */
    /* compare symbol status with NIL, ADD, MOD, DEL */
    if(S.contains("NIL")){
        ucStatus = 0;
    }else if(S.contains("ADD")){
        ucStatus = 1;
    }else if(S.contains("MOD")){
        ucStatus = 2;
    }else if(S.contains("DEL")){
        ucStatus = 3;
    }
    return ucStatus;
}

void readSymbolData::readSymbolField_SYMD(QString Data){
    QString szTmp="";

    Symb_Symd.m_szName=Data.mid(7,8);
    Symb_Symd.m_ucType=Data.mid(15,1);

    szTmp=Data.mid(16,5);
    Symb_Symd.m_usPivotX = (short)atoi (szTmp.toLatin1());

    szTmp=Data.mid(21,5);
    Symb_Symd.m_usPivotY = (short)atoi (szTmp.toLatin1());

    szTmp=Data.mid(26,5);
    Symb_Symd.m_usWidth = (short)atoi (szTmp.toLatin1());

    szTmp=Data.mid(31,5);
    Symb_Symd.m_usHeight = (short)atoi (szTmp.toLatin1());

    szTmp=Data.mid(36,5);
    Symb_Symd.m_usULX = (short)atoi (szTmp.toLatin1());

    szTmp=Data.mid(41,5);
    Symb_Symd.m_usULY = (short)atoi (szTmp.toLatin1());
}
void readSymbolData::readSymbolField_SXPO(QString Data){
    Symb_Sxpo.m_pszDscr=Data.mid(7,Data.length());
}

void readSymbolData::readSymbolField_SCRF(QString Data){
    QString D=Data.mid(0,1);
    Symb_Scrf.ucIndx=D.toUShort();
    Symb_Scrf.szColor=Data.mid(1,5);

    //qDebug()<<Data<<"D"<<D<<" ucIndx"<<ucIndx<<" szColor"<<szColor;
}

void readSymbolData::readSymbolField_SVCT(QString Data){
    //qDebug()<<Data;

    QString DataTemp=Data.mid(5,Data.length());
    if (Symb_Symd.m_ucType == 'V'){
        QStringList DList;
        if(DataTemp.size()>0 && DataTemp.contains(";")){
            DList=DataTemp.split(";");
            if(DList.last().contains("")){
                DList.removeLast();
            }
            //qDebug()<<Data<<DList;


            foreach (QString Var, DList) {
                //qDebug()<<Var<<"==="<<Data;
                initializeVectorData(Var);
            }

        }
    }
}





void readSymbolData::readLINEFields(QString Data,QStringList DataList){
    //qDebug()<<DataList;

    foreach (QString Var, DataList) {
        if (Var.contains("LIND")){/* Line Identifier field */
            readSymbol_LIND(Var);
        }else if (Var.contains("LNST")){/* Line definition field */
            readSymbol_LNST(Var);
        }else if (Var.contains("LXPO")){/* Line Exposition Field */
            readSymbol_LXPO(Var);
        }else if (Var.contains("LCRF")){/* Line Colour Reference Field */
            readSymbol_LCRF(Var);
        }else if (Var.contains("LVCT")){/* Line Vector Field */
            readSymbol_LVCT(Var);
        }
    }
}
void readSymbolData::readSymbol_LNST(QString Data){/*Linestyle Identifier field*/
    Sym_Symb.m_szMID=Data.mid(9,2);
    Sym_Symb.m_usRCID=(short)atoi(Data.mid(11,5).toLatin1());
    Sym_Symb.m_ucStatus=getSymbolFieldStatus(Data.mid(16,3));
}

void readSymbolData::readSymbol_LIND(QString Data){/* Linestyle Definition field */
//    strncpy (m_szName, ppszSymb[usIndx]+9, 8);
//    m_szName[8] = '\0';

//    strncpy (szTmp, ppszSymb[usIndx]+17, 5);
//    szTmp[5] = '\0'; m_usPivotX = (short)atoi (szTmp);

//    strncpy (szTmp, ppszSymb[usIndx]+22, 5);
//    szTmp[5] = '\0'; m_usPivotY = (short)atoi (szTmp);

//    strncpy (szTmp, ppszSymb[usIndx]+27, 5);
//    szTmp[5] = '\0'; m_usWidth = (short)atoi (szTmp);

//    strncpy (szTmp, ppszSymb[usIndx]+32, 5);
//    szTmp[5] = '\0'; m_usHeight = (short)atoi (szTmp);

//    strncpy (szTmp, ppszSymb[usIndx]+37, 5);
//    szTmp[5] = '\0'; m_usULX = (short)atoi (szTmp);

//    strncpy (szTmp, ppszSymb[usIndx]+42, 5);
//    szTmp[5] = '\0'; m_usULY = (short)atoi (szTmp);

}

void readSymbolData::readSymbol_LXPO(QString Data){/* Linstyle Exposition field */
//    m_pszDscr = SDBStrdup (ppszSymb[usIndx]+9);
}
void readSymbolData::readSymbol_LCRF(QString Data){/* Linstyle Colour Reference Field */
    //InitColPal (ppszSymb[usIndx] + 9);
}
void readSymbolData::readSymbol_LVCT(QString Data){/* Linstyle Vector Field */
    //InitVectors (ppszSymb[usIndx]);
}


void readSymbolData::initializeVectorData(QString Data){


    stVector pstVect;
    bool bArcFound;


    if(Data.contains("SP")){        /* color of the symbol/Line/Area.*/
        Symb_Scvt.szClr=Data.mid(4,Data.length());
        //24SPA


    }else if(Data.contains("SW")){  /* Width of the line */
        Symb_Scvt.ucLineWidth=Data.mid(2,Data.length()).toUShort();
        //SW1

    }else if(Data.contains("CI")){  /* If the type of vector is a Circle */
        Symb_Scvt.enmType = enmCircle;
        Symb_Scvt.usRadius= atoi (Data.mid(2,Data.length()).toLatin1());
        //CI201



    }else if(Data.contains("PM")){   /* If the vector type is a polygon */
        QString PmVal=Data.mid(2,Data.length());
        //PM2

    }else if(Data.contains("EP")){   /* EP */
        QString PmVal=Data.mid(2,Data.length());
        pstVect.ucType = 0; pstVect.ucFill = 0;

    }else if (Data.contains("FP")){/* FP (Fill the polygon with specified color. */
        pstVect.ucFill = 1;
        //FP
        // If FP is there then FILL Pattern is true for the Polygon

    }else if(Data.contains("ST")){ /* Status ST */
        Symb_Scvt.ucTrans = atoi (Data.mid(2,Data.length()).toLatin1());
        //ST3 or ST0

    }else if(Data.contains("PU")){ /* Pen UP */
        //PenUpPoint
        //"PU1500,1400"
        //"121PU1500,1350"
        QString Temp=Data.mid(2,Data.length());
        QStringList List=Temp.split(",");
        if(List.size()>0){
            Symb_Scvt.PenUpPoint=QPointF(List.at(0).toInt(),List.at(1).toInt());
        }


    }else if (Data.contains("PD")) {   /* Pen Down */
        //"PD1335,1251"
        //"PD1135,1250"
        //"PD675,300,818,300,818,750,809,725,806,706,800,700,778,690,759,684,753,681,734,684,725,684,712,690"
        //"109PD703,703,693,718,681,725,675,740,675,750"

        pstVect.enmType = enmLine; pstVect.ucType = 0;


    }else if (Data.contains("AA")) {   /* Arc Angle */

      pstVect.enmType = enmArc;
      pstVect.ucType   = 1;
      bArcFound = true;
    }else if (Data.contains("SC")) {/* SymbolName, Orientation */

//        pstVect.szEmbdSymbName;
//        pstVect.usOrient;
//        pstVect.enmType=enmEmSymbol;
//        pstVect.ucType = 4;
//        pstVect->usOrient = (UInt8)atoi (ppszSymbolToks [1]);
//        pstVect->enmType = enmEmSymbol;    pstVect->ucType = 4;

//          // Orient to be coded.


        qDebug()<<Data;

    }

    Symb_Scvt.pstVect=pstVect;

}


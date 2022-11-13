#include "ReadOpenCPNSupportFiles.h"

ReadOpenCPNSupportFiles::ReadOpenCPNSupportFiles(QObject *parent) : QObject(parent)
{
    path="./MyResource/Data";

    SymbolsVSupportFileName="S57SymbLib1.dat";
    SymbolsRSupportFileName="S57SymbLib.txt";

    ColorCalibSupportFileName="S57ColCalib.dat";

    plainBoundariesLukupTblFileName="asymrefs.dic";
    symbolisedBoundryLukupTblFileName="asymreft.dic";
    linesLukupTblFileName="lsymrefs.dic";
    SimplifiedLukupTblFileName="psymrefs.dic";
    paperChartLukupTblFileName="psymreft.dic";

    AttributeFileName="S57Attrs.dat";
    ObjectClassFileName="S57Objects.dat";
}

ReadOpenCPNSupportFiles::~ReadOpenCPNSupportFiles()
{

}


void ReadOpenCPNSupportFiles::readOPENCPN_S57Data562_File(){//
    QString filePath="";

    filePath=path+"/OpenCPNData/s57data_5_6_2/S57RAZDS.RLE";

    FileRawData.clear();
    SourceDataList.clear();

    S57CPNSymLib.clear();
    S57CPNColorCalibLib.clear();


    // Open File
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    // Start Reading the File
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        FileRawData.append(line);

        processLineData(line);
    }

//    S57CPNSymLib.writeVDataIntoSupportFile(path+"/MyOutPut/cairstyle/",SymbolsVSupportFileName);
//    S57CPNSymLib.writeRDataIntoSupportFile(path+"/MyOutPut/cairstyle/",SymbolsRSupportFileName);


//    S57CPNLukupTbleLib.writePlainBoundariesData(path+"/MyOutPut/cairstyle/",plainBoundariesLukupTblFileName);
//    S57CPNLukupTbleLib.writeSimplifiedData(path+"/MyOutPut/cairstyle/",SimplifiedLukupTblFileName);
//    S57CPNLukupTbleLib.writelinesData(path+"/MyOutPut/cairstyle/",linesLukupTblFileName);
//    S57CPNLukupTbleLib.writepaperChartData(path+"/MyOutPut/cairstyle/",paperChartLukupTblFileName);
//    S57CPNLukupTbleLib.writesymbolisedBoundaryData(path+"/MyOutPut/cairstyle/",symbolisedBoundryLukupTblFileName);

    //S57CPNColorCalibLib.
}

void ReadOpenCPNSupportFiles::processLineData(QString Data){
    //qDebug()<<Data.size()<<Data;

    if(Data.simplified().contains("****")&&Data.simplified().size()==4){
        // Based on **** Only Split the Data
        if(SourceDataList.size()>0){
            categoriseDataBasedOnCommand(SourceDataList);
        }
        SourceDataList.clear();
    }else if(Data.simplified().contains("0001")&&Data.simplified().size()==4){
        SourceDataList.clear();
    }else{//0001
        SourceDataList.append(Data);
    }

}

void ReadOpenCPNSupportFiles::categoriseDataBasedOnCommand(QStringList DataList){
    if(DataList.size()>1){
        // First Data Contains the Type of data i.e
        // is it Color / Lookup / Symbol
        QString Data=DataList.first();

        if(Data.contains("COLS   ")){
            // Colors Data
            Data=DataList.at(0);
            QString ColorName=Data.mid(19,Data.length());
            ColorName=ColorName.simplified();
            ColorName=ColorName.remove("\u001F");

            S57CPNColorCalibLib.appendColorCalibData(ColorName,DataList);
        }else if(Data.contains("LUPT   ")){
            // Look Up Table Data
            Data=DataList.at(0);
            //Data=Data.simplified();
            Data=Data.remove("\u001F");
            Data=Data.mid(32,Data.length());
            Data=Data.simplified();

            S57CPNLukupTbleLib.appendLookUpTbleData(Data,DataList);

        }else if((Data.contains("SYMB   "))||(Data.contains("PATT   "))||(Data.contains("LNST   "))){
            // Symbols Data
            Data=DataList.at(1);
            QString SymbolName=Data.mid(9,8);

            S57CPNSymLib.appendLibrary(SymbolName,DataList);


        }else {

        }
    }
}


void ReadOpenCPNSupportFiles::readOPENCPN_S57Attributes_File(){//
    QString filePath="";

    filePath=path+"/OpenCPNData/s57data_5_6_2/s57attributes.csv";


    S57Atrr.clearAtrrData();
    // Open File
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    // Start Reading the File
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        line=line.simplified();
        if(!(line.contains("Code,Attribute,Acronym,Attributetype,Class"))){
             if(line.length()>1){

                 S57Atrr.appendAttributeData(line);
             }
        }
    }

    S57Atrr.writeAtrrSupportFile(path+"/MyOutPut/cairstyle/",AttributeFileName);
}

void ReadOpenCPNSupportFiles::readOPENCPN_S57ObjectClass_File(){//
    QString filePath="";

    filePath=path+"/OpenCPNData/s57data_5_6_2/s57objectclasses.csv";

    //1,Administration area (Named),ADMARE,JRSDTN;NATION;NOBJNM;OBJNAM;,INFORM;NINFOM;NTXTDS;PICREP;SCAMAX;SCAMIN;TXTDSC;,RECDAT;RECIND;SORDAT;SORIND;,G,Area;


    S57ObjectClass.clearObjectClassData();
    // Open File
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    // Start Reading the File
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        line=line.simplified();
        if(!(line.contains("Code,ObjectClass"))){
             if(line.length()>1){

                 //qDebug()<<line;
                 S57ObjectClass.appendObjectClassData(line);
             }
        }
    }

    S57ObjectClass.writeObjectClassSupportFile(path+"/MyOutPut/cairstyle/",ObjectClassFileName);
}


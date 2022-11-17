#include "ReadV4S57SupportFiles.h"

ReadV4S57SupportFiles::ReadV4S57SupportFiles(QObject *parent) : QObject(parent)
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

void ReadV4S57SupportFiles::readVersion4_S57Data_File(){

    QString filePath="";

    filePath=path+"/V4Data/V4Data.dai";

    FileRawData.clear();
    SourceDataList.clear();

    //    S57CPNSymLib.clear();
    //    S57CPNColorCalibLib.clear();


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

    S57SymLib.writeVDataIntoSupportFile(path+"/MyOutPut/V4ToV3/cairstyle/",SymbolsVSupportFileName);
    S57SymLib.writeRDataIntoSupportFile(path+"/MyOutPut/V4ToV3/cairstyle/",SymbolsRSupportFileName);


    S57LukupTbleLib.writePlainBoundariesData(path+"/MyOutPut/V4ToV3/cairstyle/",plainBoundariesLukupTblFileName);
    S57LukupTbleLib.writeSimplifiedData(path+"/MyOutPut/V4ToV3/cairstyle/",SimplifiedLukupTblFileName);
    S57LukupTbleLib.writelinesData(path+"/MyOutPut/V4ToV3/cairstyle/",linesLukupTblFileName);
    S57LukupTbleLib.writepaperChartData(path+"/MyOutPut/V4ToV3/cairstyle/",paperChartLukupTblFileName);
    S57LukupTbleLib.writesymbolisedBoundaryData(path+"/MyOutPut/V4ToV3/cairstyle/",symbolisedBoundryLukupTblFileName);

    S57ColorCalibLib.writeDataIntoSupportFile(path+"/MyOutPut/V4ToV3/cairstyle/",ColorCalibSupportFileName);

}

void ReadV4S57SupportFiles::processLineData(QString Data){
    //qDebug()<<Data.size()<<Data;

    if(Data.simplified().contains("****")&&Data.simplified().size()>=4){
        // Based on **** Only Split the Data
        if(SourceDataList.size()>0){
            categoriseDataBasedOnCommand(SourceDataList);
        }
        SourceDataList.clear();
    }else if(Data.simplified().contains("0001")&&Data.simplified().size()>=4){
        SourceDataList.clear();
    }else{//0001
        SourceDataList.append(Data);
    }

}
void ReadV4S57SupportFiles::categoriseDataBasedOnCommand(QStringList DataList){

    if(DataList.size()>1){
        // First Data Contains the Type of data i.e
        // is it Color / Lookup / Symbol
        QString Data=DataList.first();

        if(Data.contains("COLS   ")){
            // Colors Data
            Data=DataList.at(0);
            QString ColorName=Data.mid(19,Data.length());
            //ColorName=ColorName.simplified();
            //ColorName=ColorName.remove("\u001F");
            S57ColorCalibLib.appendColorCalibData(ColorName,DataList);


        }else if(Data.contains("LUPT   ")){
            // Look Up Table Data
            Data=DataList.at(0);
            //Data=Data.simplified();
            Data=Data.remove("\u001F");
            Data=Data.mid(32,Data.length());
            Data=Data.simplified();

            S57LukupTbleLib.appendLookUpTbleData(Data,DataList);

        }else if((Data.contains("SYMB   "))||(Data.contains("PATT   "))||(Data.contains("LNST   "))){
            // Symbols Data
            Data=DataList.at(1);
            QString SymbolName=Data.mid(9,8);

            S57SymLib.appendLibrary(SymbolName,DataList);


        }else {

        }
    }
}

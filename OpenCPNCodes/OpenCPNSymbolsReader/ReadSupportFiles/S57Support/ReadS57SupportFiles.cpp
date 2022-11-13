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



}
void ReadS57SupportFiles::processLineData(QString Data){

    if((Data.contains("/* Symbol description */"))||(Data.contains("static char *ppszSymb[] = {"))){

    }else{
        Data=Data.simplified();
        //qDebug()<<Data;


        if(Data.length()>2){
             List.append(Data);
        }else{
            // \n Found so new Data
            if(List.size()>1){
                QString SymName=List.at(0);
                List.removeFirst();
                SymbolData.insert(SymName,List);
            }

            List.clear();
        }
    }


    //qDebug()<<Data;

}

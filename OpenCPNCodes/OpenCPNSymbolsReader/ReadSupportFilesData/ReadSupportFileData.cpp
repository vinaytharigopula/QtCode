#include "ReadSupportFileData.h"

ReadSupportFileData::ReadSupportFileData(QObject *parent) : QObject(parent)
{
    numOfSpaces="                         ";//25 spaces
}

void ReadSupportFileData::readFileData(){
    QString Path="./MyResource/s57data_5_6_2/S52RAZDS.RLE";
    QFile file(Path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    SourceDataVec.clear();
    SourceData.clear();

    SymbolDataMap.clear();

    PatternDataMap.clear();

    LineDataMap.clear();



    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        processLine(line);
    }


    //    writeSymbolsDataToText("./MyResource/MyOutPut/S52SymLib1.txt");


}
void ReadSupportFileData::processLine(QString Data){
    //    Data=Data.remove(QRegExp("\u001F"));
    //    Data=Data.remove(QRegExp("\n"));

    if(Data.simplified().contains("****")&&Data.simplified().size()==4){
        // Based on **** Only Split the Data
        if(SourceData.size()>0){
            categoriseData(SourceData);

            SourceDataVec.append(SourceData);
        }
        SourceData.clear();
    }else if(Data.simplified().contains("0001")&&Data.simplified().size()==4){
        SourceData.clear();
    }else{//0001
        SourceData.append(Data);
    }



}
void ReadSupportFileData::categoriseData(QStringList List){

    QString Data="";

    if(List.size()>0){
        //qDebug()<<List.size()<<List;
        Data=List.at(0);
        if(Data.contains("COLS   ")){
            // Colors Data
        }else if(Data.contains("LUPT   ")){
            // Look Up Table Data
            categoriseLookUpTableData(List);
        }else if(Data.contains("SYMB   ")){
            // Symbols Data
            categoriseSymbolData(List);
        }else if(Data.contains("PATT   ")){
            // Pattern Data
            categorisePatternData(List);
        }else if(Data.contains("LNST   ")){
            // Line Data
            categoriseLineData(List);
        }else {

        }
    }
}

void ReadSupportFileData::categoriseColorsData(QStringList list){

}
void ReadSupportFileData::categoriseLookUpTableData(QStringList list){
    //qDebug()<<list.size()<<list;

    QString Data="";
    if(list.size()>4){
        Data=list.at(0);
        Data=Data.remove("\u001F");
        QString type=Data.mid(31,Data.length());
        if(type.contains("PLAIN_BOUNDARIES")){//PLAIN_BOUNDARIES or asymrefs.dic
            prepareListFor_PlainBoundaries(list);
        }
    }
}

void ReadSupportFileData::prepareListFor_PlainBoundaries(QStringList list){
    //PLAIN_BOUNDARIES
    QString Data="";
    QString ObjectName="";
    QString SymbolName="";
    QString term1="";//3
    QString term2="";//S

    QString ATTC=""; //SubSymbol
    QString Instrn="";

    QString DispCat="";

    QString LUCM="";

    QString FinalData="";

    QString multicolons;
    multicolons.clear();
    multicolons.append('"');
    multicolons.append(',');
    multicolons.append('"');

    //qDebug()<<"multicolons"<<multicolons<<"->"<<multicolons.simplified();
    //std::cout<<multicolons.toStdString();

    if(list.size()>4){
        Data=list.at(0);
        Data=Data.remove("\u001F");
        ObjectName=Data.mid(19,6);
        SymbolName=Data.mid(32,Data.length());
        term1=Data.mid(30,1);//3
        term2=Data.mid(31,1);//S



        Data=list.at(1);
        Data=Data.remove("\u001F");
        ATTC=Data.mid(9,Data.length());//ATTC    8CATACH8

        Data=list.at(2);
        Data=Data.remove("\u001F");
        Instrn=Data.mid(9,Data.length());//INST   43SY(ACHARE02);LS(DASH,2,CHMGF);CS(RESTRN01)

        Data=list.at(3);
        Data=Data.remove("\u001F");
        DispCat=Data.mid(9,Data.length());//DISC    9STANDARD

        Data=list.at(3);
        Data=Data.remove("\u001F");
        LUCM=Data.mid(9,Data.length());//LUCM    626220

        //"ACHARE","CATACH8","SY(ACHARE02);LS(DASH,2,CHMGF);CS(RESTRN01)","3","S","STANDARD","26220"
        FinalData.clear();
        FinalData.append('"');
        FinalData.append(ObjectName);
        FinalData.append(multicolons);
        FinalData.append(SymbolName);
        FinalData.append(multicolons);
        FinalData.append(Instrn);
        FinalData.append(multicolons);
        FinalData.append(term1);
        FinalData.append(multicolons);
        FinalData.append(term2);
        FinalData.append(multicolons);
        FinalData.append(DispCat);
        FinalData.append(multicolons);
        FinalData.append(LUCM);
        FinalData.append(multicolons);

        //FinalData=FinalData.remove("\\");
        //FinalData=FinalData.remove(QChar('\\'), Qt::CaseInsensitive);

        //qDebug()<<"PB"<<FinalData.length()<<FinalData;
    }
}












void ReadSupportFileData::categoriseSymbolData(QStringList list){
    //qDebug()<<list.size()<<list;
    QString Data,SymbolName="";
    if(list.size()>1){
        Data=list.at(1);
        if(Data.contains("SYMD   ")){
            SymbolName=Data.mid(9,8);
            SymbolDataMap.insert(SymbolName,list);
        }
    }
}

void ReadSupportFileData::categorisePatternData(QStringList list){
    QString Data,PatternName="";
    if(list.size()>1){
        Data=list.at(1);
        if(Data.contains("PATD   ")){
            PatternName=Data.mid(9,8);
            PatternDataMap.insert(PatternName,list);
        }
    }
}
void ReadSupportFileData::categoriseLineData(QStringList list){
    QString Data,LineName="";
    if(list.size()>1){
        Data=list.at(1);
        if(Data.contains("LIND   ")){
            LineName=Data.mid(9,8);
            LineDataMap.insert(LineName,list);
        }
    }
}

void ReadSupportFileData::writeSymbolsDataToText(QString FileName){
    //    bool exists=QDir(FileName).exists();
    //    if(!exists){
    //        QDir().mkdir(FileName);
    //    }

    qDebug()<<"writing Started";

    // Write Symbols Data
    QFile file(FileName);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);

        //SymbolDataMap
        QMapIterator<QString, QStringList> iter1(SymbolDataMap);

        while (iter1.hasNext()) {
            iter1.next();
            //qDebug()<< i.key() << ": " << i.value();

            stream<<QString(numOfSpaces+iter1.key()+".SYM\n");
            foreach(QString Val,iter1.value()){
                Val=Val.remove("\u001F");
                stream<<QString(numOfSpaces+Val);
            }
            stream<<"\n";
        }

        //PatternDataMap
        iter1=(PatternDataMap);
        while (iter1.hasNext()) {
            iter1.next();
            //qDebug()<< i.key() << ": " << i.value();
            stream<<QString(numOfSpaces+iter1.key()+".PAT\n");
            foreach(QString Val,iter1.value()){
                Val=Val.remove("\u001F");
                stream<<QString(numOfSpaces+Val);
            }
            stream<<"\n";
        }

        //LineDataMap
        iter1=(LineDataMap);
        while (iter1.hasNext()) {
            iter1.next();
            //qDebug()<< i.key() << ": " << i.value();
            stream<<QString(numOfSpaces+iter1.key()+".LIN\n");
            foreach(QString Val,iter1.value()){
                Val=Val.remove("\u001F");
                stream<<QString(numOfSpaces+Val);
            }
            stream<<"\n";
        }
    }
    qDebug()<<"writing Ended";

    file.close();
}

#include "V4S57LookUpTableLibrary.h"

V4S57LookUpTableLibrary::V4S57LookUpTableLibrary(QObject *parent) : QObject(parent)
{

}
V4S57LookUpTableLibrary::~V4S57LookUpTableLibrary(){
    clear();
}

void V4S57LookUpTableLibrary::clear(){
    plainBoundariesVec.clear();
    symbolisedBoundryVec.clear();
    linesVec.clear();
    simplifiedVec.clear();
    paperChartVec.clear();
}

QVector<LookupTable> V4S57LookUpTableLibrary::getPlainBoundariesVec(){
    return plainBoundariesVec;
}
QVector<LookupTable> V4S57LookUpTableLibrary::getSymbolisedBoundryVec(){
    return symbolisedBoundryVec;
}
QVector<LookupTable> V4S57LookUpTableLibrary::getLinesVec(){
    return linesVec;
}
QVector<LookupTable> V4S57LookUpTableLibrary::getSimplifiedVec(){
    return simplifiedVec;
}
QVector<LookupTable> V4S57LookUpTableLibrary::getPaperChartVec(){
    return paperChartVec;
}


//QMap<QString,QStringList> SymbolDataMap;
void V4S57LookUpTableLibrary::appendLookUpTbleData(QString Type,QStringList List){
    //qDebug()<<Type<<List;

    QString Data="";

    QString ObjName="";//1.field
    QString AttrCombi="";//2.field
    QString SymInstrn="";//3.field
    QString DispPriority="";//4.field

    QString radar="";
    QString dispCat="";
    QString viewingGrp="";

    LookupTable lukData;

    if(List.size()>4){

        /*********
        * 1. field - code of the object class
        * 2. field - attribute combination
        * 3. field - symbolization instruction
        * 4. field - display priority
        * 5. field - radar
        * 6. field - IMO display category
        * 7. field - viewing group (optional)
        * //"ACHARE","","SY(ACHARE02)","6","O","STANDARD","26220"
        ***********/


        Data=List.at(0);
        if(Data.contains("LUPT   ")){
            //19
            ObjName=Data.mid(19,6);
            ObjName=ObjName.simplified();
            ObjName=ObjName.remove("\u001F");

            radar=Data.mid(30,1);
            radar=radar.simplified();
            radar=radar.remove("\u001F");

            dispCat=Data.mid(31,1);
            dispCat=dispCat.simplified();
            ObjName=ObjName.remove("\u001F");
        }

        Data=List.at(1);
        if(Data.contains("ATTC   ")){//9
            AttrCombi=Data.mid(9,Data.length());
            AttrCombi=AttrCombi.simplified();

            if(!(AttrCombi.length()>1)){
                AttrCombi=AttrCombi.remove("\u001F");
            }

        }

        Data=List.at(2);
        if(Data.contains("INST   ")){
            SymInstrn=Data.mid(9,Data.length());
            SymInstrn=SymInstrn.simplified();
            SymInstrn=SymInstrn.remove("\u001F");
        }

        Data=List.at(3);
        if(Data.contains("DISC   ")){
            DispPriority=Data.mid(9,Data.length());
            DispPriority=DispPriority.simplified();
            DispPriority=DispPriority.remove("\u001F");
        }

        Data=List.at(4);
        if(Data.contains("LUCM   ")){//LUCM
            viewingGrp=Data.mid(9,Data.length());
            viewingGrp=viewingGrp.simplified();
            viewingGrp=viewingGrp.remove("\u001F");
        }

        lukData.setData(ObjName,AttrCombi,SymInstrn,DispPriority,radar,dispCat,viewingGrp);

        //        // based on type of data append data
        if(Type.contains("PLAIN_BOUNDARIES")){
            plainBoundariesVec.append(lukData);
        }else if(Type.contains("SYMBOLIZED_BOUNDARIES")){
            symbolisedBoundryVec.append(lukData);
        }else if(Type.contains("LINES")){
            linesVec.append(lukData);
        }else if(Type.contains("SIMPLIFIED")){
            simplifiedVec.append(lukData);
        }else if(Type.contains("PAPER_CHART")){
            paperChartVec.append(lukData);
        }
        //qDebug()<<Type<<ObjName<<AttrCombi<<SymInstrn<<DispPriority<<radar<<dispCat<<viewingGrp;
    }
}


void V4S57LookUpTableLibrary::writePlainBoundariesData(QString path,QString Name){
    writeLukTblIntoSupportFile(path,Name,plainBoundariesVec);
}
void V4S57LookUpTableLibrary::writesymbolisedBoundaryData(QString path,QString Name){
    writeLukTblIntoSupportFile(path,Name,symbolisedBoundryVec);
}
void V4S57LookUpTableLibrary::writelinesData(QString path,QString Name){
    writeLukTblIntoSupportFile(path,Name,linesVec);
}
void V4S57LookUpTableLibrary::writeSimplifiedData(QString path,QString Name){
    writeLukTblIntoSupportFile(path,Name,simplifiedVec);
}
void V4S57LookUpTableLibrary::writepaperChartData(QString path,QString Name){
    writeLukTblIntoSupportFile(path,Name,paperChartVec);
}
void V4S57LookUpTableLibrary::writeLukTblIntoSupportFile(QString path,QString Name,QVector<LookupTable> DataVec){

    S57LukTblLib.clear();

    //qDebug()<<path<<Name;

    QString Temp="";
    QString Special="\",\"";
    foreach (LookupTable var, DataVec) {
        Temp.clear();
        Temp.append('\"');
        Temp.append(var.ObjName);
        Temp.append(Special);
        Temp.append(var.AttrCombi);
        Temp.append(Special);
        Temp.append(var.SymInstrn);
        Temp.append(Special);
        Temp.append(var.radar);
        Temp.append(Special);
        Temp.append(var.dispCat);
        Temp.append(Special);
        Temp.append(var.DispPriority);
        Temp.append(Special);
        Temp.append(var.viewingGrp);
        Temp.append('\"');
        Temp.append("\n");

        //qDebug()<<Temp;
        S57LukTblLib.append(Temp);

    }
    //ObjName<<AttrCombi<<SymInstrn<<DispPriority<<radar<<dispCat<<viewingGrp

    QFile file(path+Name);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&file);

        foreach (QString var, S57LukTblLib) {
            stream<<var;
        }
    }
    file.close();
}

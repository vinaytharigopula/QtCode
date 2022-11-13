#include "OpenCPNS57SymbolLibrary.h"

OpenCPNS57SymbolLibrary::OpenCPNS57SymbolLibrary(QObject *parent) : QObject(parent)
{
    Space="                           ";//28 spaces
}

OpenCPNS57SymbolLibrary::~OpenCPNS57SymbolLibrary(){
    clear();
}
void OpenCPNS57SymbolLibrary::clear(){
    clearVSymbol();
    clearRSymbol();

    clearVLine();
    clearRLine();

    clearVPattern();
    clearRPattern();

}

void OpenCPNS57SymbolLibrary::appendLibrary(QString SymName,QStringList List){


    if(List.size()>1){
        QString Data=List.at(0);
        if(Data.contains("SYMB   ")){
            appendSymbolData(SymName+".SYM",List);
        }else if(Data.contains("PATT   ")){
            appendPatternData(SymName+".PAT",List);
        }else if(Data.contains("LNST   ")){
            appendLineData(SymName+".LIN",List);
        }
    }
}


/*********
 * Symbol Logic
***********/


void OpenCPNS57SymbolLibrary::appendSymbolData(QString SymName,QStringList List){
    QString type="";

    if(List.size()>1){
        type=List.at(1);
        type=type.mid(17,1);
        if(type.contains("V")){
            appendVSymbolData(SymName,List);
        }else if(type.contains("R")){
            appendRSymbolData(SymName,List);
        }
    }

}
QMap<QString,QStringList> OpenCPNS57SymbolLibrary::getVSymbolDataMap(){
    return SymbolDataMap_V;
}
void OpenCPNS57SymbolLibrary::appendVSymbolData(QString SymName,QStringList List){
    SymbolDataMap_V.insert(SymName,List);
}
void OpenCPNS57SymbolLibrary::clearVSymbol(){
    SymbolDataMap_V.clear();
}


QMap<QString,QStringList> OpenCPNS57SymbolLibrary::getRSymbolDataMap(){
    return SymbolDataMap_R;
}
void OpenCPNS57SymbolLibrary::appendRSymbolData(QString SymName,QStringList List){
    SymbolDataMap_R.insert(SymName,List);
}
void OpenCPNS57SymbolLibrary::clearRSymbol(){
    SymbolDataMap_R.clear();
}
/**********************************/




/*********
 * Pattern Logic
***********/

void OpenCPNS57SymbolLibrary::appendPatternData(QString PatName,QStringList List){
    QString type="";

    if(List.size()>1){
        type=List.at(1);
        type=type.mid(17,1);
        if(type.contains("V")){
            appendVPatternData(PatName,List);
        }else if(type.contains("R")){
            appendRPatternData(PatName,List);
        }
    }
    //    qDebug()<<PatName<<List;
}
QMap<QString,QStringList> OpenCPNS57SymbolLibrary::getVPatternDataMap(){
    return PatternDataMap_V;
}
void OpenCPNS57SymbolLibrary::appendVPatternData(QString PatName,QStringList List){
    PatternDataMap_V.insert(PatName,List);
}
void OpenCPNS57SymbolLibrary::clearVPattern(){
    PatternDataMap_V.clear();
}


QMap<QString,QStringList> OpenCPNS57SymbolLibrary::getRPatternDataMap(){
    return PatternDataMap_R;
}
void OpenCPNS57SymbolLibrary::appendRPatternData(QString PatName,QStringList List){
    PatternDataMap_R.insert(PatName,List);
}
void OpenCPNS57SymbolLibrary::clearRPattern(){
    PatternDataMap_R.clear();
}
/**********************************/


/*********
 * Line Logic
***********/

void OpenCPNS57SymbolLibrary::appendLineData(QString LineName,QStringList List){
//    QString type="";

//    if(List.size()>1){
//        type=List.at(1);
//        type=type.mid(17,1);
//        if(type.contains("V")){
//            appendVLineData(LineName,List);
//        }else if(type.contains("R")){
//            appendRLineData(LineName,List);
//        }
//    }
    appendVLineData(LineName,List);
    //qDebug()<<LineName<<List;
}

QMap<QString,QStringList> OpenCPNS57SymbolLibrary::getVLineDataMap(){
    return LineDataMap_V;
}
void OpenCPNS57SymbolLibrary::appendVLineData(QString LineName, QStringList List){
    LineDataMap_V.insert(LineName,List);
}
void OpenCPNS57SymbolLibrary::clearVLine(){
    LineDataMap_V.clear();
}


QMap<QString,QStringList> OpenCPNS57SymbolLibrary::getRLineDataMap(){
    return LineDataMap_R;
}
void OpenCPNS57SymbolLibrary::appendRLineData(QString LineName, QStringList List){
    LineDataMap_R.insert(LineName,List);
}
void OpenCPNS57SymbolLibrary::clearRLine(){
    LineDataMap_R.clear();
}
/**********************************/





void OpenCPNS57SymbolLibrary::writeVDataIntoSupportFile(QString path,QString Name){
    S57SymbLib.clear();


    QString Data="";

    Data="/* Symbol description */";
    S57SymbLib.append(Data);
    S57SymbLib.append("\n");
    Data="static char *ppszSymb[] = {";
    S57SymbLib.append(Data);
    S57SymbLib.append("\n");



    QString Temp="";

    //qDebug()<<SymbolDataMap_V.size();
    QMapIterator<QString,QStringList> i(SymbolDataMap_V);
    while (i.hasNext()) {
        i.next();

        //qDebug()<<i.key()<<i.value()<<endl;

        S57SymbLib.append(Space+i.key());
        S57SymbLib.append("\n");

        Temp="";
        foreach (QString var, i.value()) {
            var=var.remove("\u001F");
            S57SymbLib.append(Space+var);
            //S57SymbLib.append("\n");

            //qDebug()<<var;
        }
        S57SymbLib.append("\n");
    }


    i=(PatternDataMap_V);
    while (i.hasNext()) {
        i.next();

        //qDebug()<<i.key()<<i.value()<<endl;

        S57SymbLib.append(Space+i.key());
        S57SymbLib.append("\n");

        Temp="";
        foreach (QString var, i.value()) {
            var=var.remove("\u001F");
            S57SymbLib.append(Space+var);
            //S57SymbLib.append("\n");
        }
        S57SymbLib.append("\n");
    }

    i=(LineDataMap_V);
    while (i.hasNext()) {
        i.next();

        //qDebug()<<i.key()<<i.value()<<endl;

        S57SymbLib.append(Space+i.key());
        S57SymbLib.append("\n");

        Temp="";
        foreach (QString var, i.value()) {
            var=var.remove("\u001F");
            S57SymbLib.append(Space+var);
            //S57SymbLib.append("\n");
        }
        S57SymbLib.append("\n");
    }

    S57SymbLib.append(Space+"NULL\n");//};
    S57SymbLib.append(Space.mid(0,24)+"};");


    //qDebug()<<S57SymbLib.size()<<endl;


    //    QDir dir("path/to/dir");
    //    if (!dir.exists())
    //        dir.mkpath(".");

    QFile file(path+Name);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&file);

        foreach (QString var, S57SymbLib) {
            stream<<var;
        }
    }
    file.close();
}
void OpenCPNS57SymbolLibrary::writeRDataIntoSupportFile(QString path,QString Name){

    // Raster file of Line is not updated here.
    S57SymbLib.clear();

    QString Temp="";
    QString Start="START ";
    QMapIterator<QString,QStringList> i(SymbolDataMap_R);
    while (i.hasNext()) {
        i.next();

        //qDebug()<<i.key()<<i.value()<<endl;

        S57SymbLib.append(Start+i.key());
        S57SymbLib.append("\n");

        Temp="";
        foreach (QString var, i.value()) {
            //var=var.remove("\u001F");
            S57SymbLib.append(var);
            //S57SymbLib.append("\n");

            //qDebug()<<var;
        }
        S57SymbLib.append("END\n");
    }


    i=(PatternDataMap_R);
    while (i.hasNext()) {
        i.next();

        //qDebug()<<i.key()<<i.value()<<endl;

        S57SymbLib.append(Start+i.key());
        S57SymbLib.append("\n");

        Temp="";
        foreach (QString var, i.value()) {
            //var=var.remove("\u001F");
            S57SymbLib.append(var);
            //S57SymbLib.append("\n");

            //qDebug()<<var;
        }
        S57SymbLib.append("END\n");
    }


    QFile file(path+Name);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&file);

        foreach (QString var, S57SymbLib) {
            stream<<var;
        }
    }
    file.close();
}

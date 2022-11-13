#include "S57DrawSymbols.h"

S57DrawSymbols::S57DrawSymbols(QObject *parent) : QObject(parent)
{
    Pen1=QPen(Qt::black);
    Pen1.setWidth(1);

    Pen2=QPen(Qt::red);
    Pen2.setWidth(2);

    // example in psymreft if for a object name
    // if instrctuion type =Type
//    QString Type="";
//    if (Type=="SY"){
//        // em Symbol
//    }else if(Type=="LC"){
//        // Complex Line
//    }else if(Type=="LS"){
//        // Simple Line
//    }else if(Type=="TE"){
//        // Text
//    }else if(Type=="TX"){
//        // Text
//    }else if(Type=="AP"){
//        // Pattern
//    }else if(Type=="AC"){
//        // Color
//    }else if(Type=="CS"){
//        // Cond Procedure
//    }

}

void S57DrawSymbols::setSymbolData(QMap<QString,QStringList> Data){
    SymbolData=Data;

    QPolygon poly;

    QMapIterator<QString,QStringList> i(SymbolData);

    //SVCT 30SPA;SW1;PU1108,938;PD1412,938;
    //SVCT 56SPA;SW1;PU1061,1188;PD1167,1292;PD1365,1292;PD1463,1191;

//    while (i.hasNext()) {
//        //i.next();
//        qDebug()<<i.key()<<i.value()<<endl;
//        foreach (QString var, i.value()) {

//        }
//        //break;
//    }

    //SVCT 30SPA;SW1;PU1108,938;PD1412,938;

//    this->showMaximized();
//    update();
}

void S57DrawSymbols::paint(QPaintEvent *event,QPainter *painter)
{

    //SVCT   31SPA;SW1;PU1264,789;PD1264,1291;
    //SVCT   30SPA;SW1;PU1108,938;PD1412,938;
    //SVCT   56SPA;SW1;PU1061,1188;PD1167,1292;PD1365,1292;PD1463,1191;

    double factor=4;
    QPoint pt1,pt2;
    pt1=QPoint(1264/factor,789/factor);
    pt2=QPoint(1264/factor,1291/factor);

    painter->setPen(Pen1);
    painter->drawLine(pt1,pt2);

    pt1=QPoint(1108/factor,938/factor);
    pt2=QPoint(1412/factor,938/factor);

    painter->setPen(Pen1);
    painter->drawLine(pt1,pt2);

    QPolygon Poly;
    Poly<<QPoint(1061/factor,1188/factor);
    Poly<<QPoint(1167/factor,1292/factor);
    Poly<<QPoint(1365/factor,1292/factor);
    Poly<<QPoint(1463/factor,1191/factor);

    painter->setPen(Pen2);
    painter->drawPolygon(Poly);

}

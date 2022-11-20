#include "S57DrawSymbols.h"

S57DrawSymbols::S57DrawSymbols(QObject *parent) : QObject(parent)
{
    Pen1=QPen(Qt::black);
    Pen1.setWidth(1);

    Pen2=QPen(Qt::red);
    Pen2.setWidth(2);

    fscale=5;

    ScreenCoordinates=QPointF(1000,800);
    DiagAOI=QPointF(3000,3000);


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



QPointF S57DrawSymbols::scaleTheCoordinates(QPointF P){
    QPointF ScaledXY=QPoint(0,0);

    ScaledXY.setX((ScreenCoordinates.x()*P.x())/DiagAOI.x());
    ScaledXY.setY((ScreenCoordinates.y()*P.y())/DiagAOI.y());
    if(ScaledXY.x()>ScreenCoordinates.x()){
        ScaledXY.setX(ScreenCoordinates.x());
    }

    if(ScaledXY.y()>ScreenCoordinates.y()){
        ScaledXY.setY(ScreenCoordinates.y());
    }
    return ScaledXY;
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


void S57DrawSymbols::setS57SymbolInstrnDataMap(QMap<QString, SymbolAllData> SymInstrn){

    SymbolInstrnDataMap=SymInstrn;

    //    QMapIterator<QString,SymbolAllData> i(SymbolInstrnDataMap);

    //    SymAllData SymInstrnData;
    //    while (i.hasNext()) {
    //        i.next();

    //        if(i.key().contains("ACHARE02.SYM")){
    //            //processSymbolInstrnData(i.key(),i.value());
    //        }


    //        //        qDebug()<<i.key()<<"***********************";
    //        //        SymInstrnData=i.value();
    //        //        //if(SymInstrnData.SymblDefn.SymbolFullName.contains(".SYM")){


    //        //        qDebug()<<SymInstrnData.printData();
    //        //        qDebug()<<"============================";
    //        //        // }


    //    }
}

void S57DrawSymbols::processSymbolInstrnData(QString Symbol,SymbolAllData SymInstrnData,QPaintEvent *event,QPainter *painter){
    qDebug()<<"Symbol"<<Symbol<<"***********************";
    qDebug()<<SymInstrnData.printData();
    //    qDebug()<<"============================";

    /*******
     * ACHARE02.SYM
     * SYMB   10SY01423NIL
     * SYMD   39ACHARE02V012670105200402005030106100789
     * SXPO   90anchorage area as a point at small scale, or anchor points of mooring trot at large scale
     * SCRF    6ACHMGD
     * SVCT   32SPA;SW1;PU1264,789;PD1264,1291;
     * SVCT   31SPA;SW1;PU1108,938;PD1412,938;
     * SVCT   57SPA;SW1;PU1061,1188;PD1167,1292;PD1365,1292;PD1463,1191;
     *****
     *****/


    SymblIden=SymblInstrnData.SymblIdentify;

    SymblDef=SymblInstrnData.SymblDefn;

    SymblDesc=SymblInstrnData.SymblDesc;

    ClrRefVec=SymblInstrnData.ClrRefVec;

    SymblClrRef=SymblInstrnData.SymblClrRefs;


    //SymblVectrDataVec
    //    SymblVectrDataVec=SymblInstrnData.SymblVectrDataVec;
    //    SymblVctrData=SymblInstrnData.SymblVectrData;

    //    qDebug()<<SymblVectrDataVec.size();

    foreach (SymVectrData VecData, SymInstrnData.SymblVectrDataVec){
        qDebug()<<"VecData.VecType"<<VecData.VecType;
        switch (VecData.VecType) {
        case 0:{//Line
            onDrawLine(VecData,event,painter);
            break;
        }case 1:{// Arc
            onDrawArc(VecData,event,painter);
            break;
        }case 2:{// Circle
            onDrawCircle(VecData,event,painter);
            break;
        }case 3:{//Poly
            onDrawPolygon(VecData,event,painter);
            break;
        }case 4:{//Symbol

            break;
        }

        }
    }

}

void S57DrawSymbols::paint(QPaintEvent *event,QPainter *painter,QString Symbol)
{

    //int key1 = map.key( "Mario" );SymbolInstrnDataMap.key("ACHARE02.SYM");

    // QString Symbol="ACHARE51.SYM";

    qDebug()<<" PAint Show Only Symbol "<<Symbol;
    SymbolAllData VecData = SymbolInstrnDataMap.value(Symbol);
    processSymbolInstrnData(Symbol,VecData,event,painter);

    //    //SVCT   31SPA;SW1;PU1264,789;PD1264,1291;
    //    //SVCT   30SPA;SW1;PU1108,938;PD1412,938;
    //    //SVCT   56SPA;SW1;PU1061,1188;PD1167,1292;PD1365,1292;PD1463,1191;

    //    double factor=4;
    //    QPoint pt1,pt2;
    //    pt1=QPoint(1264/factor,789/factor);
    //    pt2=QPoint(1264/factor,1291/factor);

    //    painter->setPen(Pen1);
    //    painter->drawLine(pt1,pt2);

    //    pt1=QPoint(1108/factor,938/factor);
    //    pt2=QPoint(1412/factor,938/factor);

    //    painter->setPen(Pen1);
    //    painter->drawLine(pt1,pt2);

    //    QPolygon Poly;
    //    Poly<<QPoint(1061/factor,1188/factor);
    //    Poly<<QPoint(1167/factor,1292/factor);
    //    Poly<<QPoint(1365/factor,1292/factor);
    //    Poly<<QPoint(1463/factor,1191/factor);

    //    painter->setPen(Pen2);
    //    painter->drawPolygon(Poly);

}


void S57DrawSymbols::onDrawLine(SymVectrData VecData,QPaintEvent *event,QPainter *painter){
    QPointF StartPoint;
    QPointF EndPoint;

    //    StartPoint.setX(VecData.PenUpPt.x()/fscale);
    //    StartPoint.setY(VecData.PenUpPt.y()/fscale);

//    EndPoint.setX(VecData.PenDownPt.x()/fscale);
//    EndPoint.setY(VecData.PenDownPt.y()/fscale);


    StartPoint=scaleTheCoordinates(VecData.PenUpPt);
    EndPoint=scaleTheCoordinates(VecData.PenDownPt);



    QPen myPen;
    myPen.setWidth(VecData.PenWidth);
    myPen.setColor(Qt::red);
    //later set the value of SymColorReference Color linked with index VecData.VecColorIndex;

    painter->setPen(myPen);

    if(VecData.PenDownPoly.size()>0){
        QPolygonF PolyLine;
        PolyLine.clear();

        foreach(QPointF Pt,VecData.PenDownPoly){
            //PolyLine.append(QPointF(Pt.x()/fscale,Pt.y()/fscale));
            PolyLine.append(scaleTheCoordinates(Pt));

            //scaleTheCoordinates
        }
        if(PolyLine.size()>0){
            //qDebug()<<" PolyLine"<<PolyLine;

            painter->drawLine(StartPoint,PolyLine.at(0));
            painter->drawPolyline(PolyLine);
        }

    }else{
        //qDebug()<<" drawLine"<<StartPoint<<EndPoint;
        painter->drawLine(StartPoint,EndPoint);
    }



}

void S57DrawSymbols::onDrawArc(SymVectrData VecData,QPaintEvent *event,QPainter *painter){
    QPointF StartPoint;
    StartPoint.setX(VecData.PenUpPt.x()/fscale);
    StartPoint.setY(VecData.PenUpPt.y()/fscale);

    QPointF EndPoint;
    EndPoint.setX(VecData.PenDownPt.x()/fscale);
    EndPoint.setY(VecData.PenDownPt.y()/fscale);


    QPen myPen;
    myPen.setWidth(VecData.PenWidth);
    myPen.setColor(Qt::red);
    //later set the value of SymColorReference Color linked with index VecData.VecColorIndex;

    painter->setPen(myPen);


    //painter->drawArc(StartPoint,VecData.radius,VecData.radius);




}

void S57DrawSymbols::onDrawCircle(SymVectrData VecData,QPaintEvent *event,QPainter *painter){
    QPointF StartPoint;
    StartPoint.setX(VecData.PenUpPt.x()/fscale);
    StartPoint.setY(VecData.PenUpPt.y()/fscale);

    QPointF EndPoint;
    EndPoint.setX(VecData.PenDownPt.x()/fscale);
    EndPoint.setY(VecData.PenDownPt.y()/fscale);


    QPen myPen;
    myPen.setWidth(VecData.PenWidth);
    myPen.setColor(Qt::red);
    //later set the value of SymColorReference Color linked with index VecData.VecColorIndex;

    painter->setPen(myPen);


    painter->drawEllipse(StartPoint,VecData.radius,VecData.radius);




}

void S57DrawSymbols::onDrawPolygon(SymVectrData VecData,QPaintEvent *event,QPainter *painter){
    QPointF StartPoint;
    StartPoint.setX(VecData.PenUpPt.x()/fscale);
    StartPoint.setY(VecData.PenUpPt.y()/fscale);

    QPointF EndPoint;
    EndPoint.setX(VecData.PenDownPt.x()/fscale);
    EndPoint.setY(VecData.PenDownPt.y()/fscale);


    QPen myPen;
    myPen.setWidth(VecData.PenWidth);
    myPen.setColor(Qt::red);
    //later set the value of SymColorReference Color linked with index VecData.VecColorIndex;

    painter->setPen(myPen);

    if(VecData.PenDownPoly.size()>0){
        QPolygonF PolyLine;
        PolyLine.clear();

        foreach(QPointF Pt,VecData.PenDownPoly){
            PolyLine.append(QPointF(Pt.x()/fscale,Pt.y()/fscale));
        }
        if(PolyLine.size()>0){
            //qDebug()<<" PolyLine"<<PolyLine;

            painter->drawLine(StartPoint,PolyLine.at(0));
            painter->drawPolygon(PolyLine);
        }

    }else{
        //qDebug()<<" drawLine"<<StartPoint<<EndPoint;
        painter->drawLine(StartPoint,EndPoint);
    }



}

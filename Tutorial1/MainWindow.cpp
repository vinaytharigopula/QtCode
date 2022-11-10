#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    this->showMaximized();
    //    this->setMouseTracking(true);

    //    update();

    QString Path="G:/CAIR/CAIRGISLibs_28-06-2022/CAIRGISLibs_28-06-2022/src/CAIRGIS/MapLegend_Prashanth/Support/S52SymbLib1.dat";

    readTextLineByLine(Path);


}

void MainWindow::readTextLineByLine(QString &path){
    QMap<QString,QStringList> SymbolMap;


    QVector<QStringList> SymbolDetailsVector;
    QStringList extlist;
    extlist<<".LIN"<< ".SYM"<<".PAT";

    SymbolDetailsVector.clear();
    SymbolMap.clear();



    QFile file(path);
    QString line;
    qint64 count=0;
    QStringList SymbolDetails;

    QString ext="";
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line.clear();

            line=QString(stream.readLine()).trimmed();
            if(line.contains("/* Symbol description */")||line.contains("static char *ppszSymb[] = {")){
                continue;
            }

            count++;

            //qDebug()<<count<<line;


            if(line.count()==0){
                ext="";
                //qDebug()<<"Symbol Details Ends===========================";
                //qDebug()<<" Before Ending See the Symbol Data";
                //qDebug()<<SymbolDetails.size()<<SymbolDetails;

                if(SymbolDetails.size()>0){
                    SymbolDetailsVector.append(SymbolDetails);
                    QString SymbolName=SymbolDetails.at(0);
                    SymbolDetails.removeFirst();
                    SymbolMap.insert(SymbolName,SymbolDetails);
                }
                SymbolDetails.clear();

            }else{
                if(line.contains(".LIN")||line.contains(".SYM")||line.contains(".PAT")){
                    //qDebug()<<" Symobls Data Starts here ***************************";
                    SymbolDetails.clear();

                    SymbolDetails.append(line);
                }else{
                    SymbolDetails.append(line);
                }
            }
        }
    }

    file.close();


    SymbolDetails.clear();

    qDebug()<<" Inside List of Container ===========================";

    QStringList DataList;
    DataList.clear();
    QMapIterator<QString, QStringList> iter(SymbolMap);
    while(iter.hasNext()){
        iter.next();

        if(iter.key().contains(".SYM")){
            //qDebug() << iter.key() << " : " << iter.value()<<endl;
            //qDebug()<<iter.key()<<" Reading .SYM ***************";
            //qDebug()<<" Symbol Data :"<<iter.value();
            readSymbolData(iter.value());
        }


    }

    qDebug()<<"//////////////////////////////////////////////////////// ";
}



void MainWindow::Method1(QMap<QString, QStringList> Data){
    /* Iterate through each index and decode the symbol/Line/Area (Image) */

}
void MainWindow::readSymbolData(QStringList DataList){
    QString Temp="";
    QString szTmp="";

    // For SYMB
    QString szMID="";
    ushort usRCID=0;
    ushort ucStatus=0;

    // For SYMD
    QString m_szName="";    /* Name of the symbol. */
    QString m_ucType;  /* Type of Symbol defintion:
                        V - Vector definition,
                        R - Raster definition. */

    ushort m_usPivotX,  /* Pivot point column no. */
            m_usPivotY,  /* Pivot point row no */
            m_usWidth,   /* Width of the bounding box. */
            m_usHeight,  /* Height of the bounding box. */
            m_usULX,     /* Upper Left Column No. */
            m_usULY,     /* Upper Left Row No. */
            m_usMinDist, /* Min dist b/w pattern symbols */
            m_usMaxDist; /* Max dist b/w pattern symbols */

    QString m_pszDscr;  /* Description of the symbol. */



    foreach (QString Data, DataList) {

        if (Data.contains("SYMB")){/* Symbol Identifier field */
            szMID=Data.mid(9,2);
            szTmp=Data.mid(11,5);
            usRCID=(short)atoi(szTmp.toLatin1());
            Temp=Data.mid(16,3);
            ucStatus=getSymbolStatus(Temp);

            //qDebug()<<"szMID"<<szMID<<"szTmp"<<szTmp<<"usRCID"<<usRCID<<"Temp"<<Temp<<"ucStatus"<<ucStatus;
        }else if (Data.contains("SYMD")){/* Symbol definition field */
            m_szName=Data.mid(9,8);
            m_ucType=Data.mid(17,1);
            szTmp=Data.mid(18,5);
            m_usPivotX = (short)atoi (szTmp.toLatin1());

            szTmp=Data.mid(23,5);
            m_usPivotY = (short)atoi (szTmp.toLatin1());

            szTmp=Data.mid(28,5);
            m_usWidth = (short)atoi (szTmp.toLatin1());

            szTmp=Data.mid(33,5);
            m_usHeight = (short)atoi (szTmp.toLatin1());

            szTmp=Data.mid(38,5);
            m_usULX = (short)atoi (szTmp.toLatin1());

            szTmp=Data.mid(43,5);
            m_usULY = (short)atoi (szTmp.toLatin1());

            //            qDebug()<<" ++++++++++++++ "<<Data;
            //            qDebug()<<"m_szName"<<m_szName<<"m_ucType"<<m_ucType<<"szTmp"<<szTmp;
            //            qDebug()<<"m_usPivotX"<<m_usPivotX<<"m_usPivotY"<<m_usPivotY<<"m_usWidth";
            //            qDebug()<<m_usWidth<<"m_usHeight"<<m_usHeight<<"m_usULX"<<m_usULX<<"m_usULY"<<m_usULY;

        }

        else if (Data.contains("SXPO")){/* Symbol Exposition Field */
            m_pszDscr = Data.mid(9,Data.length());

            //            qDebug()<<Data<<" ============== ";
            //            qDebug()<<m_pszDscr.size()<<m_pszDscr;

        }else if (Data.contains("SCRF")){/* Symbol Colour Reference Field */
            //qDebug()<<Data<<" ============== ";
            InitColPal(Data.mid(9,Data.length()));
        }else if (Data.contains("SVCT")){/* Symbol Vector Field */
            //qDebug()<<Data;
            if (m_ucType == 'V'){
                InitVector(Data);
            }
        }
        //39SPD;SW1;PU1500,1300;PD;PU1700,1500;PD;

    }
}

void MainWindow::readLineData(QStringList DataList){

    foreach (QString Data, DataList) {
        if (Data.contains("LNST")) {/*Linestyle Identifier field*/

        }else if(Data.contains("LIND")){/* Linestyle Definition field */

        }else if(Data.contains("LXPO")){/* Linstyle Exposition field */

        }else if(Data.contains("LCRF")){/* Linstyle Colour Reference Field */

        }else if(Data.contains("LVCT")){/* Linstyle Vector Field */

        }
    }
}

void MainWindow::readPatternData(QStringList DataList){

    foreach (QString Data, DataList) {
        if (Data.contains("PATT")) {/*Pattern Identifier field */

        }else if (Data.contains("PATD")) {/* Pattern Definition Field */

        }else if (Data.contains("PXPO")){/* Pattern Exposition field */

        }else if (Data.contains("PCRF")){/* Pattern Colour Reference Field */

        }else if (Data.contains("PBTM")){/* Pattern Bitmap field */

        }else if (Data.contains("PVCT")){/* Pattern Vector Field */

        }
    }
}



ushort MainWindow::getSymbolStatus(QString &S){
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

void MainWindow::InitColPal(QString Data){

    // this method needs correction for index
    //qDebug()<<" Init ColPal"<<Data;
    //    m_pstColRef = (stColRef*) SDBRealloc (m_pstColRef,
    //                               sizeof (stColRef) * (m_ucColRef+1));
    //    /* */
    //    m_pstColRef[m_ucColRef].ucIndx = pcchrPalInfo[0];
    //    strncpy (m_pstColRef[m_ucColRef].szColor,
    //                                pcchrPalInfo + 1, 5);
    //    m_pstColRef[m_ucColRef].szColor[5] = '\0';
    //    m_ucColRef++;
    //    pcchrPalInfo = pcchrPalInfo + 6;

    QString D=Data.mid(0,1);
    ushort ucIndx=D.toUShort();
    QString szColor=Data.mid(1,5);

    //qDebug()<<"D"<<D<<" ucIndx"<<ucIndx<<" szColor"<<szColor;


}

void MainWindow::InitVector(QString Data){

    //    QString pszToken="";/* temp variable for storing the Symbol/Line/Area. */
    //    QStringList ppszTokens;/* variable for storing all the instructions. */


    //    QString szClr="";/* holds the color */


    //    QString ucCnt="",/* holds the no of tokens */
    //            ucTok="",/* iterator */
    //            ucClr="";/* index of the color*/

    //    QString ucLineWidth = 0, /* holds the width of the line */
    //            ucTrans = 0;  /* holds the transparency */

    //    QStringList ppszPoints;/* holds the points in the instruction */

    //    uint usPnts = 0, /* No. of points */
    //           usIndx = 0; /* iterator */


    //    bool bArcFound = false; /* variable for checking the presence of arc */

    //    stVector* pstVect = NULL; /* Pointer object of the structure holding
    //                                 the vectors */

    Data = Data.simplified(); // For Removing the Extra spaces
    QString DataTemp=Data.mid(5,Data.length());


    //qDebug()<<"InitVector";
//    qDebug()<<"Data:"<<Data;


    QStringList DList;
    if(DataTemp.size()>0 && DataTemp.contains(";")){
        DList=DataTemp.split(";");
        if(DList.last().contains("")){
            DList.removeLast();
            QString Temp="";
            ushort LineWidth=0;
            foreach (QString var, DList) {
                Temp=var;

                if (var.contains("SP")){/* color of the symbol/Line/Area.*/


                }else if(var.contains("SW")){/* Width of the line */
                    Temp=var.remove("SW");
                    LineWidth=Temp.toUShort();

                }else if(var.contains("CI")){/* If the type of vector is a Circle */



                }else if (var.contains("PM")){/* If the vector type is a polygon */
                    //qDebug()<<Temp;
                    Temp=var.remove("PM");
                    //ucTy=Temp.toUShort();

                }else if (var.contains("EP")){/* EP */
                    ushort ucType = 0;
                    ushort ucFill = 0;

                }else if (var.contains("FP")){/* FP (Fill the polygon with specified color. */
                     ushort ucFill = 1;

                }else if (var.contains("ST")){/* Status ST */
                    //qDebug()<<Temp;
                    Temp=var.remove("PM");
                    ushort ucTrans = Temp.toUShort();

                }else if (var.contains("PU")){/* Pen UP */
                    //qDebug()<<Temp;
                    Temp=var.remove("PU");
                    QPointF Pt;
                    if(Temp.contains(",")){
                        QStringList Lst;
                        Lst=Temp.split(",");
                        if(Lst.size()>0){
                            Pt=QPointF(Lst.at(0).toFloat(),Lst.at(1).toFloat());
                        }
                    }
                    //qDebug()<<"PU"<<" Data"<<Pt;


                }else if (var.contains("PD")){/* Pen Down */

                }else if (var.contains("AA")){/* Arc Angle */

                }else if (var.contains("SC")){/* SymbolName, Orientation */

                }
            }
        }
//        qDebug()<<"DList:"<<DList;
    }


    ////    { GetColor (pszToken[2], szClr); continue; }



    //    /* If the type of vector is a Circle */
    //    else if (SDBEqualn (pszToken, "CI", 2)) {


    //      if (pstVect == NULL && m_ppstVector)
    //        { pstVect = m_ppstVector [m_usVectors-1]; }

    //      pstVect->enmType = enmCircle;
    //      pstVect->ucType = 2;
    //      pstVect->usRadius = atoi (pszToken+2);
    //    continue;
    //    }




}


void MainWindow::pan(const QPoint &delta)
{
    offset += delta;
    update();
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //    if (event->buttons()!= Qt::LeftButton) return;

    //    pressed = snapped = true;
    //    pressPos = dragPos = event->pos();

    update();
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    pos=event->pos();
    qDebug()<<" mouse move event "<<pos;
    update();

}

void MainWindow::paintEvent(QPaintEvent*) {
    //    QPainter painter(this);

    //    // Load your SVG
    //    //QSvgRenderer renderer(QString("C:/Users/vinay/OneDrive/Documents/GitHub/Qt/Cpp/Resources/SVGFIles/india.svg"));
    //    QSvgRenderer renderer(QString("C:/Users/vinay/OneDrive/Documents/GitHub/Qt/Cpp/Resources/SVGFIles/world.svg"));

    //    // Prepare a QImage with desired characteritisc
    //    QImage image(1920, 1080, QImage::Format_ARGB32);
    //    image.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    //    //image.fill(0xaaA08080);  // partly transparent red-ish background

    //    painter.drawImage(this->rect(),image);

    //    //painter.scale(scale,scale);

    //    renderer.render(&painter);


    //    // night mode
    //    if(true)
    //    {

    //            painter.setClipping(true);


    //            //qDebug()<<" Video Widget "<<light;

    //            int diameterx = 100;
    //            int diametery = 100;

    //            QRegion screen(QRect(0, 0, width(), height()));
    //            QRegion ellipse(QRect(pos.x() - diameterx, pos.y() - diametery, diameterx * 2, diametery * 2), QRegion::Ellipse);

    //            // FOr Night Vision
    //            //if(Engine::trainSetting.GreenLight){
    //            painter.fillRect(QRect(pos.x() - diameterx, pos.y() - diametery, diameterx * 2, diametery * 2), QColor(153, 255,153, 138));
    //            //}

    //            QRegion mask = screen.subtracted(ellipse);
    //            painter.setClipRegion(mask);



    //        //painter.fillRect(QRect(0, 0, width(), height()), QColor(0, 0, 0));

    //        painter.setClipping(false);
    //        update();
    //    }





}
void MainWindow::wheelEvent ( QWheelEvent * event ){

    //    double delta =event->delta();


    ////    scale+=(event->delta()/120); //or use any other step for zooming


    //    scale =scale +1.0f;
    //    event->accept();

    //    //update();
    //    qDebug()<<scale;

}
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    zoomed = false;
    update();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    zoomed = false;
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!zoomed)
    {
        if (event->key() == Qt::Key_Left)  offset += QPoint(20 ,   0);
        if (event->key() == Qt::Key_Right) offset += QPoint(-20,   0);
        if (event->key() == Qt::Key_Up)    offset += QPoint(0  ,  20);
        if (event->key() == Qt::Key_Down)  offset += QPoint(0  , -20);
        if (event->key() == Qt::Key_Z || event->key() == Qt::Key_Select)
        {
            dragPos = QPoint(width()/2, height()/2);
            // activateZoom();
        }
        update();
    }
    else
    {
        if (event->key() == Qt::Key_Z || event->key() == Qt::Key_Select)
        {
            zoomed = false;
            update();
        }
        QPoint delta(0,0);
        if (event->key() == Qt::Key_Left)  delta += QPoint(-15,   0);
        if (event->key() == Qt::Key_Right) delta += QPoint(15 ,   0);
        if (event->key() == Qt::Key_Up)    delta += QPoint(0  , -15);
        if (event->key() == Qt::Key_Down)  delta += QPoint(0  ,  15);
        if (delta != QPoint(0, 0))
        {
            dragPos += delta;
            update();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

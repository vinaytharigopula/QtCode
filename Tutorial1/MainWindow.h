#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QExposeEvent>
#include <QEvent>
#include <QDebug>

#include <QApplication>
#include <QSvgRenderer>
#include <QPainter>
#include <QImage>
#include <QPainter>
#include <QWheelEvent>
#include <QBasicTimer>
#include <QImage>
#include <QPixmap>
#include <QPoint>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QHoverEvent>


#include "readSymbolData.h"


/* Enumerator to identity element type to be drawn,
   in S-52 presentation library. */
typedef enum enms52vectype {

    enmLine = 0,
    enmArc,
    enmCircle,
    enmPolygon,
    enmEmSymbol,

}enmS52VecType;
/* structure representing the vector information.*/
typedef struct stvector {

    QString    szColor;         /* Colour of the pen */
    ushort     ucLineWidth;     /* Line width (should be > 0) */
    ushort     ucFill;          /* Fill > 0 - Not filled , 1 - Filled       */
    ushort     ucType;          /* 0-Line , 1 - Arc , 2 - Polygon */

    enmS52VecType enmType;      /* type of the vector (Line, circle, polygon) */

    QPointF    pstPnts;         /* coordinates of the vector */
    ushort     usXPnts,         /* No of vertices of the vector */
               usRadius;        /* Radius of the vector (for eType = eCircle only) */
    ushort     ucTransparency;  /* Level of transparency */
    ushort     usArcAngle;      /* Arc angle - (for eType = eArc only) */
    QString    szEmbdSymbName;  /* used for line only */
    ushort     usOrient,        /* used for line only */
               usPatTyp;        /* used for pattern only */
}stVector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow()Q_DECL_OVERRIDE;

protected:
    //bool event(QEvent *event) Q_DECL_OVERRIDE;
    //void exposeEvent(QExposeEvent *event) ;

    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *)override;
    void resizeEvent(QResizeEvent *)override;


    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;


private slots:


    void pan(const QPoint &delta);
    void readTextLineByLine(QString &path);
    void Method1(QMap<QString,QStringList> Data);

    void readSymbolData(QStringList DataList);
    void readLineData(QStringList DataList);
    void readPatternData(QStringList DataList);
    ushort getSymbolStatus(QString &S);
    void InitColPal(QString Data);
    void InitVector(QString Data);
private:
    Ui::MainWindow *ui;
    qreal scale;

    QPoint pos;
    QImage image;
    QPixmap smallPixmap;
    QPixmap largePixmap;
    QPixmap zoomPixmap;
    QPixmap maskPixmap;
    bool pressed;
    bool snapped;
    bool zoomed;
    QPoint offset;
    QPoint pressPos;
    QPoint dragPos;


};

#endif // MAINWINDOW_H

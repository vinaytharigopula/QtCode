#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();
    this->setMouseTracking(true);

    update();

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
    QPainter painter(this);

    // Load your SVG
    //QSvgRenderer renderer(QString("C:/Users/vinay/OneDrive/Documents/GitHub/Qt/Cpp/Resources/SVGFIles/india.svg"));
    QSvgRenderer renderer(QString("C:/Users/vinay/OneDrive/Documents/GitHub/Qt/Cpp/Resources/SVGFIles/world.svg"));

    // Prepare a QImage with desired characteritisc
    QImage image(1920, 1080, QImage::Format_ARGB32);
    image.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    //image.fill(0xaaA08080);  // partly transparent red-ish background

    painter.drawImage(this->rect(),image);

    //painter.scale(scale,scale);

    renderer.render(&painter);


    // night mode
    if(true)
    {

            painter.setClipping(true);


            //qDebug()<<" Video Widget "<<light;

            int diameterx = 100;
            int diametery = 100;

            QRegion screen(QRect(0, 0, width(), height()));
            QRegion ellipse(QRect(pos.x() - diameterx, pos.y() - diametery, diameterx * 2, diametery * 2), QRegion::Ellipse);

            // FOr Night Vision
            //if(Engine::trainSetting.GreenLight){
            painter.fillRect(QRect(pos.x() - diameterx, pos.y() - diametery, diameterx * 2, diametery * 2), QColor(153, 255,153, 138));
            //}

            QRegion mask = screen.subtracted(ellipse);
            painter.setClipRegion(mask);



        //painter.fillRect(QRect(0, 0, width(), height()), QColor(0, 0, 0));

        painter.setClipping(false);
        update();
    }





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

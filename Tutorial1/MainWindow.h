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

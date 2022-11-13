#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ReadSupportFiles/OpenCPN/ReadOpenCPNSupportFiles.h"

#include "ReadSupportFiles/S57Support/ReadS57SupportFiles.h"
#include "DrawLogic/DrawSymbols/S57DrawSymbols.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::MainWindow *ui;

    ReadOpenCPNSupportFiles readCPNfile;

    ReadS57SupportFiles s57files;
    S57DrawSymbols *drwSymb;

};
#endif // MAINWINDOW_H

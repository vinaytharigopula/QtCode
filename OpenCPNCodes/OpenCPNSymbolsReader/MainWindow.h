#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QListWidget>

#include "ReadSupportFiles/OpenCPN/ReadOpenCPNSupportFiles.h"

#include "ReadSupportFiles/S57Support/ReadS57SupportFiles.h"
#include "DrawLogic/DrawSymbols/S57DrawSymbols.h"

#include "ReadSupportFiles/V4S57SupportFiles/ReadV4S57SupportFiles.h"

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
    void showListOfSymbolsInList();
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;

    ReadOpenCPNSupportFiles readCPNfile;

    ReadS57SupportFiles s57files;

    ReadV4S57SupportFiles v4files;
    S57DrawSymbols *drwSymb;

    QMap<QString, SymbolAllData> S57InstrnData;

    QString CurrentSelection;

};
#endif // MAINWINDOW_H

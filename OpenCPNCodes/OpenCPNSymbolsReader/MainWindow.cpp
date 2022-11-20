#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
    ui->listWidget->setSelectionMode( QAbstractItemView::SingleSelection );

    /* reading & writing logic for S57 OPENCPN Data*/
    //    readCPNfile.readOPENCPN_S57Data562_File();
    //    readCPNfile.readOPENCPN_S57Attributes_File();
    //    readCPNfile.readOPENCPN_S57ObjectClass_File();

    /* reading & writing logic for S57 Version 4 IHO 4.0.3 Data*/
    //v4files.readVersion4_S57Data_File();


    s57files.readS57SymbolsFile();

    S57InstrnData=s57files.getS57InstructionData();
    showListOfSymbolsInList();



    //drwSymb
    drwSymb= new S57DrawSymbols();
    drwSymb->setS57SymbolInstrnDataMap(S57InstrnData);

    //    this->update();
    //    this->repaint();
    //drwSymb->setSymbolData(s57files.getS57Symbols());

    //Widget *native = new Widget(&helper, this);
    // S57DrawSymbols *native = new S57DrawSymbols(this);

    //drwSymb->d


}
void MainWindow::showListOfSymbolsInList(){
    // Make data

    ui->listWidget->clear();

    QMapIterator<QString,SymbolAllData> i(S57InstrnData);

    SymAllData SymInstrnData;
    while (i.hasNext()) {
        i.next();

        ui->listWidget->addItem(i.key());
        //        qDebug()<<i.key()<<"***********************";
        //        SymInstrnData=i.value();
        //        //if(SymInstrnData.SymblDefn.SymbolFullName.contains(".SYM")){


        //        qDebug()<<SymInstrnData.printData();
        //        qDebug()<<"============================";
        //        // }
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    drwSymb->paint(event,&painter,CurrentSelection);
    painter.end();

}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item){

    ui->listWidget->setStyleSheet("QListView::item:selected{background-color: rgb(173,202,230);}");

    CurrentSelection=item->text();
    qDebug()<<" Clicked On "<<CurrentSelection;


    this->update();

    ui->statusbar->showMessage("CurrentSelection:"+CurrentSelection);
}


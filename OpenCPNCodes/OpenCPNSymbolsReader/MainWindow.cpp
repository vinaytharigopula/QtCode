#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //    readCPNfile.readOPENCPN_S57Data562_File();
    //    readCPNfile.readOPENCPN_S57Attributes_File();
    //    readCPNfile.readOPENCPN_S57ObjectClass_File();

    s57files.readS57SymbolsFile();

    v4files.readVersion4_S57Data_File();

    //drwSymb
    drwSymb= new S57DrawSymbols(this);
    //drwSymb->setSymbolData(s57files.getS57Symbols());

    //Widget *native = new Widget(&helper, this);
    // S57DrawSymbols *native = new S57DrawSymbols(this);

    //drwSymb->d


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
    drwSymb->paint(event,&painter);
    painter.end();

}


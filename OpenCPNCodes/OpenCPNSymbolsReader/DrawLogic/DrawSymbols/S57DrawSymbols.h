#ifndef S57DRAWSYMBOLS_H
#define S57DRAWSYMBOLS_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QDebug>
#include <QVector>
#include <QStringList>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <iostream>
#include <QList>
#include <QPolygon>
#include <QPaintEvent>
#include <QPainter>

class S57DrawSymbols : public QObject
{
    Q_OBJECT
public:
    explicit S57DrawSymbols(QObject *parent = nullptr);

public slots:
    void setSymbolData(QMap<QString,QStringList> Data);
    void paint(QPaintEvent *event, QPainter *painter);
signals:

protected:
 //   void paintEvent(QPaintEvent *event) override;
private:
     QMap<QString,QStringList> SymbolData;

     QPen Pen1;
     QPen Pen2;
};

#endif // S57DRAWSYMBOLS_H

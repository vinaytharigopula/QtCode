#ifndef READSYMBOLDATA_H
#define READSYMBOLDATA_H

#include <QObject>

class readSymbolData : public QObject
{
    Q_OBJECT
public:
    explicit readSymbolData(QObject *parent = nullptr);

public slots:
    void readSymbolTextData();
signals:

};

#endif // READSYMBOLDATA_H

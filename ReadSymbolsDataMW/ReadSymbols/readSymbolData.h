#ifndef READSYMBOLDATA_H
#define READSYMBOLDATA_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QDebug>
#include <QPolygonF>



typedef enum enms52vectype {
    enmLine = 0,
    enmArc,
    enmCircle,
    enmPolygon,
    enmEmSymbol,

}enmS52VecType;

/* structure representing the vector information.*/
typedef struct stVector {

  QString       szColor;   /* Colour of the pen */
  ushort        ucLineWidth;   /* Line width (should be > 0) */
  ushort        ucFill;	      /* Fill > 0 - Not filled
                                      1 - Filled       */
  ushort        ucType;        /* 0-Line , 1 - Arc , 2 - Polygon */

  enmS52VecType enmType;         /* type of the vector (Line, circle, polygon) */

  QPolygonF     PntsList;       /* coordinates of the vector */
  ushort        PntsSize;       /* No of vertices of the vector */
  ushort        usRadius;       /* Radius of the vector (for eType = eCircle only) */
  ushort        ucTransparency; /* Level of transparency */
  ushort        usArcAngle;     /* Arc angle - (for eType = eArc only) */
  QString       szEmbdSymbName;  /* used for line only */
  ushort        usOrient,         /* used for line only */
                usPatTyp;         /* used for pattern only */
}stvector;


/* Symbol Identifier Field. */
typedef struct SymbolIdentifierField_SYMB {
    QString m_szMID; /* Module Identifier */

    ushort m_usRCID;  /* Record Identifier */

    ushort m_ucStatus; /* Status of the module contents:
                         NIL - No change,
                         ADD - New Addition,
                         MOD - Modify,
                         DEL - Delete. */

}Symbol_Symb;


/* Symbol definition Field */
typedef struct SymbolDefinitionField_SYMD {
   QString m_szName,  /* Name of the symbol. */
        m_szPatFill, /* Type of Fill Pattern */
        m_szPatSpac; /* Pattern Symbol Spacing */

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
}Symbol_Symd;


/* Symbol Exposition Field */
typedef struct SymbolExpositionField_SXPO {
    QString m_pszDscr; /* Description of the symbol. */
}Symbol_Sxpo;


/* Symbol Colour Reference Field */
typedef struct SymbolColourReferenceField_SCRF {
    ushort ucIndx;      /* Index for each color. */
    QString szColor;    /* Colour Code */
}Symbol_Scrf;


/* Symbol Exposition Field */
typedef struct SymbolExpositionField_SVCT {
    QString szClr="";       /* holds the color */
    ushort ucLineWidth=0,   /* holds the width of the line */
            ucTrans=0;      /* holds the transparency */

    enmS52VecType enmType;  /* type of the vector (Line, circle, polygon) */
    ushort usRadius;        /* Radius of the vector (for eType = eCircle only) */
    stvector pstVect;
    bool bArcFound;
    QPointF PenUpPoint;
}Symbol_Scvt;






class readSymbolData : public QObject
{
    Q_OBJECT
public:
    explicit readSymbolData(QObject *parent = nullptr);
    ~readSymbolData();
public slots:
    void readSymbolsTextFile();
signals:

private slots:


    void loadSymbols(QString Data);
    void processSymbolsData();

    void readSymbolFields(QString Data, QStringList DataList);
    void readSymbolField_SYMB(QString Data);
    ushort getSymbolFieldStatus(QString S);
    void readSymbolField_SYMD(QString Data);
    void readSymbolField_SXPO(QString Data);
    void readSymbolField_SCRF(QString Data);
    void readSymbolField_SVCT(QString Data);

    void readLINEFields(QString Data, QStringList DataList);
    void readSymbol_LIND(QString Data);
    void readSymbol_LNST(QString Data);
    void readSymbol_LXPO(QString Data);
    void readSymbol_LCRF(QString Data);
    void readSymbol_LVCT(QString Data);

    void initializeVectorData(QString Data);

private:
    QMap<QString,QStringList> SymbolMap;
    QStringList SymbolDataList;
    QString SymbolData;


    /* Symbol Identifier Field. */
    Symbol_Symb Sym_Symb;

    /* Symbol definition Field */
    Symbol_Symd Symb_Symd;

    /* Symbol Exposition Field */
    Symbol_Sxpo Symb_Sxpo;

    /* Symbol Colour Reference Field */
    Symbol_Scrf Symb_Scrf;

    /* Symbol Vector Field */
    Symbol_Scvt Symb_Scvt;


   //stVector
   stVector pstVect;

};

#endif // READSYMBOLDATA_H

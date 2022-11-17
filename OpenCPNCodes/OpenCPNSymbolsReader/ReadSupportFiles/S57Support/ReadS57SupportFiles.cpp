#include "ReadS57SupportFiles.h"

ReadS57SupportFiles::ReadS57SupportFiles(QObject *parent) : QObject(parent)
{
    path="./MyResource/Data/MyOutPut/cairstyle";
}
QMap<QString,QStringList> ReadS57SupportFiles::getS57Symbols(){
    return SymbolData;
}


void ReadS57SupportFiles::readS57SymbolsFile(){
    List.clear();
    SymbolData.clear();

    QString filePath="";

    filePath=path+"/S52SymbLib1.dat";


    // Open File
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // Start Reading the File
    while (!file.atEnd()) {
        QString line = file.readLine();

        processLineData(line);
    }



}
void ReadS57SupportFiles::processLineData(QString Data){

    if((Data.contains("/* Symbol description */"))||(Data.contains("static char *ppszSymb[] = {"))){

    }else{
        Data=Data.trimmed();
        //qDebug()<<Data;


        if(Data.length()>2){
            List.append(Data);
        }else{
            // \n Found so new Data
            if(List.size()>1){
                QString SymName=List.at(0);

                List.removeFirst();
                SymbolData.insert(SymName,List);

                initialiseData(SymName,List);
            }

            List.clear();
        }
    }


    //qDebug()<<Data;

}


void ReadS57SupportFiles::initialiseData(QString Sym,QStringList lst){

    QString Temp="";

    foreach (QString Data, lst) {
        // Symbol Identification
        if(Data.contains("SYMB")){
            Data=Data.simplified();
            Iden.MIdentifier=Data.mid(9,2);
            Iden.RecordId=Data.midRef(11,5).toInt();
            Temp=Data.mid(16,3);
            if(Temp.contains("NIL")){
                Iden.status=0;
            }else if(Temp.contains("ADD")){
                Iden.status=1;
            }else if(Temp.contains("MOD")){
                Iden.status=1;
            }else if(Temp.contains("DEL")){
                Iden.status=2;
            }
            //qDebug()<<Data<<Sym<<MIdentifier<<RecordId<<Temp<<status;
        }


        // Symbol Defination
        if(Data.contains("SYMD")){
            Data=Data.simplified();
            //qDebug()<<Sym<<Data;

            Def.SymbolName=Data.mid(9,8);
            Def.DataType=Data.mid(17,1);
            Temp=Data.mid(18,5);
            Def.PivotX=Temp.toUShort();
            Temp=Data.mid(23,5);
            Def.PivotY=Temp.toUShort();
            Temp=Data.mid(28,5);
            Def.Width=Temp.toUShort();
            Temp=Data.mid(33,5);
            Def.Height=Temp.toUShort();
            Temp=Data.mid(39,5);
            Def.ULeftC=Temp.toUShort();
            Temp=Data.mid(43,5);
            Def.ULeftR=Temp.toUShort();

            //qDebug()<<SymbolName<<DataType<<PivotX<<PivotY<<Width<<Height<<ULeftC<<ULeftR;

        }

        // Symbol Exposition
        if(Data.contains("SXPO")){
            Data=Data.simplified();
            //qDebug()<<Sym<<Data;
            Desc.SymbolDesc=Data.mid(9,Data.length());
            //qDebug()<<SymbDesc;

        }


        // Symbol Colour Reference
        if(Data.contains("SCRF")){
            Data=Data.simplified();
            ClrRef.Color=Data.mid(9,Data.length());
            //ColorIndex
            //qDebug()<<Sym<<Data<<Color;
        }

        if(Data.contains("SVCT")){
            //Data=Data.simplified();

            QString MainData=Data.mid(9,Data.length());
            QString ColorData="";
            int8_t PenWidth=1;
            int radius=0;

            QStringList DList=MainData.split(";");

            //"SVCT   31SPA;SW1;PU1264,789;PD1264,1291;"
            foreach (QString var, DList) {
                if(var.contains("SP")){/* color of the symbol/Line/Area.*/

                }
                if(var.contains("SW")){/* Width of the line */

                }
                if(var.contains("CI")){/* If the type of vector is a Circle */

                }
                if(var.contains("PM")){ /* If the vector type is a polygon */

                }
                if(var.contains("EP")){/* EP */

                }
                if(var.contains("FP")){    /* FP (Fill the polygon with specified color. */

                }
                if(var.contains("ST")){ /* Status ST */

                }
                if(var.contains("PU")){ /* Pen UP */

                }
                if(var.contains("PD")){ /* Pen Down */

                }
                if(var.contains("AA")){/* Arc Angle */

                }
                if(var.contains("ST")){/* SymbolName, Orientation */

                }
                if(var.contains("FP")){

                }

                //PM//ST
                //qDebug()<<Sym<<Data<<ColorData;
            }


            if(Def.DataType=="V"){


//                /* color of the symbol/Line/Area.*/
//                if (SDBEqualn (pszToken, "SP", 2))
//                  { GetColor (pszToken[2], szClr); continue; }

//                    /* Width of the line */
//                else if (SDBEqualn (pszToken, "SW", 2))
//                    {  ucLineWidth = atoi (pszToken+2); continue; }

//                /* If the type of vector is a Circle */
//                else if (SDBEqualn (pszToken, "CI", 2)) {


//                  if (pstVect == NULL && m_ppstVector)
//                    { pstVect = m_ppstVector [m_usVectors-1]; }

//                  pstVect->enmType = enmCircle;
//                  pstVect->ucType = 2;
//                  pstVect->usRadius = atoi (pszToken+2);
//                continue;
//                }

            }
        }

    }

}

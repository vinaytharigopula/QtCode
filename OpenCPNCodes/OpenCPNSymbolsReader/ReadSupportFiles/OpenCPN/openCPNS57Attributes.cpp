#include "openCPNS57Attributes.h"

openCPNS57Attributes::openCPNS57Attributes(QObject *parent) : QObject(parent)
{
    Special=",";
}

openCPNS57Attributes::~openCPNS57Attributes()
{

}

void openCPNS57Attributes::clearAtrrData()
{
    AtrrVec.clear();
}
//1,AGENCY,A,F,Agency responsible for production
//"1,Agency responsible for production,AGENCY,A,F\n"
void openCPNS57Attributes::appendAttributeData(QString data){
    Final.clear();
    QStringList List=data.split(",");
    if(List.size()>4){

        Final.append(List.at(0));
        Final.append(Special);
        Final.append(List.at(2));
        Final.append(Special);
        Final.append(List.at(3));
        Final.append(Special);
        Final.append(List.at(4));
        Final.append(Special);
        Final.append(List.at(1));

        AtrrVec.append(Final);

        //qDebug()<<Final;
    }

}

void openCPNS57Attributes::writeAtrrSupportFile(QString path,QString Name){



    qDebug()<<path<<Name;

    QFile file(path+Name);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&file);

        foreach (QString var, AtrrVec) {
            stream<<var<<"\n";
        }
    }
    file.close();
}




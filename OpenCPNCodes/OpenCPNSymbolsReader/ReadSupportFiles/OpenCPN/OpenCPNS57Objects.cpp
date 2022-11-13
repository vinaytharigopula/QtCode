#include "OpenCPNS57Objects.h"

OpenCPNS57Objects::OpenCPNS57Objects(QObject *parent) : QObject(parent)
{
    //s57objectclasses.csv
    Special=",";
}

OpenCPNS57Objects::~OpenCPNS57Objects()
{

}
void OpenCPNS57Objects::clearObjectClassData()
{
    ObjectClasses.clear();
}
//1,AGENCY,A,F,Agency responsible for production
//"1,Agency responsible for production,AGENCY,A,F\n"
void OpenCPNS57Objects::appendObjectClassData(QString data){
    data=data.simplified();
    data=data.remove("\"");
    ObjectClasses.append(data);
}

void OpenCPNS57Objects::writeObjectClassSupportFile(QString path,QString Name){



    //qDebug()<<path<<Name;

    QFile file(path+Name);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&file);

        foreach (QString var, ObjectClasses) {
            stream<<var<<"\n";
        }
    }
    file.close();
}



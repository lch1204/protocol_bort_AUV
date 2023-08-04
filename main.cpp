#include <QCoreApplication>

#include <QDebug>
#include "protocol_bort.h"
#include "protocol_pc.h"
#include <QTimer>

//const QString ConfigFile = "protocols.conf";
//const QString agent = "agent";



int main(int argc, char *argv[])
{



    QCoreApplication a(argc, argv);
    QTimer timer;
    timer.start(1000);

    protocolAUV protocolauv;
    protocolPC protocolpc;
    //Создадим объект обмена со стороны пульта!
//    Pult::PC_Protocol *pcProtocol = new Pult::PC_Protocol();
//    ControlSystem::PC_Protocol *auvProtocol = new ControlSystem::PC_Protocol(ConfigFile, "agent");
//    Pult::PC_Protocol *pcProtocol = new Pult::PC_Protocol(ConfigFile, "pult");

//    auvProtocol->send_data.dataAH127C.yaw = 180;
//    qDebug() << (auvProtocol -> send_data.dataAH127C.yaw);
//    pcProtocol->send_data.proverkadataAH127C.yaw = 10;
//    qDebug() << (pcProtocol -> send_data.proverkadataAH127C.yaw);

//    pcProtocol->startExchange();
//    auvProtocol->startExchange();

//    auvProtocol->rec_data.proverkadataAH127C.yaw;
//    auvProtocol->send_data.dataAH127C.yaw = 90;
//    pcProtocol->rec_data.dataAH127C.yaw;
//    QObject::connect(&timer,&QTimer::timeout,[&](){
//        qDebug()<<"Pult yaw = "<<pcProtocol->rec_data.dataAH127C.yaw;
//        qDebug()<<"Bort yaw = "<<auvProtocol->rec_data.proverkadataAH127C.yaw;

//    });


//    QObject::connect(pcProtocol,&Pult::PC_Protocol::receiveData,[&](){
//        qDebug()<<"yaw = "<<pcProtocol->rec_data.dataAH127C.yaw;
//    });

    return a.exec();
}

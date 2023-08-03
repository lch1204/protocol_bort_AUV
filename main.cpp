#include <QCoreApplication>
#include <pc_protocol.h>
#include <protocol.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Создадим объект обмена со стороны пульта!
    Pult::PC_Protocol *pcProtocol = new Pult::PC_Protocol();
    ControlSystem::PC_Protocol *auvProtocol = new ControlSystem::PC_Protocol();

    auvProtocol->send_data.dataAH127C.yaw = 180;
    qDebug() << (auvProtocol -> send_data.dataAH127C.yaw);

    pcProtocol->startExchange();
    auvProtocol->startExchange();

//    QObject::connect(pcProtocol,&Pult::PC_Protocol::receiveData,[&](){
//        qDebug()<<"yaw = "<<pcProtocol->rec_data.dataAH127C.yaw;
//    });

    return a.exec();
}

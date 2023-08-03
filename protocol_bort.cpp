#include "protocol_bort.h"
#include "protocol.h"
#include "pc_protocol.h"

protocolAUV:: protocolAUV (QObject *parent)
{
    connect(&timer, &QTimer::timeout, this, &protocolAUV::tick);
    timer.start(10);

}


void protocolAUV:: tick()
{
    readDataFromPult();
//    readDataFromSensors();
//    regulators();
//    BFS_DRK(X[101][0], X[102][0], X[103][0] , X[104][0], X[105][0], X[106][0]);
//    writeDataToVMA();
    writeDataToPult();
}

void protocolAUV::readDataFromPult ()
{
//    auvProtocol->rec_data.proverkadataAH127C.yaw;
}

void protocolAUV::writeDataToPult ()
{
//    pcProtocol->rec_data.dataAH127C.yaw;
}

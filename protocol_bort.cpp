#include "protocol_bort.h"
#include "protocol.h"

protocolAUV:: protocolAUV (QObject *parent)
{
    connect(&timer, &QTimer::timeout, this, &protocolAUV::tick);
}


void protocolAUV:: tick()
{
//    readDataFromPult();
//    readDataFromSensors();
//    regulators();
//    BFS_DRK(X[101][0], X[102][0], X[103][0] , X[104][0], X[105][0], X[106][0]);
//    writeDataToVMA();
//    writeDataToPult();
}

void protocolAUV::readDataFromPult ()
{

}

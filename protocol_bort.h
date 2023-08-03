#ifndef PROTOCOL_BORT_H
#define PROTOCOL_BORT_H

#include "stdint.h"
#include <QDebug>
#include <QTime>
#include <QTimer>


class protocolAUV : public QObject
{
    Q_OBJECT
public:
    protocolAUV(QObject * parent = nullptr);
    void start(int dt){
        timer.start(dt);
    }
public:
    void tick();
protected:
        QTimer timer;
        void readDataFromPult();
//        PC_Protocol *pultProtocol = nullptr;
};


#endif

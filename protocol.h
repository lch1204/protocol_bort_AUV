#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "stdint.h"
#include <QDebug>


enum class e_CSMode : quint8
{ //режим работы
    MODE_HANDLE = 0, //ручной
    MODE_AUTOMATED, //автоматизированный
    MODE_AUTOMATIC, //автоматический
    MODE_GROUP //групповой
};

#pragma pack(push,1)
//структура данных, которая передается из Северова в Пульт
//тут описаны данные, которые Пульт принимает от Северова

struct ControlData
{ //данные, которые идут с пульта в СУ
    float yaw       = 0;
    float pitch     = 0;
    float roll      = 0;
    float march     = 0;
    float depth     = 0;
    float lag       = 0;
};

struct ControlContoursFlags
{ //флаги замыкания контуров (если 1, то замкнуты, 0 - разомкнуты)
    quint8 yaw = 0;
    quint8 pitch = 0;
    quint8 roll = 0;
    quint8 march = 0;
    quint8 depth = 0;
    quint8 lag = 0;
};


struct AUVCurrentData
{
    //!!тут все текущие параметры АНПА
    quint8 modeReal;//текущий режим
    ControlContoursFlags controlReal;//текущее состояние контуров
    quint8 modeAUV_Real;//текущий выбор модель/реальный НПА
    ControlData ControlDataReal;//текущие курс, дифферент, крен
    quint16 signalVMA_real;//управление на ВМА (текущие управляющие сигнлы на движители)
};

struct PowerSystemData
{
    //состояние системы питания
};

struct Header
{
    int senderID=0;
    int receiverID=0;
    int msgSize=0;
};

struct DataAH127C
{ //структура данных с датчика бесплатформенной системы ориентации
    float yaw       = 0; //курс градусы +/- 180
    float pitch     = 0; //...
    float roll      = 0;

    float X_accel   = 0;
    float Y_accel   = 0;
    float Z_accel   = 0;

    float X_rate    = 0;
    float Y_rate    = 0;
    float Z_rate    = 0;

    float X_magn    = 0;
    float Y_magn    = 0;
    float Z_magn    = 0;

    float quat [4];
};

struct DataPressure
{ //структура данных с датчика давления
    float temperature = 0; //Temperature returned in deg C.
    float depth       = 0; //Depth returned in meters
    float pressure    = 0; // Pressure returned in mbar or mbar*conversion rate.
};

struct DataUWB
{ //структура данных с сверхширокополосного модуля
    float locationX = 0; //координата аппарата по оси X
    float locationY = 0; //координата аппарата по оси Y
    float distanceToBeacon[4]; //расстоние до i-го маяка
    float distanceToAgent[10]; //расстояние до i-го агента
};

struct ToPult
{
    ToPult(int auvID=0)
    {
        header.senderID = auvID;
        header.receiverID = 0;
        header.msgSize = sizeof (ToPult);
    }
    Header header;
    AUVCurrentData auvData;// данные о текущих параметрах
    DataAH127C dataAH127C;// данные с БСО
    DataPressure dataPressure; //данные с датчика давления
    DataUWB dataUWB;//данные с UWB
    quint16 checksum;
};

//структура данных, которая передается из пульта в АНПА
struct FromPult
{
    ControlData controlData; //данные, которые идут с пульта при замыканиии контуров
    e_CSMode cSMode; //режим работы
    ControlContoursFlags controlContoursFlags; //флаги замыкания контуров (если больше 0, то замкнуты
    PowerSystemData desiredPowerState; //структура с желаемыми параметрами системы питания
    quint16 checksum;
};

#pragma pack (pop)


#endif // PROTOCOL_H

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "stdint.h"
#include <QDebug>

#pragma pack(push,1)

enum class e_CSMode : quint8
{ //режим работы
    MODE_MANUAL = 0, //ручной
    MODE_AUTOMATED, //автоматизированный
    MODE_AUTOMATIC, //автоматический
    MODE_GROUP //групповой
};

enum class power_Mode : quint8
{ //режим работы
    MODE_2 = 0, //включены вычислитель, wifi, uwb
    MODE_3, //включены вычислитель, wifi, uwb, гидроакустика
    MODE_4, //включены вычислитель, wifi, uwb, гидроакустика, ВМА
    MODE_5 //выключить вычислитель на 5 секунд и включить обратно
};


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
    quint8 yaw = 1;
    quint8 pitch = 1;
    quint8 roll = 1;
    quint8 march = 1;
    quint8 depth = 1;
    quint8 lag = 1;
};


struct AUVCurrentData
{
    //!!тут все текущие параметры АНПА
    quint8 modeReal = 0;//текущий режим
    ControlContoursFlags controlReal;//текущее состояние контуров, чтобы проверить что сигнал с пульта был обработан
    quint8 modeAUV_Real = 0;//текущий выбор модель/реальный НПА
    ControlData ControlDataReal;//текущие курс, дифферент, крен, значения с имушки по сути
    ControlData signalVMA_real;//управление на ВМА (текущие управляющие сигнлы на движители)
};


struct HeaderSwap
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

struct FlagAH127C_bort
{
    quint8 startCalibration = 0;
    quint8 endCalibration = 0;
};

struct FlagAH127C_pult
{
    quint8 initCalibration = 0;
    quint8 saveCalibration = 0;
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
        headerSwap.senderID = auvID;
        headerSwap.receiverID = 0;
        headerSwap.msgSize = sizeof (ToPult);
    }
    HeaderSwap headerSwap;
    AUVCurrentData auvData;// данные о текущих параметрах
    DataAH127C dataAH127C;// данные с БСО
    DataPressure dataPressure; //данные с датчика давления
    DataUWB dataUWB;//данные с UWB
    uint checksum;
    FlagAH127C_bort flagAH127C_bort;
};

//структура данных, которая передается из пульта в АНПА
struct FromPult
{
    ControlData controlData; //данные, которые идут с пульта при замыканиии контуров
    e_CSMode cSMode = e_CSMode::MODE_MANUAL; //режим работы
    power_Mode pMode = power_Mode::MODE_2; //режим работы системы питания, структура с желаемыми параметрами системы питания
    ControlContoursFlags controlContoursFlags; //флаги замыкания контуров (если больше 0, то замкнуты
    quint8 modeAUV_selection;//текущий выбор модель/реальный НПА
    uint checksum;
    FlagAH127C_pult flagAH127C_pult;
};

#pragma pack (pop)


#endif // PROTOCOL_H

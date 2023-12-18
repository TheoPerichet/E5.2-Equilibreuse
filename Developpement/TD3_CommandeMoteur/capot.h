#ifndef CAPOT_H
#define CAPOT_H

#include <QTimer>
#include "mcculdaq.h"
#include "../include/uldaq.h"
#include "../include/UlDaqDeviceManager.h"
#include "../include/UlException.h"
#include "../include/DioDevice.h"
#include "../include/AoDevice.h"
#include "../include/AiDevice.h"
#include "../include/CtrDevice.h"

class Capot : public QObject
{
    Q_OBJECT
public:
    Capot(MccUldaq &_laCarte,const int _numDio, QObject *parent);

private:
    QTimer timerCapot;
    bool etatCapot;
    int numDio;
    bool etatCourant;
    MccUldaq &laCarte;
signals:
    void EtatCapotChange(const bool _etatCapot);

public slots:
    void onTimerCapot_timeout();

};

#endif // CAPOT_H

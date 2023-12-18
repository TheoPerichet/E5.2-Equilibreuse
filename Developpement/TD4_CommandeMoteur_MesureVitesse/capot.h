#ifndef CAPOT_H
#define CAPOT_H

#include <QObject>
#include <QTimer>
#include "mcculdaq.h"
#include <QLabel>
#include "moteur.h"
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
    explicit Capot(MccUldaq &_laCarte, const int _numDio, QObject *parent = nullptr);
    bool getEtatCapot() const;

signals:
    void EtatCapotChange(bool _etat);

private slots:
    void onTimerCapot_timeout();

private:
    MccUldaq &laCarte;
    QTimer timerCapot;
    const int numDio;
    bool etatCapot;
};

#endif // CAPOT_H

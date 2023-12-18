#ifndef CODEUR_H
#define CODEUR_H


#include "mcculdaq.h"
#include <QTimer>
#include <QObject>

class Codeur : public QObject
{
    Q_OBJECT
public:
    Codeur(const int _numDio, MccUldaq &_laCarte, QObject *parent = nullptr);
    ~Codeur();
    int vitesse;
    void LancerMesureVitesse();
    void ArreterMesureVitesse();
public slots:
    void onTimerVitesse_timeout();
private:
    MccUldaq &laCarte;
    QTimer timerVitesse;
    const int numDio;
    double vitesseCalculee;
signals:
    void VitesseChange(const int _vitesse);
};

#endif // CODEUR_H

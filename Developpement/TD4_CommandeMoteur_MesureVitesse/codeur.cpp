#include "codeur.h"
#include "constantes.h"
#include "ui_equilibreuse.h"

Codeur::Codeur(const int _numDio, MccUldaq &_laCarte, QObject *parent):
    QObject(parent),
    laCarte(_laCarte),
    numDio(_numDio)
{
    vitesse = 0;
    timerVitesse.setTimerType(Qt::PreciseTimer);
    timerVitesse.setSingleShot(true);
    connect(&timerVitesse, &QTimer::timeout, this, &Codeur::onTimerVitesse_timeout);
}

Codeur::~Codeur()
{

}

void Codeur::LancerMesureVitesse()
{
    laCarte.UlCClear();
    timerVitesse.start(TEMPO_VITESSE);

}

void Codeur::ArreterMesureVitesse()
{
    timerVitesse.stop();
}

void Codeur::onTimerVitesse_timeout()
{
    long valCpt;
    laCarte.ulCIn(valCpt);
    vitesseCalculee=(2000*valCpt)/33333;

    if(vitesse!=vitesseCalculee){
        emit VitesseChange(vitesseCalculee);
        vitesse = vitesseCalculee;
    }
    laCarte.UlCClear();

    timerVitesse.start(TEMPO_VITESSE);
}

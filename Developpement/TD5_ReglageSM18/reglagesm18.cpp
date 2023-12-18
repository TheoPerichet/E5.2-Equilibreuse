#include "reglagesm18.h"
#include "constantes.h"

ReglageSM18::ReglageSM18(QWidget *parent)
    : QWidget(parent)
{
    connect(&tension, &QTimer::timeout,this,&ReglageSM18::onTimerReglageSM18_timeout);
}

ReglageSM18::~ReglageSM18()
{

}

void ReglageSM18::LancerMesure()
{
    tension.start(500);

}

void ReglageSM18::onTimerReglageSM18_timeout()
{
    laCarte.ulAIn(CH2, valeur, AIN_FF_DEFAULT);
}


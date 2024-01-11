#include "reglagesm18.h"
#include "constantes.h"
#include "ui_reglagesm18.h"

ReglageSM18::ReglageSM18(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::ReglageSM18)
{
    ui->setupUi(this);

}

ReglageSM18::~ReglageSM18()
{

}

void ReglageSM18::onTimerReglageSM18_timeout()
{
    qDebug() << "oui";
    laCarte.ulAIn(2, valeur, AIN_FF_DEFAULT);
    ui->lcdNumber->display(valeur);
}


void ReglageSM18::on_pushButton_LancerMesure_clicked()
{
    if(ui->pushButton_LancerMesure->text() == "Lancer Mesure"){
        tension.start(500);
        connect(&tension, &QTimer::timeout,this,&ReglageSM18::onTimerReglageSM18_timeout);
        ui->pushButton_LancerMesure->setText("Arreter Mesure");
    }
    else
    {
        tension.stop();
        ui->lcdNumber->display(0);
    }
}


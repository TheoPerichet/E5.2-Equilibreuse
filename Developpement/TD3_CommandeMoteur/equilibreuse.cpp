#include "equilibreuse.h"
#include "ui_equilibreuse.h"
#include "mcculdaq.h"
#include "capot.h"

Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equilibreuse)

{
    ui->setupUi(this);
    leCapot = new Capot(laCarte, 0, this);
    ui->statusbar->addPermanentWidget(&labelEtatCapot);
    labelEtatCapot.setText("Pas initialisée");
    leMoteur = new Moteur(laCarte, 0, 4);
    connect(leCapot, &Capot::EtatCapotChange, this, &Equilibreuse::onCapot_EtatCapotChange);
}

Equilibreuse::~Equilibreuse()
{
    delete ui;
    delete leCapot;
    delete leMoteur;
}

void Equilibreuse::onCapot_EtatCapotChange(const bool _etat)
{
    QPalette palette;
    labelEtatCapot.setAutoFillBackground(true);
    if(_etat)
    {
        palette.setColor(QPalette::WindowText,Qt::green);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot fermé |");
    }
    else
    {
        palette.setColor(QPalette::WindowText,Qt::red);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot ouvert |");
        leMoteur->FixerConsigneVitesse(0);
        ui->dial->setValue(0);
    }
}


void Equilibreuse::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}


void Equilibreuse::on_pushButtonLancerMoteur_clicked()
{
    leMoteur->FixerConsigneVitesse(ui->dial->value());
}


void Equilibreuse::on_pushButtonArreterMoteur_clicked()
{
    leMoteur->FixerConsigneVitesse(0);
}


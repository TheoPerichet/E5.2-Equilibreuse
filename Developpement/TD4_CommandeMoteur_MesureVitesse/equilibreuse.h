#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "capot.h"
#include "codeur.h"
#include "moteur.h"
#include "mcculdaq.h"
#include "../include/uldaq.h"
#include "../include/UlDaqDeviceManager.h"
#include "../include/UlException.h"
#include "../include/DioDevice.h"
#include "../include/AoDevice.h"
#include "../include/AiDevice.h"
#include "../include/CtrDevice.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Equilibreuse; }
QT_END_NAMESPACE

class Equilibreuse : public QMainWindow
{
    Q_OBJECT

public:
    Equilibreuse(QWidget *parent = nullptr);
    ~Equilibreuse();

public slots:
    void onCapot_EtatCapotChange(bool _etat);
    void onCodeur_NouvelleVitesse(const int vitesse);

private slots:
    void on_pushButton_Lancer_clicked();
    void on_pushButton_Arreter_clicked();


private:
    Ui::Equilibreuse *ui;
    MccUldaq laCarte;
    Capot *leCapot;
    Codeur *leCodeur;

    QLabel labelEtatCapot;

    Moteur *leMoteur;
};
#endif // EQUILIBREUSE_H

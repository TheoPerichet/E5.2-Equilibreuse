#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "capot.h"
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
    void onCapot_EtatCapotChange(const bool _etat);

private slots:
    void on_dial_valueChanged(int value);


    void on_pushButtonLancerMoteur_clicked();

    void on_pushButtonArreterMoteur_clicked();

private:
    Ui::Equilibreuse *ui;
    Capot *leCapot;
    Moteur *leMoteur;
    MccUldaq laCarte;
    QLabel labelEtatCapot;
};
#endif // EQUILIBREUSE_H

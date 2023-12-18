#ifndef REGLAGESM18_H
#define REGLAGESM18_H

#include "mcculdaq.h"
#include <QTimer>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ReglageSM18; }
QT_END_NAMESPACE

class ReglageSM18 : public QWidget
{
    Q_OBJECT

public:
    ReglageSM18(QWidget *parent = nullptr);
    ~ReglageSM18();


private slots:
    void onTimerReglageSM18_timeout();
    void on_pushButton_LancerMesure_clicked();

private:
    Ui::ReglageSM18 *ui;
    double valeur;
    MccUldaq laCarte;
    QTimer tension;
};
#endif // REGLAGESM18_H

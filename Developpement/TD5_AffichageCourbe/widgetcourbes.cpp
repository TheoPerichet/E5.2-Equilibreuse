#include <QDebug>

#include "widgetcourbes.h"
#include "ui_widgetcourbes.h"


WidgetCourbes::WidgetCourbes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetCourbes)
{
    ui->setupUi(this);
    connect(&timerMesure,&QTimer::timeout,this,&WidgetCourbes::onTimerMesure_timeout);


    courbeA.setName("Palier A");

    courbeO.setName("Palier O");


    chartView = new QChartView(&chart);
    layout = new QHBoxLayout(ui->widgetCourbes);
    layout->addWidget(chartView);
    chart.addSeries(&courbeA);
    chart.addSeries(&courbeO);
    chart.createDefaultAxes();

    QList<QAbstractAxis *> axe = chart.axes();
    if(axe.size() == 2)
    {
        QValueAxis *axeY = static_cast<QValueAxis *>(axe.last());
        axeY->applyNiceNumbers();
        axeY->setTickCount(5);
        axeY->setMinorTickCount(2);
        axeY->setLabelFormat("%d");
        axeY->setMin(-50);
        axeY->setMax(+50);

        QValueAxis *axeX = static_cast<QValueAxis *>(axe.first());
        axeX->setLabelFormat("%d");
        axeX->setMax(NB_ECHANTILLONS_PAR_CANAL*360/1000);
    }
    valeursBrutes = new double[NB_ECHANTILLONS_PAR_CANAL * NB_CANAUX];
}

WidgetCourbes::~WidgetCourbes()
{
    delete layout;
    delete chartView;
    delete ui;

}


void WidgetCourbes::on_pushButton_Lancer_clicked()
{
    double vitesse = 33000;
    if(ui->pushButton_Lancer->text()=="Lancer")
    {
        ScanOption options = static_cast<ScanOption>(SO_SINGLEIO | SO_CONTINUOUS | SO_EXTCLOCK | SO_EXTTRIGGER);
        qDebug() << "scanOption : " << Qt::hex << options;
        AInScanFlag flags = AINSCAN_FF_DEFAULT ;
        UlError erreur = laCarte.ulAInScan(CH0,CH1,NB_ECHANTILLONS_PAR_CANAL,&vitesse,options,flags,valeursBrutes);
        qDebug()<< "ulAInScan " << erreur;
        timerMesure.start(1000);
        ui->pushButton_Lancer->setText("Arrêter");
    }
    else
    {
        timerMesure.stop();
        laCarte.ulAInScanStop();
        ui->pushButton_Lancer->setText("Lancer");
    }
}

void WidgetCourbes::onTimerMesure_timeout()
{
    ScanStatus status;
    TransferStatus transferStatus;
    UlError erreur = laCarte.ulAInScanStatus(status,transferStatus);
    qDebug()<< "ulAInScanStatus " << erreur;
    qDebug() <<"Status " << status;
    if(status == SS_RUNNING)
    {
         QString resultat;
        if(erreur == ERR_NO_ERROR)
        {
            int index = transferStatus.currentIndex;
            int totalEchantillons = transferStatus.currentTotalCount;

            courbeA.clear();
            courbeO.clear();
            if(totalEchantillons > NB_ECHANTILLONS_PAR_CANAL)
                index = NB_ECHANTILLONS_PAR_CANAL;
            for (int i=0;i<index*NB_CANAUX;i+=NB_CANAUX) {
                courbeA << QPointF(i*360/1000,valeursBrutes[i]*11.206);
                courbeO << QPointF(i*360/1000,valeursBrutes[i+1]*11.206);
            }
            chartView->setRenderHint(QPainter::Antialiasing);
        }
    }
}

void WidgetCourbes::on_pushButton_clicked()
{
    QList<QAbstractAxis *> axe = chart.axes();
    QValueAxis *axeX = static_cast<QValueAxis *>(axe.first());
    axeX->setMin(ui->lineEdit->text().toInt());
    axeX->setMax((NB_ECHANTILLONS_PAR_CANAL+ui->lineEdit->text().toInt())*360/1000);
}


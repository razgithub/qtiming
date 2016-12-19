#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDateTime>


QTimer tim;
unsigned int nsecs;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(&tim, SIGNAL(timeout()), this, SLOT(count()));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


unsigned int nresetpush;

void MainWindow::on_pushButton_clicked()
{
    if(nresetpush != 0)
    {
        ui->pushButton_2->setText("Reset");
        nresetpush = 0;
    }

    if(!tim.isActive())
    {
        tim.start(1000);
        ui->pushButton->setText("Stop it");
    }
    else
    {
        tim.stop();
        ui->pushButton->setText("Start it");
    }
}

void MainWindow::count()
{
    nsecs++;
    ui->textEdit->setHtml(QDateTime::fromTime_t(nsecs).toUTC().toString("hh:mm:ss"));
}

void MainWindow::on_pushButton_2_clicked()
{
    if(nresetpush > 0)
    {
        nsecs = 0;
        ui->textEdit->setHtml(QDateTime::fromTime_t(nsecs).toUTC().toString("hh:mm:ss"));
        ui->pushButton_2->setText("Reset");
        nresetpush = 0;
    }
    else
    {
        nresetpush++;
        ui->pushButton_2->setText("Reset (1+)");
    }
}

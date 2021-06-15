#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QWebEngineView>
#include <QProgressBar>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView *view = new QWebEngineView();
    view->load(QUrl("http://192.168.1.11:8080/?action=stream"));
    view->show();
    ui->camera->addWidget(view);
   connect( &robot , SIGNAL( updateUI(QByteArray)),this,SLOT(batterie()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connexion_clicked()
{
      robot.doConnect();
}

/* Pour la manif libre .......................................................
void MainWindow::on_avancer_clicked()
{
       robot.move(1);
}
void MainWindow::on_gauche_clicked()
{
     robot.move(2);
}
void MainWindow::on_droite_clicked()
{
      robot.move(3);
}
void MainWindow::on_stop_clicked()
{
      robot.move(4);
}
void MainWindow::on_reculer_clicked()
{
      robot.move(5);
}...............................................................................
*/

void MainWindow::on_bouger_1_clicked()
{
     qDebug()<<"test";
     request.setUrl(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"));
     manager->get(request);
}
void MainWindow::on_bouger_2_clicked()
{
    qDebug()<<"test";
     request.setUrl(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200"));
     manager->get(request);
}

void MainWindow::on_bouger_3_clicked()
{
    qDebug()<<"test";
     request.setUrl(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200"));
     manager->get(request);
}
void MainWindow::on_bouger_4_clicked()
{
     qDebug()<<"test";
     request.setUrl(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200"));
     manager->get(request);
}
void MainWindow::on_avancer_released()
{
       robot.move(5);
}
void MainWindow::on_avancer_pressed()
{
    robot.move(1);
}
void MainWindow::on_gauche_pressed()
{
    robot.move(2);
}

void MainWindow::on_reculer_pressed()
{
    robot.move(4);
}

void MainWindow::on_droite_pressed()
{
    robot.move(5);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
        {
            case Qt::Key_A:
             robot.doConnect();
              break;

            case Qt::Key_Z:
              robot.move(1);
                break;

            case Qt::Key_Q:
              robot.move(2);
                break;

            case Qt::Key_D:
              robot.move(3);
                break;

             case Qt::Key_S:
             robot.move(5);
             break;
          case Qt::Key_W:
            robot.move(4);
             break;
        }
}

void MainWindow::batterie(){    //A tester
    if(((unsigned int) robot.DataReceived[2] < 100) && ((unsigned int) robot.DataReceived[2]> 0)){
      this->ui->batterie->setValue(robot.DataReceived[2]);
    }
    else if(((unsigned int) robot.DataReceived[2] > 100)){
        this->ui->batterie->setValue(100);
        //Afficher "En recharge"
    }
    else{
        this->ui->batterie->setValue(0);
        //Afficher "plus de batterie"
    }
}

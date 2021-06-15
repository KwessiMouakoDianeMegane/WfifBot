#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "myrobot.h"
#include <QMainWindow>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connexion_clicked();
/*
    void on_avancer_clicked();

    void on_gauche_clicked();

    void on_droite_clicked();

    void on_stop_clicked();

    void on_reculer_clicked();
*/
    void on_bouger_1_clicked();

    void on_bouger_2_clicked();

    void on_bouger_3_clicked();

    void on_bouger_4_clicked();

    void on_avancer_released();

    void on_avancer_pressed();

    void on_gauche_pressed();

    void on_reculer_pressed();

    void on_droite_pressed();

     void batterie();
private:
      void keyPressEvent(QKeyEvent *event);
    Ui::MainWindow *ui;
      MyRobot robot;
      QNetworkRequest request;
      QNetworkAccessManager* manager=new QNetworkAccessManager();
};
#endif // MAINWINDOW_H

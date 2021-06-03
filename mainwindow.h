#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "myrobot.h"
#include <QMainWindow>
#include <QDebug>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QWebEngineView>
#include <QTimer>
#include <QKeyEvent>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots :
void connexion();
void avancer();
void gauche();
void droite();
void reculer();
void stop();
void batterie();

private:
Ui::MainWindow *ui;
QVBoxLayout* colonne1;
QVBoxLayout* colonne2;
QVBoxLayout* colonne3;
QVBoxLayout* colonne4;
QHBoxLayout* ligne;
QWidget* fenetre;
MyRobot* robot;
QWebEngineView* streamView;
QFormLayout* camera;

};


#endif // MAINWINDOW_H

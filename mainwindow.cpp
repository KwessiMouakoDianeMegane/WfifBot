#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui (new Ui::MainWindow)
//organisation de l'affichage
{
  //affiche la Camera ....................................
  QWebEngineView *view = new QWebEngineView();
  view->load(QUrl("http://192.168.1.11:8080/?action=stream"));
  view->show();
  robot = new MyRobot(this);
  colonne1 = new QVBoxLayout(this);
   colonne2 = new QVBoxLayout(this);
   colonne3 = new QVBoxLayout(this);
   colonne4 = new QVBoxLayout(this);
   ligne = new QHBoxLayout(this);
   ligne->addLayout(colonne1);
   ligne->addLayout(colonne2);
   ligne->addLayout(colonne3);
   ligne->addLayout(colonne4);

//Fenetre contenant les Widget
    fenetre = new QWidget(this);

//Ajout des boutons dans l'oganisation
    QPushButton* connexion = new QPushButton("Connexion", fenetre);
    colonne1->addWidget(connexion);
    QPushButton* gauche = new QPushButton("gauche", fenetre);
    colonne2->addWidget(gauche);
    QPushButton* haut = new QPushButton("avancer", fenetre);
    colonne3->addWidget(haut);
    QPushButton* stop = new QPushButton("STOP", fenetre);
    colonne3->addWidget(stop);
    QPushButton* bas = new QPushButton("reculer", fenetre);
    colonne3->addWidget(bas);
    QPushButton* droite = new QPushButton("droite", fenetre);
    colonne4->addWidget(droite);

     robot = new MyRobot(this);
//Connexions entre les boutons et les fonctions

   QObject::connect(connexion, SIGNAL(clicked(bool)), this, SLOT(connexion()));
   QObject::connect(gauche, SIGNAL(clicked(bool)), this, SLOT(gauche()));
   QObject::connect(haut, SIGNAL(clicked(bool)), this, SLOT(avancer()));
   QObject::connect(stop, SIGNAL(clicked(bool)), this, SLOT(stop()));
   QObject::connect(bas, SIGNAL(clicked(bool)), this, SLOT(reculer()));
   QObject::connect(droite, SIGNAL(clicked(bool)), this, SLOT(droite()));
   //Affichage des boutons dans la fenetre

//Affichage des boutons dans la fenetre


   fenetre->setLayout(ligne);
   setCentralWidget(fenetre);
   }
   void MainWindow::connexion()
   {
   robot->doConnect();
   }
   void MainWindow::avancer()
 {
       robot->move(1);
   }
   void MainWindow::gauche()
   {
   robot->move(2);
   }
   void MainWindow::droite()
   {
       robot->move(3);
   }
   void MainWindow::reculer()
   {
       robot->move(4);
    }
   void MainWindow::stop()
   {
        robot->move(5);
   }
   //affichage de la batterie

   void MainWindow::batterie(){
 if(((unsigned int) robot->DataReceived[2] < 100) && ((unsigned int) robot->DataReceived[2] > 0))
 {

 }

MainWindow::~MainWindow(){
    delete ui;
}

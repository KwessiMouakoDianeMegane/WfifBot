#include "myrobot.h"

MyRobot::MyRobot(QObject *parent) : QObject(parent) {
 DataToSend. resize(9);
    DataToSend[0] = (unsigned char)0xFF;
    DataToSend[1] = (unsigned char)0x07;
    DataToSend[2] = (unsigned char)0x0;
    DataToSend[3] = (unsigned char)200;
    DataToSend[4] = (unsigned char)200;
    DataToSend[5] = (unsigned char)200;
    DataToSend[6] = (unsigned char)50;
    DataToSend[7] = (unsigned char)0;
    DataToSend[8] = (unsigned char)0;
 DataReceived. resize(21);
    TimerEnvoi = new QTimer();
    // setup signal and slot
    connect(TimerEnvoi, SIGNAL(timeout()), this, SLOT(MyTimerSlot())); //Send data to wifibot timer
}
void MyRobot::doConnect() {
    socket = new QTcpSocket(this); // socket creation
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    qDebug() << "connecting... "; // this is not blocking call
    //socket->connectToHost("LOCALHOST", 15020);
    socket->connectToHost("192.168.1.11", 15020); // connection to wifibot
    // we need to wait...
    if(!socket->waitForConnected(5000)) {
        qDebug() <<  "Error: "  << socket->errorString();
        return;
    }
    TimerEnvoi->start(75);
}
void MyRobot::disConnect() {
    TimerEnvoi->stop();
    socket->close();
}

void MyRobot::connected() {
    qDebug() << "connected... "; // Hey server, tell me about you.
}

void MyRobot::disconnected() {
    qDebug() << "disconnected... ";
}

void MyRobot::bytesWritten(qint64 bytes) {
    qDebug() << bytes <<  "bytes written... " ;
}
void MyRobot::move(int QObject)
{
   qDebug() << QObject << "Qobject written......";
   DataToSend[0]=(unsigned char)0xFF;
   DataToSend[1]=(unsigned char)7;
   DataToSend[2]=(unsigned char)200;
   DataToSend[3]=0x0;
   DataToSend[4]=(unsigned char)200;
   DataToSend[5]=(unsigned char)0x0;
   DataToSend[6]=(unsigned char)80;
   if (QObject ==1)
   {
      DataToSend[6]=(unsigned char)80;
   }
   else if ( QObject == 2)
   {
     DataToSend[6]=(unsigned char)64;
   }
   else if (QObject == 3)
   {
      DataToSend[6]=(unsigned char)16;
   }
   else if (QObject == 4 )
   {
     DataToSend[6]=(unsigned char)0;
   }
   else if (QObject == 5 )
   {
   DataToSend[2]=(unsigned char)0;
   DataToSend[4]=(unsigned char)0;
   }

   quint16 erreur = crc165(DataToSend , 1);
   DataToSend[7]=(unsigned char)erreur;
   DataToSend[8]=(unsigned char) (erreur>>8);
}

void MyRobot::readyRead() {
    qDebug() << "reading... "; // read the data from the socket
    DataReceived = socket->readAll();
    emit updateUI(DataReceived);
    qDebug() << DataReceived[0 ] << DataReceived[1 ] << DataReceived[2 ];
}

void MyRobot::MyTimerSlot() {
    qDebug() <<  "Timer... " ;
    while(Mutex. tryLock());
    socket->write(DataToSend);
 Mutex. unlock();
}
quint16 MyRobot::crc165(QByteArray byteArray , int pos)
{
byteArray.data();
unsigned char *data =(unsigned char* )byteArray.constData();
quint16 crc=0xFFFF;
quint16 polynome = 0xA001;
quint16 parity = 0 ;
for (; pos <byteArray.length()-2;pos++)
{ crc^=*(data+pos);
for (unsigned int CpBit=0;CpBit <=7;CpBit++)
{    parity=crc;
    crc>>=1;
    if (parity%2 == true) crc^=polynome;
}
}
return crc;
}


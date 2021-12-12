#include "arduinowindow.h"
#include "ui_arduinowindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <QPixmap>

ArduinoWindow::ArduinoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArduinoWindow)
{
    ui->setupUi(this);
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    light1 = false;
    light2 = false;
    light3 = false;
    light4 = false;

    /*
    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }

        qDebug() << "Has product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }
    */

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id && serialPortInfo.productIdentifier() == arduino_uno_product_id){
                arduino_port_name = serialPortInfo.portName();
                arduino_is_available = true;
            }
        }
    }

    if(arduino_is_available){
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

        this->on_buttonOFF_released();
    }
    else{
        QMessageBox::warning(this, "Port error", "Arduino not found!");
    }
}

ArduinoWindow::~ArduinoWindow()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}

void ArduinoWindow::on_pushButton_7_released()
{
    this->close();
}

void ArduinoWindow::updateLED(QString command){

    if(arduino->isWritable()){
        arduino->write(command.toStdString().c_str());
    }
    else{
        qDebug() << "Could not write to serial!";
    }
}



void ArduinoWindow::on_button1_released()
{
    light1 = !light1;
    if(light1){
        updateLED(QString("y255"));
        ui->light1->setPixmap(QPixmap(":/new/prefix1/lightOn.png"));

    }
    else{
        updateLED(QString("y0"));
        ui->light1->setPixmap(QPixmap(":/new/prefix1/lightOff.png"));
    }
}

void ArduinoWindow::on_button2_released()
{
    light2 = !light2;
    if(light2){
        updateLED(QString("b255"));
        ui->light2->setPixmap(QPixmap(":/new/prefix1/lightOn.png"));
    }
    else{
        updateLED(QString("b0"));
        ui->light2->setPixmap(QPixmap(":/new/prefix1/lightOff.png"));
    }
}

void ArduinoWindow::on_button3_released()
{
    light3 = !light3;
    if(light3){
        updateLED(QString("g255"));
        ui->light3->setPixmap(QPixmap(":/new/prefix1/lightOn.png"));
    }
    else{
        updateLED(QString("g0"));
        ui->light3->setPixmap(QPixmap(":/new/prefix1/lightOff.png"));
    }
}

void ArduinoWindow::on_button4_released()
{
    light4 = !light4;
    if(light4){
        updateLED(QString("r255"));
        ui->light4->setPixmap(QPixmap(":/new/prefix1/lightOn.png"));
    }
    else{
        updateLED(QString("r0"));
        ui->light4->setPixmap(QPixmap(":/new/prefix1/lightOff.png"));
    }
}


void ArduinoWindow::on_buttonALL_released()
{
    light1 = false;
    light2 = false;
    light3 = false;
    light4 = false;

    this->on_button1_released();
    this->on_button2_released();
    this->on_button3_released();
    this->on_button4_released();
}


void ArduinoWindow::on_buttonOFF_released()
{
    light1 = true;
    light2 = true;
    light3 = true;
    light4 = true;

    this->on_button1_released();
    this->on_button2_released();
    this->on_button3_released();
    this->on_button4_released();
}


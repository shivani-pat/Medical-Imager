#ifndef ARDUINOWINDOW_H
#define ARDUINOWINDOW_H

#include <QDialog>
#include <QSerialPort>

namespace Ui {
class ArduinoWindow;
}

class ArduinoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ArduinoWindow(QWidget *parent = nullptr);
    ~ArduinoWindow();

private slots:
    void on_pushButton_7_released();

    void updateLED(QString);


    void on_button1_released();
    void on_button2_released();
    void on_button3_released();
    void on_button4_released();

    void on_buttonALL_released();

    void on_buttonOFF_released();

private:
    Ui::ArduinoWindow *ui;
    QSerialPort *arduino;

    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;

    QString arduino_port_name;
    bool arduino_is_available;

    bool light1;
    bool light2;
    bool light3;
    bool light4;
};

#endif // ARDUINOWINDOW_H

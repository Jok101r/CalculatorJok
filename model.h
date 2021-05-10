#pragma once

#include <QString>
#include <QMessageBox>


class Model
{
public:
    Model();

    double getAnswer();
    int getError();
    QString getOperation();

    void setPreviusNumber(double);
    void setNextNumber(double);
    void setOperation(QString );
    void clear();
    void calculatingValues();



private:
    //первое число в решении
    double m_previousNumber = 0.0;
    //второе число
    double m_nextNumber = 0.0;
    //ответ
    double m_answer = 0.0;
    //переключение между первым и последующими числами
    bool m_trigger = false;
    //математическая операция
    QString m_operation = " ";


    void math_operation();

};


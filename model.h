#pragma once

#include <QString>
#include <QMessageBox>
#include <QWidget>


class Model
{
public:
    Model();

    double getAnswer();
    int getError();

    void setPreviusNumber(double);
    void setNextNumber(double);
    void setOperation(QString );
    void clear();
    void calculatingValues(QWidget *);



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

    //Код ошибок

    unsigned int m_error = 0;


    void math_operation();
};


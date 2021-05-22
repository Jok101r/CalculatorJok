#pragma once

#include <QString>
#include <QMessageBox>


class Model
{
public:
    Model();
    enum class Operation
    {
        Plus,
        Minus,
        Divide,
        Multiply,
        No
    };


    double getAnswer();
    Model::Operation getOperation();

    void setFirstArgument(double);
    void setSecondArgument(double);
    void setOperation(Operation );
    void clear();
    void calculatingValues();



private:
    //первое число в решении
    double m_firstArgument = 0.0;
    //второе число
    double m_secondArgument = 0.0;
    //ответ
    double m_answer = 0.0;

    Operation m_operation = Operation::No;


    void math_operation();

};


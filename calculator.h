#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "./ui_calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void defenition_button();

    void on_pushButton_dot_clicked();

    void on_pushButton_plus_and_minus_clicked();

    void on_pushButton_persent_clicked();

    void on_pushButton_Zero_clicked();

    void on_pushButton_equally_clicked();

    void choice_math_operation();

private:
    Ui::Calculator *ui;
    //первое число в решении
    double previousNumber = 0.0;
    //второе число
    double nextNumber = 0.0;
    //ответ
    double answer = 0.0;
    //проверка использовании математических операция
    bool checkUseOperation = false;
    //переключение между первым и последующими числами
    bool trigger = false;
    //история изменений
    QString historyCalculator;

    QString operation = " ";

    void math_operation();

};
#endif // CALCULATOR_H
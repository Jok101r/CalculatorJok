#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QtGui>
#include "model.h"
#include "output.h"

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
    void use_math_operation_on_form();
    void on_pushButton_dot_clicked();
    void on_pushButton_plus_and_minus_clicked();
    void on_pushButton_persent_clicked();
    void on_pushButton_Zero_clicked();
    void on_pushButton_equally_clicked();
    void choice_math_operation();

    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::Calculator *ui;

    Model *m_model;
    OutPut *m_output;


    //проверка использовании математических операция
    bool m_checkUseOperation = false;
    //переключение между первым и последующими числами
    bool m_firstCallNumber = false;

    //используется ли ввод с клавиатуры
    bool UseKeyboard = false;
    void inputStatusbar(const QString &);


};

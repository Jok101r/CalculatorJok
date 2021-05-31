#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QtGui>
#include "model.h"
#include "output.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model &, QWidget *parent = nullptr);
    ~View();

private slots:
    void defenition_button();
    void use_math_operation_on_form();
    void on_pushButton_dot_clicked();
    void on_pushButton_plus_and_minus_clicked();
    void on_pushButton_persent_clicked();
    void on_pushButton_Zero_clicked();
    void on_pushButton_equally_clicked();
    void choice_math_operation(const QString &);

    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::View *ui;
    Model &m_model;

    OutPut *m_output;


    //проверка использовании математических операция
    bool m_checkUseOperation = false;

    //переключение между первым и последующими операциями
    bool m_secondCallNumber = false;

    //от двойных кликов по операциями
    bool m_doubleClickOperation = false;

    //состояние между аргументами операции
    bool m_stateBetweenArguments = false;

    //используется ли ввод с клавиатуры
    bool m_useKeyboard = false;
    void inputStatusbar(const QString &);
    Model::Operation operationList(const QString &);


};

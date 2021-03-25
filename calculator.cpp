#include "calculator.h"
#include "./ui_calculator.h"
#include <QMessageBox>
#include <QtGui>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(defenition_button()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(defenition_button()));


    connect(ui->pushButton_division,SIGNAL(clicked()),this,SLOT(choice_math_operation()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(choice_math_operation()));
    connect(ui->pushButton_multi,SIGNAL(clicked()),this,SLOT(choice_math_operation()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(choice_math_operation()));

    ui->pushButton_division->setCheckable(true);
    ui->pushButton_multi->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);


}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::defenition_button()
{

    if (checkUseOperation == true){
        ui->answer_field->setText(0);
        checkUseOperation = false;
    }
    QPushButton *button = (QPushButton *)sender();
    QString output;
    double allNumber;

    outPutStatusBar(button->text());



    allNumber = (ui->answer_field->text() + button->text()).toDouble();

    //увелечение количество символов для экспонициального вывода
    output = QString::number(allNumber, 'g',15);
    ui->answer_field->setText(output);

}

void Calculator::on_pushButton_dot_clicked()
{
    //чтобы точка была единственной в answer_field
    if(!(ui->answer_field->text().contains(".")) ){
        ui->answer_field->setText(ui->answer_field->text()+".");
    }
}

void Calculator::on_pushButton_plus_and_minus_clicked()
{
    double fullNumber = ui->answer_field->text().toDouble() * -1;
    ui->answer_field->setText( QString::number(fullNumber, 'g',15));
}

void Calculator::on_pushButton_persent_clicked()
{
    double fullNumber = ui->answer_field->text().toDouble() / 100;
    ui->answer_field->setText( QString::number(fullNumber) );
}

void Calculator::on_pushButton_Zero_clicked()
{
    previousNumber = 0.0;
    nextNumber = 0.0;
    answer = 0.0;
    checkUseOperation = false;
    historyCalculator.clear();
    trigger = false;
    operation = " ";

    ui->pushButton_division->setChecked(false);
    ui->pushButton_multi->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->answer_field->setText(0);
    ui->statusbar->showMessage(0);
}

void Calculator::math_operation(){


    nextNumber = ui->answer_field->text().toDouble();

    //trigger = false;
    //Решение матемаических операций
    {
        if (operation == "/") {
            answer = previousNumber / nextNumber;


            ui->pushButton_division->setChecked(false);
        }
        if (operation == "*" )      {
            answer = previousNumber * nextNumber;
            ui->pushButton_multi->setChecked(false);
        }

        if (operation == "-" ){
            answer = previousNumber - nextNumber;
            ui->pushButton_minus->setChecked(false);
        }

        if (operation == "+" ){
            answer = previousNumber + nextNumber;
            ui->pushButton_plus->setChecked(false);
        }
    }


    checkUseOperation = true;

    //previousNumber = answer;
}
void Calculator::on_pushButton_equally_clicked()
{

    math_operation();
    ui->answer_field->setText(QString::number(answer, 'g',15));

    checkUseOperation = true;
}

void Calculator::choice_math_operation(){    

    if (UseKeyboard){
        if (!trigger){
            previousNumber = ui->answer_field->text().toDouble();
            trigger = true;
            checkUseOperation = true;

        }else {
            on_pushButton_equally_clicked();
                previousNumber = answer;
        }

    }else {

        QPushButton *button = (QPushButton *)sender();
        outPutStatusBar(button->text());


        if (!trigger){
            previousNumber = ui->answer_field->text().toDouble();
            button->setChecked(false);
            trigger = true;
            checkUseOperation = true;
            operation = button->text();
            button->text();

        }else {

            //QMessageBox::critical(this,"", QString::number(button->isChecked() ));

            on_pushButton_equally_clicked();
                previousNumber = answer;
            operation = button->text();
        }
    }

}


void Calculator::keyPressEvent(QKeyEvent *event)
{
    UseKeyboard = true;

    if (checkUseOperation == true){
        ui->answer_field->setText(0);
        checkUseOperation = false;
    }

    if (event->text() == "1" || event->text() == "2" || event->text() == "3" ||
        event->text() == "4" || event->text() == "5" || event->text() == "6" ||
        event->text() == "7" || event->text() == "8" || event->text() == "9" ||
        event->text() == "0"){

        QString output;
        double allNumber;

        outPutStatusBar(event->text());

        allNumber = (ui->answer_field->text() + event->text()).toDouble();

        //увелечение количество символов для экспонициального вывода
        output = QString::number(allNumber, 'g',15);
        ui->answer_field->setText(output);

    }
    if (event->text() == "-" || event->text() == "+" || event->text() == "/" ||
        event->text() == "*"){

        if (!trigger){
            operation = event->text();
        }

        choice_math_operation();
        operation = event->text();
        outPutStatusBar(event->text());

    }

    if(event->text() == "="){
        on_pushButton_equally_clicked();
        previousNumber = answer;
    }

    if(event->text() == "%"){
        on_pushButton_persent_clicked();
    }
    UseKeyboard = false;

}

//первое знакомство с r-value и l-value  корректно?
void Calculator::outPutStatusBar(QString &&inPut)
{
    historyCalculator = historyCalculator + inPut;
    ui->statusbar->showMessage(historyCalculator);
}


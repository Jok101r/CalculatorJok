#include "calculator.h"
#include "./ui_calculator.h"
#include <QMessageBox>

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

    //запись истории решения в statusbar
    historyCalculator = historyCalculator + button->text();
    ui->statusbar->showMessage(historyCalculator);


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
    ui->answer_field->setText( QString::number(fullNumber) );
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


//    {
//        if (ui->pushButton_division->isChecked() ) {
//            answer = previousNumber / nextNumber;


//            ui->pushButton_division->setChecked(false);
//        }
//        if (ui->pushButton_multi->isChecked() )      {
//            answer = previousNumber * nextNumber;
//            ui->pushButton_multi->setChecked(false);
//        }

//        if (ui->pushButton_minus->isChecked() ){
//            answer = previousNumber - nextNumber;
//            ui->pushButton_minus->setChecked(false);
//        }

//        if (ui->pushButton_plus->isChecked() ){
//            answer = previousNumber + nextNumber;
//            ui->pushButton_plus->setChecked(false);
//        }
//    }


    checkUseOperation = true;

    previousNumber = answer;
}
void Calculator::on_pushButton_equally_clicked()
{

    math_operation();
    ui->answer_field->setText(QString::number(answer, 'g',15));

    checkUseOperation = true;
}

void Calculator::choice_math_operation(){


    QPushButton *button = (QPushButton *)sender();

    historyCalculator = historyCalculator + button->text();
    ui->statusbar->showMessage(historyCalculator);

    if (!trigger){
        previousNumber = ui->answer_field->text().toDouble();
        button->setChecked(false);
        trigger = true;
        checkUseOperation = true;
        operation = button->text();

    }else {

        //QMessageBox::critical(this,"", QString::number(button->isChecked() ));

        //можно ли так вызывать сигнал?
        on_pushButton_equally_clicked();
        operation = button->text();
    }



}


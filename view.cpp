#include "view.h"
#include "./ui_view.h"


View::View(Model &model,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , m_model(model)
{
    ui->setupUi(this);
    m_output = new OutPut;

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


    connect(ui->pushButton_division,SIGNAL(clicked()),this,SLOT(use_math_operation_on_form()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(use_math_operation_on_form()));
    connect(ui->pushButton_multi,SIGNAL(clicked()),this,SLOT(use_math_operation_on_form()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(use_math_operation_on_form()));

    ui->pushButton_division->setCheckable(true);
    ui->pushButton_multi->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);


}

View::~View()
{
    delete ui;
}

void View::defenition_button()
{
    //если введена операция, то обнуляет строку
    if (m_checkUseOperation == true){
        ui->answer_field->setText(0);
        m_checkUseOperation = false;
    }

    QPushButton *button = (QPushButton *)sender();
    QString output;
    double allNumber;

    inputStatusbar(button->text());
    allNumber = (ui->answer_field->text() + button->text()).toDouble();

    //увелечение количество символов для экспонициального вывода
    output = QString::number(allNumber, 'g',15);
    ui->answer_field->setText(output);

    m_doubleClickOperation = true;
    m_stateBetweenArguments = false;



}
void View::use_math_operation_on_form()
{
    QPushButton *button = (QPushButton *)sender();

    choice_math_operation(button->text());

    button->setChecked(false);

}
Model::Operation View::operationList(const QString &operation)
{

    if (operation == "/")
    {
        return Model::Operation::Divide;
    }
    if (operation == "*")
    {
        return Model::Operation::Multiply;
    }
    if (operation == "+")
    {
        return Model::Operation::Plus;
    }
    if (operation == "-")
    {
        return Model::Operation::Minus;
    }
    else
    {
        return Model::Operation::No;
    }

}
void View::choice_math_operation(const QString &operation){


    //смена знака в одной операции
    if (m_stateBetweenArguments == true)
    {
        m_model.setOperation(operationList(operation));
        inputStatusbar(operation);
    }

    if ( (m_doubleClickOperation) || (m_model.getOperation() != operationList(operation) && m_secondCallNumber == true) )
    {


        if (m_secondCallNumber)
        {
            on_pushButton_equally_clicked();
        }

        double first = ui->answer_field->text().toDouble();
        m_model.setFirstArgument(first);
        m_model.setOperation(operationList(operation));
        inputStatusbar(operation);

        m_secondCallNumber = true;
        m_checkUseOperation = true;
        m_stateBetweenArguments = true;
        m_doubleClickOperation = false;


    }

}
void View::on_pushButton_dot_clicked()
{
    //чтобы точка была единственной в answer_field
    if(!(ui->answer_field->text().contains(".")) )
    {
        ui->answer_field->setText(ui->answer_field->text()+".");
        inputStatusbar(".");
    }
}
void View::on_pushButton_plus_and_minus_clicked()
{
    double fullNumber = ui->answer_field->text().toDouble() * -1;
    ui->answer_field->setText( QString::number(fullNumber, 'g',15));
}
void View::on_pushButton_persent_clicked()
{
    double fullNumber = ui->answer_field->text().toDouble() / 100;
    ui->answer_field->setText( QString::number(fullNumber) );
}
void View::on_pushButton_Zero_clicked()
{
    m_model.clear();
    m_output->historyStatusBarClear();
    ui->statusbar->addWidget(m_output->getHistoryStatusBar());

    m_checkUseOperation = false;
    m_secondCallNumber = false;
    m_doubleClickOperation = false;
    m_stateBetweenArguments = false;

    ui->pushButton_division->setChecked(false);
    ui->pushButton_multi->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->answer_field->setText(0);
    ui->statusbar->showMessage(0);
}
void View::on_pushButton_equally_clicked()
{


    m_model.setSecondArgument(ui->answer_field->text().toDouble());

    //в случае появление ошибок
    try
    {
        m_model.calculatingValues();
    }
    catch (std::runtime_error & err)
    {
        QMessageBox::warning(this, "Warning!!!", err.what());
        m_output->chopOutPutStatusBar(1);
        m_output->getHistoryStatusBar();
    }

    ui->answer_field->setText(QString::number(m_model.getAnswer(), 'g',15));

    m_doubleClickOperation = true;
    m_secondCallNumber = false;
    m_checkUseOperation = true;
//    m_stateBetweenArguments = true;

    m_model.setSecondArgument(0.0);
}
void View::keyPressEvent(QKeyEvent *event)
{
    m_useKeyboard = true;


    if (event->text() == "1" || event->text() == "2" || event->text() == "3" ||
        event->text() == "4" || event->text() == "5" || event->text() == "6" ||
        event->text() == "7" || event->text() == "8" || event->text() == "9" ||
        event->text() == "0"){

        //если введена операция, то обнуляет строку
        if (m_checkUseOperation == true){
            ui->answer_field->setText(0);
            m_checkUseOperation = false;
        }

        m_doubleClickOperation = true;
        m_stateBetweenArguments = false;

        QString output;
        double allNumber;

        inputStatusbar(event->text());
        allNumber = (ui->answer_field->text() + event->text()).toDouble();

        //увелечение количество символов для экспонициального вывода
        output = QString::number(allNumber, 'g',15);
        ui->answer_field->setText(output);

    }
    if (event->text() == "-" || event->text() == "+" || event->text() == "/" ||
        event->text() == "*")
    {

        choice_math_operation(event->text());

    }
    if (event->key() == Qt::Key_Escape){
        on_pushButton_Zero_clicked();
    }
    if (event->key() == Qt::Key_Backspace){

        QString str = ui->answer_field->text();
        str.chop(1);
        ui->answer_field->setText(str);
        m_output->chopOutPutStatusBar(1);
        m_output->getHistoryStatusBar();

    }

    if(event->text() == "=" || event->key() == Qt::Key_Return){
        on_pushButton_equally_clicked();
    }

    if(event->text() == "%"){
        on_pushButton_persent_clicked();
    }

    if (event->text() == "," || event->text() == ".")
    {
        on_pushButton_dot_clicked();
    }
    m_useKeyboard = false;

}
void View::inputStatusbar(const QString &input)
{

    m_output->addHistoryStatusBar(input);
    ui->statusbar->addWidget(m_output->getHistoryStatusBar());
}

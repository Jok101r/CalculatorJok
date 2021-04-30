#include "model.h"

Model::Model()
{

}

double Model::getAnswer()
{
    return m_answer;
}

void Model::setPreviusNumber(double previousNumber)
{
    m_previousNumber = previousNumber;
}

void Model::setNextNumber(double nextNumber)
{
    m_nextNumber = nextNumber;
}

void Model::setOperation(QString operation)
{
    m_operation = operation;
}

void Model::clear()
{
    m_previousNumber = 0.0;
    m_nextNumber = 0.0;
    m_answer = 0.0;
    m_operation = " ";
}

void Model::calculatingValues()
{
    //Решение матемаических операций
    {
        if (m_operation == "/")
        {
            if ( !(m_nextNumber == 0))
                m_answer = m_previousNumber / m_nextNumber;
            else {
                clear();
                //вывод ошибки на экран;
            }
        }
        if (m_operation == "*" )
        {
            m_answer = m_previousNumber * m_nextNumber;
        }
        if (m_operation == "-" )
        {
            m_answer = m_previousNumber - m_nextNumber;
        }
        if (m_operation == "+" )
        {
            m_answer = m_previousNumber + m_nextNumber;
        }
    }
}

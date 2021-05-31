#include "model.h"

Model::Model()
{

}

double Model::getAnswer()
{
    return m_answer;
}

void Model::setFirstArgument(double firstArgument)
{
    m_firstArgument = firstArgument;
}

void Model::setSecondArgument(double secondArgument)
{
    m_secondArgument = secondArgument;
}

void Model::setOperation(Operation operation)
{
    assert(operation != Operation::No);
    m_operation = operation;
}

Model::Operation Model::getOperation()
{
    return m_operation;
}


void Model::clear()
{
    m_firstArgument = 0.0;
    m_secondArgument = 0.0;
    m_answer = 0.0;
    m_operation = Operation::No;

}

void Model::calculatingValues()
{
    //Решение матемаических операций
    switch (m_operation)
    {
        case Operation::No:
        {

            throw std::runtime_error("Operation not found!");
        }; break;

        case Operation::Minus:
        {
            m_answer = m_firstArgument - m_secondArgument;

        }; break;

        case Operation::Plus:
        {
            m_answer = m_firstArgument + m_secondArgument;

        }; break;

        case Operation::Divide:
        {
            if ( m_secondArgument == 0 )
            {
                throw std::runtime_error("You cannot divide by zero!");
            }
            m_answer = m_firstArgument / m_secondArgument;

        }; break;

        case Operation::Multiply:
        {
            m_answer = m_firstArgument * m_secondArgument;

        }; break;
    }

}

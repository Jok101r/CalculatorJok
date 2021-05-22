#include "calculator.h"


Calculator::Calculator()
    :m_view(m_model)
{

}

void Calculator::start()
{
    m_view.show();
}

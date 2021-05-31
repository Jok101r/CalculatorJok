#include "output.h"

OutPut::OutPut()
{

}

QLabel *OutPut::getHistoryStatusBar() const
{
    m_labelStatusBar->setText(m_outStatus.arg(m_historyStatusBar));
    return m_labelStatusBar;
}

void OutPut::addHistoryStatusBar(const QString &input)
{

    if (m_historyStatusBar.length() > 0)
    {
        QChar index = m_historyStatusBar[m_historyStatusBar.length()-1];

        //уаделние повторяющих или заменяемых знаков
        if(index == "/" || index == "*" || index == "+" || index == "-")
        {
            if (input == "/" || input == "*" || input == "+" || input == "-")
            {
                m_historyStatusBar.chop(1);
            }
        }
    }

    m_historyStatusBar.push_back(input);

}

void OutPut::historyStatusBarClear()
{
    m_historyStatusBar.clear();
}

void OutPut::chopOutPutStatusBar(int index)
{
    m_historyStatusBar.chop(index);
}

#pragma once

#include <QString>
#include <QLabel>
#include <QDebug>

class OutPut
{
public:
    OutPut();

    QLabel *getHistoryStatusBar() const;
    void addHistoryStatusBar(const QString &);
    void historyStatusBarClear();
    void chopOutPutStatusBar(int );

private:

    QString m_historyStatusBar = "";
    QString m_outStatus = "History: %1";
    QLabel *m_labelStatusBar = new QLabel;
};


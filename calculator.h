#pragma once

#include "model.h"
#include "view.h"

class Calculator
{
public:
    Calculator();

    void start();

private:
    Model m_model;
    View m_view;
};



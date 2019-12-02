#include <Arduino.h>

#include "potentiometer.h"

void Pot::potSetup()
{
    pinMode(m_pin, INPUT);
    m_currPotValue = analogRead(m_pin);
    m_lastPotValue = m_currPotValue;
}

int Pot::getPotValue()
{
    return m_currPotValue;
}

bool Pot::potTurned()
{
    m_currPotValue = analogRead(m_pin);

    if ((m_currPotValue > m_lastPotValue) || (m_currPotValue < m_lastPotValue))
    {
        m_lastPotValue = m_currPotValue;
        return true;
    }
    else
    {
        m_lastPotValue = m_currPotValue;
        return false;
    }
}
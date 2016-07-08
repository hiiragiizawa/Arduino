#include "Delay.h"

void Delay::setDelay(unsigned int t)
{
    m_timeout = millis() + t;
}

bool Delay::timeout()
{
    return (m_timeout < millis());
}

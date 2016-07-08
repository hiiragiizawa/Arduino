#ifndef Delay_h
#define Delay_h

#include <Arduino.h>

class Delay {
    public:
        void setDelay(unsigned int t);
        bool timeout();

    private:
        unsigned long m_timeout = 0;
};
#endif

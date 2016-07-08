#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <Delay.h>

class LED{
    public:
        LED(uint8_t ledPin);
	    bool getState();
        void on();
        void on(int);
        void off();
	    void off(int);
	    void toggle(int);
        void blink(int);
	    void blink(int, byte);
        void update();

    private:
        uint8_t pin;
        byte m_blinkCount = 0;
        unsigned int m_blinkInterval = 1000;
        Delay m_delay;
};

#endif

#include "LED.h"

LED::LED(uint8_t ledPin)
{
	pin = ledPin;
	pinMode(pin, OUTPUT);
}

bool LED::getState()
{
	return digitalRead(pin) == HIGH;
}
void LED::on()
{
	digitalWrite(pin, HIGH);
}
void LED::on(int time)
{
	on();
	if (time > 0) {
		Serial.print("On for ");
		Serial.print(time);
		Serial.println("ms");
		m_delay.setDelay(time);
	}
}
void LED::off()
{
	digitalWrite(pin, LOW);
}

void LED::off(int time)
{
	off();
	if (time > 0) {
		Serial.print("Off for ");
		Serial.print(time);
		Serial.println("ms");
		m_delay.setDelay(time);
	}
}

void LED::toggle(int time = 0)
{
	getState() ? off(time) : on(time);
}

void LED::blink(int time)
{
	blink(time, 1);
}

void LED::blink(int time, byte times)
{
	m_blinkInterval = time / 2;
	m_blinkCount = times;
}

void LED::update()
{
	if (m_delay.timeout())
	{
		if (m_blinkCount > 0)
		{
			toggle(m_blinkInterval);
			if (!getState())
			{
				m_blinkCount--;
			}
		} else {
			off();
		}
	}
}

#include <LED.h>

LED led = LED(3); // Connect your led between pin 3 and GND

void setup()
{

}

void loop()
{
    led.blink(1000);

    led.update();
}

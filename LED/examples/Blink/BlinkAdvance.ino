#include <LED.h>
#include <Delay.h>

LED led = LED(3);
Delay m_delay;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (m_delay.timeout())
  {
    Serial.println("wait for 2.5 seconds timeout");
    led.blink(600, 2); // blink twice
    m_delay.setDelay(2500);
  }
  
  led.update();
}

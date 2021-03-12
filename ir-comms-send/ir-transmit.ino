#include <IRremote.h>

IRsend irsend;

const uint8_t LED_PIN = 3; // Predefined by IRsend, cannot change?
const uint8_t MAGIC_VALUE = 37;
void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(4800);
}

void loop() {
    Serial.println("Sending signal");
    irsend.sendNEC(0x000025, 32);
    delay(2000);
}
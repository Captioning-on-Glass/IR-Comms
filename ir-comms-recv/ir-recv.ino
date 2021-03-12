#include <IRremote.h>

const uint8_t RECEIVER_PIN = 7;
IRrecv irrecv(RECEIVER_PIN);
decode_results results;

void setup()
{
    pinMode(RECEIVER_PIN, INPUT);
    SerialUSB.begin(9600);
    SerialUSB.println("Is this thing on?");
    irrecv.enableIRIn();
}

void loop()
{
    // SerialUSB.println("Loop running");
    if (irrecv.decode(&results))
    {
        SerialUSB.print("Received a value!! It is ");
        SerialUSB.println(results.value, HEX);
        irrecv.resume();
        delay(150);
    }
}
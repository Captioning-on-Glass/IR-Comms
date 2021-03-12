// #include <IRremote.h>

// const uint8_t RECEIVER_PIN = 7;
// IRrecv irrecv(RECEIVER_PIN);
// decode_results results;

void setup()
{
    // pinMode(RECEIVER_PIN, INPUT);
    Serial.begin(9600);
    Serial.println("Is this thing on?");
    // irrecv.enableIRIn();
}

void loop()
{
    Serial.println("Loop running");
    // if (irrecv.decode(&results))
    // {
    //     Serial.print("Received a value!! It is ");
    //     Serial.println(results.value, HEX);
    //     irrecv.resume();
    //     delay(150);
    // }
}
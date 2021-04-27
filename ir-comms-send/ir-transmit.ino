#include <IRremote.h>

// On the Zero and others we switch explicitly to SerialUSB
#if defined(ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif

#define IR_SEND_PIN A2
#define ADDRESS 0x0
#define COMMAND 0x40
#define REPEATS 0

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    /*
     * The IR library setup. That's all!
     */
    IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}

void loop()
{
    /*
     * Print current send values
     */
    Serial.println();
    Serial.print(F("Send now: address=0x"));
    Serial.print(ADDRESS, HEX);
    Serial.print(F(" command=0x"));
    Serial.print(COMMAND, HEX);
    Serial.print(F(" repeats="));
    Serial.print(REPEATS);
    Serial.println();

    Serial.println(F("Send NEC with 16 bit address"));
    Serial.flush();

    // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(ADDRESS, COMMAND, REPEATS);

    delay(1000); // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}

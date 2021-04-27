#include "JurorBuffer.hpp"
#define JUROR_A_SECONDARY_PIN 2
#define JUROR_B_SECONDARY_PIN 3
#define JUROR_C_SECONDARY_PIN 4
#define JURY_FOREMAN_SECONDARY_PIN 6

JurorBuffer buffer;
void setup()
{
    pinMode(JUROR_A_SECONDARY_PIN, INPUT);
    pinMode(JUROR_B_SECONDARY_PIN, INPUT);
    pinMode(JUROR_C_SECONDARY_PIN, INPUT);
    pinMode(JURY_FOREMAN_SECONDARY_PIN, INPUT);
    Serial.begin(9600);
    buffer = JurorBuffer();
}

void loop()
{
    auto jurorAResult = digitalRead(JUROR_A_SECONDARY_PIN);
    auto jurorBResult = digitalRead(JUROR_B_SECONDARY_PIN);
    auto jurorCResult = digitalRead(JUROR_C_SECONDARY_PIN);
    auto juryForemanResult = digitalRead(JURY_FOREMAN_SECONDARY_PIN);
    if (jurorAResult || jurorBResult || jurorCResult || juryForemanResult)
    {
        if (jurorAResult == HIGH)
        {
            buffer.add(JUROR_A_VALUE);
            // Serial.println(JUROR_A_VALUE);
        }
        if (jurorBResult == HIGH)
        {
            buffer.add(JUROR_B_VALUE);
            // Serial.println(JUROR_B_VALUE);
        }

        if (jurorCResult == HIGH)
        {
            buffer.add(JUROR_C_VALUE);
            // Serial.println(JUROR_C_VALUE);
        }

        if (juryForemanResult == HIGH)
        {
            buffer.add(JURY_FOREMAN_VALUE);
            // Serial.println(JURY_FOREMAN_VALUE);
        }
    }
    else
    {
        buffer.add(NO_SIGNAL);
        // Serial.println("X");
    }
    if (buffer.is_full()) {
        if (buffer.mode() == NO_SIGNAL) {
            Serial.println("X");
        } else {
            Serial.println(buffer.mode());
        }
        buffer.clear();
        Serial.flush();
    }
    delay(5);
}

void printBuffer(JurorBuffer buffer) {
    Serial.print("[");
    for (auto i = 0; i < buffer.BUFFER_SIZE; ++i) {
        Serial.print(buffer.buf[i]);
        if (i < buffer.BUFFER_SIZE - 1) {
        Serial.print(", ");
        }
    }
    Serial.println("]");
}
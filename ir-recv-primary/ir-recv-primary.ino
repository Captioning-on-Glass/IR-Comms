#define JUROR_A_SECONDARY_PIN 2
#define JUROR_B_SECONDARY_PIN 3
#define JUROR_C_SECONDARY_PIN 4
#define JURY_FOREMAN_SECONDARY_PIN 6

void setup()
{
    pinMode(JUROR_A_SECONDARY_PIN, INPUT);
    // pinMode(JUROR_B_SECONDARY_PIN, INPUT);
    // pinMode(JUROR_C_SECONDARY_PIN, INPUT);
    pinMode(JURY_FOREMAN_SECONDARY_PIN, INPUT);
    Serial.begin(9600);
}

void loop()
{
    auto jurorAResult = digitalRead(JUROR_A_SECONDARY_PIN);
    if (jurorAResult == HIGH)
    {
        Serial.println(0);
    }
    // auto jurorBResult = digitalRead(JUROR_B_SECONDARY_PIN);
    // if (jurorBResult == HIGH) {
    //     Serial.println(1);
    // }
    // auto jurorCResult = digitalRead(JUROR_C_SECONDARY_PIN);
    // if (jurorCResult == HIGH) {
    //     Serial.println(2);
    // }
    // auto juryForemanResult = digitalRead(JURY_FOREMAN_SECONDARY_PIN);
    // if (juryForemanResult == HIGH) {
    //     Serial.println(3);
    // }
    // delay(100);
}
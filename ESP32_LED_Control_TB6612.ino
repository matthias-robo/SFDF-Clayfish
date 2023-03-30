const uint8_t AIN1 = 33;
const uint8_t AIN2 = 32;
const uint8_t BIN1 = 25;
const uint8_t BIN2 = 26;

int led_stat = 0;
long led_prev_mills = 0;

void setup ()
{
    Serial.begin (9600);

    pinMode (AIN1, OUTPUT);
    pinMode (AIN2, OUTPUT);
    pinMode (BIN1, OUTPUT);
    pinMode (BIN2, OUTPUT);
}

void loop ()
{
    digitalWrite (AIN1, LOW);
    digitalWrite (AIN2, HIGH);
}
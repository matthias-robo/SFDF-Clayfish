# 1 "c:\\Users\\Graphite Venture\\Documents\\SFDF-Clayfish\\ESP32_LED_Control_TB6612.ino"
const uint8_t AIN1 = 33;
const uint8_t AIN2 = 32;
const uint8_t BIN1 = 25;
const uint8_t BIN2 = 26;

int led_stat = 0;
long led_prev_mills = 0;

void setup ()
{
    Serial.begin (9600);

    pinMode (AIN1, 0x02);
    pinMode (AIN2, 0x02);
    pinMode (BIN1, 0x02);
    pinMode (BIN2, 0x02);

    // Initialize LED
    led_changestat ('r');
    delay (500);
    led_changestat ('y');
    delay (500);
    led_changestat ('g');
    delay (500);
    led_changestat ('o');
    delay (500);
}

void loop ()
{
    led_blink ('r', 500);
}

void led_changestat (char led_color)
{
    // Set switch case for LED status
    // led_stat : 0 = Off; 1 = Red; 2 = Yellow; 3 = Green
    switch (led_color)
    {
        case 'o':
        digitalWrite (AIN1, !0x1);
        digitalWrite (AIN2, !0x1);
        digitalWrite (BIN1, !0x1);
        digitalWrite (BIN2, !0x1);
        led_stat = 0;
        break;

        case 'r':
        digitalWrite (AIN1, 0x1);
        digitalWrite (AIN2, !0x1);
        digitalWrite (BIN1, !0x1);
        digitalWrite (BIN2, !0x1);
        led_stat = 1;
        break;

        case 'y':
        digitalWrite (AIN1, !0x1);
        digitalWrite (AIN2, 0x1);
        digitalWrite (BIN1, !0x1);
        digitalWrite (BIN2, !0x1);
        led_stat = 2;
        break;

        case 'g':
        digitalWrite (AIN1, !0x1);
        digitalWrite (AIN2, !0x1);
        digitalWrite (BIN1, 0x1);
        digitalWrite (BIN2, !0x1);
        led_stat = 3;
        break;
    }
}

int led_blink (char led_color, long interval_time)
{
    unsigned long cur_millis = millis();

    if (cur_millis - led_prev_mills > interval_time)
    {
       led_prev_mills = cur_millis;

       if (led_stat == 0 || led_stat == 99)
       {
            led_changestat (led_color);
       }
       else
       {
           led_changestat ('o');
       }
    }
}

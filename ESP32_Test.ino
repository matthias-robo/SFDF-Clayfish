#include <ModbusMaster.h>

#define RXD2 16
#define TXD2 17

ModbusMaster node1;
ModbusMaster node2;
ModbusMaster node3;

void setup ()
{
    Serial.begin (9600);
    Serial2.begin (9600, SERIAL_8N1, RXD2, TXD2);

    node1.begin (1, Serial2);
    node2.begin (2, Serial2);
    node3.begin (3, Serial2);
}

void loop ()
{
    
}

// read electrical conductivity from EC sensor; Address: 0x01; return as double in unit uS/cm
double read_ec ()
{
    double value_ec;
    uint16_t result = node1.readHoldingRegisters (0x00, 0x01);
    if (result == node1.ku8MBSuccess)
    {
        value_ec = double(node2.getResponseBuffer(0))/100;
    }

    return value_ec;
}

// read pH value from pH sensor; Address: 0x02; return as double
double read_ph ()
{
    double value_ph;
    uint16_t result = node2.readHoldingRegisters (0x00, 0x01);
    if (result == node2.ku8MBSuccess)
    {
        value_ph = double(node2.getResponseBuffer(0))/100;
    }

    return value_ph;
}

// read Disolved Oxygen value from DO sensor; Address: 0x03; return as double in unit mg/L
double read_do ()
{
    double value_do;
    uint16_t result = node3.readHoldingRegisters (0x30, 0x01);
    if (result == node3.ku8MBSuccess)
    {
        value_do = double(node3.getResponseBuffer(0))/100;
    }

    return value_do;
}

// read temperature from DO sensor; Address: 0x03; return double in °C
double read_temp ()
{
    double value_temp;
    uint16_t result = node3.readHoldingRegisters (0x30, 0x01);
    if (result == node3.ku8MBSuccess)
    {
        value_temp = double(node3.getResponseBuffer(0))/100;
    }

    return value_temp;
}


#include <IRremote.h>

int irPort = 9;

IRrecv irrecv(irPort);

decode_results results;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop()
{
    if (irrecv.decode())
    {
        // Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
        move();

        irrecv.resume();
    }
}

void move()
{
    long int hexDataButton = irrecv.decodedIRData.decodedRawData;

    if (hexDataButton == 0x2ED100FF)
        Serial.println("Up");
    if (hexDataButton == 0x2CD300FF)
        Serial.println("Left");
    if (hexDataButton == 0x2BD400FF)
        Serial.println("Right");
    if (hexDataButton == 0x2DD200FF)
        Serial.println("Down");

    if (hexDataButton == 0x55AA00FF)
        Serial.println("A");
    if (hexDataButton == 0x54D400FF)
        Serial.println("B");
    if (hexDataButton == 0x53AC00FF)
        Serial.println("C");
    if (hexDataButton == 0x52AD00FF)
        Serial.println("D");
}

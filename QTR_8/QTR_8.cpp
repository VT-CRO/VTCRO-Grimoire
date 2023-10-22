#include "QTR_8.h"


typedef struct
{
  uint16_t pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8;
  uint16_t* data;
} QTR_t;

int s0 = A0;
int s1 = A1;
int s2 = A2;
int s3 = A3;
int s4 = A4;
int s5 = A5;
int s6 = A6;
int s7 = A7;
uint16_t readings[8];
QTR_t data{};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  data = QTR_init(s0, s1, s2, s3, s4, s5, s6, s7, readings);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  data.data[0] = analogRead(data.pin1);
  data.data[1] = analogRead(data.pin2);
  data.data[2] = analogRead(data.pin3);
  data.data[3] = analogRead(data.pin4);
  data.data[4] = analogRead(data.pin5);
  data.data[5] = analogRead(data.pin6);
  data.data[6] = analogRead(data.pin7);
  data.data[7] = analogRead(data.pin8);
/*
  readings[0] = analogRead(s0);
  readings[1] = analogRead(s1);
  readings[2] = analogRead(s2);
  readings[3] = analogRead(s3);
  readings[4] = analogRead(s4);
  readings[5] = analogRead(s5);
  readings[6] = analogRead(s6);
  readings[7] = analogRead(s7);
*/
  for (uint8_t i = 0; i < 8; i++)
  {
    Serial.print("Value at ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(data.data[i]);
    
  }

  data.data[0] = changeBit(data.data[0]);
  data.data[1] = changeBit(data.data[1]);
  data.data[2] = changeBit(data.data[2]);
  data.data[3] = changeBit(data.data[3]);
  data.data[4] = changeBit(data.data[4]);
  data.data[5] = changeBit(data.data[5]);
  data.data[6] = changeBit(data.data[6]);
  data.data[7] = changeBit(data.data[7]);

/*
  readings[0] = changeBit(readings[0]);
  readings[1] = changeBit(readings[1]);
  readings[2] = changeBit(readings[2]);
  readings[3] = changeBit(readings[3]);
  readings[4] = changeBit(readings[4]);
  readings[5] = changeBit(readings[5]);
  readings[6] = changeBit(readings[6]);
  readings[7] = changeBit(readings[7]);
*/
  for (uint8_t j = 0; j < 8; j++)
  {
    Serial.print("Value at ");
    Serial.print(j);
    Serial.print(": ");
    Serial.println(data.data[j]);
    
  }
  
  delay(1000);
}


QTR_t QTR_init(uint16_t pin1, uint16_t pin2, uint16_t pin3, uint16_t pin4, uint16_t pin5, uint16_t pin6, uint16_t pin7, uint16_t pin8, uint16_t data[])
{
   QTR_t values = {pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, data};
   return values;
}

int changeBit (int initialVal)
{
    int changedBit = -1;

    if (initialVal >= 7)
    {
        changedBit = 1;
    }
    else
    {
        changedBit = 0;
    }

    return changedBit;
}

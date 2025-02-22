#include "SparkBot.h"
#include "BluetoothSerial.h"

int sparkSpeed=255;

BluetoothSerial SerialBT;


SparkBot::SparkBot()
{
}

void SparkBot::begin()
{
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

double SparkBot::getDistance()
{
  double mesafe;
  double sure;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  sure = pulseIn(ECHO, HIGH);
  mesafe = sure * 0.0343 / 2;
  return mesafe;
}

void SparkBot::forward(){
  digitalWrite(M1A,0);
  digitalWrite(M1B,sparkSpeed);

  digitalWrite(M2A,sparkSpeed);
  digitalWrite(M2B,0);
}

void SparkBot::backward(){
  digitalWrite(M1A,sparkSpeed);
  digitalWrite(M1B,0);

  digitalWrite(M2A,0);
  digitalWrite(M2B,sparkSpeed);
}

void SparkBot::right(){
  digitalWrite(M1A,sparkSpeed);
  digitalWrite(M1B,0);

  digitalWrite(M2A,sparkSpeed);
  digitalWrite(M2B,0);
}

void SparkBot::left(){
  digitalWrite(M1A,0);
  digitalWrite(M1B,sparkSpeed);

  digitalWrite(M2A,0);
  digitalWrite(M2B,sparkSpeed);
}

void SparkBot::stop(){
  digitalWrite(M1A,0);
  digitalWrite(M1B,0);

  digitalWrite(M2A,0);
  digitalWrite(M2B,0);
}

void SparkBot::setSpeed(int speed){
  sparkSpeed=speed;
}

void SparkBot::beginBT(String device_name,int PIN){
  SerialBT.begin(device_name);
}

char SparkBot::readBTChar(){
  if (SerialBT.available()) {
    return SerialBT.read();
  }
}

String SparkBot::readBT(){
  String data="";
  while (SerialBT.available()) {
    char a= SerialBT.read();
    data+=a;
  }
  return data;
}
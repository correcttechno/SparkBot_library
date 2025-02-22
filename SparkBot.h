#define M1A 25
#define M1B 26

#define M2A 27
#define M2B 14

#define TRIG 16
#define ECHO 4

#include "Arduino.h"
#include "BluetoothSerial.h"
class SparkBot
{

public:
  SparkBot();
  void begin();
  double getDistance();
  void forward();
  void backward();
  void left();
  void right();
  void stop();
  void setSpeed(int speed);
  void beginBT(String device_name,int PIN=1234);
  char readBTChar();
  String readBT();
private:
  
};

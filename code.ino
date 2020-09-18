#include <Servo.h>

Servo frontKnee;
Servo frontHip;
Servo rearKnee;
Servo rearHip;

int throttle;
int mode;


void setup() 
{
  Serial.begin(9600);
  
  frontKnee.attach(8);
  
  frontHip.attach(9);
  
  rearKnee.attach(10);
  
  rearHip.attach(11);
  
  pinMode(2, INPUT);

  pinMode(4, INPUT);

  write(180, 50, frontKnee);

  write(90, 50, rearKnee);
  
  delay(2000);
}

void loop() 
{
  throttle = direction(pulseIn(2, HIGH, 20000));
  mode = pulseIn(4, HIGH, 25000);
  Serial.println(mode);
  delay(10); 
}

//converts pulse to a number 0-2

int direction(int stick)
{
  if (stick > 1600)
  {
    return 2;
  }
  else if (stick < 1200)
  {
    return 0;
  }
  return 1;
}

//method to vary servo speed

void write(int pos, int speed, Servo s)
{
  if ((s.read() - pos) > 0)
  {
    for (int i = s.read(); i >= pos; i--)
    {
      s.write(i);
      delay(speed);
    }
  }
  else 
  {
    for (int i = s.read(); i <= pos; i++)
    {
      s.write(i);
      delay(speed);
    }
  }
}



void walkFoward()
{
  
}


#include <Servo.h>
//define two servomotors horizontal and vertical
Servo servohori;
int servoh = 60;
int servohLimitHigh = 120;
int servohLimitLow = 60;

Servo servoverti; 
int servov = 0; 
int servovLimitHigh = 30;
int servovLimitLow = 0;

//Pin declaration
int ldrtopl = A2; //top left 
int ldrtopr = A1; //top right 
int ldrbotl = A3; // bottom left 
int ldrbotr = A0; // bottom right 

 void setup () 
 {
  servohori.attach(10);
  servohori.write(60);
  servoverti.attach(9);
  servoverti.write(0);
  Serial.begin(9600);
  delay(500);
 }
 
void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  //Analog value of the photoresistor
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  //Let's calculate an average 
  int avgtop = (topl + topr) ; //average of top 
  int avgbot = (botl + botr) ; //average of bottom 
  int avgleft = (topl + botl) ; //average of left 
  int avgright = (topr + botr) ; //average of right 

  if (avgtop < avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(10);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh -1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh +1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(10);
  }
  else 
  {
    servohori.write(servoh);
  }
  delay(50);
}

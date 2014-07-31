#include <Servo.h>
Servo myservo;  

#define ServoM    12        
#define Bright    11       
#define Exit      9         
#define In        8         

#define BarLow    177       
#define BarUp     95        
#define CAPACITY  9         
#define INTEN     80        

#define  segA  0
#define  segB  1
#define  segC  2
#define  segD  3
#define  segE  4
#define  segF  5
#define  segG  6

byte segments[10] = {

B1111110,B0110000,B1101101,B1111001,B0110011,B1011011,B1011111,B1110000,B1111111,B1111011

};

void setup(){
  myservo.attach(ServoM);          
  pinMode(Exit, INPUT);           
  pinMode(In, INPUT);             
  digitalWrite(Exit, HIGH);       
  digitalWrite(In, HIGH);         
  pinMode(segA,OUTPUT);
  pinMode(segB,OUTPUT);
  pinMode(segC,OUTPUT);
  pinMode(segD,OUTPUT);
  pinMode(segE,OUTPUT);
  pinMode(segF,OUTPUT);
  pinMode(segG,OUTPUT);
  pinMode(Bright,OUTPUT);
  analogWrite(Bright,255*INTEN/100);

  myservo.write(BarLow);         

}
int  Available= 9;                    

void loop(){
Display(Available);
if(digitalRead(In)==0)
{
  if(Available > 0 && Available < 10){
    Available--;
    myservo.write(BarLow);
    delay(3000);
    myservo.write( BarUp);
    }
  }
if(digitalRead(Exit)==0)
{
  if(Available != CAPACITY){
    Available++;
    myservo.write(BarLow);
    delay(3000);
    myservo.write(BarUp);
    }
  }
}
void Display(int number){
byte segs =  ~segments[number];      
digitalWrite(segA, bitRead(segs, 0) );
digitalWrite(segB, bitRead(segs, 1) );
digitalWrite(segC, bitRead(segs, 2) );
digitalWrite(segD, bitRead(segs, 3) );
digitalWrite(segE, bitRead(segs, 4) );
digitalWrite(segF, bitRead(segs, 5) );
digitalWrite(segG, bitRead(segs, 6) );
}

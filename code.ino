//embedded final code




#include <Servo.h>
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0;    
 
void setup() 
{ Serial.begin(9600);
  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
  servo_test.write(0);
  
} 
  
void loop() 
{ 
 int data=Serial.read();
 int t=switch_com(data);

}
int switch_com(int data)
{
  switch(data)
 {
  case '1': rotate_left(); break; 
  case '2': rotate_right(); break;
  case '3': servo_test.detach(); return 1; break; 
  case '4': servo_test.attach(9); break;
 }
 return 0;
}
void rotate_left()
{
  servo_test.attach(9);
for(;angle <= 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    int data=Serial.read();
    int t=switch_com(data);
    if(t==1)
    break;
    delay(60);                       
  } 

  
}
void rotate_right()
{
  servo_test.attach(9);
for(; angle>=1; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    int data=Serial.read();
    int t=switch_com(data);
    if(t==1)
    break;
    delay(60);                       
  } 
 
}

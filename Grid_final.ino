#include <Servo.h>
Servo servoLeft; // Declare left and right servos
Servo servoRight; 
int k = 0;
int flag = 0;
void confusion(int i);

void setup() // Built-in initialization block
{
Serial.begin(9600); //Enable serial communication
servoLeft.attach(13); // Attach left signal to pin 13
servoRight.attach(12); // Attach right signal to pin 12
//servoLeft.writeMicroseconds(1550); // limit speed (Full speed forward use 1700)
//servoRight.writeMicroseconds(1450); //Full speed forward use 1300
}

void loop() // Main loop auto-repeats0
{
int a[7] = {2,1,2,0,2,1,3}; //0-Right, 1-Left, 2- Forward, 3-stop
//For exam Just change above junction points

Serial.print("A2 = "); // Display "A2 = "
Serial.print(ERight(A2)); // Display measured A2 volts
Serial.println("ERight"); // Display " Voltage of ERight sensor" & add newline

Serial.print("A3 = "); // Display "A3 = "
Serial.print(Left(A0)); // Display measured A3 volts
Serial.println("Left"); // Display " Voltage of Left sensor" & add newline

Serial.print("A4 = "); // Display "A4 = "
Serial.print(ELeft(A1)); // Display measured A4 volts
Serial.println("ELeft"); // Display " Voltage of ELeft sensor" & add newline

Serial.print("A5 = "); // Display "A5 = "
Serial.print(Right(A2)); // Display measured A5 volts
Serial.println("Right"); // Display " Voltage of Right sensor" & add newline
//delay(1000);  // only add if u want to check voltage

//For Left Sensor A3
if (Left(A3) < 1.5) //Left Led On/Off
{
left();
}

  //For Right Sensor A5
if(Right(A5) < 1.5) // If Right sensor detected then turn Right
{
right();
}

//GRID

if(ERight(A2) < 1.5 && Left(A3) < 1.5 && Right(A5) < 1.5 && ELeft(A4) < 1.5){  //If all 3 sensors detected black
  if(flag == 0){
confusion(a[k]);
Serial.print("Command = "); 
Serial.print(a[k] );
k++;
flag =1;}
}

else if(ERight(A2) > 1.5 && Left(A3) < 1.5 && Right(A5) > 1.5) //Turn left
{
left();
}

else if(Left(A3) > 1.5 && Right(A5) < 1.5 && ELeft(A4) > 1.5) //Turn right
{
right();
    
}

else if((ERight(A2) > 1.5 && Left(A3) > 1.5 && Right(A5) > 1.5 && ELeft(A4) > 1.5)) //Move Forward
{
forward();
    if (flag == 1)
      flag = 0;
}
}

void confusion(int i){  //Program for Grid
if((ERight(A2) < 1.5 && Left(A3) < 1.5 && Right(A5) < 1.5 && ELeft(A4) < 1.5 && (i == 0)))
{
  forward();
  delay(500);
right90();
delay(1000);
}
//else if(ERight(A2) < 1.5 && Left(A3) > 1.5 && Right(A5) < 1.5 && ELeft(A4) > 1.5 && (i=0)) //Turn right
//{
//  //forward();
//  //delay(500);
//right90();
//delay(3000);
//}

if((ERight(A2) < 1.5 && Left(A3) < 1.5 && Right(A5) < 1.5 && ELeft(A4) < 1.5 && (i == 1)))
{
  forward();
  delay(500);
left90();
delay(1000);
}

//
//else if(ERight(A2) > 1.5 && Left(A3) < 1.5 && Right(A5) > 1.5 && ELeft(A4) < 1.5 && (i == 1)) //Turn left
//{
//  //forward();
//  //delay(500);
//left90();
//delay(3000);
//}

if((ERight(A2) < 1.5 && Left(A3) < 1.5 && Right(A5) < 1.5 && ELeft(A4) < 1.5 && (i == 2)))
{
forward();
}
if((ERight(A2) < 1.5 && Left(A3) < 1.5 && Right(A5) < 1.5 && ELeft(A4) < 1.5 && (i == 3)))
{
stop1();
}
}

void left()
{
  servoLeft.writeMicroseconds(1500); 
    servoRight.writeMicroseconds(1450);

}

void right()
{
  servoLeft.writeMicroseconds(1550); 
    servoRight.writeMicroseconds(1500);
}

void forward()
{
  servoLeft.writeMicroseconds(1550); // Full speed forward 1700
  servoRight.writeMicroseconds(1450); //1300
}

void left90()
{

      servoLeft.writeMicroseconds(1450); 
    servoRight.writeMicroseconds(1450);
}

void right90()
{
  
  servoLeft.writeMicroseconds(1550); 
    servoRight.writeMicroseconds(1550);
}

void stop1()
{
servoLeft.detach(); // Stop servo signals
servoRight.detach();
}

float ERight(int A2) // Measures volts at adPin
{ // Returns floating point voltage
return float(analogRead(A0)) * 5.0 / 1024.0;
}

float Left(int A0) // Measures volts at adPin
{ // Returns floating point voltage
return float(analogRead(A0)) * 5.0 / 1024.0;
}

float ELeft(int A1) // Measures volts at adPin
{ // Returns floating point voltage
return float(analogRead(A1)) * 5.0 / 1024.0;
}

float Right(int A2) // Measures volts at adPin
{ // Returns floating point voltage
return float(analogRead(A2)) * 5.0 / 1024.0;
}

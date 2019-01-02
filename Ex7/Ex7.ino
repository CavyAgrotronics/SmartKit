/* Example code for SmartKit V0.01
 *  Ex:5
  This example demonstrates the use of GetFloatValue().
          Connections....
             Arduino                        SmartKit
              pin 13                          rst
              pin 10                          tx
              pin 11                          rx
               +5 v                           vcc
                 GND                          GND
                                             

     The Example code is in the public domain.
     Created 1st Aug 2018  by Vilas Khade & Ayush Khade.
   
*/
#include<SmartKit.h>
SmartKit KP;
int rx=10;
int tx=11;
int rst=13;
long int baud=57600;//
float  radius;
void setup() {
             KP.SetPort(rx,tx,rst,baud);//
             KP.LcdClear();
           }

void loop() { 
              radius=KP.GetFloatValue("Enter  radius");
              KP.LcdPrint("Area =" + String(radius*radius*3.14) );
              KP.WaitForKeyNum();//Pause until key is pressed        
             }


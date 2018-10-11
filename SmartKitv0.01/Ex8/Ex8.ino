/* Example code for SmartKit V0.01
 *  Ex:5
  This example demonstrates the use of WaitForKeyNum().
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
int num;
String message;
SmartKit KP;
int rx=10;
int tx=11;
int rst=13;
int smartkit_led;

long int baud=57600;//This is previously defined baud rate of SmartKit v0.01
int val;
void setup() {
               KP.SetPort(rx,tx,rst,baud);//
              }

void loop() {
            num=KP.WaitForKeyNum();
            KP.LcdClear();
            message=" Key "+String(num)+" pressed";
            KP.LcdPrint(message);
 
            }


/* Example code for SmartKit V0.01
 * Ex:4
  This example demonstrates the use of AnalogRead().It reads a analog voltage on pin A0  and prints the results to the serial monitor.
  The brightness of LED on pin D0 is controlled with potentiometer.

  The circuit:
* LED on pin 0

 With   PinMode(Read_Pin ,INPUT_PULLUP), an internal 20K-ohm resistor is pulled to 5V. This configuration causes the input to
 read HIGH when the switch is open, and LOW when it is closed.
          Connections....
             Arduino                        SmartKit
              pin 13                          rst
              pin 10                          tx
              pin 11                          rx
               +5 v                           vcc
                 GND                          GND
                                              A0-------variable voltage through potentiometer
                                              D0-------to Anode of LED in series with 470 OHM  resistor and GND

 The Example code is in the public domain.
     Created 1st Aug 2018  by Vilas Khade & Ayush Khade.
   
    */
//----------------------------------------------------------- -(Start )------------------------------------------------------------------------------ -------


#include<SmartKit.h>
   SmartKit KP;//creates a variable of type SmartKit
    int Read_Pin = A0;
    int LED=0;//digital PWM pin
    int rx=10;
    int tx=11;
    int rst=13;
    long int baud=57600;//Baud rate of SmartKit v0.01
    
    
void setup() {  Serial.begin(9600);
                KP.SetPort(rx,tx,rst,baud);//Defines the port for communication with SmartKit
                KP.PinMode(LED, OUTPUT);
              }

void loop() {
             
             int AnalogVal = KP.AnalogRead(Read_Pin );//read the voltage at Pin A0
                              KP.AnalogWrite(LED, AnalogVal);//writes the value to PWM pin D0                                        
                    
                            
                         
                           

              }
    
  


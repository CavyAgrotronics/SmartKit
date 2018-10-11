/* Example code for SmartKit V0.01
/* Ex:3
  This example shows how to fade an LED using the AnalogWrite() function.
 * LED on pin 0

 With   PinMode(Read_Pin ,INPUT_PULLUP), an internal 20K-ohm resistor is pulled to 5V. This configuration causes the input to
 read HIGH when the switch is open, and LOW when it is closed.
          Connections....
           Arduino                        SmartKit
              pin 13                          rst
              pin 10                          tx
              pin 11                          rx
                 +5 v                         vcc
                 GND                         GND
                                              D0-------to Anode of LED in series with 470 OHM  resistor and GND
                                            
    
     The Example code is in the public domain.
     Created 1st Aug 2018  by Vilas Khade & Ayush Khade.
   
    */
    
    
    #include<SmartKit.h>
    String name;
    SmartKit KP;//creates a variable of type SmartKit
    int LED=0;
    int rx=10;
    int tx=11;
    int rst=13;
    long int baud=57600;//Baud rate of SmartKit v0.01
    void setup() { 
                KP.SetPort(rx,tx,rst,baud);//Defines the port for communication with SmartKit
                 }

    void loop() {
                   // fade in from min to max in increments of 5 points:
                   for (int brightness = 0 ; brightness <= 255; brightness += 5) {
                     KP.AnalogWrite(LED, brightness); 
                     delay(30); 
                     }
                  // fade out from max to min in increments of 5 points:
                   for (int brightness = 255 ; brightness >= 0; brightness -= 5)
                   {
                    KP.AnalogWrite(LED, brightness);
                    delay(50);
                   }
             }
    


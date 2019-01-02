/* Example code for SmartKit V0.01
/* Ex:2
  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a   digital input on pin 4 and prints the 
  results to the serial monitor.

  The circuit:
 * Momentary switch attached from pin 4 to ground
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
                                             D4------to Pushbutton and Ground

    
     The Example code is in the public domain.
     Created 1st Aug 2018  by Vilas Khade & Ayush Khade.
   
    */
    #include<SmartKit.h>
    SmartKit KP;//creates a variable of type SmartKit
    int Read_Pin=4;
    int LED=2;
    int rx=10;
    int tx=11;
    int rst=13;
    long int baud=57600;//Baud rate of SmartKit v0.01
void setup() {  Serial.begin(9600);
               KP.SetPort(rx,tx,rst,baud);//Defines the port for communication with SmartKit
               KP.PinMode(Read_Pin, INPUT_PULLUP);//
               KP.PinMode(LED, OUTPUT);
              }

void loop() {
         
            int sensorVal = KP.DigitalRead(Read_Pin );//read the pushbutton value into a                                                 
                    //variable
            Serial.println(sensorVal); //print out the value of the pushbutton
                         if (sensorVal == HIGH) {
                                  KP.DigitalWrite(LED, LOW);
                                  }
                         else {
                              KP.DigitalWrite(LED, HIGH);
                                        }
              }
    


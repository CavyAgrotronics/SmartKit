    
      /* Example code for SmartKit V0.01
       *  
       *  
       *  
       *  Connections....
           Arduino                        SmartKit
              pin 13                          rst
              pin 10                          tx
              pin 11                          rx
                 +5 v                         vcc
                 GND                         GND
                                              D2-------to Anode of LED in seris with 470 OHM  resistor and GND
      
     The Example code is in the public domain.
     Created 1st Aug 2018  by Vilas Khade.
   
    */
    
    
    #include<SmartKit.h>
    SmartKit KP;//creates a variable of type SmartKit
    int LED=2;
    int rx=10;
    int tx=11;
    int rst=12;
    long int baud=57600;//Baud rate of SmartKit v0.01
    void setup(){ 
                 KP.SetPort(rx,tx,rst,baud);//Defines the port for communication with SmartKit
                 KP.PinMode(LED, OUTPUT);
                 KP.GetString("vilas khade akola");
              }

    void loop(){
                KP.DigitalWrite(LED, HIGH);// turn the LED on (HIGH is the voltage level)
                delay(1000);                       // wait for a second
                KP.DigitalWrite(LED, LOW);//turn the LED off by making the voltage LOW
                delay(1000);                       // wait for a second
         }//End of loop


/* Example code for SmartKit V0.01
 *  Ex:5
  This example demonstrates the use of GetString().
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
    String name;
    SmartKit KP;
    int rx=10;
    int tx=11;
    int rst=13;
    long int baud=57600;//Baud rate of SmartKit v0.01
    void setup(){ 
                 KP.SetPort(rx,tx,rst,baud);//
               }

    void loop(){
                name=KP.GetString("Enter your name please");
                KP.LcdClear();
                KP.LcdPrint("Your name is  " +  name );
                KP.WaitForKeyNum();//Pause until key is pressed        
             }


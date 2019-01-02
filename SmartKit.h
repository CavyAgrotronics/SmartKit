#ifndef SmartKit_h
#define SmartKit_h
#include "Arduino.h"
#if defined(ARDUINO_ARCH_AVR) || defined(ARDUINO_ARCH_ARC32) || (ARDUINO >= 100 && ARDUINO < 10500)
#include <SoftwareSerial.h>
#endif
#include <stdlib.h>

class SmartKit 
{
  public:
   SmartKit();
    
   //------------------------------Functions For GPIO -----------------------
   void PinMode(int Pin,int mode);
   void DigitalWrite(int Pin,bool state);
   void AnalogWrite(int Pin,int value);
    int AnalogRead(int Pin);
    int DigitalRead(int Pin);
   
   //--------------------------Functions For Display------------------------------------
   void LcdBegin(int col,int row);
   void SetCursor(int col ,int row);
   void LcdPrint(String string);
   void LcdPrint(long int value);
   void LcdPrint(int value);
   void LcdPrint(double value);
   void LcdPrint(char c);
   void LcdPrint(float value,int decimal_places);
   void LcdClear();
   void Blink();
   void NoBlink();
   void Cursor();
   void NoCursor();
   //--------------Function to define Arduino Port for  Communication with  SmartKit-----------------------------
   //------------------------------------------------------------------  ----------------------------------------- 
   void SetPort(int r,int t,int rst,long int baud);
   //-----------------------------------------------------------------------------
   //-----------------------------------------------SETTINGS---------------------------------------------------------

   void SetBaud(long int baud);
   
   //--------------------------------------------------------------------------------------------------------------------

   //-----------------------Functions for INPUT from alphanumeric Keypad of SmartKit-------------------------------------
   String GetString();
   String GetString(String prompt);
   long int GetIntValue();
   long int GetIntValue(String prompt);
   double GetFloatValue();
   double GetFloatValue(String prompt);
   int WaitForKeyNum();

   //-------------------------------------------------------------------------
private:

bool user_port_defined=false;
int _r=0;int _t=1; long int _baud=9600;
int readline(int readch, char *buffer, int len)
{
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
      case '\n': 
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;// Ignore new-lines
        break;
      case ('\r'): // Return on CR
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;
        break;
      default:
        if (pos < len-1) {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  // No end of line has been found, so return -1.
  return -1;
}
    
};

//---------------------------------------------------------------------------------------------------------------------------------

SmartKit :: SmartKit(){};//Constructor 
//=================================================================================================================================

long int SmartKit::GetIntValue()             {
	                                             String string;
												 String recd;
												 static char buffer[80];
												 SoftwareSerial port(_r, _t); 
												 port.begin(_baud);
												 port.println("<<GetString()>");
														for (int i=0;i<25;i++)
														{
															while(readline(port.read(), buffer, 80) < 0);
														    recd=buffer;
														 if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){i=26;}
			  	
														}
												string=(recd.substring( (recd.indexOf('<')+1),(recd.indexOf('>'))) );

												return(string.toInt());
												}

//---------------------------------------------------------------------------------------------------------------------------------
long int SmartKit::GetIntValue(String prompt)             {
	                                             String string;
												 String recd;
												 static char buffer[80];
												 SoftwareSerial port(_r, _t); 
												 port.begin(_baud);
												 port.println("<<GetString("+prompt+")>");
														for (int i=0;i<25;i++)
														{
															while(readline(port.read(), buffer, 80) < 0);
														    recd=buffer;
														 if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){i=26;}
			  	
														}
												string=(recd.substring( (recd.indexOf('<')+1),(recd.indexOf('>')) ) );

												return(string.toInt());
												}
//---------------------------------------------------------------------------------------------------------------------------------
  double SmartKit::GetFloatValue()             {
	                                             String string;
												 String recd;
												 static char buffer[80];
												 SoftwareSerial port(_r, _t); 
												 port.begin(_baud);
												 port.println("<<GetString()>");
														for (int i=0;i<25;i++)
														{
															while(readline(port.read(), buffer, 80) < 0);
														    recd=buffer;
														 if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){i=26;}
			  	
														}
												string=(recd.substring( (recd.indexOf('<')+1),(recd.indexOf('>')) ) );

												return(string.toFloat());
												}
//---------------------------------------------------------------------------------------------------------------------------------

double SmartKit::GetFloatValue(String prompt)  {
	                                             String string;
												 String recd;
												 static char buffer[80];
												 SoftwareSerial port(_r, _t); 
												 port.begin(_baud);
												 port.println("<<GetString("+prompt+")>");
														for (int i=0;i<25;i++)
														{
															while(readline(port.read(), buffer, 80) < 0);
														    recd=buffer;
														 if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){i=26;}
			  	
														}
												string=(recd.substring( (recd.indexOf('<')+1),(recd.indexOf('>')) ) );

												return(string.toFloat());
												}


//---------------------------------------------------------------------------------------------------------------------------------

String SmartKit::GetString()    {
	                                String string;
									String recd;
									static char buffer[80];
									SoftwareSerial port(_r, _t); 
									port.begin(_baud);
									
									port.println("<<GetString()>");
										for (int i=0;i<25;i++)
											{
											while(readline(port.read(), buffer, 80) < 0);
											recd=buffer;
											if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){i=26;}
			  	
											}
								    string=(recd.substring((recd.indexOf('<')+1),(recd.indexOf('>')) ) );

								 return(string);
								}
//---------------------------------------------------------------------------------------------------------------------------------

String SmartKit::GetString(String prompt)
								{
									String string;
									String recd;
									static char buffer[80];
									SoftwareSerial port(_r, _t); 
									port.begin(_baud);
									
									port.println("<<GetString("+prompt+")>");
										for (int i=0;i<25;i++)
											{
											while(readline(port.read(), buffer, 80) < 0);
											recd=buffer;
											if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){i=26;}
			  	
											}
								    string=(recd.substring((recd.indexOf('<')+1),(recd.indexOf('>')) ) );

								    return(string);
								}


//-----------------------------------------------------------------------------------------------------------------
void SmartKit::SetPort(int r,int t,int reset,long int baud){
												              _r=r;_t=t;_baud=baud;
                                                              pinMode(reset, OUTPUT);
                                                              digitalWrite(reset,LOW);
                                                              delay(10);
                                                              digitalWrite(reset,HIGH);
                                                              delay(200);
															}
 
 

//------------------------------------------------------------------------------------------------------------------  
void SmartKit::PinMode(int Pin,int mode){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"pinMode("+Pin+","+mode+")>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                        

										}


//--------------------------------------------------------------------------------------------------------------------


void SmartKit::DigitalWrite(int Pin,bool mode){
                                                String recd;
                                                static char buffer[80];
                                                SoftwareSerial port(_r, _t);
                                                port.begin(_baud);
                                                String command="<<";
                                                command=command+"digitalWrite("+Pin+","+mode+")>";
                                                port.println(command);
                                                          for (int i=0;i<25;i++)
														  {
                                                            while(readline(port.read(), buffer, 80) < 0);
                                                             recd=buffer;
                                                             if (recd.endsWith(">Ok!")){i=26;}
			  	
														  }
                                               


											}
//--------------------------------------------------------------------------------------------------------------------

void SmartKit::AnalogWrite(int Pin,int value){
                                                String recd;
                                                static char buffer[80];
                                                SoftwareSerial port(_r, _t);
                                                port.begin(_baud);
                                                String command="<<";
                                                command=command+"analogWrite("+Pin+","+value+")>";
                                                port.println(command);
                                                          for (int i=0;i<25;i++)
														  {
                                                            while(readline(port.read(), buffer, 80) < 0);
                                                             recd=buffer;
                                                             if (recd.endsWith(">Ok!")){i=26;}
			  	
														  }
                                               


											}


//--------------------------------------------------------------------------------------------------------------------

int SmartKit::AnalogRead(int Pin){
                                       String recd;
                                       String value;
                                       int Value;
                                       static char buffer[80];
                                       SoftwareSerial port(_r, _t);
                                       port.begin(_baud);
                                       String command="<<";
                                       command=command+"analogRead("+Pin+")>";
                                       port.println(command);
                                                 for (int i=0;i<25;i++)
												 {
													while(readline(port.read(), buffer, 80) < 0);
													recd=buffer;
													if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){	i=26;}
	                                                                                  
												 }

                                        value=recd.substring( (recd.indexOf('<')+1),(recd.indexOf('>')) );
                                        Value=value.toInt();
                                        return(Value);

									}
//--------------------------------------------------------------------------------------------------------------------

int SmartKit::DigitalRead(int Pin){
                                       String recd;
                                       String value;
                                       int Value;
                                       static char buffer[80];
                                       SoftwareSerial port(_r, _t);
                                       port.begin(_baud);
                                       String command="<<";
                                       command=command+"DigitalRead("+Pin+")>";
                                       port.println(command);
                                                 for (int i=0;i<25;i++)
												 {
													while(readline(port.read(), buffer, 80) < 0);
													recd=buffer;
													if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){	i=26;}
	                                                                                  
												 }

                                        value=recd.substring( (recd.indexOf('<')+1),(recd.indexOf('>')) );
                                        Value=value.toInt();
                                        return(Value);

									}
//--------------------------------------------------------------------------------------------------------------------


void SmartKit::LcdBegin(int col,int row){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"LcdBegin("+col+","+row+")>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       

										}

//--------------------------------------------------------------------------------------------------------------------

void SmartKit::SetCursor(int col,int row){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"SetCursor("+col+","+row+")>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                      

										}
//--------------------------------------------------------------------------------------------------------------------

/*int SmartKit::GetKeyNum(){

                                        String recd;
										String value;
                                        int Value;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"GetKeyNum()>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                                if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){i=26;}
                                              // if (recd.endsWith(">Ok!"))
			  	
											 }
                                        value=recd.substring( (recd.indexOf('<')+1),(recd.indexOf('>')) );
                                        Value=value.toInt();
                                        return(Value);


										}*/
//--------------------------------------------------------------------------------------------------------------------

int SmartKit::WaitForKeyNum(){
                                        String recd;
										String value;
                                        int Value;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"WaitForKeyNum()>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.startsWith("<", 0)&& recd.endsWith(">Ok!")){i=26;}
                                             
			  	
											 }
                                        value=recd.substring( (recd.indexOf('<')+1),(recd.indexOf('>')) );
                                        Value=value.toInt();
                                        return(Value+1);


										}
//--------------------------------------------------------------------------------------------------------------------

void SmartKit::LcdPrint(String string){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"LcdPrint("+ string +")>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       

										}
//--------------------------------------------------------------------------------------------------------------------


void  SmartKit::LcdPrint(long int value){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"LcdPrint("+ value +")>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       

										}
//--------------------------------------------------------------------------------------------------------------------

void SmartKit::LcdPrint(int value){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"LcdPrint("+ value +")>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       

										}
//--------------------------------------------------------------------------------------------------------------------

void SmartKit::LcdPrint(char c){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"LcdPrint("+ c +")>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       

										}
//--------------------------------------------------------------------------------------------------------------------

void SmartKit::LcdPrint(double value){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
										port.print(command);
										port.print("LcdPrint(");
                                        port.print(value,5);
										port.println(")>");
                                        
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       

										}

//--------------------------------------------------------------------------------------------------------------------

void SmartKit::LcdPrint(float value,int decimal_places){
                                        String recd;
										String Value=String(value,decimal_places);
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);String command="<<";
	                                    port.print(command);
										port.print("LcdPrint(");
                                        port.print(value,6);
										port.print("," );port.print(decimal_places);port.println(")>");                                                                           
                                        for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       
										}

//--------------------------------------------------------------------------------------------------------------------

void SmartKit::LcdClear(){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"LcdClear()>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       
										}
//--------------------------------------------------------------------------------------------------------------------

void SmartKit::Blink(){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"Blink()>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       
										}
//--------------------------------------------------------------------------------------------------------------------

void SmartKit::NoBlink(){
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"NoBlink()>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       

										}
//--------------------------------------------------------------------------------------------------------------------


void SmartKit::Cursor(){

                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"Cursor()>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       
										}
//--------------------------------------------------------------------------------------------------------------------


void SmartKit::NoCursor()           {
                                        String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"NoCursor()>";
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                       
										}


//--------------------------------------------------------------------------------------------------------------------




void SmartKit::SetBaud(long int value){ String recd;
                                        static char buffer[80];
                                        SoftwareSerial port(_r, _t);
                                        port.begin(_baud);
                                        String command="<<";
                                        command=command+"SetBaud("+value+")>";		
                                        port.println(command);
                                             for (int i=0;i<25;i++)
											 {
                                               while(readline(port.read(), buffer, 80) < 0);
                                               recd=buffer;
                                               if (recd.endsWith(">Ok!")){i=26;}
			  	
											 }
                                        
										}




#endif
//---------------------------------------------------------------------------------------------------------------

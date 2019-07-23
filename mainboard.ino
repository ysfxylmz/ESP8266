#include <RTClib.h>
#include <Wire.h>
#include <IRremote.h>
#include <EEPROM.h>
RTC_DS1307 RTC;
char*x;
char*y;
char isaret="-";
char*codecx;
int h0;
int h1;
int h2;
int h3;
int h4;
int b1;
int b2;
int b3;
int dk;
int sa;
int tsop=11;
IRrecv irrecv(tsop);
decode_results results;
void setup() {
pinMode(9,OUTPUT);
Serial.begin(115200);
Wire.begin();
RTC.begin();
irrecv.enableIRIn();
}

void loop() {
  h1=EEPROM.read(0);
  h2=EEPROM.read(1);
  h3=EEPROM.read(2);
  h4=EEPROM.read(3);
  b1=EEPROM.read(4);
  b2=EEPROM.read(5);
  b3=EEPROM.read(6);
  b1=map(b1,0,100,0,255);
  analogWrite(9,b1);
DateTime now = RTC.now();

if(irrecv.decode(&results)){
  if(results.value==2131){bilgial();}
  if(results.value==2132){bilgigonder();}
 irrecv.resume(); 
  }


  
}
void bilgial(){
delay(2000);
  while(Serial.available()>0){
    char codec[50]={NULL};
     Serial.readBytes(codec,50);
      int i=0;
  for(codecx=strtok(codec,"-"); codecx!=NULL; codecx=strtok(NULL,"-")){
    i++; 
   
   if(i==1){h1=atoi(codecx);}
   if(i==2){h2=atoi(codecx);}
   if(i==3){h3=atoi(codecx);}
   if(i==4){h4=atoi(codecx);}
   if(i==5){b1=atoi(codecx);}
   if(i==6){b2=atoi(codecx);}
   if(i==7){b3=atoi(codecx);}
   if(i==8){sa=atoi(codecx);}
   if(i==9){dk=atoi(codecx);}

  }

  EEPROM.write(0, h1);
  EEPROM.write(1, h2);
  EEPROM.write(2, h3);
  EEPROM.write(3, h4);
  EEPROM.write(4, b1);
  EEPROM.write(5, b2);
  EEPROM.write(6, b3);
  EEPROM.write(7, sa);
  EEPROM.write(8, dk);

 
RTC.adjust(DateTime(2018, 10, 24, sa, dk, 0));
analogWrite(9,0);  
}
  
  
  }
  /*************************-----------------------------------------------------***************/
void bilgigonder(){
  }


#include <ESP8266WiFi.h> 
#include <WiFiClient.h>
#include <WiFiUdp.h>
const char* ssid= "direk1";
const char* password="00000000";
unsigned int localUdpPort=4210;
char codec[50];
IPAddress locip(192,168,4,1);
IPAddress hostip(192,168,4,10);
IPAddress subnet(255,255,255,0);
WiFiUDP Udp;
void setup() {
 Serial.begin(115200);
 WiFi.mode(WIFI_STA);
 WiFi.config(hostip, locip, subnet);
 
  WiFi.begin(ssid,password,2);
  
  Udp.begin(localUdpPort);
 } 
void loop() { 
  while(WiFi.status() != WL_CONNECTED){delay(1);}   
    if(Serial.available()>0){
      Serial.readBytes(codec,50);
    Udp.beginPacket(locip,localUdpPort);
    Udp.write(codec);
    Udp.endPacket();
    codec[50]={NULL};
    }
  int datalen=Udp.parsePacket();
  if(datalen){
    int len=Udp.read(codec,50);
    Serial.write(codec);
    if(len>0){codec[len]=0;}
    }
  }



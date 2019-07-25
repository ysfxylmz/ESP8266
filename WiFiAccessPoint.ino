#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
IPAddress locip(192,168,4,1);
IPAddress hostip(192,168,4,10);
IPAddress subnet(255,255,255,0);
WiFiUDP Udp;
const char *ssid = "direk1";
const char *password = "00000000";
unsigned int localUdpPort=4210;
char codec[50];
void setup() {
  Serial.begin(115200);
  WiFi.config(hostip, locip, subnet);
  WiFi.softAP(ssid, password,2);
  Udp.begin(localUdpPort);
}

void loop() {
   if(Serial.available()>0){
      Serial.readBytes(codec,50);
    Udp.beginPacket(Udp.remoteIP(),localUdpPort);
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

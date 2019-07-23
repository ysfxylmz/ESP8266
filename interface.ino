#include <IRremote.h>
#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 10);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
IRsend irsend;
char*isaret="-";
char y[5];
int h1 = EEPROM.read(0);
int h2 = EEPROM.read(1);
int h3 = EEPROM.read(2);
int h4 = EEPROM.read(3);
int b1 = EEPROM.read(4);
int b2 = EEPROM.read(5);
int b3 = EEPROM.read(6);
int sa;
int dk;
int up = 13;
int down = 8;
int ok = 9;
int sendd = 12;
int menu = 1;
int page = 1;
int stateb=2;
char*wfs;
byte oks = 0;
void setup() {
  pinMode(A0,OUTPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(ok, INPUT);
  pinMode(sendd, INPUT);
  pinMode(stateb,INPUT);
  Serial.begin(115200);
  display.begin();
  display.setContrast(50);
  display.setTextSize(1);
  display.clearDisplay();
  display.display();
}

/**************************************************/
void loop() {
  if (oks == 0) {
    minus();
    plus();
  }
  select();

 
  drwmenu();

   delay(100);
  if(oks==0){senddata();}
  if(oks==0){state();}
  }

void drwmenu() {




  if (page == 1 && menu == 1) {
    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println(" hour1:");
    display.setCursor(0, 30);
    display.println("power1:");
    display.setCursor(0, 40);
    display.println(" hour2:");
    display.setCursor(60, 40);
    display.println(h2);
    display.setCursor(60, 30);
    display.println(b1);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 20);
    display.println(h1);
    if (oks == 1) {
      seth1();
    }
    display.display();
  }
  /********************************************************************************************************************/
  if (page == 1 && menu == 2) {
    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println(" hour1:");
    display.setCursor(0, 30);
    display.println("power1:");
    display.setCursor(0, 40);
    display.println(" hour2:");
    display.setCursor(60, 20);
    display.println(h1);
    display.setCursor(60, 40);
    display.println(h2);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 30);
    display.println(b1);
    if (oks == 1) {
      setb1();
    }
    display.display();
  }


  if (page == 1 && menu == 3) {

    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println(" hour1:");
    display.setCursor(0, 30);
    display.println("power1:");
    display.setCursor(0, 40);
    display.println(" hour2:");
    display.setCursor(60, 20);
    display.println(h1);
    display.setCursor(60, 30);
    display.println(b1);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 40);
    display.println(h2);
    if (oks == 1) {
      seth2();
    }
    display.display();
  }


  if (page == 2 && menu == 1) {

    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println("power2:");
    display.setCursor(0, 30);
    display.println(" hour3:");
    display.setCursor(0, 40);
    display.println("power3:");
    display.setCursor(60, 40);
    display.println(b3);
    display.setCursor(60, 30);
    display.println(h3);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 20);
    display.println(b2);
    if (oks == 1) {
      setb2();
    }
    display.display();
  }

  if (page == 2 && menu == 2) {

    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println("power2:");
    display.setCursor(0, 30);
    display.println(" hour3:");
    display.setCursor(0, 40);
    display.println("power3:");
    display.setCursor(60, 40);
    display.println(b3);
    display.setCursor(60, 20);
    display.println(b2);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 30);
    display.println(h3);
    if (oks == 1) {
      seth3();
    }
    display.display();
  }

  if (page == 2 && menu == 3) {

    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println("power2:");
    display.setCursor(0, 30);
    display.println(" hour3:");
    display.setCursor(0, 40);
    display.println("power3:");
    display.setCursor(60, 20);
    display.println(b2);
    display.setCursor(60, 30);
    display.println(h3);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 40);
    display.println(b3);
    if (oks == 1) {
      setb3();
    }
    display.display();
  }
  if (page == 3 && menu == 1) {
    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println("hour4:");
    display.setCursor(0, 30);
    display.println(" hour:");
    display.setCursor(0, 40);
    display.println("minute:");
    display.setCursor(60, 30);
    display.println(sa);
    display.setCursor(60, 40);
    display.println(dk);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 20);
    display.println(h4);

    if (oks == 1) {
      seth4();
      }
      display.display();
      }
if (page == 3 && menu == 2) {
    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println("hour4:");
    display.setCursor(0, 30);
    display.println(" hour:");
    display.setCursor(0, 40);
    display.println("minute:");
    display.setCursor(60, 20);
    display.println(h4);
    display.setCursor(60, 40);
    display.println(dk);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 30);
    display.println(sa);



 
    if (oks == 1) {
      setsa();
    }
    display.display();
  }
  if (page == 3 && menu == 3) {

    display.clearDisplay();
      display.drawFastHLine(0, 10, 83, BLACK);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.print("ValueSet");
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 20);
    display.println("hour4:");
    display.setCursor(0, 30);
    display.println(" hour:");
    display.setCursor(0, 40);
    display.println("minute:");
    display.setCursor(60, 30);
    display.println(sa);
    display.setCursor(60, 20);
    display.println(h4);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(60, 40);
    display.println(dk);


 
    if (oks == 1) {
      setdk();
    }
    display.display();
  }
}

void plus() {
  if (digitalRead(up) == HIGH)
  {
    menu++;
  }
  if (menu == 4)
  {
    page++;
  }
  if (menu == 4)
  {
    menu = 1;
  }
  if (page == 4)
  {
    page = 1;
  }
}
void minus() {
  if (digitalRead(down) == HIGH)
  {
    menu--;
  }
  if (menu == 0)
  {
    page--;
  }
  if (menu == 0)
  {
    menu = 3;
  }
  if (page == 0)
  {
    page = 3;
  }
}
void select() {
  if (digitalRead(ok) == HIGH) {
    oks++;
    if (oks == 2) {
      oks = 0;
    }
  }

}




/****************************************************/









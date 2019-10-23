#include <LiquidCrystal_SR_LCD3.h> 
const int PIN_LCD_STROBE         =  2;   
const int PIN_LCD_DATA           =  3;   
const int PIN_LCD_CLOCK          =  4;   
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK, PIN_LCD_STROBE); 

//sesuikan posisi pin select
int s0 = 9; //15 //A
int s1 = 10; //16 //B
int s2 = 11; //17 //C
int sensor[] = {A0, A1, A2, A3, A4}; //pin sensor samping 23-26
int Muxl_State [8] = {0,0,0,0,0,0,0,0};
//gunakan A0 sebagai input
int analogPin = A4; //27 ATAU X
 
//variabel untuk menyimpan nilai input
int nilaiInput = 0 ;
int x1,x2,x3,x4,x5,x6,x7,x8 = 0;

//variabel motor
int kirimaju=5, kirimundur=6, kananmaju=7, kananmundur=8;


void setup() {
  //jadikan pin select sebagai output
  lcd.begin(16,2);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  for (int i=0; i<4; i++) {
    pinMode(sensor[i],INPUT);
  }
  Serial.begin(9600);
  //motor
  pinMode(kirimaju,OUTPUT);
  pinMode(kirimundur,OUTPUT);
  pinMode(kananmaju,OUTPUT);
  pinMode(kananmundur,OUTPUT);
}

void Sensor(){
  digitalWrite(s0,LOW);
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
  x1 = analogRead(analogPin);
  Serial.println(nilaiInput);
  lcd.print("Sensor 1 : ");
  lcd.print(nilaiInput);
  delay(1000);
    
  //memilih y1 sebagai input
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
  x2 = analogRead(analogPin);
Serial.println(nilaiInput);
  lcd.clear();
  lcd.print("Sensor 2 : ");
  lcd.print(nilaiInput);
  delay(1000);
  
 //memilih y2 sebagai input
  digitalWrite(s0,LOW);
  digitalWrite(s1,HIGH);
  digitalWrite(s2,LOW);
  x3 = analogRead(analogPin);
Serial.println(nilaiInput);
  lcd.clear();
  lcd.print("Sensor 3 : ");
  lcd.print(nilaiInput);
  delay(1000);

   //memilih y3 sebagai input
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  digitalWrite(s2,LOW);
  x4 = analogRead(analogPin);
  Serial.println(nilaiInput);
  lcd.clear();
  lcd.print("Sensor 4 : ");
  lcd.print(nilaiInput);
  delay(1000);

   //memilih y4 sebagai input
  digitalWrite(s0,LOW);
  digitalWrite(s1,LOW);
  digitalWrite(s2,HIGH);
  x5 = analogRead(analogPin);
Serial.println(nilaiInput);
  lcd.clear();
  lcd.print("Sensor 5 : ");
  lcd.print(nilaiInput);
  delay(1000);

   //memilih y5 sebagai input
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);
  digitalWrite(s2,HIGH);
  x6 = analogRead(analogPin);
 Serial.println(nilaiInput);
  lcd.clear();
  lcd.print("Sensor 6 : ");
  lcd.print(nilaiInput);
  delay(1000);

   //memilih y6 sebagai input
  digitalWrite(s0,LOW);
  digitalWrite(s1,HIGH);
  digitalWrite(s2,HIGH);
  x7 = analogRead(analogPin);
  Serial.println(nilaiInput);
  lcd.clear();
  lcd.print("Sensor 7 : ");
  lcd.print(nilaiInput);
  delay(1000);

   //memilih y7 sebagai input
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  digitalWrite(s2,HIGH);
  x8 = analogRead(analogPin);
  Serial.println(nilaiInput);
  lcd.clear();
  lcd.print("Sensor 8 : ");
  lcd.print(nilaiInput);
  delay(1000);
  lcd.clear();

  for (int i=0; i<4; i++) {
    nilaiInput=analogRead(sensor[i]);
    lcd.clear();
    lcd.print("Sensor ");
    lcd.print(i+9);
    lcd.print(" : ");
    lcd.print(nilaiInput);
  Serial.println(nilaiInput);
//    delay(1000);
//  }
}

}

 void maju () {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MAJU");
  digitalWrite(kirimaju,HIGH);
  digitalWrite(kirimundur,LOW);
  digitalWrite(kananmaju,HIGH);
  digitalWrite(kananmundur,LOW);
  //delay(1000);
  
 }
void belokkanan(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("belok kanan");
  digitalWrite(kirimaju,LOW);
  digitalWrite(kirimundur,LOW);
  digitalWrite(kananmaju,HIGH);
  digitalWrite(kananmundur,LOW);
 //delay(10);
}

void belokkiri(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("belok kiri");
  digitalWrite(kirimaju,HIGH);
  digitalWrite(kirimundur,LOW);
  digitalWrite(kananmaju,LOW);
  digitalWrite(kananmundur,LOW);
  //delay(10);
}

void mati(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("MATI");
  digitalWrite(kirimaju,LOW);
  digitalWrite(kirimundur,LOW);
  digitalWrite(kananmaju,LOW);
  digitalWrite(kananmundur,LOW);
  //delay(10);  
}

void loop() {

Sensor();
if (  x4 > 600 && x5 > 600)  {  //semua angka2 merupakan nilai sensor
  maju();
}

else if  ( x5 < 700 || (x3 > 700 && x4 >700) || x2 > 700) {
  belokkiri();  
}

else if  ( x4 < 700 || (x5 > 700 && x6 > 700) && x8 > 700) {
 belokkanan();  
}

else if ( x4 < 600 && x5 < 600){
  mati();
}

//nilai sensor lama
//else if ((x2 >600 || x3 >600 || x4 > 600) || x5 > 600) {
//  belokkiri(); 
//}
//   
//else if (x4 < 600 || (x5 > 600 || x6 > 600 || x8 > 600)) {
//  belokkanan();

// }
 
//else if (x4 < 500 && x5 < 500 && x6 < 500 && x3 < 500) {
//  mati();
//}
 
////if ((x4 > 1000 && x5 > 1000) && ( x3 > 1000 || x2 > 1000 || x6 > 1000 || x8 > 1000)){
//  maju();  
//}

} 

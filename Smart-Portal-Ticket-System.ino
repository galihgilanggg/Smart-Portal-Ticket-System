#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigpin = 7;
const int echopin = 6;  

#define buzzer 5
#define rLED 10    
#define gLED 9
#define LED 8
#define button 13
#define IR 12
#define ldr A3 

int distance;
int duration;
int vehicle = 0;

int buttonState = 0; 
int infrared;

int pos = 45;
Servo servo;

void dekat();
void menyala();
void masuk();

void setup(){
  Serial.begin(9600);
  servo.attach(3);
  servo.write(pos);
  
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  pinMode(ldr, INPUT);
  
  lcd.begin(16, 2);
  lcd.init();
  lcd.setBacklight(1);
  lcd.display();
  delay(500);
  lcd.setCursor(1, 0);
  lcd.print("Smart Portal");
  delay(1000); 
  lcd.setCursor(5, 1);
  lcd.print("Ticket");
  delay(2000);   
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vehicle Parked qty:");
  lcd.setCursor(6, 1);
  lcd.print(vehicle);
}

void loop() {
  buttonState = digitalRead(button);
  Serial.println(buttonState);
 
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration * 0.0343) / 2;
  
  int ldrval = analogRead(ldr);
  Serial.println(ldrval);

  lcd.clear();
  
  if (distance < 10) {
    dekat();
  } else {
    Serial.print("Jarak :");
    Serial.print(distance);
    Serial.print(" CM");
    lcd.setCursor(0, 0);
    lcd.print("Vehicle Parked qty:");
    lcd.setCursor(6, 1);
    lcd.print(vehicle);
    delay(1000); 
  }

  if (buttonState == HIGH) {
    masuk();
  } else {
    dekat();
  }

  if (ldrval > 10) {
    digitalWrite(LED, HIGH);
    delay(1000);
  }
}

void dekat() {
  digitalWrite(rLED, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("=====Welcome======");
  lcd.setCursor(0, 1);
  lcd.print("Push the Button");   
  delay(1000);
}

void menyala() {
  digitalWrite(LED, HIGH);
  delay(1000);  
}

void masuk() {
  digitalWrite(gLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Silahkan Masuk");
  delay(3000);
  digitalWrite(gLED, LOW);
  delay(5000);   
  servo.write(pos);  // Kembali ke posisi default
  vehicle++;  // Increment jumlah kendaraan
  lcd.setCursor(0, 0);
  lcd.print("Vehicle Parked qty:");
  lcd.setCursor(6, 1);
  lcd.print(vehicle);
  delay(1000);
}
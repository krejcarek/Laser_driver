
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int state=0;
int PWM=50;
int led_value=0;
int pulse=500;
int xAxis;
int yAxis;
int pushButton;
const int LED_PIN = 6;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("PWM[%]: ");
  lcd.setCursor(0, 1);
  lcd.print("Pulse[ms]: ");
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A0, INPUT_PULLUP);


}

void loop() {

  xAxis = analogRead(A1);
  yAxis = analogRead(A2);
  pushButton = digitalRead(A0);
  
  if (pushButton == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pulse!!!");
    led_value=map(PWM, 0, 100, 0, 255);
    analogWrite(LED_PIN, led_value);   
    delay(pulse);                       // wait for pulse time
    analogWrite(LED_PIN, 0); 
    delay(1000);
  }

  if ((yAxis>600) || (yAxis<400)) {
    if (yAxis>900) {
      if (PWM>10) PWM=PWM-10;

    }
    else if (yAxis>600) {
      if (PWM>1) PWM=PWM-1;

    }
    else if (yAxis<100) {
      if (PWM<91) PWM=PWM+10;

    }
    else if (yAxis<400) {
      if (PWM<100) PWM=PWM+1;
    }
    delay(400);
    lcd.clear();

  }

  if ((xAxis>600) || (xAxis<400)) {
    if (xAxis>900) {
      if (pulse>100) pulse=pulse-100;
    }
    else if (xAxis>600) {
      if (pulse>10) pulse=pulse-10;
    }
    else if (xAxis<100) {
      if (pulse<9900) pulse=pulse+100;
    }
    else if (xAxis<400) {
      if (pulse<9990) pulse=pulse+10;

    }
    delay(400);
    lcd.clear();

  }
  
  lcd.setCursor(0, 0);
  lcd.print("PWM[%]: ");
  lcd.setCursor(0, 1);
  lcd.print("Pulse[ms]: ");
  lcd.setCursor(12, 0);
  lcd.print(PWM);
  lcd.setCursor(12, 1);
  lcd.print(pulse);

}

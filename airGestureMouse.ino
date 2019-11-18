#include<Wire.h>
#include <Adafruit_SSD1306_STM32.h>
const int MPU6050_addr = 0x68;
int16_t AccX, AccY, AccZ, Temp, GyroX, GyroY, GyroZ;
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//------------
const int left_click_pin = PC13;
const int right_click_pin = PC14;
int left_click_val = 0;
int right_click_val = 0;
#define OLED_RESET -1  // Not used
Adafruit_SSD1306 display(OLED_RESET);
int up = 8, right = 6, left = 4, down = 2, sto = 5;
void setup() {
  Wire.setClock(400000);
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(left_click_pin, INPUT_PULLUP);
  pinMode(right_click_pin, INPUT_PULLUP);
}
void loop() {
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr, 14);
  AccX = Wire.read() << 8 | Wire.read();
  AccY = Wire.read() << 8 | Wire.read();
  AccZ = Wire.read() << 8 | Wire.read();
  Temp = Wire.read() << 8 | Wire.read();
  GyroX = Wire.read() << 8 | Wire.read();
  GyroY = Wire.read() << 8 | Wire.read();
  GyroZ = Wire.read() << 8 | Wire.read();
  AccX = AccX / 100;
  AccY = AccY / 100;
  Serial.println(AccX);
  Serial.println(AccY);
  // AccZ = AccZ / 100;
  //Serial.print("AccX = "); Serial.print(AccX);
  //Serial.print(" || AccY = "); Serial.print(AccY);
  // Serial.println(GyroX);
  // Serial.print("||ACCZ="); Serial.println(AccZ);
  //Serial1.println(AccX);
  // Serial1.println(AccY);
  // Serial1.println(AccZ);
  left_click_val = digitalRead(left_click_pin);
  Serial.println(left_click_val);
  if (left_click_val == 0) {
    delay(400);
    Serial.println("click");
    Serial1.println("lclick");
    left_click_val = digitalRead(left_click_pin);
    Serial.println(left_click_val);
    if (left_click_val == 0) {
      delay(400);
      Serial.println("dclick");
      Serial1.println("dclick");
    }
  }
  right_click_val = digitalRead(right_click_val);
  if (right_click_val == 0) {
    delay(400);
    Serial.println("rclick");
    Serial1.println("rclick");
  }
  if (AccX > 20) {
    Serial1.println("up");
    Serial.println("up");
  }
  else if (AccX < -20) {
    Serial1.println("down");
    Serial.println("down");
  }
  /*else {
    Serial1.println("stop");
    Serial.println("stop");
    }*/
  if (AccY < -20) {
    Serial1.println("right");
    Serial.println("right");
  }
  else  if (AccY > 20) {
    Serial1.println("left");
    Serial.println("left");
  }
  /* else {
     Serial1.println("stop");
     Serial.println("stop");
    }*/
  delay(50);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  // init done

  // Clear the buffer.
  //display.clearDisplay();
  display.clearDisplay();
  //display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("X : ");
  display.print(AccX);
  display.setCursor(50, 0);
  display.print("Y : ");
  display.print(AccY);
  // AccX = abs(AccX);
  if (AccX > 100) {
    AccX = 100;
  }
  if (AccX < -100) {
    AccX = -100;
  }
  AccX = map(AccX, -100, 100, 64, 20);
  // AccY = abs(AccY);
  if (AccY > 100) {
    AccY = 100;
  }
  if (AccY < -100) {
    AccY = -100;
  }
  AccY = map(AccY, -100, 100, 128, 0);
  for (int i = 1; i <= 3; i++) {
    display.drawCircle(AccY, AccX, i, WHITE);
  }
  display.display();
  // Draw a test
  /* display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("X : ");
    display.print(AccX);
    display.setCursor(0, 20);
    display.print("Y : ");
    display.print(AccY);
    //  display.setCursor(0, 40);
    // display.print("Z : ");
    //display.print(AccZ);
    display.display();*/
  delay(150);
}

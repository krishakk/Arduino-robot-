#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;); // Don't continue if display not found
  }
  display.clearDisplay();
}

void loop() {
  drawSmiley();
  delay(2000);

  drawSad();
  delay(2000);
}

void drawSmiley() {
  display.clearDisplay();

  // Eyes
  display.fillRect(40, 20, 5, 5, SSD1306_WHITE); 
  display.fillRect(80, 20, 5, 5, SSD1306_WHITE);

  // Mouth (smile)
  display.drawLine(50, 45, 70, 45, SSD1306_WHITE);
  display.drawLine(70, 45, 75, 40, SSD1306_WHITE);
  display.drawLine(50, 45, 45, 40, SSD1306_WHITE);

  display.display();
}

void drawSad() {
  display.clearDisplay();

  // Eyes
  display.fillRect(40, 20, 5, 5, SSD1306_WHITE); 
  display.fillRect(80, 20, 5, 5, SSD1306_WHITE);

  // Mouth (sad)
  display.drawLine(50, 40, 70, 40, SSD1306_WHITE);
  display.drawLine(70, 40, 75, 45, SSD1306_WHITE);
  display.drawLine(50, 40, 45, 45, SSD1306_WHITE);

  display.display();
}

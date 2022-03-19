#include <Arduino.h>
#include <U8g2lib.h>


#define OLED_CLOCK  15
#define OLED_DATA   4
#define OLED_RESET  16
// OLED Used
U8G2_SSD1306_128X64_NONAME_F_SW_I2C g_OLED(U8G2_R0, 15, 4,  16);
int g_lineHeight = 0;

void setup() 
{
pinMode(LED_BUILTIN, OUTPUT);
g_OLED.begin();
g_OLED.clear();
g_OLED.setFont(u8g2_font_profont15_tf);

g_lineHeight = g_OLED.getFontAscent() - g_OLED.getFontDescent();

g_OLED.setCursor(0, g_lineHeight);
g_OLED.print("Hi Raechel :)");

g_OLED.setCursor(0, g_lineHeight *  2);
g_OLED.printf("Download # ");
g_OLED.sendBuffer();

}

void loop() 
{
digitalWrite(LED_BUILTIN, 1);
delay(100);
digitalWrite(LED_BUILTIN, 0);
delay(4990);  
}
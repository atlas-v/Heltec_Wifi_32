#include <Arduino.h>
#include <U8g2lib.h>
#include <WiFi.h>


#define OLED_CLOCK  15
#define OLED_DATA   4
#define OLED_RESET  16
// OLED Used
U8G2_SSD1306_128X64_NONAME_F_SW_I2C g_OLED(U8G2_R0, 15, 4,  16);
int g_lineHeight = 0;


// initialize wifi scan and prompt for connection
#include <WiFi.h>



// Our home network, if on a different network replace with your keys
 const  char*   ssid      =   "HoloNet";
 const  char*   password    =   "Coruscant";


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



// Open serial port for program feedback
Serial.begin(9600);

WiFi.begin(ssid,    password);
WiFi.mode(WIFI_STA);
// Connection attempt
while (WiFi.status()    !=  WL_CONNECTED)
{
    delay(500);
    Serial.println("connection attempt. . .");
}
Serial.println(WiFi.localIP());




}

void loop() 


{
digitalWrite(LED_BUILTIN, 1);
delay(100);
digitalWrite(LED_BUILTIN, 0);
delay(400);  
}
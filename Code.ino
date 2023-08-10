#include <SoftwareSerial.h> // Use software serial since the hardware serial port is used by the USB interface. 
#include <ModbusMaster.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>

#define SSerialRX         19
#define SSerialTX         18

// set up a new serial object
SoftwareSerial mySerial (SSerialRX, SSerialTX);
WiFiClient client;
HTTPClient http;
String serverName = "http://dinhduongdat.info/pushvalue.php?id=3";

ModbusMaster node1;
ModbusMaster node2;
ModbusMaster node3;

const char *ssid = "Ten Wifi";
const char *password = "Mat khau";

uint16_t data3[6];
float Temp3, Humi3; //Sensor Temperarure and Humidity
float Nito, Photpho, Kali; // Smart water sensor PH/ORP
float result3;

uint16_t data2[6];
float Temp2, Humi2; //Sensor Temp1erarure and Humi2dity Soil
float result2;
uint16_t data1[6];
float Temp1, Humi1; //Sensor Temp1erarure and Humi2dity Soil
float result1;
void putData()
{
  String part = serverName;
  part += "&tem=";
  part += String(Temp2);
  part += "&hum=";
  part += String(Humi2);
  part += "&ph=";
  part += String(Temp1);
  part += "&nito=";
  part += String(Nito);
  part += "&photpho=";
  part += String(Photpho);
  part += "&kali=";
  part += String(Kali);

  http.begin(client, part.c_str());
  int temp = http.GET();
  http.end();
  Serial.println(part);
}
void setup()
{
  Serial.begin(9600); //Hardware serial for serial monitor in Arduino IDE)
  Serial.println("Read Data Modbus");
  mySerial.begin(4800);
  node2.begin(2, mySerial);
  node3.begin(3, mySerial);
  node1.begin(1, mySerial);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(2000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");

}

void loop()
{

  Serial.println("READ DATA");
  node3.begin(3, mySerial);
  node2.begin(2, mySerial);
  node1.begin(1, mySerial);
  delay(500);
  ph();
  delay(500);
  nhietdo();
  delay(500);
  npk();
  delay(500);
  Serial.println();
  putData();

}

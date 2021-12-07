
#include <Process.h>
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Bridge.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue0 = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);
  // print out the value you read:
  Serial.print("sensorValue0 = " );
  Serial.println(sensorValue0);
  Serial.print("sensorValue1 = ");
  Serial.println(sensorValue1);
  Serial.print("sensorValue2 = ");
  Serial.println(sensorValue2);
  Serial.print("sensorValue3 = ");
  Serial.println(sensorValue3);
  Serial.println("\n");
  delay(2000);        // delay in between reads for stability
  

//String deviceId = "sensor1"; // Change this to the name of your Yun or team, e.g. dshop002, dshop003, etc.
//
//String url = "<add your rest url here>" + deviceId + "/A0";
//
//Process p;
//
//p.begin("curl");
//p.addParameter("-k");  // allow https without certificate checking
//p.addParameter("-XPUT");  // initiate a PUT request
//p.addParameter("--data");
//p.addParameter((String) sensorValue0);
//p.addParameter("--url");
//p.addParameter(url);
//p.run();
//
//Serial.print("Exit: ");
//Serial.println(p.exitValue());

int size = 64;
String deviceId = "<arduino name>"; // Change this to the name of your arduino 
char json[size];  // buffer for the JSON String
int pos = 0;
pos += sprintf(json, "{");
// String needs to be converted to char array for printf
char deviceIdChars[deviceId.length() + 1];
deviceId.toCharArray(deviceIdChars, deviceId.length() + 1);
pos += snprintf(json + pos, size - pos, "A0:%d", sensorValue0);
pos += snprintf(json + pos, size - pos, ",");
pos += snprintf(json + pos, size - pos, "A1:%d", sensorValue1);
pos += snprintf(json + pos, size - pos, ",");
pos += snprintf(json + pos, size - pos, "A2:%d", sensorValue2);
pos += snprintf(json + pos, size - pos, ",");
pos += snprintf(json + pos, size - pos, "A3:%d", sensorValue3);
pos += snprintf(json + pos, size - pos, "}");

String url = "<add your rest url here>" + deviceId; // URL is updated to write the full device data

Process p;
p.begin("curl");
p.addParameter("-k");  // allow https without certificate checking

p.addParameter("-XPUT");  // initiate a PUT request
p.addParameter("--data");
p.addParameter(json);
p.addParameter("--url");
p.addParameter(url);
p.run();

Serial.print("Exit: ");
Serial.println(p.exitValue());



}

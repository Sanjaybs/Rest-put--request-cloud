#include <Process.h>
void setup() {
  // put your setup code here, to run once:
Bridge.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
int value = analogRead(A0);

String deviceId = "<device ID>"; // Change this to the name of your Arduino or team

String url = "<insert your url here>";

Process p;

p.begin("curl");
p.addParameter("-k");  // allow https without certificate checking
p.addParameter("-XPUT");  // initiate a PUT request
p.addParameter("--data");
p.addParameter((String) value);
p.addParameter("--url");
p.addParameter(url);
p.addParameter("-X");
p.addParameter("DELETE");
p.run();

Serial.print("Exit: ");
Serial.println(p.exitValue());
}

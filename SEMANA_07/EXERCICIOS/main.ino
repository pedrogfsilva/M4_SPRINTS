// Librarys
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
// WIFI info
const char* ssid = "Inteli-COLLEGE";
const char* password = "QazWsx@123";

//Your Domain name with URL path or IP address with path
String serverName = "https://zbr31n-3000.preview.csb.app/getInfo";

unsigned long lastTime = 0;

unsigned long timerDelay = 5000;

int greenLed = 15;
int blueLed = 16;
int redLed = 17;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.println("Connecting");

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}
void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status() == WL_CONNECTED){
      HTTPClient http;
      String serverPath = serverName;
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());

      // Send HTTP GET request
      int httpResponseCode = http.GET();
      if (httpResponseCode>0) {

        String payload = http.getString();
        Serial.println(payload);

        JSONVar myObject = JSON.parse(payload);
        JSONVar keys = myObject.keys();

        int winStatus = int(myObject[keys[0]]);
        int loseStatus = int(myObject[keys[1]]);
        int drawStatus = int(myObject[keys[2]]);

        Serial.println(winStatus);
        Serial.println(loseStatus);
        Serial.println(drawStatus);

        if(winStatus == 1) {
          digitalWrite(greenLed, HIGH);
        } else {
          digitalWrite(greenLed, LOW);
        }
        if(drawStatus == 1) {
          digitalWrite(blueLed, HIGH);
        } else {
          digitalWrite(blueLed, LOW);
        }
        if(loseStatus == 1) {
          digitalWrite(redLed, HIGH);
        } else {
          digitalWrite(redLed, LOW);
        }
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
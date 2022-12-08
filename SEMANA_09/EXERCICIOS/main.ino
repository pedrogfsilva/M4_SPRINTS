#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFiMulti.h>

const char *AP_SSID = "Inteli-COLLEGE";
const char *AP_PWD = "QazWsx@123";

const int length = 20;
char messageToSend[] = "FELIZ NATAL";
bool needToSend = true;

String criptoMessage = "";

WiFiMulti wifiMulti;

void setup() {

  Serial.begin(115200);
  delay(500);
  wifiMulti.addAP(AP_SSID, AP_PWD);

  for(int i = 0; i < strlen(messageToSend); i++) {
    if(messageToSend[i] == 'A'){
      criptoMessage += "Z";
    } else if (messageToSend[i] == 'B') {
      criptoMessage += "A";
    } else if (messageToSend[i] == 'C') {
      criptoMessage += "B";
    } else if (messageToSend[i] == 'D') {
      criptoMessage += "C";
    } else if (messageToSend[i] == 'E') {
      criptoMessage += "D";
    } else if (messageToSend[i] == 'F') {
      criptoMessage += "E";
    } else if (messageToSend[i] == 'G') {
      criptoMessage += "F";
    } else if (messageToSend[i] == 'H') {
      criptoMessage += "G";
    } else if (messageToSend[i] == 'I') {
      criptoMessage += "H";
    } else if (messageToSend[i] == 'J') {
      criptoMessage += "I";
    } else if (messageToSend[i] == 'K') {
      criptoMessage += "J";
    } else if (messageToSend[i] == 'L') {
      criptoMessage += "K";
    } else if (messageToSend[i] == 'M') {
      criptoMessage += "L";
    } else if (messageToSend[i] == 'N') {
      criptoMessage += "M";
    } else if (messageToSend[i] == 'O') {
      criptoMessage += "N";
    } else if (messageToSend[i] == 'P') {
      criptoMessage += "O";
    } else if (messageToSend[i] == 'Q') {
      criptoMessage += "P";
    } else if (messageToSend[i] == 'R') {
      criptoMessage += "Q";
    } else if (messageToSend[i] == 'S') {
      criptoMessage += "R";
    } else if (messageToSend[i] == 'T') {
      criptoMessage += "S";
    } else if (messageToSend[i] == 'U') {
      criptoMessage += "T";
    } else if (messageToSend[i] == 'V') {
      criptoMessage += "U";
    } else if (messageToSend[i] == 'W') {
      criptoMessage += "V";
    } else if (messageToSend[i] == 'X') {
      criptoMessage += "W";
    } else if (messageToSend[i] == 'Y') {
      criptoMessage += "X";
    } else if (messageToSend[i] == 'Z') {
      criptoMessage += "Y";
    } else if (messageToSend[i] == ' ') {
      criptoMessage += " ";
    }
  } 

  postDataToServer(messageToSend, criptoMessage);
}
void loop() {
}

void postDataToServer(char* messageToSend, String criptoMessage) {
  Serial.println("Posting Tag information to API...");
  // Block until we are able to connect to the WiFi
  if(wifiMulti.run() == WL_CONNECTED) {
    HTTPClient http;

    http.begin("https://ur524n-3000.preview.csb.app/teobaldo");

    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;

    // Add values in the document
    doc["nome"] = "Pedro Silva";
    doc["turma"] = "Turma 3";
    doc["grupo"] = "Grupo 2";
    doc["mensagemNormal"] = messageToSend;
    doc["mensagemCriptografada"] = criptoMessage;

    String requestBody;

    serializeJson(doc, requestBody);

    int httpResponseCode = http.POST(requestBody);

    if(httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.printf("Error occurred while sending HTTP POST: %s\n");
    }
  }
}
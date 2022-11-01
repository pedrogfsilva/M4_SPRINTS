int LED1 = 4;
int LED2 = 5;
int LED3 = 6;
int LED4 = 7;
int buttonState = 0;
int button2State = 0;
int buttonPin = 17;
int buttonPin2 = 18;

int c[] = {};

int combinations[] = {};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S3!");
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000); // this speeds up the simulation
  int analog = analogRead(8);
  int luz = map(analog, 64, 8126, 2000, 0);

  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed
  if (buttonState == LOW) {
    if(luz >= 0 && luz <= 125){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 0;
    } else if (luz > 125 && luz <= 250){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 1;
    } else if (luz > 250 && luz <= 375){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 1;
      combinations[3] = 0;
    } else if (luz > 375 && luz <= 500){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 1;
      combinations[3] = 1;
    } else if (luz > 500 && luz <= 625){
      combinations[0] = 0;
      combinations[1] = 1;
      combinations[2] = 0;
      combinations[3] = 0;
    } else if (luz > 625 && luz <= 750){
      combinations[0] = 0;
      combinations[1] = 1;
      combinations[2] = 0;
      combinations[3] = 1;
    } else if (luz > 750 && luz <= 875){
      combinations[0] = 0;
      combinations[1] = 1;
      combinations[2] = 1;
      combinations[3] = 0;
    } else if (luz > 875 && luz <= 1000){
      combinations[0] = 0;
      combinations[1] = 1;
      combinations[2] = 1;
      combinations[3] = 1;
    } else if (luz > 1000 && luz <= 1125){
      combinations[0] = 1;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 0;
    } else if (luz > 1125 && luz <= 1250){
      combinations[0] = 1;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 1;
    } else if (luz > 1250 && luz <= 1375){
      combinations[0] = 1;
      combinations[1] = 0;
      combinations[2] = 1;
      combinations[3] = 0;
    } else if (luz > 1375 && luz <= 1500){
      combinations[0] = 1;
      combinations[1] = 0;
      combinations[2] = 1;
      combinations[3] = 1;
    } else if (luz > 1500 && luz <= 1625){
      combinations[0] = 1;
      combinations[1] = 1;
      combinations[2] = 0;
      combinations[3] = 0;
    } else if (luz > 1625 && luz <= 1750){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 1;
    } else if (luz > 1750 && luz <= 1875){
      combinations[0] = 1;
      combinations[1] = 1;
      combinations[2] = 1;
      combinations[3] = 0;
    } else if (luz > 1875 && luz <= 2000){
      combinations[0] = 1;
      combinations[1] = 1;
      combinations[2] = 1;
      combinations[3] = 1;
    }

  button2State = digitalRead(buttonPin2);
  if(button2State == LOW) {
    for(int i = 0; i < 4; i++){
    if(combinations[i] == 0){
      c[i] = LOW;
    } else {
      c[i] = HIGH;
    }
  }
    digitalWrite(LED1, c[0]);
    digitalWrite(LED2, c[1]);
    digitalWrite(LED3, c[2]);
    digitalWrite(LED4, c[3]);

    tone(15, rand(), 1000);
  }
}

}

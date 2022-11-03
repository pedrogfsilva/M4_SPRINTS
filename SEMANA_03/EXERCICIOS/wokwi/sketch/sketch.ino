int LED1 = 4;
int LED2 = 5;
int LED3 = 6;
int LED4 = 7;
int buttonState = 0;
int button2State = 0;
int buttonPin = 1;
int buttonPin2 = 2;

int c[4];

int combinations[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S3!");
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000); // this speeds up the simulation
  int analog = analogRead(8);
  Serial.println(analog);
  // int luz = map(analog, 0, 2092, 2000, 0);

  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed
  if (buttonState == LOW) {
    if(analog >= 0 && analog <= 125){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 0;
    } else if (analog > 125 && analog <= 250){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 1;
    } else if (analog > 250 && analog <= 375){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 1;
      combinations[3] = 0;
    } else if (analog > 375 && analog <= 500){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 1;
      combinations[3] = 1;
    } else if (analog > 500 && analog <= 625){
      combinations[0] = 0;
      combinations[1] = 1;
      combinations[2] = 0;
      combinations[3] = 0;
    } else if (analog > 625 && analog <= 750){
      combinations[0] = 0;
      combinations[1] = 1;
      combinations[2] = 0;
      combinations[3] = 1;
    } else if (analog > 750 && analog <= 875){
      combinations[0] = 0;
      combinations[1] = 1;
      combinations[2] = 1;
      combinations[3] = 0;
    } else if (analog > 875 && analog <= 1000){
      combinations[0] = 0;
      combinations[1] = 1;
      combinations[2] = 1;
      combinations[3] = 1;
    } else if (analog > 1000 && analog <= 1125){
      combinations[0] = 1;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 0;
    } else if (analog > 1125 && analog <= 1250){
      combinations[0] = 1;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 1;
    } else if (analog > 1250 && analog <= 1375){
      combinations[0] = 1;
      combinations[1] = 0;
      combinations[2] = 1;
      combinations[3] = 0;
    } else if (analog > 1375 && analog <= 1500){
      combinations[0] = 1;
      combinations[1] = 0;
      combinations[2] = 1;
      combinations[3] = 1;
    } else if (analog > 1500 && analog <= 1625){
      combinations[0] = 1;
      combinations[1] = 1;
      combinations[2] = 0;
      combinations[3] = 0;
    } else if (analog > 1625 && analog <= 1750){
      combinations[0] = 0;
      combinations[1] = 0;
      combinations[2] = 0;
      combinations[3] = 1;
    } else if (analog > 1750 && analog <= 1875){
      combinations[0] = 1;
      combinations[1] = 1;
      combinations[2] = 1;
      combinations[3] = 0;
    } else if (analog > 1875 && analog <= 2000){
      combinations[0] = 1;
      combinations[1] = 1;
      combinations[2] = 1;
      combinations[3] = 1;
    }
    Serial.println("Hello port 1!");
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
    Serial.println("Hello port 2!");
  }
}
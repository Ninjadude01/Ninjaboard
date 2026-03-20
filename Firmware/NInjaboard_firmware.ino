int BUT1 = D10;
int BUT2 = D7;
int BUT3 = D3;
int BUT4 = D6;

int LED1 = D9;
int LED2 = D8;
int LED3 = D4;
int LED4 = D5;

int ledPins[] = {D9, D8, D4, D5};   
int butPins[] = {D10, D7, D3, D6};

unsigned long starttime = 0;
bool pressed = false;
bool endcode = false;

void setup() {

  Serial.begin(9600);
  randomSeed(analogRead(A0));

  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

}

void loop() {
  while(endcode == false){
    pressed = false;
    delay (500);

    int randNum = random (4);

    int currentLED = LED[randNum];
    int currentBUT = BUT[randNum];

    digitalWrite(currentLED, HIGH);
    starttime = millis();

    while(millis() - starttime < 1000){
      if(digitalRead(currentBUT) == LOW){
        pressed = true;
        digitalWrite(currentLED, LOW);
        break;}}


    if(!pressed){
      digitalWrite(currentLED, LOW);
      
      for(int c = 0; c < 3; c ++){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);  
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);  
      delay (500);

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);  
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);  
      delay (500);}
      
      endcode = true;}
      
  }
}



   


      


  

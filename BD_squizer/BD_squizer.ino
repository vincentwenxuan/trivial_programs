


void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  Keyboard.begin();
  delay(4000);
  pinMode(5,INPUT_PULLUP);
}

void loop() {

  if (digitalRead(5)==LOW){
    pinMode(1, OUTPUT);
    delay(20);
    digitalWrite(1, LOW); 
    delay(500);
    pinMode(1, INPUT);
    delay(400);
    pinMode(3, OUTPUT);
    delay(20);
    digitalWrite(3, LOW); 
    delay(500);
    pinMode(3, INPUT);
    delay(400);    

  }
}  


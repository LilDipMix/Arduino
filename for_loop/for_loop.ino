const int motor = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int start_val = 0;
  int end_val = 10;

  for(int i = start_val; i <= end_val; i++) {
    Serial.println(i);
    analogWrite(motor,255)
    delay(1000);
    digitalWrite(motor,LOW);
  }
}


void loop() {
}

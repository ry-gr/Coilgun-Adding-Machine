void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) 
  { 
    String input = Serial.readString();
    input.trim();
    Serial.println(input);
    if(input.equals("go"))
    {
      digitalWrite(2, HIGH);
      Serial.println("discharged capacitor");
      delay(10);
      digitalWrite(2, LOW);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT); //trigger pin for charging relay
  pinMode(2, OUTPUT); //trigger pin for thyristor relay

  digitalWrite(4, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int del;
  if (Serial.available() > 0) 
  { 
    String input = Serial.readString();
    input.trim();
    Serial.println(input);

    if(input.equals("go"))
    {
      digitalWrite(4, HIGH); //turns on charging relay, letting capacitor start to charge
      Serial.println("charging cap");
      del = 20000; //how much should the capacitor charge? 
      for(int i = 0; i<4; i++)
      {
        delay(del/4);
        Serial.print((25*(i+1)));
        Serial.println("% of the way charged");
        //simple charging progress loop
      }
      digitalWrite(4, LOW);
      

      digitalWrite(2, HIGH); //triggers thyristor relay allowing the thyristor to close and the coil to fire
      Serial.println("discharged capacitor");
      delay(10); //latches for 10ms
      digitalWrite(2, LOW);
    }

    if(input.equals("charge"))
    {
      digitalWrite(4, HIGH); //turns on charging relay, letting capacitor start to charge
      Serial.println("charging cap");
      del = 25000; //how much should the capacitor charge? 
      for(int i = 0; i<4; i++)
      {
        delay(del/4);
        Serial.print((25*(i+1)));
        Serial.println("% of the way charged");
        //simple charging progress loop
      }
      digitalWrite(4, LOW);

    }
    if(input.equals("fire"))
    {
      digitalWrite(2, HIGH); //triggers thyristor relay allowing the thyristor to close and the coil to fire
      Serial.println("discharged capacitor");
      delay(10); //latches for 10ms
      digitalWrite(2, LOW);
    }
  }
}

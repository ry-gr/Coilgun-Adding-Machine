void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT); //trigger pin for charging relay
  pinMode(3, OUTPUT); //power for charging relay
  pinMode(2, OUTPUT); //trigger pin for thyristor relay
  pinMode(7, OUTPUT); //power for thyristor relay

  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  //the relays must be set low here otherwise they turn on unpredictably at arduino startup


}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) 
  { 
    digitalWrite(3, HIGH);//supplies power to charging relay
    digitalWrite(7, HIGH);//supplies power to thyristor relay
    String input = Serial.readString();
    input.trim();
    Serial.println(input);

    if(input.equals("go"))
    {
      digitalWrite(4, HIGH); //turns on charging relay, letting capacitor start to charge
      Serial.println("charging cap");
      int del = 18000; //how much should the capacitor charge? 
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


    
  }
}

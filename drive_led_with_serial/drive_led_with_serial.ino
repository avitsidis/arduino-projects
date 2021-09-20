
#define LEDPIN 13
#define DELAY 200

bool isLedpinOn = false; 

void setup() { 
  Serial.begin(9600);
  Serial.println("drive_led_with_serial");
  Serial.println("Starting setup");
  
  pinMode(LEDPIN, OUTPUT);
  
  Serial.println("closing setup");
}

void loop() { 
  if (Serial.available() )
  {
    String command = Serial.readString();
    command.trim();
    Serial.print("command received:"); 
    Serial.println(command); 
    if(command.equals("ON"))
    {
      Serial.println("turn ON");
      isLedpinOn = true;
    }
    else if(command.equals("OFF"))
    {
      Serial.println("turn OFF");
      isLedpinOn = false;
    }
  }
  else
  {
    digitalWrite(LEDPIN,isLedpinOn ? HIGH : LOW);
  }

  delay(DELAY);
}
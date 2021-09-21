
#define DIGIT1 10
#define DIGIT2 11
#define DIGIT3 12
#define DIGIT4 13
#define SEGMENT_A 2
#define SEGMENT_B 3
#define SEGMENT_C 4
#define SEGMENT_D 5
#define SEGMENT_E 6
#define SEGMENT_F 7
#define SEGMENT_G 8
#define SEGMENT_H 9

#define DELAY 200

/*  _       A
 * |_|    F G B
 * |_|.   E D C H
*/


void setup() { 
  Serial.begin(9600);
  Serial.println("four_digits_seven_segments_screen");
  Serial.println("Starting setup");
  
  pinMode(DIGIT1, OUTPUT);
  pinMode(DIGIT2, OUTPUT);
  pinMode(DIGIT3, OUTPUT);
  pinMode(DIGIT4, OUTPUT);
  pinMode(SEGMENT_A, OUTPUT);
  pinMode(SEGMENT_B, OUTPUT);
  pinMode(SEGMENT_C, OUTPUT);
  pinMode(SEGMENT_D, OUTPUT);
  pinMode(SEGMENT_E, OUTPUT);
  pinMode(SEGMENT_F, OUTPUT);
  pinMode(SEGMENT_G, OUTPUT);
  pinMode(SEGMENT_H, OUTPUT);
  
  Serial.println("closing setup");
}

int positions[] = {DIGIT1,DIGIT2,DIGIT3,DIGIT4};
int positionsLength = 4;

int digits[10][8] = {
  //A   B    C    D    E    F    G   H
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW ,LOW }, // 0
  {LOW ,HIGH,HIGH,LOW ,LOW ,LOW ,LOW ,LOW }, // 1
  {HIGH,HIGH,LOW ,HIGH,HIGH,LOW ,HIGH, LOW}, // 2
  {HIGH,HIGH,HIGH,HIGH,LOW ,LOW ,HIGH,LOW }, // 3
  {LOW ,HIGH,HIGH,LOW ,LOW ,HIGH,HIGH ,LOW}, // 4
  {HIGH,LOW ,HIGH,HIGH,LOW ,HIGH,HIGH,LOW }, // 5
  {HIGH,LOW ,HIGH,HIGH,HIGH,HIGH,HIGH,LOW }, // 6
  {HIGH,HIGH,HIGH,LOW ,LOW ,LOW ,LOW ,LOW }, // 7
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW }, // 8
  {HIGH,HIGH,HIGH,HIGH,LOW ,HIGH,HIGH,LOW } // 9
  };
int digitsLength = 10;

int segments[8] = {SEGMENT_A,SEGMENT_B,SEGMENT_C,SEGMENT_D,SEGMENT_E,SEGMENT_F,SEGMENT_G,SEGMENT_H};
int segmentsLenght = 8;

void setDigit(int position,int value)
{
  int positionToSet = position -1;
  for (int positionIndex = 0; positionIndex < positionsLength; positionIndex++) 
  {
    digitalWrite(positions[positionIndex],positionIndex == positionToSet ? LOW : HIGH);
  }
  setValue(value);
}

void setValue(int value)
{
  for(int segmentIndex = 0; segmentIndex < segmentsLenght; segmentIndex++)
  {
    int segmentLevel = digits[value][segmentIndex];
    digitalWrite(segments[segmentIndex],segmentLevel);
  }
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
    }
    else if(command.equals("OFF"))
    {
      Serial.println("turn OFF");
    }
  }
  else
  {

    for(int i = 0; i< 10; i++)
    {
      setDigit(1,i);
      delay(DELAY);
    }


  }

  delay(DELAY);
}
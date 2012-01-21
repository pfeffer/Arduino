int boardLED = 13;
int leftSignal1 = 3;                
int leftSignal2 = 5;

int leftSwitch = 14;
int leftLED = 11;
int x, y;


void setup()                    // run once, when the sketch starts
{
  pinMode(boardLED, OUTPUT);
  
  pinMode(leftSignal1, OUTPUT);
  pinMode(leftSignal2, OUTPUT); 
  
  pinMode(leftSwitch, INPUT);  
  digitalWrite(leftSwitch, HIGH);
  pinMode(leftLED, OUTPUT);   
  
  digitalWrite(boardLED, HIGH);
}

void loop()                     // run over and over again
{ 
  checkLeft();
}

void checkLeft()
{
  if (digitalRead(leftSwitch) == LOW)
  {
    digitalWrite(boardLED, LOW);
    while (digitalRead(leftSwitch) == LOW);
    leftTurn();
  }
}

void leftTurn()
{
  while (true)
  {
    digitalWrite(leftSignal1, HIGH);
    digitalWrite(leftSignal2, LOW);    
    digitalWrite(leftLED, HIGH); 
    for(y=0;y<10;y++)
    {
      delay(30);
      if (digitalRead(leftSwitch) == LOW)
      {
        while (digitalRead(leftSwitch) == LOW);
        digitalWrite(leftSignal1, LOW);
        digitalWrite(leftSignal2, LOW);
        digitalWrite(leftLED, LOW); 
        return;
      }
    }
    digitalWrite(leftSignal1, LOW);
    digitalWrite(leftSignal2, HIGH);
    digitalWrite(leftLED, LOW);
    for(y=0;y<10;y++)
    {
      delay(30);
      if (digitalRead(leftSwitch) == LOW)
      {
        while (digitalRead(leftSwitch) == LOW);
        digitalWrite(leftSignal1, LOW);
        digitalWrite(leftSignal2, LOW);
        digitalWrite(leftLED, LOW);
        return;
      }
    }
    digitalWrite(leftLED, LOW); 
  }
}

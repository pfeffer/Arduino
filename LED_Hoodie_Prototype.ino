int LED = 14;
int s = 11;
int m_LED = 13;
int buttonState;
int lastButtonState = HIGH;
int mode = 0;

int pin5 = 5;
int pin3 = 3;

int timesPressed = 0;

int buttonPressed = 0;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(m_LED, OUTPUT);
  
  pinMode(pin3, OUTPUT);
  pinMode(pin5, OUTPUT);
  
  pinMode(s, INPUT);
  digitalWrite(s, HIGH);
  
  //lastButtonState = digitalRead(s);
}

void loop(){
  buttonState = digitalRead(s);

  if (buttonState == HIGH){
    if (buttonState != lastButtonState){
      timesPressed ++;
    }
    if (timesPressed>0){
      timesPressed = 0;
      buttonPressed = 1 - buttonPressed;
    }
  }else if (buttonState == LOW && buttonPressed == 0 ){
    
  }
  
  lastButtonState = buttonState;
  
  if (buttonPressed == 1){
    digitalWrite(LED, HIGH);
    digitalWrite(m_LED,HIGH);
    
      if (digitalRead(s) == HIGH){
        if (buttonState != lastButtonState){
          buttonState = LOW;
          buttonPressed = 0;
          return;
        }
      }
      digitalWrite(pin3, HIGH);
      digitalWrite(pin5, LOW);
      
      delay(100);
      
      digitalWrite(pin3, LOW);
      digitalWrite(pin5, HIGH);
      delay(100);
  }else{
    digitalWrite(LED, LOW);
    digitalWrite(m_LED,LOW);
    
    digitalWrite(pin3, LOW);
    digitalWrite(pin5, LOW);
  }
 }
 

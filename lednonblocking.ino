int pinRed = 8;
int pinGreen = 9;
int pinYellow = 10;
unsigned long prev1;
unsigned long prev2;
unsigned long prev3;
int ledState1 = LOW;
int ledState2 = HIGH;
int tmp = 0;
float ledBrightness;    

void setup(){
  Serial.begin(9600);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  prev1 = millis();
  prev2 = millis();
  prev3 = millis();
  ledBrightness = 0;
  }

void loop(){
      if (millis() - prev1 >= 1000)
      {
        prev1 = millis();
        if(ledState1 == LOW){
          ledState1 = HIGH;}
        else{
          ledState1 = LOW;}
      } 
    if (millis() - prev2 >= 300)
      {
        prev2 = millis();
        if(ledState2 == HIGH){
          ledState2 = LOW;}
        else{
          ledState2 = HIGH;}
      } 
      if (millis() - prev3 >= 4000)
        {
          prev3 = millis();
          if(tmp == 0){
            tmp = 1;
          }
          else{
            tmp = 0;
          }
        }
        else{
          if(tmp == 0){
            ledBrightness += 0.6375;
            if(ledBrightness >= 255){
              ledBrightness = 255;
            }
          }else{
            ledBrightness -= 0.6375;
            if(ledBrightness <= 0){
              ledBrightness = 0;
            }
          }
        }
        Serial.print(ledBrightness);
        Serial.print("  ");
        digitalWrite(pinRed,ledState1);
        digitalWrite(pinGreen,ledState2);
        digitalWrite(pinYellow,ledBrightness);
    }

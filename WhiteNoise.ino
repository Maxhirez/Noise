const int outputPin = 9;
const int outputPin2 = 10;
const int cvPin = A0;  
int fuzz;
int cvValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
unsigned long previousMilliseconds = 0;   

void setup(){
  pinMode (cvPin, INPUT);
  pinMode (outputPin, OUTPUT);
  pinMode (outputPin2, OUTPUT);
}
void loop(){
 unsigned long currentMilliseconds = millis();
 cvValue = analogRead(cvPin);
 outputValue = map(cvValue, 0, 1023, 0, 255);
 fuzz = (random(2)-1);
 if(currentMilliseconds-previousMilliseconds>=outputValue){
    previousMilliseconds=currentMilliseconds;
    digitalWrite(outputPin, fuzz);
  }
 if(currentMilliseconds-previousMilliseconds>=(outputValue*.7)){
  digitalWrite(outputPin2, fuzz);
 }
}

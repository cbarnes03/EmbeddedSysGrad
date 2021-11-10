void setup() {
  // put your setup code here, to run once:
// pinMode(13,OUTPUT); <- USED TO BLINK LED on Pin 13
// pinMode(9,OUTPUT); <- USED TO BLINK LED on Pin 9


pinMode(13,INPUT);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);

}

// THIS FUNCTION SERVES TO BLINK the LED on pin 13 
//void loop() {    
//digitalWrite(13,HIGH);
//delay(2800);
//digitalWrite(13,LOW);
//delay(2800);
//}

// THIS FUNCTION SERVES TO BLINK the LED on pin 9  
//void loop() {    
//digitalWrite(13,HIGH);
//delay(2800);
//digitalWrite(13,LOW);
//delay(2800);
//}

//THIS FUNCTION LETS THE BOARD CONTROL 3 LEDs WIRED SEPARATELY 
//void loop() {
//digitalWrite(7,LOW);
//digitalWrite(3,HIGH);
//delay(3000);
//digitalWrite(3,LOW);
//digitalWrite(5,HIGH);
//delay(1000);
//digitalWrite(5,LOW);
//digitalWrite(7,HIGH);
//delay(3000);
//}
  void loop() {
//THIS FUNCTION SERVES TO ALLOW NIGHTMODE ON THE TRAFFIC LIGHT WHICH BLINKS THE LEDs ATTACHED IF Pin 13 SHOWS LOW (done manually)
if (digitalRead(13)==LOW){
  digitalWrite(7,LOW);
  digitalWrite(3,HIGH);
  delay(3000);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  digitalWrite(7,HIGH);
  delay(3000);
}
else {
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
}
  }
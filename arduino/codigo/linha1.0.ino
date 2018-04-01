int t = 0;
 
void setup(){
  pinMode(7, INPUT);
  Serial.begin(9600);
}
void loop(){
  t = digitalRead(7);
  if(t == 0)
  {
    Serial.println("t : detectado");
  }
  else
  {
    Serial.println("t : ausente");  
  }
}

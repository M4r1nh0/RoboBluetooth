char letra;
 
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
 
int velocidadeA = 10;
int velocidadeB = 9;
 
void velocidadeMotorA(int valor);
void velocidadeMotorB(int valor);
void motor_andar(int valor1, int valor2);
void motor_esquerda(int valor);
void motor_direita(int valor);
void stop_motor();
 
 
void setup(){
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(velocidadeA,OUTPUT);
  pinMode(velocidadeB,OUTPUT);
 
}
void loop(){
  letra = Serial.read();
  switch(letra){
    case 'w':
      // ir pra frente
       motor_andar(180,180);
       delay(50);
       stop_motor();
    break;
    case 's': //ir pra traz
       motor_re(180,180);
       delay(50);
       stop_motor();
    break;
    case 'a'://ir para esquerda
       motor_esquerda(180);
       delay(50);
       stop_motor();
    break;
    case 'd': //ir para direita
       motor_direita(180);
       delay(80);
       stop_motor();
    break;      
  }
}
 
 
 
void velocidadeMotorA(int valor){
    analogWrite(velocidadeA,valor);
 
}
void velocidadeMotorB(int valor){
    analogWrite(velocidadeB,valor);  
}
 
void motor_andar(int valor1, int valor2){
    velocidadeMotorA(valor1);
    velocidadeMotorB(valor2);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(1);
}
 
void motor_re(int valor1, int valor2){
    velocidadeMotorA(valor1);
    velocidadeMotorB(valor2);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(1);
}
 
void motor_esquerda(int valor){
    velocidadeMotorA(valor);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(1);
}
 
void motor_direita(int valor){
    velocidadeMotorB(valor);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    delay(1);
}
 
void stop_motor(){
   
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
   
}
 
String sprint(String msg){
  Serial.print(msg);
}

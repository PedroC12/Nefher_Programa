

#include <Ultrasonic.h>
//Motor A
#define motorA 2 //velocidade para motores, motor A dianteiro Esquerdo 
#define dirA1 30 
#define dirA2 32 //direção dos motores, horário ou anti-horário
 
//Motor B
#define motorB 3 //motor B dianteiro Direitow
#define dirB1 36 
#define dirB2 34 //direção dos motores, horário ou anti-horário
 
//Motor C
#define motorC 5 //motor C traseiro Esquerdo
#define dirC1 42
#define dirC2 44 //direção dos motores, horário ou anti-horário
 
//Motor D
#define motorD 4 //motor D traseiro Direito
#define dirD1 40
#define dirD2 38 //direção dos motores, horário ou anti-horário

//Leds
#define pinled_verm 22
#define pinled_verde 24
#define pinled_azul 26

//Sensor Infra_Vermelho
#define Sensor_Direita 51
#define Sensor_Esquerda 53
bool Direita, Esquerda;

//Microfone
#define micA A15
int valor_micA = micA; //valor para porta analogica do microfone 
int valor_micD;

//Bluetoth
#define BtRx 20 //porta receptora bluetooth
#define BtTx 21 //porta de transmissão bluetooth
char InfoBt;
char x, y; //x = iniciar, y = parar


//Ultrasom
#define pino_trigger 7
#define pino_echo 6
Ultrasonic ultrasonic(pino_trigger, pino_echo);

int d = 130;
int v = 110;
void setup(){
 
  Serial.begin(9600);
 
  pinMode(motorA, OUTPUT);
 
  pinMode(motorB, OUTPUT);
 
  pinMode(motorC, OUTPUT);
 
  pinMode(motorD, OUTPUT);
 
  pinMode(dirA1, OUTPUT);
  pinMode(dirA2, OUTPUT);
 
  pinMode(dirB1, OUTPUT);
  pinMode(dirB2, OUTPUT);
 
  pinMode(dirC1, OUTPUT);
  pinMode(dirC2, OUTPUT);
 
  pinMode(dirD1, OUTPUT);
  pinMode(dirD2, OUTPUT);

  pinMode(micA, INPUT);

 
  pinMode(pinled_verm, OUTPUT);
  pinMode(pinled_verde, OUTPUT);
  pinMode(pinled_azul, OUTPUT);

  pinMode(Sensor_Direita, INPUT);
  pinMode(Sensor_Esquerda,INPUT);
 }
 
void loop() {
valor_micA = analogRead(A15);

Serial.print("Valor Analogico: ");
delay(20);
Serial.println(valor_micA);
delay(20);

//Armazena e printa Sensor Ultrasonico
  float cm;
  long microsec = ultrasonic.timing();
  cm = ultrasonic.convert(microsec, Ultrasonic::CM);
  

 /* //Armazena e Printa os Sensores Infra_Red
  Direita = digitalRead(Sensor_Direita);
  Esquerda = digitalRead(Sensor_Esquerda);
  Serial.print(Esquerda);
  Serial.print(" || ");
  Serial.println(Direita);
  delay(300);
}
*/
  Direita = digitalRead(Sensor_Direita);
  Esquerda = digitalRead(Sensor_Esquerda);
  //Codigo para os 2 sensores identificando a faixa

  if (cm < 10 || (Esquerda == 1 && Direita == 1)){
    digitalWrite(pinled_azul, HIGH);
             

                
                }
  else if (valor_micA > 400){
               digitalWrite(pinled_verm, HIGH);

  }
  
  if (cm > 20){
  if((Esquerda == 0 && Direita == 0)) 
 
{
         
                analogWrite(motorA, v);
                 digitalWrite(dirA1, HIGH);
                 digitalWrite(dirA2, LOW);
 
                analogWrite(motorB, v);
                 digitalWrite(dirB1, LOW);
                 digitalWrite(dirB2, HIGH);
 
                analogWrite(motorC, v);
                 digitalWrite(dirC1, LOW);
                 digitalWrite(dirC2, HIGH);
 
                analogWrite(motorD, d);
                 digitalWrite(dirD1, LOW);
                 digitalWrite(dirD2, HIGH);

  }
 
  //Carrinho virando para a direita quando o sensor esquerdo não capta sinal
 
  else if((Esquerda == 0 && Direita == 1))
  {
                
                analogWrite(motorA, v);
                 digitalWrite(dirA1, HIGH);
                 digitalWrite(dirA2, LOW);
              
                analogWrite(motorB, v);
                 digitalWrite(dirB1, HIGH);
                 digitalWrite(dirB2, LOW);
               
                analogWrite(motorC, v);
                 digitalWrite(dirC1, LOW);
                 digitalWrite(dirC2, HIGH);
               
                analogWrite(motorD, d);
                 digitalWrite(dirD1, HIGH);
                 digitalWrite(dirD2, LOW);
  }
 
  //Carrinho virando para a esquerda quando o sensor direito não capta sinal
 
  else if((Esquerda == 1 && Direita == 0))
  {
 

                analogWrite(motorA, v);
                 digitalWrite(dirA1, LOW);
                 digitalWrite(dirA2, HIGH);
               
                analogWrite(motorB, v);
                 digitalWrite(dirA1, LOW);
                 digitalWrite(dirA2, HIGH);
               
                analogWrite(motorC, v);
                 digitalWrite(dirA1, HIGH);
                 digitalWrite(dirA2, LOW);
               
                analogWrite(motorD, d);
                 digitalWrite(dirA1, LOW);
                 digitalWrite(dirA2, HIGH);
}
}
  if((Esquerda == 1 && Direita == 1)) 
 
{
                     analogWrite(motorA, 60);
                 digitalWrite(dirA1, HIGH);
                 digitalWrite(dirA2, HIGH);
 
                analogWrite(motorB, 60);
                 digitalWrite(dirB1, HIGH);
                 digitalWrite(dirB2, HIGH);
 
                analogWrite(motorC, 60);
                 digitalWrite(dirC1, HIGH);
                 digitalWrite(dirC2, HIGH);
 
                analogWrite(motorD, 80);
                 digitalWrite(dirD1, HIGH);
                 digitalWrite(dirD2, HIGH);
 
  }
  
  else if (cm < 20){
                 analogWrite(motorA, v);
                 digitalWrite(dirA1, HIGH);
                 digitalWrite(dirA2, HIGH);
 
                analogWrite(motorB, v);
                 digitalWrite(dirB1, HIGH);
                 digitalWrite(dirB2, HIGH);
 
                analogWrite(motorC, v);
                 digitalWrite(dirC1, HIGH);
                 digitalWrite(dirC2, HIGH);
 
                analogWrite(motorD, d);
                 digitalWrite(dirD1, HIGH);
                 digitalWrite(dirD2, HIGH);
  }
}

 
 



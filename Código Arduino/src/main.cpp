#include "Arduino.h"
#include "Volante.h"
#include "Giroscopio.h"
#include "MotorDC.h"
#include "Pinos.h"
#include "Robo.h"
#include "Tempo.h"

//* Este arquivo contém o código principal do robô, que junta todas as funções e estrutura a lógica principal do robô

//TODO: Mudar o README para ter um tutorial de como usar o código
//TODO: Adicionar comentários explicativos no código

// Declarações dos objetos -----------------------------------------------------------------------------------------------------------------------------------------------------------

//MotorDC motor_dc(ENCA, ENCB, PWM, IN1, IN2);
//Volante volante(SERVO);
//Giroscopio giroscopio;
//Robo robo(motor_dc, volante, giroscopio);

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

float float1 = 0.0; // Variável para armazenar o primeiro float recebido pela comunicação serial
float float2 = 0.0; // Variável para armazenar o segundo float recebido pela comunicação serial

// Declaração das variáveis de tempo ------------------------------------------------------------------------------------------------------------------------------------------------

double T; // tempo atual em milissegundos
double prevT; // tempo anterior em milissegundos
double dt; // diferença de tempo em segundos

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Declaração da comunicação serial do ROS ------------------------------------------------------------------------------------------------------------------------------------------

//? Quais são os tipos de mensagens que precisarão ser enviadas pelo ROS?
//TODO: Verificar se é necessário enviar mensagens de outros tipos
//TODO: Criar Publisher e Subscriber para os tipos de mensagens necessários

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Funções principais do código ----------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {

  // Início da comunicação serial
  Serial.begin(9600);

  // Declaração de pinos do encoder do motor {
    
    //attachInterrupt(digitalPinToInterrupt(ENCA), [](){
    //  motor_dc.ler_encoder();
    //}, RISING);

  //}

}

void loop() {
  
  // Cálculo do tempo decorrido
  T = millis(); // tempo atual em milissegundos
  dt = (T - prevT)/1000.0; // tempo decorrido em segundos em relação a última medição
  prevT = T; // atualiza o tempo anterior
  
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read the input from serial until newline character
    int commaIndex = input.indexOf(','); // Find the index of the comma character
    if (commaIndex != -1) { // If comma character is found
      String float1Str = input.substring(0, commaIndex); // Extract the first float string
      String float2Str = input.substring(commaIndex + 1); // Extract the second float string
      float1 = float1Str.toFloat(); // Convert the first float string to float
      float2 = float2Str.toFloat(); // Convert the second float string to float
      // Now you can use float1 and float2 variables for further processing
    }
  }

  // Ler encoder do motor
  //robo.motor.ler_encoder();

}
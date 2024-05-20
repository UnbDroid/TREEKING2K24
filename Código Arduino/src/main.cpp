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

// Declaração das variáveis de tempo ------------------------------------------------------------------------------------------------------------------------------------------------

double T;
double prevT; 
double dt;

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Funções principais do código ----------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {

  // Início da comunicação serial
  Serial.begin(9600);

  //! Inicialização dos objetos (oficial) -------------------------------------------------------------------------------------------------------------------------------------------
  
  //robo.ligar_robo();

  //! --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  // Inicialização dos objetos (teste) ---------------------------------------------------------------------------------------------------------------------------------------------

  //volante.inicializar_volante();
  //motor_dc.ligar_encoder();
  //giroscopio.ligar_mpu();

  // --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

}


void loop() {
  
  // Cálculo do tempo decorrido
  T = millis();
  dt = (T - prevT)/1000.0; // Usa a diferença em um segundo
  prevT = T;

  

}
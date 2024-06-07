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

MotorDC motor_dc_esquerdo(ENCA_Esquerdo, ENCB_Esquerdo, PWM_Esquerdo, IN1_Esquerdo, IN2_Esquerdo);
MotorDC motor_dc_direito(ENCA_Direito, ENCB_Direito, PWM_Direito, IN1_Direito, IN2_Direito);
// Volante volante(SERVO);
// Giroscopio giroscopio;
// Robo robo(motor_dc_esquerdo, motor_dc_direito, volante, giroscopio);

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Declaração das variáveis de tempo ------------------------------------------------------------------------------------------------------------------------------------------------

long T;
long prevT; 
double dt;

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void interrupcao_encoder_esquerdo() {
  motor_dc_esquerdo.ler_encoder();
}

void interrupcao_encoder_direito() {
  motor_dc_direito.ler_encoder();
}

// Funções principais do código ----------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {

  //! Início da comunicação serial ---------------------------------------------------------------------------------------------------------------------------------------------------

  Serial.begin(9600);

  //! --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  //! Inicialização dos objetos (oficial) -------------------------------------------------------------------------------------------------------------------------------------------
  
  // robo.ligar_robo();

  //! --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



  // Inicialização dos objetos (teste) ---------------------------------------------------------------------------------------------------------------------------------------------

  // volante.inicializar_volante();
  attachInterrupt(digitalPinToInterrupt(ENCA_Esquerdo), interrupcao_encoder_esquerdo, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCA_Esquerdo), interrupcao_encoder_direito, RISING);
  // giroscopio.ligar_mpu();

  // --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



  // Funções de teste ---------------------------------------------------------------------------------------------------------------------------------------------------------------

  // motor_dc.andar_reto_cm(10, 80);
  // robo.virar_robo(90);

  // --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



}

void loop() {



  //! -------------------- Núcleo do código ---------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  atualizar_tempo();

  //! --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



  // -------------------- Funções de teste ---------------------------------------------------------------------------------------------------------------------------------------------------------------

  // robo.virar_robo(90);

  motor_dc_esquerdo.andar_reto(30); //! Ajustar aqui a velocidade em RPM
  motor_dc_direito.andar_reto(30); //! Ajustar aqui a velocidade em RPM
  
  // analogWrite(PWM, 100);
  // digitalWrite(IN1, HIGH);
  // digitalWrite(IN2, LOW);

  // Serial.print("Posição Esquerda: ");
  // Serial.print(motor_dc_esquerdo.posi);
  // Serial.print(" | ");
  // Serial.print("Posição Direita: ");
  // Serial.println(motor_dc_direito.posi);

  // --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



}
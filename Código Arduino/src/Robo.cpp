#include "MotorDC.h"
#include "Volante.h"
#include "Giroscopio.h"
#include "Robo.h"
#include "Pinos.h"
#include "Arduino.h"
#include "Wire.h"
#include "Tempo.h"

//* Este arquivo contém a implementação da classe Robo, que é responsável por
//* controlar o robô e ter os comandos básicos de movimentação

//! Antes de começar a declarar as funções, vamos declarar o subscriber do ROS ------------------------------------------------------

const int rxPin = 2; // Pino RX do módulo Serial
const int txPin = 3; // Pino TX do módulo Serial

//! ---------------------------------------------------------------------------------------------------------------------------------

// Construtor da classe Robo
//! De novo, eu tô confiando 100% no Copilot aqui, porque ele falou que tá tudo certo :D
Robo::Robo(MotorDC& motor, Volante& volante, Giroscopio& giroscopio)
: motor(motor), volante(volante), giroscopio(giroscopio)
{
    Serial.println("Robo construido");
}

void Robo::ler_visao() {
    if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int commaIndex = input.indexOf(',');
    if (commaIndex != -1) {
      String float1Str = input.substring(0, commaIndex);
      String float2Str = input.substring(commaIndex + 1);
      Robo::cone_posicao_x = float1Str.toFloat();
      Robo::cone_posicao_y = float2Str.toFloat();
    }
  }
}

// Função para fazer o robô andar reto indefinidamente
void Robo::andar_reto(int velocidade_rpm)
{
    motor.andar_reto(velocidade_rpm);
}

void Robo::andar_reto_cm (int distancia_cm, int velocidade_rpm) {
    motor.andar_reto_cm(distancia_cm, velocidade_rpm);
}

// Função para fazer o robô virar para um ângulo específico
void Robo::virar_robo(int angulo)
{
    //!
    //! Ainda não testada
    //!
    //TODO: Testar a função

    int giro_volante = 0; // Valor de giro do volante
    float valor_angulacao_inicial = giroscopio.get_z(); // Valor atual do ângulo de yaw (z)
    float angulo_final = valor_angulacao_inicial + angulo; // Valor final do ângulo de yaw (z)
    // Enquanto o robô não atingir o ângulo desejado
    while (static_cast<int>(giroscopio.get_z()) != static_cast<int>(angulo_final)) { //! Supostamente esse static_cast é pra converter de float pra int, mas de novo, eu tô confiando 100% no Copilot
            if (angulo_final - giroscopio.get_z() > 35) { // Se a diferença entre o ângulo desejado e o atual for menor que 10 graus
                giro_volante = 35;
            } else if (angulo_final - giroscopio.get_z() < (-35)) {
                giro_volante = -35;
            } else {
                giro_volante = (angulo_final - giroscopio.get_z()) > 10 || (angulo_final - giroscopio.get_z()) < -10 ? (angulo_final - giroscopio.get_z()) : 10;
            }
            volante.virar_volante(giro_volante);
            int velocidade_rpm = 80 + (abs(giro_volante) * 40 / 35); // Velocidade de referência
            Robo::andar_reto(velocidade_rpm);
    }
}

float Robo::retornar_posicao_x_do_cone() { 
    Robo::ler_visao();
    return Robo::cone_posicao_x;
}

float Robo::retornar_posicao_y_do_cone() {
    Robo::ler_visao();
    return Robo::cone_posicao_y;
}

void Robo::alinhar_com_cone() { // Função para fazer o robô alinhar com um cone
    Robo::ler_visao(); // Lê a visão do robô
    delay(1); // Delayzinho pra dar tempo de processar as mensagens
    while (Robo::cone_posicao_x > 0.01 or Robo::cone_posicao_x < 0.01) { // 0.01 é a tolerância, pode ser ajustada
        Robo::ler_visao(); // Lê a visão do robô
        delay(1); // Delayzinho pra dar tempo de processar as mensagens
        int angulo = Robo::cone_posicao_x > 0 ? 1 : -1; // gira para a direita se x > 0, caso contrário gira para a esquerda
        if (Robo::cone_posicao_x > 0.01) {  // Se o cone estiver à direita
            angulo = -35;
        } else if (Robo::cone_posicao_x < -0.01) { // Se o cone estiver à esquerda
            angulo = 35;
        }
        volante.virar_volante(angulo); // O volante gira para o ângulo desejado
        motor.ligar_motor(1, 80 + (abs(angulo) * 40 / 35)); // O robô anda encurvado
    }
}
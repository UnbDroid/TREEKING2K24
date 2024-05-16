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

// Construtor da classe Robo
//! De novo, eu tô confiando 100% no Copilot aqui, porque ele falou que tá tudo certo :D
Robo::Robo(MotorDC& motor, Volante& volante, Giroscopio& giroscopio)
: motor(motor), volante(volante), giroscopio(giroscopio)
{
    giroscopio.ligar_mpu();
    motor.ligar_encoder();
}

//Função responsável por ler e armazenar a posição do cone na visão recebida pela comunicação serial
void Robo::ler_visao() {
    if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int commaIndex = input.indexOf(',');
    if (commaIndex != -1) {
      String float1Str = input.substring(0, commaIndex);
      String float2Str = input.substring(commaIndex + 1);
      cone_posicao_x = float1Str.toFloat(); // cone_posicao_x recebe o valor da posição x do cone
      cone_posicao_y = float2Str.toFloat(); // cone_posicao_y recebe o valor da posição y do cone
    }
  }
}

// Função para fazer o robô andar reto indefinidamente
void Robo::andar_reto(int velocidade_rpm)
{
    motor.andar_reto(velocidade_rpm);
}

// Função para fazer o robô andar reto por uma distância específica
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

    int giro_volante = 0;
    float valor_angulacao_inicial = giroscopio.get_z();
    float angulo_final = valor_angulacao_inicial + angulo;

    // Enquanto o robô não atingir o ângulo desejado, ele vira o volante e anda pra frente
    while (static_cast<int>(giroscopio.get_z()) != static_cast<int>(angulo_final)) { //! Supostamente esse static_cast é pra converter de float pra int, mas de novo, eu tô confiando 100% no Copilot
            if (angulo_final - giroscopio.get_z() > 35) {
                giro_volante = 35;
            } else if (angulo_final - giroscopio.get_z() < (-35)) {
                giro_volante = -35;
            } else {
                giro_volante = static_cast<int>((angulo_final - giroscopio.get_z()) > 10 || (angulo_final - giroscopio.get_z()) < -10 ? (angulo_final - giroscopio.get_z()) : 10);
            }
            volante.virar_volante(giro_volante);
            int velocidade_rpm = 80 + (abs(giro_volante) * 40 / 35); // Velocidade de referência
            Robo::andar_reto(velocidade_rpm);
    }
}

// Função para retornar a posição x do cone
float Robo::retornar_posicao_x_do_cone() { 
    Robo::ler_visao();
    return cone_posicao_x;
}

// Função para retornar a posição y do cone
float Robo::retornar_posicao_y_do_cone() {
    Robo::ler_visao();
    return cone_posicao_y;
}

// Função para fazer o robô alinhar com um cone (faz o mesmo que virar_robo, mas usando a visão do robô como referência para alinhar com o cone)
void Robo::alinhar_com_cone() {
    Robo::ler_visao();
    int giro_volante = 0;
    while (cone_posicao_x > 0.05 or cone_posicao_x < 0.05) { //! 0.05 é a tolerância, mas pode e deve ser ajustada
        Robo::ler_visao();
        if (cone_posicao_x > 0.10) {  // Se o cone estiver à direita
            giro_volante = -35;
        } else if (cone_posicao_x < -0.10) { // Se o cone estiver à esquerda
            giro_volante = 35;
        } else {
            giro_volante = static_cast<int>(angulo_atual_x*3.5);
        }
        volante.virar_volante(giro_volante);
        Robo::andar_reto(80 + (abs(giro_volante) * 40 / 35));
    }
}
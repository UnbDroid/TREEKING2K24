#include "MotorDC.h"
#include "Volante.h"
#include "Giroscopio.h"
#include "Robo.h"
#include "Pinos.h"
#include "Arduino.h"
#include "Wire.h"
#include "Tempo.h"
#include "ros.h"
#include "std_msgs/Float32MultiArray.h"

//* Este arquivo contém a implementação da classe Robo, que é responsável por
//* controlar o robô e ter os comandos básicos de movimentação

//! Antes de começar a declarar as funções, vamos declarar o subscriber do ROS ------------------------------------------------------

ros::NodeHandle nh; // Cria um objeto do tipo NodeHandle que serve para se comunicar com o ROS

float cone_posicao_x; // Variável que armazena a posição x do cone
float cone_posicao_y; // Variável que armazena a posição y do cone

void posicaoCallback(const std_msgs::Float32MultiArray& msg) { // Função de callback para o subscriber do ROS (que recebe a posição do robô)
    cone_posicao_x = msg.data[0]; // Armazena a posição x do cone recebida pelo rosserial
    cone_posicao_y = msg.data[1]; // Armazena a posição y do cone recebida pelo rosserial
} 

ros::Subscriber<std_msgs::Float32MultiArray> sub("distancia_posicionamento", &posicaoCallback); // Cria um subscriber que recebe a posição do robô (subscriber é um objeto que recebe mensagens do tópico "distancia_posicionamento" do ROS)

//! ---------------------------------------------------------------------------------------------------------------------------------

// Construtor da classe Robo
//! De novo, eu tô confiando 100% no Copilot aqui, porque ele falou que tá tudo certo :D
Robo::Robo(MotorDC& motor, Volante& volante, Giroscopio& giroscopio)
: motor(motor), volante(volante), giroscopio(giroscopio)
{
    Serial.println("Robo construido");
    nh.initNode(); // Inicializa o nó do ROS
    nh.subscribe(sub); // Inicializa o subscriber do ROS
}

// Função para fazer o robô andar reto indefinidamente
void Robo::andar_reto(int velocidade_rpm)
{
    //!
    //! Ainda não testada
    //!
    //TODO: Testar a função

    motor.rpm_referencia = velocidade_rpm; // Velocidade de referência
  
    double posi_atual = 0; // posição atual do encoder
    noInterrupts(); // desabilita interrupções
    posi_atual = motor.posi; // atualiza a posição atual do encoder
    interrupts(); // reabilita interrupções

    motor.voltas_anterior = motor.voltas; // atualiza o número de voltas anterior

    motor.voltas = posi_atual/motor.encoder_volta; // calcula o número de voltas do motor
    motor.rps = (motor.voltas - motor.voltas_anterior)/dt; // calcula a velocidade do motor em rps

    double e = motor.rpm_referencia - (motor.rps * 60); // calcula o erro da velocidade em rpm

    float p = motor.kp * e;

    motor.eintegral += e;

    float d = motor.kd * (e - motor.eprev)/dt;

    float u = p + (motor.ki * motor.eintegral)+ d;

    float pwmVal = fabs(u); // valor do pwm que será enviado ao motor
    if(pwmVal > 255) {
        pwmVal = 255;
    }

    if(u > 0){
        motor.dir = 1;
    }
    else if(u < 0){
        motor.dir = -1;
    }
    else{
        motor.dir = 0;
    }

    motor.ligar_motor(motor.dir, pwmVal);
}

void Robo::andar_reto_cm(int distancia_cm, int velocidade_rpm) {
    //TODO: Alterar o valor do comprimento da roda para o valor correto
    //TODO: Testar a função

    //! Com certeza absoluta a gente vai ter que fazer um controle pra velocidade, porque ele vai andar mais do que o necessário
    //! mas por enquanto vamos deixar assim :D
    
    int voltas_inicio = motor.posi / motor.encoder_volta;
    if (distancia_cm > 0) {
        while ((motor.posi / motor.encoder_volta) - voltas_inicio < distancia_cm) {
            andar_reto(velocidade_rpm);
        }
    } else {
        while ((motor.posi / motor.encoder_volta) - voltas_inicio > distancia_cm) {
            andar_reto(velocidade_rpm);
        }
    }
}

// Função para fazer o robô virar para um ângulo específico
void Robo::virar_robo(int angulo)
{
    //!
    //! Ainda não testada
    //!
    //TODO: Testar a função

    int giro_volante = 0; // Valor de giro do volante
    float valor_angulacao_inicial = giroscopio.get_yaw(); // Valor atual do ângulo de yaw (z)
    // Enquanto o robô não atingir o ângulo desejado
    while (static_cast<int>(giroscopio.get_yaw()) != static_cast<int>(valor_angulacao_inicial + angulo)) { //! Supostamente esse static_cast é pra converter de float pra int, mas de novo, eu tô confiando 100% no Copilot
        if ((valor_angulacao_inicial + angulo) - giroscopio.get_yaw() > 35) { // Se a diferença entre o ângulo desejado e o atual for menor que 10 graus
          giro_volante = 35;
        } else if ((valor_angulacao_inicial + angulo) - giroscopio.get_yaw() < (-35)) { // Se a diferença entre o ângulo desejado e o atual for maior que 10 graus
          giro_volante = -35;
        } else {
          giro_volante = (valor_angulacao_inicial + angulo) - giroscopio.get_yaw(); // Gira o volante para o ângulo desejado
        }
        volante.virar_volante(giro_volante); // O volante gira para o ângulo desejado
        int velocidade_rpm = 80 + (abs(giro_volante) * 40 / 35); // Velocidade de referência
        motor.ligar_motor(1, velocidade_rpm); // O robô anda reto
    }
}

void Robo::alinhar_com_cone() { // Função para fazer o robô alinhar com um cone
    nh.spinOnce(); // Verifica se há mensagens do ROS e as processa (chamando a função de callback)
    delay(1); // Delayzinho pra dar tempo de processar as mensagens
    while (cone_posicao_x > 0.01 or cone_posicao_x < 0.01) { // 0.01 é a tolerância, pode ser ajustada
        nh.spinOnce(); // Verifica se há mensagens do ROS e as processa
        delay(1); // Delayzinho pra dar tempo de processar as mensagens
        int angulo = cone_posicao_x > 0 ? 1 : -1; // gira para a direita se x > 0, caso contrário gira para a esquerda
        if (cone_posicao_x > 0.01) {  // Se o cone estiver à direita
            angulo = -35;
        } else if (cone_posicao_x < -0.01) { // Se o cone estiver à esquerda
            angulo = 35;
        }
        volante.virar_volante(angulo); // O volante gira para o ângulo desejado
        motor.ligar_motor(1, 80 + (abs(angulo) * 40 / 35)); // O robô anda encurvado
    }
}
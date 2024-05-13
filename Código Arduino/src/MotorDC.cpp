#include "MotorDC.h"
#include "Arduino.h"
#include "Wire.h"
#include "Tempo.h"

//* Esse arquivo contém a implementação da classe MotorDC, que é responsável por controlar o motor DC do robô
//* e fornecer os valores de velocidade e direção de giro do motor

// Construtor da classe MotorDC
MotorDC::MotorDC(const int ENCA, const int ENCB, const int PWM, const int IN1, const int IN2)
{
  this->ENCA = ENCA;
  this->ENCB = ENCB;
  this->PWM = PWM;
  this->IN1 = IN1;
  this->IN2 = IN2;
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  pinMode(PWM, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

// Função para ligar o motor e definir a direção e a velocidade
void MotorDC::ligar_motor(int dir, int pwmVal)
{
  analogWrite(PWM, pwmVal); // (pino do pwm, valor do pwm (máximo = 255))
  if (dir == 1)
  { // 1 para frente
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else if (dir == -1)
  { // -1 para trás
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  else
  { // 0 para parar
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}

// Função para ler o encoder do motor
void MotorDC::ler_encoder()
{
  double b = digitalRead(ENCB);
  if (b > 0)
  { // Se ler pulso positivo do encoder
    posi++;
  }
  else
  { // Se ler pulso negativo do encoder
    posi--;
  }
}

void MotorDC::andar_reto(int velocidade_rpm)
{
  //!
  //! Ainda não testada
  //!
  // TODO: Testar a função

  MotorDC::rpm_referencia = velocidade_rpm; // Velocidade de referência

  double posi_atual = 0;      // posição atual do encoder
  noInterrupts();             // desabilita interrupções
  posi_atual = MotorDC::posi; // atualiza a posição atual do encoder
  interrupts();               // reabilita interrupções

  MotorDC::voltas_anterior = MotorDC::voltas; // atualiza o número de voltas anterior

  MotorDC::voltas = posi_atual / MotorDC::encoder_volta;            // calcula o número de voltas do motor
  MotorDC::rps = (MotorDC::voltas - MotorDC::voltas_anterior) / dt; // calcula a velocidade do motor em rps

  double e = MotorDC::rpm_referencia - (MotorDC::rps * 60); // calcula o erro da velocidade em rpm

  float p = MotorDC::kp * e;

  MotorDC::eintegral += e;

  float d = MotorDC::kd * (e - MotorDC::eprev) / dt;

  float u = p + (MotorDC::ki * MotorDC::eintegral) + d;

  float pwmVal = fabs(u); // valor do pwm que será enviado ao motor

  if (pwmVal > 255) // Limita o valor do pwm para 255
  {
    pwmVal = 255;
  }

  // Define a direção do motor com base no valor de u
  if (u > 0)
  {
    MotorDC::dir = 1;
  }
  else if (u < 0)
  {
    MotorDC::dir = -1;
  }
  else
  {
    MotorDC::dir = 0;
  }

  MotorDC::ligar_motor(MotorDC::dir, pwmVal);
}

void MotorDC::andar_reto_cm(int distancia_cm, int velocidade_rpm)
{
  // TODO: Alterar o valor do comprimento da roda para o valor correto
  // TODO: Testar a função

  //! Com certeza absoluta a gente vai ter que fazer um controle pra velocidade, porque ele vai andar mais do que o necessário
  //! mas por enquanto vamos deixar assim :D

  int voltas_inicio = MotorDC::posi / MotorDC::encoder_volta;
  if (distancia_cm > 0)
  {
    while ((MotorDC::posi / MotorDC::encoder_volta) - voltas_inicio < distancia_cm)
    {
      andar_reto(velocidade_rpm);
    }
  }
  else
  {
    while ((MotorDC::posi / MotorDC::encoder_volta) - voltas_inicio > distancia_cm)
    {
      andar_reto(velocidade_rpm);
    }
  }
}
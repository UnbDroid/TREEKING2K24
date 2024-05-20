#include "Arduino.h"
#include "Volante.h"
#include "Wire.h"

//* Esse arquivo contém a implementação da classe Volante, que é responsável por controlar o servo motor que controla o volante do robô

Volante::Volante(const int SERVO)
{
    this->SERVO = SERVO;
}

int Volante::return_angulo_inicial()
{
    return s.read();
}

void Volante::set_angulo_inicial(int angulo)
{
    angulo_inicial = angulo;
}

void Volante::inicializar_volante()
{
    s.attach(SERVO);
    set_angulo_inicial(return_angulo_inicial());
}

void Volante::resetar_volante()
{
    s.write(angulo_inicial);
}

void Volante::virar_volante(int angulo)
{
    int angulo_final = angulo_inicial + angulo;
    s.write(angulo_final);
    //TODO: Verificar o ângulo máximo que o servo pode virar
}
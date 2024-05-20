#ifndef Volante_h
#define Volante_h

#include "Arduino.h"
#include "Servo.h"

//* Este arquivo contém a declaração da classe Volante, que é responsável por
//* controlar o servo motor do câmbio de direção do robô

class Volante{
    public:
        Volante(const int SERVO);
        int return_angulo_inicial();
        void set_angulo_inicial(int angulo);
        void inicializar_volante(); // Função para inicializar o volante
        void resetar_volante(); // Função para resetar o volante para a posição inicial
        void virar_volante(int angulo); // Função para virar o volante para um ângulo específico
    private:
        int SERVO;
        Servo s;
        int angulo_inicial = 0;
};

#endif


#ifndef MotorDC_h
#define MotorDC_h

#include "Arduino.h"

class MotorDC{
    public:
        MotorDC(const int ENCA, const int ENCB, const int PWM, const int IN1, const int IN2);
        volatile double posi;
        double voltas = 0; // número de voltas do motor
        double voltas_anterior = 0; // número de voltas do motor no instante anterior, para cálculo do erro
        double rps = 0; // velocidade ATUAL do motor em radianos por segundo
        int rpm_referencia = 80; // velocidade desejada do motor, velocidade que ele buscará alcançar
        double rps_max = 5.75; // velocidade máxima do motor (apenas por curiosidade, usar caso seja necessário)
        double comprimento_roda = 6*2*3.1415; // Usado para cálculo dos valores em cm (velocidade e espaço percorrido)
        float eprev = 0;
        float eintegral = 0; // ki do controle PID
        int dir = 1; // 1 para frente, -1 para trás (pelo menos essa é a ideia)
        const int encoder_volta = 1044; // valor de encoder referente a uma volta completa da roda
        const float kp = 5.0; // constante proporcional do controle PID
        const float ki = 3.0; // constante integral do controle PID
        const float kd = 0.0; // constante derivativa do controle PID
        void ligar_motor(int dir, int pwmVal);
        void ler_encoder();
    private:
        int ENCA; // YELLOW
        int ENCB; // WHITE
        int PWM;
        int IN1;
        int IN2;
};

#endif
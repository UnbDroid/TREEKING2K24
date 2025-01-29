#include <stdio.h>
#include "MotorDC.h"

MotorDC::MotorDC(const int ENCA, const int ENCB, const int L_EN, const int L_PWM, const int R_PWM)
{
    this->ENCA = ENCA;
    this->ENCB = ENCB;
    this->L_EN = L_EN;
    this->L_PWM = L_PWM;
    this->R_PWM = R_PWM;

    // instance = this;
}

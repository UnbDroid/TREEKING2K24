#ifndef __Pinos_h
#define __Pinos_h

//* Este arquivo contém a declaração dos pinos utilizados no projeto

// Declarações do motor -----------------------------------------------------------------------------------------------------------------------------------------------------------

    #define ENCA_Esquerdo 18 // Cabo amarelo
    #define ENCB_Esquerdo 19 // Cabo branco
    #define PWM_Esquerdo 5 // 5 para uso no Mega, 6 para uso no Uno
    #define IN1_Esquerdo 6 // 6 para uso no Mega, 10 para uso no Uno
    #define IN2_Esquerdo 7 // 7 para uso no Mega, 11 para uso no Uno

    #define ENCA_Direito 2 // Cabo amarelo
    #define ENCB_Direito 3 // Cabo branco
    #define PWM_Direito 11
    #define IN1_Direito 13
    #define IN2_Direito 12

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Declarações do MPU9250 ---------------------------------------------------------------------------------------------------------------------------------------------------------

    #define SDA 20 // 20 para uso no Mega, A4 para uso no Uno
    #define SCL 21 // 21 para uso no Mega, A5 para uso no Uno
    //! Provavelmente não será necessário, mas é bom ter esses valores aqui para referência

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Declarações do Servo -----------------------------------------------------------------------------------------------------------------------------------------------------------

    #define SERVO 9

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
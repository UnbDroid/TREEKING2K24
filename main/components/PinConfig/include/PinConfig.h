#ifndef __PIN_CONFIG_H__
#define __PIN_CONFIG_H__

#include "driver/gpio.h"
#include "driver/ledc.h"

#define L_EN_ESQUERDO_FRENTE 1  //placeholders
#define L_PWM_ESQUERDO_FRENTE 2 //placeholders
#define R_PWM_ESQURDO_FRENTE 3 //placeholders
#define OUTPUT_ESQUERDO_FRENTE ((1ULL<<L_EN_ESQUERDO_FRENTE) | (1ULL<<L_PWM_ESQUERDO_FRENTE) | (1ULL<<R_PWM_ESQURDO_FRENTE))
#define ENCA_ESQUERDO_FRENTE 4 //placeholders
#define ENCB_ESQUERDO_FRENTE 5 //placeholders
#define INPUT_ESQUERDO_FRENTE ((1ULL<<ENCA_ESQUERDO_FRENTE) | (1ULL<<ENCB_ESQUERDO_FRENTE))

#define L_EN_ESQUERDO_TRAS 6 //placeholders
#define L_PWM_ESQUERDO_TRAS 7 //placeholders
#define R_PWM_ESQURDO_TRAS 8 //placeholders
#define OUTPUT_ESQUERDO_TRAS ((1ULL<<L_EN_ESQUERDO_TRAS) | (1ULL<<L_PWM_ESQUERDO_TRAS) | (1ULL<<R_PWM_ESQURDO_TRAS))
#define ENCA_ESQUERDO_TRAS 9 //placeholders
#define ENCB_ESQUERDO_TRAS 10 //placeholders
#define INPUT_ESQUERDO_TRAS ((1ULL<<ENCA_ESQUERDO_TRAS) | (1ULL<<ENCB_ESQUERDO_TRAS))

#define L_EN_DIREITO_FRENTE 11 //placeholders
#define L_PWM_DIREITO_FRENTE 12 //placeholders
#define R_PWM_DIREITO_FRENTE 13 //placeholders
#define OUTPUT_DIREITO_FRENTE ((1ULL<<L_EN_DIREITO_FRENTE) | (1ULL<<L_PWM_DIREITO_FRENTE) | (1ULL<<R_PWM_DIREITO_FRENTE))
#define ENCA_DIREITO_FRENTE 14 //placeholders
#define ENCB_DIREITO_FRENTE 15 //placeholders
#define INPUT_DIREITO_FRENTE ((1ULL<<ENCA_DIREITO_FRENTE) | (1ULL<<ENCB_DIREITO_FRENTE))

#define L_EN_DIREITO_TRAS 16 //placeholders
#define L_PWM_DIREITO_TRAS 17 //placeholders
#define R_PWM_DIREITO_TRAS 18 //placeholders
#define OUTPUT_DIREITO_TRAS ((1ULL<<L_EN_DIREITO_TRAS) | (1ULL<<L_PWM_DIREITO_TRAS) | (1ULL<<R_PWM_DIREITO_TRAS))
#define ENCA_DIREITO_TRAS 19 //placeholders
#define ENCB_DIREITO_TRAS 20 //placeholders
#define INPUT_DIREITO_TRAS ((1ULL<<ENCA_DIREITO_TRAS) | (1ULL<<ENCB_DIREITO_TRAS))

// Configuração GPIO dos pinos { --------------------------------------------------------------------------------

gpio_config_t config = {
    .pin_bit_mask = OUTPUT_ESQUERDO_FRENTE | OUTPUT_ESQUERDO_TRAS | OUTPUT_DIREITO_FRENTE | OUTPUT_DIREITO_TRAS,
    .mode = GPIO_MODE_OUTPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_DISABLE
};

// } ------------------------------------------------------------------------------------------------------------

// Configuração LEDC { ------------------------------------------------------------------------------------------

// gpio_config(&config);

//} -------------------------------------------------------------------------------------------------------------


#endif
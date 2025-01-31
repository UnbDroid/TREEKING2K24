#include <stdio.h>
#include <PinConfig.h>
#include <iostream>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <MotorDC.h>
#include <inttypes.h>

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO          OUTPUT_ESQUERDO_FRENTE // Define the output GPIO
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_8_BIT // Set duty resolution to 13 bits
#define LEDC_DUTY               (128) // Set duty to 50%. (2 ** 13) * 50% = 4096
#define LEDC_FREQUENCY          (128) // Frequency in Hertz. Set frequency at 4 kH


static QueueHandle_t gpio_evt_queue = NULL;

uint32_t posicao = 0;

void IRAM_ATTR gpio_isr_handler(void *arg)
{
    posicao += 1;
    xQueueSendFromISR(gpio_evt_queue, &posicao, NULL);
}

MotorDC motor1(ENCA_ESQUERDO_TRAS, ENCB_ESQUERDO_TRAS, L_EN_ESQUERDO_TRAS, L_PWM_ESQUERDO_TRAS, R_PWM_ESQUERDO_TRAS);


extern "C" void app_main(void)
{
    pin_configuration();
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, LEDC_DUTY);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);

    gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));

    gpio_install_isr_service(ESP_INTR_FLAG_IRAM);

    gpio_isr_handler_add((gpio_num_t) ENCA_ESQUERDO_TRAS, gpio_isr_handler, (void *)ENCA_ESQUERDO_TRAS);
    
    motor1.ligar_motor(1, 255);
    while (1){
        
        std::cout<<posicao<<std::endl;    /* code */
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
    
    

    // }
    
}

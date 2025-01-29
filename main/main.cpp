#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <PinConfig/include/PinConfig.h>
#include <MotorDC/include/MotorDC.h>
#include "driver/ledc.h"

ledc_timer_config_t timer_conf = {
    .duty_resolution = LEDC_TIMER_10_BIT,
    .freq_hz = 5000,
    .speed_mode = LEDC_HIGH_SPEED_MODE,
    .timer_num = LEDC_TIMER_0
};

ledc_timer_config(&timer_conf);

extern "C" void app_main(void)
{
    while (1)
    {
        gpio_set_direction(GPIO_NUM_25, GPIO_MODE_OUTPUT);
        gpio_set_level(GPIO_NUM_25, 10);
    }
    
}
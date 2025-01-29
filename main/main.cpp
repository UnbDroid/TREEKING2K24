#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <PinConfig/include/PinConfig.h>
#include <MotorDC/include/MotorDC.h>



extern "C" void app_main(void)
{
    while (1)
    {
        gpio_set_direction(GPIO_NUM_22, GPIO_MODE_OUTPUT);
        gpio_set_level(GPIO_NUM_22, 1);
    }
    
}
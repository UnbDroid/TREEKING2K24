#include <stdio.h>
#include "PinConfig.h"

void pin_setup(void)
{
    gpio_config(&config);
}

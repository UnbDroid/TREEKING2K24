#include <MotorDC.h>
#include <PinConfig.h>

MotorDC left_front_motor(ENCA_LEFT_FRONT, ENCB_LEFT_FRONT, L_PWM_LEFT_FRONT,
                         R_PWM_LEFT_FRONT, LEDC_CHANNEL_LEFT_FRONT_L_PWM,
                         LEDC_CHANNEL_LEFT_FRONT_R_PWM);
MotorDC left_back_motor(ENCA_LEFT_BACK, ENCB_LEFT_BACK, L_PWM_LEFT_BACK,
                        R_PWM_LEFT_BACK, LEDC_CHANNEL_LEFT_BACK_L_PWM,
                        LEDC_CHANNEL_LEFT_BACK_R_PWM);
MotorDC right_front_motor(ENCA_RIGHT_FRONT, ENCB_RIGHT_FRONT, L_PWM_RIGHT_FRONT,
                          R_PWM_RIGHT_FRONT, LEDC_CHANNEL_RIGHT_FRONT_L_PWM,
                          LEDC_CHANNEL_RIGHT_FRONT_R_PWM);
MotorDC right_back_motor(ENCA_RIGHT_BACK, ENCB_RIGHT_BACK, L_PWM_RIGHT_BACK,
                         R_PWM_RIGHT_BACK, LEDC_CHANNEL_RIGHT_BACK_L_PWM,
                         LEDC_CHANNEL_RIGHT_BACK_R_PWM);

void read_encoder_left_front(void *arg)
{
  left_front_motor.read_encoder(arg);
}

void read_encoder_left_back(void *arg)
{
  left_back_motor.read_encoder(arg);
}

void read_encoder_right_front(void *arg)
{
  right_front_motor.read_encoder(arg);
}

void read_encoder_right_back(void *arg)
{
  right_back_motor.read_encoder(arg);
}

void robot_setup()
{
  pin_configuration();
  gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
  gpio_isr_handler_add((gpio_num_t)ENCA_LEFT_FRONT, read_encoder_left_front,
                       (void *)ENCA_LEFT_FRONT);
  gpio_isr_handler_add((gpio_num_t)ENCA_LEFT_BACK, read_encoder_left_back,
                       (void *)ENCA_LEFT_BACK);
  gpio_isr_handler_add((gpio_num_t)ENCA_RIGHT_FRONT, read_encoder_right_front,
                       (void *)ENCA_RIGHT_FRONT);
  gpio_isr_handler_add((gpio_num_t)ENCA_RIGHT_BACK, read_encoder_right_back,
                       (void *)ENCA_RIGHT_BACK);
}

extern "C" void app_main(void)
{

  robot_setup();

  while (true)
  {

    for (int i = 0; i < 80; i++)
    {
      left_front_motor.set_motor(1, i);
      right_front_motor.set_motor(1, i);
      left_back_motor.set_motor(1, i);
      right_back_motor.set_motor(1, i);
      std::cout << left_front_motor.return_posi()
                << " "
                << left_back_motor.return_posi()
                << " "
                << right_front_motor.return_posi()
                << " "
                << right_back_motor.return_posi()
                << std::endl;
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }

    left_front_motor.stop_motor();
    right_front_motor.stop_motor();
    left_back_motor.stop_motor();
    right_back_motor.stop_motor();
    vTaskDelay(3000 / portTICK_PERIOD_MS);

    for (int i = 0; i < 80; i++)
    {
      left_front_motor.set_motor(-1, i);
      right_front_motor.set_motor(-1, i);
      left_back_motor.set_motor(-1, i);
      right_back_motor.set_motor(-1, i);
      std::cout << left_front_motor.return_posi()
                << " "
                << left_back_motor.return_posi()
                << " "
                << right_front_motor.return_posi()
                << " "
                << right_back_motor.return_posi()
                << std::endl;
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
    left_front_motor.stop_motor();
    right_front_motor.stop_motor();
    left_back_motor.stop_motor();
    right_back_motor.stop_motor();
    vTaskDelay(3000 / portTICK_PERIOD_MS);
  }
}

#include "Arduino.h"
#include "Giroscopio.h"
#include "Wire.h"
#include "Tempo.h"

//* Esse arquivo contém a implementação da classe Giroscopio, que é responsável por controlar o sensor MPU9250
//* e fornecer os valores de ângulos de roll(x), pitch(y) e yaw(z)

Giroscopio::Giroscopio() { // Construtor da classe Giroscopio

}

void Giroscopio::ligar_mpu() {

    // Início da comunicação com o MPU9250 --------------------------------------------------------------------------------

        while (!Serial) {} // Aguarda a comunicação serial ser estabelecida

        Wire.begin(); // Inicia a comunicação I2C
        Wire.setClock(400000); // Define a velocidade da comunicação I2C

        imu.Config(&Wire, bfs::Mpu9250::I2C_ADDR_PRIM); // Configura o sensor imu

        // Início da comunicação com o sensor imu

        if (!imu.Begin()) { // Se não conseguir iniciar a comunicação com o sensor imu
            Serial.println("Erro ao inicializar a comunicação com o sensor imu");
            while(1) {}
        }

        if (!imu.ConfigSrd(19)) { // Se não conseguir configurar o SRD
            Serial.println("Erro ao configurar o SRD");
            while(1) {}
        }

        imu.

    // --------------------------------------------------------------------------------------------------------------------

}

void Giroscopio::atualizar_leituras() {
  
  //TODO: Checar frequência de leitura do sensor MPU
  
  imu.Read();

  T = micros();

  // Recebe os dados do giroscópio em rad/s
  gyro_x_rad = imu.gyro_x_radps();
  gyro_y_rad = imu.gyro_y_radps();
  gyro_z_rad = imu.gyro_z_radps();

  // Recebe os dados do giroscópio em g (aceleração da gravidade)
  accel_x_g = imu.accel_x_mps2() / 9.81;
  accel_y_g = imu.accel_y_mps2() / 9.81;
  accel_z_g = imu.accel_z_mps2() / 9.81;

  dt = ((float) (T - prevT))/( 1.0e6 );
  prevT = T;

  // Calcula o roll e o pitch a partir dos dados do acelerômetro (estimativa inicial)
  pitch_angle = atan2(accel_x_g, accel_z_g) * deg_to_rad;
  roll_angle = atan2(accel_y_g, accel_z_g) * deg_to_rad;

  // Filtro de Kalman para os ângulos de roll e pitch (usa os dados do giroscópio para corrigir as estimativas)
  roll_angle = alpha_x * (roll_angle + gyro_x_rad * dt) + (1.0 - alpha_x) * pitch_angle;
  pitch_angle = alpha_y * (pitch_angle + gyro_y_rad * dt) + (1.0 - alpha_y) * roll_angle;
  Serial.print("Yaw: ");
  Serial.println((double) (gyro_z_rad));
  if ((gyro_z_rad * dt) > 0.00004 or (gyro_z_rad * dt) < (-0.00004)) {yaw_angle += (gyro_z_rad * dt * 2.72);}

}

float Giroscopio::get_x()
{
    atualizar_leituras();
    return (roll_angle * deg_to_rad); // Retorna o valor do ângulo de roll (x)
}

float Giroscopio::get_y()
{
    atualizar_leituras();
    return (pitch_angle * deg_to_rad); // Retorna o valor do ângulo de pitch (y)
}

float Giroscopio::get_z()
{
    atualizar_leituras();
    return (yaw_angle * deg_to_rad); // Retorna o valor de yaw (z)
}
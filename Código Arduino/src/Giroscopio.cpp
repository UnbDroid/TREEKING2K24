#include "Arduino.h"
#include "Giroscopio.h"
#include "Wire.h"
#include "Tempo.h"

//* Esse arquivo contém a implementação da classe Giroscopio, que é responsável por controlar o sensor MPU9250
//* e fornecer os valores de ângulos de roll(x), pitch(y) e yaw(z)

Giroscopio::Giroscopio() { // Construtor da classe Giroscopio

    // Início da comunicação com o MPU9250 {

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

    // }
    
}

float Giroscopio::get_x()
{
    imu.Read(); // Lê os dados do sensor imu
    Giroscopio::gyro_x_rad = imu.gyro_x_radps(); // Lê o valor do giroscópio no eixo x em radianos por segundo
    Giroscopio::accel_x_g = imu.accel_x_mps2() / 9.81; // Lê o valor do acelerômetro no eixo x em g (aceleração da gravidade)
    Giroscopio::roll_angle = atan2((imu.accel_y_mps2() / 9.81), (imu.accel_z_mps2() / 9.81)) * Giroscopio::deg_to_rad; // Calcula o ângulo de roll em radianos
    Giroscopio::roll_angle = Giroscopio::alpha_x * (Giroscopio::roll_angle + Giroscopio::gyro_x_rad * dt) + (1 - Giroscopio::alpha_x) * Giroscopio::roll_angle; // Aplica o filtro de Kalman
    return roll_angle * Giroscopio::deg_to_rad; // Retorna o valor do ângulo de roll
}

float Giroscopio::get_y()
{
    imu.Read(); // Lê os dados do sensor imu
    Giroscopio::gyro_y_rad = imu.gyro_y_radps(); // Lê o valor do giroscópio no eixo y em radianos por segundo
    Giroscopio::accel_y_g = imu.accel_y_mps2() / 9.81; // Lê o valor do acelerômetro no eixo y em g (aceleração da gravidade)
    Giroscopio::pitch_angle = atan2((imu.accel_x_mps2() / 9.81), (imu.accel_z_mps2() / 9.81)) * Giroscopio::deg_to_rad; // Calcula o ângulo de pitch em radianos
    Giroscopio::pitch_angle = Giroscopio::alpha_y * (Giroscopio::pitch_angle + Giroscopio::gyro_y_rad * dt) + (1 - Giroscopio::alpha_y) * Giroscopio::pitch_angle; // Aplica o filtro de Kalman
    return (Giroscopio::pitch_angle * Giroscopio::deg_to_rad); // Retorna o valor do ângulo de pitch
}

float Giroscopio::get_z()
{
    imu.Read();
    Giroscopio::gyro_z_rad = imu.gyro_z_radps();
    float variacao = Giroscopio::gyro_z_rad * dt;
    if (variacao > 0.001 or variacao < (-0.001)) {Giroscopio::yaw_angle += variacao;}
    return (Giroscopio::yaw_angle * Giroscopio::deg_to_rad);
}
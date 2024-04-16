#include "Arduino.h"
#include "mpu9250.h"
#include "Wire.h"

// MPU-9250 sensor on I2C bus 0 with address 0x68
bfs::Mpu9250 imu;
int status;

const double deg_to_rad = 3.14159265358979;  // Conversion factor from degrees to radians

// Filter parameters
const float alpha_x = 0.45;  // Weighting factor (adjust based on your needs)
const float alpha_y = 0.45;
const float alpha_z = 0.45;

// Roll, pitch, and yaw angles in degrees
float roll_angle = 0.0;
float pitch_angle = 0.0;
float yaw_angle = 0.0;
float prev_gyro_z_rad = 0.0;

// Temporary variables for storing sensor data
float gyro_x_rad, gyro_y_rad, gyro_z_rad;
float accel_x_g, accel_y_g, accel_z_g;

unsigned long last_time = 0;
unsigned long current_time;
float dt;

void setup() {
  // serial to display data
  Serial.begin(9600);
  while (!Serial) {}

  Wire.begin();
  Wire.setClock(400000);

  imu.Config(&Wire, bfs::Mpu9250::I2C_ADDR_PRIM);

  // start communication with IMU
  if (!imu.Begin()) {
    Serial.println("Error initializing communication with IMU");
    while(1) {}
  }

  if (!imu.ConfigSrd(19)) {
    Serial.println("Error configured SRD");
    while(1) {}
  }

  last_time = millis();
}

void loop() {
  // read the data
  imu.Read();
  
  last_time = current_time;

  current_time = millis();

  dt = (current_time - last_time) / 1000.0;

  // Get gyroscope data in radians
  gyro_x_rad = imu.gyro_x_radps();
  gyro_y_rad = imu.gyro_y_radps();
  gyro_z_rad = imu.gyro_z_radps();

  // Get accelerometer data in g-force
  accel_x_g = imu.accel_x_mps2() / 9.81;  // Convert m/s^2 to g
  accel_y_g = imu.accel_y_mps2() / 9.81;
  accel_z_g = imu.accel_z_mps2() / 9.81;

  // Calculate roll and pitch angles from accelerometer (initial estimate)
  // Consider using atan2 for proper quadrant handling
  pitch_angle = atan2(accel_x_g, accel_z_g) * deg_to_rad;
  roll_angle = atan2(accel_y_g, accel_z_g) * deg_to_rad;

  // Complementary filter update (adjust alpha as needed)
  roll_angle = alpha_x * (roll_angle + gyro_x_rad * dt) + (1.0 - alpha_x) * pitch_angle;
  pitch_angle = alpha_y * (pitch_angle + gyro_y_rad * dt) + (1.0 - alpha_y) * roll_angle;
  if ((gyro_z_rad * dt) > 0.001 or (gyro_z_rad * dt) < (-0.001)) {yaw_angle += gyro_z_rad * dt;}

  // Convert to degrees and display results
  Serial.print("Roll: ");
  Serial.print(roll_angle * 180.0 / M_PI);
  Serial.print(" degrees");
  Serial.print("\t");

  Serial.print("Pitch: ");
  Serial.print(pitch_angle * 180.0 / M_PI);
  Serial.print(" degrees");
  Serial.print("\t");

  Serial.print("Yaw: ");
  Serial.print(yaw_angle * 180.0 / M_PI);
  Serial.println(" degrees");

  delay(10);  // Adjust delay based on your desired update rate
}
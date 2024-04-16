#include <Arduino.h>

#define ENCA_LEFT 3 // YELLOW 
#define ENCB_LEFT 8 // WHITE 
#define ENCA_RIGHT 2 // YELLOW
#define ENCB_RIGHT 4 // WHITE
#define PWM_LEFT 5
#define PWM_RIGHT 9 
#define IN1 6
#define IN2 7
#define IN3 11
#define IN4 10

volatile double posi_left = 0;
volatile double posi_right = 0;
volatile double pos_left = 0;
volatile double pos_right = 0;
double voltas_left = 0;
double voltas_anterior_left = 0;
double voltas_right = 0;
double voltas_anterior_right = 0;
double rps_left = 0;
double rps_right = 0;
int rpm_referencia = 100;
double rps_max = 5.75;
double comprimento_roda = 6*2*3.1415;
long prevT = 0;
float eprev_left = 0;
float eprev_right = 0;
float eintegral_left = 0;
float eintegral_right = 0;
int dir_left = 1;
int dir_right = 1;

void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
  analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }  
}

void readEncoder_Left(){
  double b = digitalRead(ENCB_LEFT);
  if(b > 0){
    posi_left++;
  }
  else{
    posi_left--;

    
  }
}

void readEncoder_Right(){
  double c = digitalRead(ENCB_RIGHT);
  if(c > 0){
    posi_right--;
  }
  else{
    posi_right++;
  }
}

void andarReto() {
  volatile double posi_left = 0;
  volatile double posi_right = 0;
  // set target position
  //int target = 1200;
  double encoder_volta_left = 1044.0;
  double encoder_volta_right = 1044.0; //408

  // PID constants - LEFT
  float kp_left = 5;
  //3.92 - 12V
  //5.42 - 6V
  float kd_left = 0.0;
  //0.121 - 12V
  //0.4 - 6V
  float ki_left = 3;

 // PID constants - RIGHT
  float kp_right = 1.2; 
  //3.92 - 12V
  //5.42 - 6V
  //float kd_left = 0;
  //0.121 - 12V
  //0.4 - 6V
  float ki_right = 2;

  // time difference
  long currT = micros();
  float deltaT = ((float) (currT - prevT))/( 1.0e6 );
  prevT = currT;

  // Read the position
  volatile double pos_left = 0;
  noInterrupts(); // disable interrupts temporarily while reading
  pos_left = posi_left;
  interrupts(); // turn interrupts back on
  volatile double pos_right = 0;
  noInterrupts(); // disable interrupts temporarily while reading
  pos_right = posi_right;
  interrupts(); // turn interrupts back on
  
  voltas_anterior_left = voltas_left;
  voltas_anterior_right = voltas_right;

  voltas_left = pos_left/1044.0;
  voltas_right = pos_right/1044.0;
  rps_left = (voltas_left - voltas_anterior_left)/(deltaT);
  rps_right = (voltas_right - voltas_anterior_right)/(deltaT);

  // error
  double e_left = rpm_referencia - (rps_left*60);
  double e_right = rpm_referencia - (rps_right*60);

  // derivative
  float dedt_left = (e_left-eprev_left)/(deltaT);
  float dedt_right = (e_right-eprev_right)/(deltaT);

  // integral
  eintegral_left += e_left;
  eintegral_right += e_right;

  // control signal
  float u_left = (kp_left*e_left) + (ki_left*eintegral_left*deltaT);
  float u_right = (kp_right*e_right) + (ki_right*eintegral_right*deltaT);

  // motor power
  float pwr_left = fabs(u_left);
  if( pwr_left > 255 ){
    pwr_left = 255;
  }
  float pwr_right = fabs(u_right);
  if( pwr_right > 255 ){
    pwr_right = 255;
  }

  // motor direction
  if(u_left<0){
    dir_left = -1;
  } else if(u_left>0){
    dir_left = 1;
  } else {
    dir_left = 0;
  }
  if(u_right<0){
    dir_right = -1;
  } else if(u_right>0){
    dir_right = 1;
  } else {
    dir_right = 0;
  }

  // signal the motor
  setMotor(dir_left,pwr_left,PWM_LEFT,IN1,IN2);
  setMotor(dir_right,pwr_right,PWM_RIGHT,IN3,IN4);


  // store previous error
  eprev_left = e_left;
  eprev_right = e_right;

  Serial.print(rpm_referencia);
  Serial.print(" ");
  Serial.print(rps_left*60);
  Serial.print(" ");
  Serial.print(pwr_left);
  Serial.print(" ");
  Serial.print(rps_right*60);
  Serial.print(" ");
  Serial.print(pwr_right);
  Serial.print(" ");
  //Serial.print(" ");
  //Serial.print(target - pos);
  Serial.println();
}

void girar90GrausEsquerda(){
  posi_left = 0;
  posi_right = 0;
  // set target position
  int target = 2400;
  double encoder_volta_left = 1044.0;
  double encoder_volta_right = 1044.0; //408

  // PID constants - LEFT
  float kp_left = 5;
  //3.92 - 12V
  //5.42 - 6V
  float kd_left = 0.0;
  //0.121 - 12V
  //0.4 - 6V
  float ki_left = 3;

 // PID constants - RIGHT
  float kp_right = 1.2; 
  //3.92 - 12V
  //5.42 - 6V
  //float kd_left = 0;
  //0.121 - 12V
  //0.4 - 6V
  float ki_right = 2;

  pos_left = 0;
  pos_right = 0;
  
  while (pos_left < (target/4) && pos_right > ((target*(-1))/4)) {
    // time difference
    long currT = micros();
    float deltaT = ((float) (currT - prevT))/( 1.0e6 );
    prevT = currT;

    // Read the position
    noInterrupts(); // disable interrupts temporarily while reading
    pos_left = posi_left;
    interrupts(); // turn interrupts back on
    noInterrupts(); // disable interrupts temporarily while reading
    pos_right = posi_right;
    interrupts(); // turn interrupts back on
    
    voltas_anterior_left = voltas_left;
    voltas_anterior_right = voltas_right;

    voltas_left = pos_left/encoder_volta_left;
    voltas_right = pos_right/encoder_volta_right;
    rps_left = (voltas_left - voltas_anterior_left)/(deltaT);
    rps_right = (voltas_right - voltas_anterior_right)/(deltaT);

    // error
    double e_left = (target/4) - (pos_left);
    double e_right = ((target*(-1))/4) - (pos_right);

    // derivative
    float dedt_left = (e_left-eprev_left)/(deltaT);
    float dedt_right = (e_right-eprev_right)/(deltaT);

    // integral
    eintegral_left += e_left;
    eintegral_right += e_right;

    // control signal
    float u_left = (kp_left*e_left) + (ki_left*eintegral_left*deltaT);
    float u_right = (kp_right*e_right) + (ki_right*eintegral_right*deltaT);

    // motor power
    float pwr_left = 80;
    if( pwr_left > 255 ){
      pwr_left = 255;
    }
    float pwr_right = 80;
    if( pwr_right > 255 ){
      pwr_right = 255;
    }

    // motor direction
    if(u_left<0){
      dir_left = -1;
    } else if(u_left>0){
      dir_left = 1;
    } else {
      dir_left = 0;
    }
    if(u_right<0){
      dir_right = -1;
    } else if(u_right>0){
      dir_right = 1;
    } else {
      dir_right = 0;
    }

    // signal the motor
    setMotor(dir_left,pwr_left,PWM_LEFT,IN1,IN2);
    setMotor(dir_right,pwr_right,PWM_RIGHT,IN3,IN4);


    // store previous error
    eprev_left = e_left;
    eprev_right = e_right;

    Serial.print(rpm_referencia);
    Serial.print(" ");
    Serial.print(rps_left*60);
    Serial.print(" ");
    Serial.print(pwr_left);
    Serial.print(" ");
    Serial.print(rps_right*60);
    Serial.print(" ");
    Serial.print(pwr_right);
    Serial.print(" ");
    //Serial.print(" ");
    //Serial.print(target - pos);
    Serial.println();
  }
  setMotor(0,0,PWM_LEFT,IN1,IN2);
  setMotor(0,0,PWM_RIGHT,IN3,IN4);
}

void girar90GrausDireita() {
  posi_left = 0;
  posi_right = 0;
  // set target position
  int target = 2400;
  double encoder_volta_left = 1044.0;
  double encoder_volta_right = 1044.0; //408

  // PID constants - LEFT
  float kp_left = 5;
  //3.92 - 12V
  //5.42 - 6V
  float kd_left = 0.0;
  //0.121 - 12V
  //0.4 - 6V
  float ki_left = 3;

 // PID constants - RIGHT
  float kp_right = 1.2; 
  //3.92 - 12V
  //5.42 - 6V
  //float kd_left = 0;
  //0.121 - 12V
  //0.4 - 6V
  float ki_right = 2;

  pos_left = 0;
  pos_right = 0;
  
  while (pos_left > ((target*(-1))/4) && pos_right < (target/4)) {
    // time difference
    long currT = micros();
    float deltaT = ((float) (currT - prevT))/( 1.0e6 );
    prevT = currT;

    // Read the position
    noInterrupts(); // disable interrupts temporarily while reading
    pos_left = posi_left;
    interrupts(); // turn interrupts back on
    noInterrupts(); // disable interrupts temporarily while reading
    pos_right = posi_right;
    interrupts(); // turn interrupts back on
    
    voltas_anterior_left = voltas_left;
    voltas_anterior_right = voltas_right;

    voltas_left = pos_left/encoder_volta_left;
    voltas_right = pos_right/encoder_volta_right;
    rps_left = (voltas_left - voltas_anterior_left)/(deltaT);
    rps_right = (voltas_right - voltas_anterior_right)/(deltaT);

    // error
    double e_left = ((target*(-1))/4) - (pos_left);
    double e_right = (target/4) - (pos_right);

    // derivative
    float dedt_left = (e_left-eprev_left)/(deltaT);
    float dedt_right = (e_right-eprev_right)/(deltaT);

    // integral
    eintegral_left += e_left;
    eintegral_right += e_right;

    // control signal
    float u_left = (kp_left*e_left) + (ki_left*eintegral_left*deltaT);
    float u_right = (kp_right*e_right) + (ki_right*eintegral_right*deltaT);

    // motor power
    float pwr_left = fabs(u_left);
    if( pwr_left > 255 ){
      pwr_left = 255;
    }
    float pwr_right = fabs(u_right);
    if( pwr_right > 255 ){
      pwr_right = 255;
    }

    // motor direction
    if(u_left<0){
      dir_left = -1;
    } else if(u_left>0){
      dir_left = 1;
    } else {
      dir_left = 0;
    }
    if(u_right<0){
      dir_right = -1;
    } else if(u_right>0){
      dir_right = 1;
    } else {
      dir_right = 0;
    }

    // signal the motor
    setMotor(dir_left,pwr_left,PWM_LEFT,IN1,IN2);
    setMotor(dir_right,pwr_right,PWM_RIGHT,IN3,IN4);


    // store previous error
    eprev_left = e_left;
    eprev_right = e_right;

    Serial.print(rpm_referencia);
    Serial.print(" ");
    Serial.print(rps_left*60);
    Serial.print(" ");
    Serial.print(pwr_left);
    Serial.print(" ");
    Serial.print(rps_right*60);
    Serial.print(" ");
    Serial.print(pwr_right);
    Serial.print(" ");
    //Serial.print(" ");
    //Serial.print(target - pos);
    Serial.println();
  }
  setMotor(0,0,PWM_LEFT,IN1,IN2);
  setMotor(0,0,PWM_RIGHT,IN3,IN4);
}

void setup() {
  Serial.begin(9600);
  pinMode(ENCA_LEFT,INPUT);
  pinMode(ENCB_LEFT,INPUT);
  pinMode(ENCA_RIGHT,INPUT);
  pinMode(ENCB_RIGHT,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA_LEFT),readEncoder_Left,RISING);
  attachInterrupt(digitalPinToInterrupt(ENCA_RIGHT),readEncoder_Right,RISING);
  pinMode(PWM_LEFT,OUTPUT);
  pinMode(PWM_RIGHT,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //Serial.println("target pos");
}

void loop() {
  andarReto();
}
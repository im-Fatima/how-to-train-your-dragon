#include <Wire.h> 

float Roll_rate, Pitch_rate, Yaw_rate;
float Roll_calibrated, Pitch_calibrated, Yaw_calibrated, Calibration_num; //define alibrated variables

void gyro_signals(void){
  //start I2C communication
  Wire.beginTransmission(0x68); //default address for MPU6050 is 0x68(datasheet)
  
  //LOW PASS filter (bcz of the vibrations)
  Wire.write(0x1A);//register address for LOW PASS Filter (Datasheet)
  Wire.write(0x05);//DLPF_CFG value (datasheet)
  Wire.endTransmission();

  //Set the sensitivity scale factor 
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);//register for sensitivity
  Wire.write(0x8);//if FS_SEL is 1 , we get hexadecimal of 8 (datasheet)
  Wire.endTransmission(); 

  //start recieving data from gyro using default register
  Wire.beginTransmission(0x68);
  Wire.write(0x43);//hex value where gyro stores from 0x43 to 0x48
  Wire.endTransmission();

  //pulling info from 6 registers (43 to 48)
  Wire.requestFrom(0x68,6);

  int16_t GyroX = Wire.read()<<8 | Wire.read(); //reading values
  int16_t GyroY = Wire.read()<<8 | Wire.read();
  int16_t GyroZ = Wire.read()<<8 | Wire.read();

  //Gyro stores the value in LSB, but the required are deg/sec. 
  //check for LSB sensitivity what you have set "65.5", thus simply divide it by 65.5

  Roll_rate = (float) GyroX/65.5;
  Pitch_rate = (float) GyroY/65.5;
  Yaw_rate = (float) GyroZ/65.5;


}

void setup() {
Serial.begin(115200);
Wire.setClock(400000);
Wire.begin();
delay(250);

Wire.beginTransmission(0x68); //start the gyro in power mode
Wire.write(0x6B); //hex value for power management register
Wire.write(0x00); //all bits in this register should be '0' for device o start

Wire.endTransmission(); 

//loop for taking avg of 2000 values 
for(Calibration_num=0; Calibration_num<3000;Calibration_num++){
gyro_signals();
Roll_calibrated+=Roll_rate;
Pitch_calibrated+=Pitch_rate;
Yaw_calibrated+=Yaw_rate;
delay(1);}

Roll_calibrated/=3000;
Pitch_calibrated/=3000;
Yaw_calibrated/=3000;

}

void loop() {
  //calling the gyro function
  gyro_signals();
  Roll_rate-=Roll_calibrated;
  Pitch_rate-=Pitch_calibrated;
  Yaw_rate-=Yaw_calibrated;

  Serial.print(" || Roll rate = ");
  Serial.print(Roll_rate);
  Serial.print(" || Pitch rate = ");
  Serial.print(Pitch_rate);
  Serial.print(" || Yaw rate = ");
  Serial.println(Yaw_rate);
  delay(500);

}

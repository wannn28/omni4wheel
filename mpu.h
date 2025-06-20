#ifndef MPU_H
#define MPU_H


// MPU :
// ===================== MAGNETOMETER RAW VALUES =====================
int16_t mx, my, mz;

// Tilt heading
float tiltheading;

// XYZ sensor arrays
float Axyz[3];
float Gxyz[3];
float Mxyz[3];
float heading;

// Sampling constant
#define sample_num_mdate 5000

// Magnetometer samples for calibration
volatile float mx_sample[3];
volatile float my_sample[3];
volatile float mz_sample[3];

// Magnetometer offsets (center)
static float mx_centre = 0;
static float my_centre = 0;
static float mz_centre = 0;

// Magnetometer min/max for calibration
volatile int mx_max = 0, mx_min = 0;
volatile int my_max = 0, my_min = 0;
volatile int mz_max = 0, mz_min = 0;

// Menu Selection
int selectedOption = 0;
int maxOption = 5;
int optionValues[5];  // Menyimpan nilai dari tiap opsi menu
Preferences preferences;

// ===================== SENSOR SCALES =====================
const float gyroScale = 500.0 / 8192.0;   // dps/LSB
const float accelScale = 10.0 / 8192.0;   // g/LSB
const float sampleRate = 20.0;            // Hz

// PS4 control (IMU data interpretation)
float rollps4 = 0, pitchps4 = 0, yawps4 = 0, yawps41 = 0;

// Raw sensor values
float gyroX, gyroY, gyroZ;
float accelX, accelY, accelZ;
float ax, ay, az;
float gx, gy, gz;

// Madgwick filter params
const float beta = 0.0;
float q0 = 1.0, q1 = 0.0, q2 = 0.0, q3 = 0.0;
float qp[4] = { 1.0, 0.0, 0.0, 0.0 };

// Complementary filter coefficient
const float alpha = 0.98;

// PID constants for stabilization
float Kp = 20;
float Ki = 0;

// Sensor offset calibration
float gyroXOffset = 0.0;
float gyroYOffset = 0.0;
float gyroZOffset = 0.0;
float accelXOffset = 0.0;
float accelYOffset = 0.0;
float accelZOffset = 0.0;

// Time tracking
unsigned long prevTime = 0;

// Orientation variables
float yaw, pitch, roll, theta;
float last_yaw, yaw0, yaw1, yaw2, yaw3;

// ===================== MPU6050 SETUP =====================
MPU6050 mpu;

// MPU control/status vars
bool dmpReady = false;
uint8_t mpuIntStatus = 0;
uint8_t devStatus = 0;
uint16_t packetSize = 0;
uint16_t fifoCount = 0;
uint8_t fifoBuffer[64];

// Orientation containers
Quaternion q;
VectorInt16 aa;
VectorInt16 aaReal;
VectorInt16 aaWorld;
VectorFloat gravity;
float euler[3];  // psi, theta, phi
float ypr[3];    // yaw, pitch, roll
int targetRpm = 300;
// Packet structure for teapot demo (optional)
uint8_t teapotPacket[14] = { '$', 0x02, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, '\r', '\n' };

// MPU interrupt flag
volatile bool mpuInterrupt = false;

#endif 
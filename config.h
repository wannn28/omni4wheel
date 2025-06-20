#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Preferences.h>
#include <Adafruit_SSD1306.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps612.h"
#include "mpu.h"

// #Interrupt
#define interruptPin 47

// setup motor
#define mdKananA 2
#define mdKananB 1
#define mdKiriA 20
#define mdKiriB 19
#define mbKananA 41
#define mbKananB 40
#define mbKiriA 10
#define mbKiriB 38

// setup encoder
#define encMdKananA 37
#define encMdKananB 42
#define encMdKiriA 36
#define encMdKiriB 21
#define encMbKananA 48
#define encMbKananB 39
#define encMbKiriA 35
#define encMbKiriB 45

// ## VARIABLE ##
// # Variable Nilai Encoder

int encMdKananAVal = 0;
int encMdKananBVal = 0;
int encMdKiriAVal = 0;
int encMdKiriBVal = 0;
int encMbKananAVal = 0;
int encMbKananBVal = 0;
int encMbKiriAVal = 0;
int encMbKiriBVal = 0;

// Variable Nilai Encoder untuk jarak
int encMdKananValJarak = 0;
int encMdKiriValJarak = 0;
int encMbKananValJarak = 0;
int encMbKiriValJarak = 0;
// tombol 
#define tombol 6
#define bootPin 0

// #Oled I2C
#define screenWidth 128  // Lebar Oled dalam Pixel
#define screenHeight 64  // Tinggi Oled dalam Pixel
#define oledReset -1
Adafruit_SSD1306 display(screenWidth, screenHeight, &Wire, oledReset);

// # Variable RPM
int rpmDepanKanan = 0;
int rpmDepanKiri = 0;
int rpmBelakangKanan = 0;
int rpmBelakangKiri = 0;
int rpm1, rpm2, rpm3, rpm4;

const int channelDepanKanan = 0;
const int channelDepanKiri = 1;
const int channelBelakangKanan = 2;
const int channelBelakangKiri = 3;

// # PWM Resolution
const int pwmResolution = 12;

// # PWM Frequency
const int pwmFrequency = 5000;

const int numOutputs = 10;
struct PIDData {
  double error;
  double integral;
  double derivative;
  double previousError;
  double lastDerivative;
  double lastOutput;
  unsigned long lastComputeTime;
};

PIDData pidData[numOutputs];
unsigned long milisRpm = 0;
int intervalRpm = 200;

int perRotasi = 230;
// rpm
int pwmKanan, pwmKiri;

// K 0.5 1.5 0.0
double kp = 0.2, ki = 0.4, kd = 0.0;
int pwmMin = -4096;
int pwmZero = 0;
int pwmMax = 4096;

int maxrpm = 900;
int minrpm = -900;
// #Timing Millis()
unsigned long previousMillis = 0;
const unsigned long interval = 100;

int baseSpeed = 1000;
#endif 
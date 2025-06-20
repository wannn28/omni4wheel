void setupMotor() {
  // Set motor control pins as outputs
  pinMode(mdKananA, OUTPUT);
  pinMode(mdKiriA, OUTPUT);
  pinMode(mbKananA, OUTPUT);
  pinMode(mbKiriA, OUTPUT);

  // Setup PWM for enable pins
  ledcSetup(channelDepanKanan, pwmFrequency, pwmResolution);
  ledcAttachPin(mdKananB, channelDepanKanan);

  ledcSetup(channelDepanKiri, pwmFrequency, pwmResolution);
  ledcAttachPin(mdKiriB, channelDepanKiri);
  // Setup PWM for enable pins
  ledcSetup(channelBelakangKanan, pwmFrequency, pwmResolution);
  ledcAttachPin(mbKananB, channelBelakangKanan);

  ledcSetup(channelBelakangKiri, pwmFrequency, pwmResolution);
  ledcAttachPin(mbKiriB, channelBelakangKiri);
}

void setupEncoder() {
  pinMode(encMdKananA, INPUT);
  pinMode(encMdKiriA, INPUT);
  pinMode(encMbKananA, INPUT);
  pinMode(encMbKiriA, INPUT);

  attachInterrupt(digitalPinToInterrupt(encMdKananA), encMdKanan, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encMdKiriA), encMdKiri, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encMbKananA), encMbKanan, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encMbKiriA), encMbKiri, CHANGE);

  for (int i = 0; i < numOutputs; ++i) {
    pidData[i].error = 0.0;
    pidData[i].integral = 0.0;
    pidData[i].derivative = 0.0;
    pidData[i].previousError = 0.0;
  }
}

// setup display
void initializeDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();
  display.setTextSize(3);  // Ukuran tulisan  //Ukuran tulisan
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);  // Koordinat awal tulisan (x,y) dimulai dari atas-kiri
  display.print("Mulai Program Omni Wheel");
  delay(1000);
  display.setTextSize(1);
  display.display();
}


void setupDisplay() {
  // Initialize I2C
  Wire.begin();
  Wire.setClock(400000);
  delay(100);

  // Initialize display
  initializeDisplay();
}

void setupAll() {
  setupMotor();
  setupEncoder();
  setupDisplay();
  Serial.println("SETUP ALL SELESAI");
}

void dmpDataReady() {
  mpuInterrupt = true;
}

void initializeMPU() {
  // Initialize MPU6050
  mpu.initialize();
  pinMode(interruptPin, INPUT);
  devStatus = mpu.dmpInitialize();

  // Set MPU offsets
  mpu.setXGyroOffset(220);
  mpu.setYGyroOffset(76);
  mpu.setZGyroOffset(-85);
  mpu.setZAccelOffset(1788);

  if (devStatus == 0) {
    mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);
    mpu.setDMPEnabled(true);
    attachInterrupt(digitalPinToInterrupt(interruptPin), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  }
}

void setupMpu() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Inisialisasi MPU...");
  display.display();

  initializeMPU();

  if (dmpReady) {
    display.println("MPU siap!");
    display.display();
    delay(1000);
  } else {
    display.println("MPU gagal!");
    display.display();
    delay(2000);
  }
}
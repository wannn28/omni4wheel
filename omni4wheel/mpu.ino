void mpu6500() {
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    yaw = ypr[0] * 180 / M_PI;
    pitch = ypr[1] * 180 / M_PI;
    roll = ypr[2] * 180 / M_PI;
    yaw = normalizeAngle(yaw, 0, 360);
    yaw1 = yaw-yaw0;
    yaw1 = normalizeAngle(yaw1, 0, 360);
  }
}
  
float degToRad(float deg)
{
  return deg * (PI / 180.0);
}

float normalizeAngle(float angle, float minAngle, float maxAngle)
{
  float range = maxAngle - minAngle;
  if (angle < minAngle)
  {
    angle += range;
  }
  if (angle >= maxAngle)
  {
    angle -= range;
  }
  return angle;
}

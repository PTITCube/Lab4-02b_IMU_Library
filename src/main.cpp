/**
 * VÍ DỤ 4-2b: ĐỌC DỮ LIỆU CẢM BIẾN QUÁN TÍNH 9 TRỤC & LA BÀN BẰNG THƯ VIỆN PTITCUBE
 */
#include <Arduino.h>
#include <PTITCube.h>

PTIT_CDH cdh;
PTIT_Sensor sensor;

void setup() {
    cdh.begin(115200);
    sensor.init(false, true, true); // Bật MPU6500 và QMC5883P
}

void loop() {
    sensor.update();

    float ax = sensor.getAccX();
    float ay = sensor.getAccY();
    float az = sensor.getAccZ();

    float mx = sensor.getMagX();
    float my = sensor.getMagY();
    float mz = sensor.getMagZ();

    float heading = sensor.getHeading();
    float roll    = sensor.getRoll();
    float pitch   = sensor.getPitch();

    cdh.printf("[IMU] Roll: %5.1f° | Pitch: %5.1f° | Head: %5.1f° | Mag: (%5.1f, %5.1f, %5.1f) uT | Acc: (%4.1f, %4.1f, %4.1f)\n",
               roll, pitch, heading, mx, my, mz, ax, ay, az);

    delay(1000);
}

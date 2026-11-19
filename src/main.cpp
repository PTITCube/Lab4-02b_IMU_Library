/**
 * VÍ DỤ 4-2b: ĐỌC DỮ LIỆU CẢM BIẾN QUÁN TÍNH 9 TRỤC BẰNG THƯ VIỆN PTITCUBE
 */
#include <Arduino.h>
#include <PTITCube.h>

PTIT_CDH cdh;
PTIT_Sensor sensor;

void setup() {
    cdh.begin(115200);
    sensor.init(false, true, true); // Bật MPU & QMC
}

void loop() {
    sensor.update();

    float ax = sensor.getAccX();
    float ay = sensor.getAccY();
    float az = sensor.getAccZ();

    float roll  = sensor.getRoll();
    float pitch = sensor.getPitch();
    float heading = sensor.getHeading();

    cdh.printf("[IMU] Roll: %6.1f° | Pitch: %6.1f° | Heading: %5.1f° | Acc: (%5.1f, %5.1f, %5.1f)\n",
               roll, pitch, heading, ax, ay, az);

    delay(1000);
}

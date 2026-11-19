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

    float gx = sensor.getGyroX();
    float gy = sensor.getGyroY();
    float gz = sensor.getGyroZ();

    float mx = sensor.getMagX();
    float my = sensor.getMagY();
    float mz = sensor.getMagZ();

    float heading = sensor.getHeading();
    float roll    = sensor.getRoll();
    float pitch   = sensor.getPitch();

    cdh.printf("Acc:  X = %5.2f, Y = %5.2f, Z = %5.2f m/s2 | Roll: %5.1f deg, Pitch: %5.1f deg\n", ax, ay, az, roll, pitch);
    cdh.printf("Gyro: X = %5.2f, Y = %5.2f, Z = %5.2f rad/s\n", gx, gy, gz);
    cdh.printf("Mag:  X = %5.2f, Y = %5.2f, Z = %5.2f uT | Heading: %5.1f deg\n\n", mx, my, mz, heading);

    delay(1000);
}

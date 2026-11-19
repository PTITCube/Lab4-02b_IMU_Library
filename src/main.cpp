/**
 * VÍ DỤ 4-2b: ĐỌC DỮ LIỆU CẢM BIẾN QUÁN TÍNH 9 TRỤC & LA BÀN BẰNG THƯ VIỆN PTITCUBE
 * 
 * Mô tả:
 * - Sử dụng lớp PTIT_Sensor trong thư viện PTITCube để thu thập đầy đủ 9 trục:
 *     + 3 trục Gia tốc (Accelerometer): getAccX(), getAccY(), getAccZ()
 *     + 3 trục Con quay hồi chuyển (Gyroscope): getGyroX(), getGyroY(), getGyroZ()
 *     + 3 trục La bàn từ trường (Magnetometer): getMagX(), getMagY(), getMagZ()
 * - Tự động tính toán góc hướng La bàn: getHeading()
 * - Tự động tính toán góc nghiêng vệ tinh: getRoll(), getPitch()
 */
#include <Arduino.h>
#include <PTITCube.h>

PTIT_CDH cdh;
PTIT_Sensor sensor;

void setup() {
    cdh.begin(115200);

    // Khởi tạo IMU (MPU6500) và La bàn từ trường (QMC5883P)
    sensor.init(false, true, true);
}

void loop() {
    sensor.update();

    // 1. Đọc dữ liệu Gia tốc & Con quay
    float ax = sensor.getAccX();
    float ay = sensor.getAccY();
    float az = sensor.getAccZ();

    float gx = sensor.getGyroX();
    float gy = sensor.getGyroY();
    float gz = sensor.getGyroZ();

    // 2. Đọc dữ liệu Từ trường La bàn (uT)
    float mx = sensor.getMagX();
    float my = sensor.getMagY();
    float mz = sensor.getMagZ();

    // 3. Đọc góc hướng La bàn & Góc nghiêng
    float heading = sensor.getHeading();
    float roll    = sensor.getRoll();
    float pitch   = sensor.getPitch();

    // 4. Hiển thị dữ liệu toàn diện 9 trục & La bàn ra Serial
    cdh.println("--- PHÂN HỆ IMU & LA BÀN - THƯ VIỆN PTITCUBE ---");
    cdh.printf("  Gia tốc (m/s^2)  : X = %6.2f | Y = %6.2f | Z = %6.2f\n", ax, ay, az);
    cdh.printf("  Con quay (rad/s) : X = %6.2f | Y = %6.2f | Z = %6.2f\n", gx, gy, gz);
    cdh.printf("  Từ trường (uT)   : X = %6.2f | Y = %6.2f | Z = %6.2f\n", mx, my, mz);
    cdh.printf("  Góc hướng La bàn : %5.1f°\n", heading);
    cdh.printf("  Góc nghiêng      : Roll = %5.1f° | Pitch = %5.1f°\n\n", roll, pitch);

    delay(1000);
}

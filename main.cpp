#include "mbed.h"
#include "LSM6DSLSensor.h"



static DevI2C devI2c(PB_11,PB_10);
static LSM6DSLSensor acc_gyro(&devI2c,0xD4,D4);


// Define PWM output pins for the LEDs
PwmOut led1(LED1);  // LED1 brightness controlled by X-axis
PwmOut led2(LED2);  // LED2 brightness controlled by Y-axis
PwmOut led3(LED3);  // LED3 brightness controlled by Z-axis

int main() {
    // Initialize the LSM6DSL sensor
    acc_gyro.init(NULL);
    acc_gyro.enable_x();  // Enable accelerometer

    int32_t axes[3];

    while (true) {
        // Read accelerometer data
        acc_gyro.get_x_axes(axes);

        led1 = (axes[0] + 1000.0) / 2000.0;  // Map X-axis to LED1 set scaling factor to human hand movement
        led2 = (axes[1] + 1000.0) / 2000.0;  // Map Y-axis to LED2 set scaling factor to human hand movement
        led3 = (axes[2] + 1000.0) / 2000.0;  // Map Z-axis to LED3 set scaling factor to human hand movement


        // small delay to make the LED brightness changes visible
        wait_us(10000);  // 10ms delay
    }
}
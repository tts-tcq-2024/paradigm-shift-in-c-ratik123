#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool isMeasureTooLow(const char* measureName, float measureValue, float lowerLimit) {
    if (measureValue < lowerLimit) {
        printf("%s is too low!\n", measureName);
        return true;
    }
    return false;
}

bool isMeasureTooHigh(const char* measureName, float measureValue, float upperLimit) {
    if (measureValue > upperLimit) {
        printf("%s is too high!\n", measureName);
        return true;
    }
    return false;
}

bool checkTemperature(float temperature) {
    return !isMeasureTooLow("Temperature", temperature, 0) &&
           !isMeasureTooHigh("Temperature", temperature, 45);
}

bool checkSoc(float soc) {
    return !isMeasureTooLow("State of Charge", soc, 20) &&
           !isMeasureTooHigh("State of Charge", soc, 80);
}

bool checkChargeRate(float chargeRate) {
    return !isMeasureTooHigh("Charge Rate", chargeRate, 0.8f);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    return checkTemperature(temperature) &&
           checkSoc(soc) &&
           checkChargeRate(chargeRate);
}

void runTests() {
    // Test cases
    assert(batteryIsOk(25, 70, 0.7f) == true);
    assert(batteryIsOk(50, 85, 0.0f) == false);
    assert(batteryIsOk(-1, 70, 0.7f) == false);
    assert(batteryIsOk(25, 10, 0.7f) == false);
    assert(batteryIsOk(25, 70, 0.9f) == false);

    printf("All tests passed!\n");
}

int main() {
    runTests();
    return 0;
}


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

bool checkMeasure(const char* measureName, float measureValue, float lowerLimit, float upperLimit) {
    return !isMeasureTooLow(measureName, measureValue, lowerLimit) &&
           !isMeasureTooHigh(measureName, measureValue, upperLimit);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempStatus = checkMeasure("Temperature", temperature, 0, 45);
    bool socStatus = checkMeasure("State of Charge", soc, 20, 80);
    bool chargeStatus = checkMeasure("Charge Rate", chargeRate, 0, 0.8f);
    return tempStatus && socStatus && chargeStatus;
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

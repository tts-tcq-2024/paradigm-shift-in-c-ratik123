#include <stdio.h>
#include <assert.h>

// Enum to represent the status of a battery check
typedef enum {
    OK,
    TEMPERATURE_HIGH,
    TEMPERATURE_LOW,
    SOC_HIGH,
    SOC_LOW,
    CHARGE_RATE_HIGH
} BatteryStatus;

// Function to check if temperature is within the valid range
BatteryStatus checkTemperature(float temperature) {
    if (temperature < 0) {
        return TEMPERATURE_LOW;
    } else if (temperature > 45) {
        return TEMPERATURE_HIGH;
    }
    return OK;
}

// Function to check if state of charge is within the valid range
BatteryStatus checkSOC(float soc) {
    if (soc < 20) {
        return SOC_LOW;
    } else if (soc > 80) {
        return SOC_HIGH;
    }
    return OK;
}

// Function to check if charge rate is within the valid range
BatteryStatus checkChargeRate(float chargeRate) {
    if (chargeRate > 0.8) {
        return CHARGE_RATE_HIGH;
    }
    return OK;
}

// Function to check overall battery status
BatteryStatus batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryStatus status;

    status = checkTemperature(temperature);
    if (status != OK) return status;

    status = checkSOC(soc);
    if (status != OK) return status;

    status = checkChargeRate(chargeRate);
    if (status != OK) return status;

    return OK;
}

// Function to print the status message based on the battery status
const char* getBatteryStatusMessage(BatteryStatus status) {
    switch (status) {
        case OK:
            return "Battery is OK";
        case TEMPERATURE_HIGH:
            return "Temperature too high!";
        case TEMPERATURE_LOW:
            return "Temperature too low!";
        case SOC_HIGH:
            return "State of Charge too high!";
        case SOC_LOW:
            return "State of Charge too low!";
        case CHARGE_RATE_HIGH:
            return "Charge Rate too high!";
        default:
            return "Unknown status";
    }
}

void printBatteryStatus(BatteryStatus status) {
    printf("%s\n", getBatteryStatusMessage(status));
}

void testBatteryStatus(float temperature, float soc, float chargeRate, BatteryStatus expectedStatus) {
    BatteryStatus status = batteryIsOk(temperature, soc, chargeRate);
    assert(status == expectedStatus);
    printBatteryStatus(status);
}

int main() {
    // Test cases to cover all conditions
    testBatteryStatus(25, 70, 0.7, OK);
    testBatteryStatus(50, 70, 0.7, TEMPERATURE_HIGH);
    testBatteryStatus(-5, 70, 0.7, TEMPERATURE_LOW);
    testBatteryStatus(25, 85, 0.7, SOC_HIGH);
    testBatteryStatus(25, 15, 0.7, SOC_LOW);
    testBatteryStatus(25, 70, 0.9, CHARGE_RATE_HIGH);

    return 0;
}

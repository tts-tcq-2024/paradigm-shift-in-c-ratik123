#include <stdio.h>
#include <assert.h>

// Enum created to represent the status of a battery check
typedef enum {
    E_OK,
    TEMP_HIGH,
    TEMP_LOW,
    SOC_HIGH,
    SOC_LOW,
    CHARGE_RATE_HIGH
} BatteryStatus;

// Function to check if temperature is within the valid range
BatteryStatus checkTemperature(float temperature) {
    if (temperature < 0) {
        return TEMP_LOW;
    } else if (temperature > 45) {
        return TEMP_HIGH;
    }
    return E_OK; // temp is in valid range
}

// Function to check if state of charge is within the valid range
BatteryStatus checkSOC(float soc) {
    if (soc < 20) {
        return SOC_LOW;
    } else if (soc > 80) {
        return SOC_HIGH;
    }
    return E_OK; // state of charge is in valid range 
}

// Function to check if charge rate is within the valid range
BatteryStatus checkChargeRate(float chargeRate) {
    if (chargeRate > 0.8) {
        return CHARGE_RATE_HIGH;
    }
    return E_OK; // charge rate is valid 
}

// Function to check overall battery status
BatteryStatus batteryIsE_OK(float temperature, float soc, float chargeRate) {
    BatteryStatus status;

    status = checkTemperature(temperature);
    if (status != E_OK) return status;

    status = checkSOC(soc);
    if (status != E_OK) return status;

    status = checkChargeRate(chargeRate);
    if (status != E_OK) return status;

    return E_OK;
}

// Function to print the status message based on the battery status
void printBatteryStatus(BatteryStatus status) {
    switch (status) {
        case E_OK:
            printf("Battery is E_OK\n");
            break;
        case TEMP_HIGH:
            printf("Temperature too high!\n");
            break;
        case TEMP_LOW:
            printf("Temperature too low!\n");
            break;
        case SOC_HIGH:
            printf("State of Charge too high!\n");
            break;
        case SOC_LOW:
            printf("State of Charge too low!\n");
            break;
        case CHARGE_RATE_HIGH:
            printf("Charge Rate too high!\n");
            break;
    }
}

void testBatteryStatus(float temperature, float soc, float chargeRate, BatteryStatus expectedStatus) {
    BatteryStatus status = batteryIsE_OK(temperature, soc, chargeRate);
    assert(status == expectedStatus);
    printBatteryStatus(status);
}

int main() {
    // Test cases to cover all conditions
    testBatteryStatus(25, 70, 0.7, E_OK);
    testBatteryStatus(50, 70, 0.7, TEMP_HIGH);
    testBatteryStatus(-5, 70, 0.7, TEMP_LOW);
    testBatteryStatus(25, 85, 0.7, SOC_HIGH);
    testBatteryStatus(25, 15, 0.7, SOC_LOW);
    testBatteryStatus(25, 70, 0.9, CHARGE_RATE_HIGH);

    return 0;
}

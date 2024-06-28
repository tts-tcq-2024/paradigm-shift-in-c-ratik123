#include <stdio.h>
#include <assert.h>
 
// Function to check if temperature is within the acceptable range
int isTemperatureWithinRange(float temperature) {
    int result = (temperature >= 0 && temperature <= 45);
    printf("Temperature check (%f): %d\n", temperature, result);
    return result;
}
 
// Function to check if State of Charge (SOC) is within the acceptable range
int isSocWithinRange(float soc) {
    int result = (soc >= 20 && soc <= 80);
    printf("SOC check (%f): %d\n", soc, result);
    return result;
}
 
// Function to check if charge rate is within the acceptable range
int isChargeRateWithinRange(float chargeRate) {
    int result = (chargeRate <= 0.8);
    printf("Charge Rate check (%f): %d\n", chargeRate, result);
    return result;
}
 
// Function to print the specific error message based on the failed condition
void printErrorMessage(float temperature, float soc, float chargeRate) {
    if (!isTemperatureWithinRange(temperature)) {
        if (temperature < 0) {
            printf("Temperature too low!\n");
        } else {
            printf("Temperature too high!\n");
        }
    }
    if (!isSocWithinRange(soc)) {
        if (soc < 20) {
            printf("State of Charge too low!\n");
        } else {
            printf("State of Charge too high!\n");
        }
    }
    if (!isChargeRateWithinRange(chargeRate)) {
        printf("Charge Rate too high!\n");
    }
}
 
// Function to check if the battery parameters are all within acceptable ranges
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int temperatureOk = isTemperatureWithinRange(temperature);
    int socOk = isSocWithinRange(soc);
    int chargeRateOk = isChargeRateWithinRange(chargeRate);
 
    if (!temperatureOk || !socOk || !chargeRateOk) {
        printErrorMessage(temperature, soc, chargeRate);
        return 0;
    }
    return 1;
}
 
// Function to run tests on batteryIsOk function using assertions
void runTests() {
    // Test with all parameters within range
    assert(batteryIsOk(25, 70, 0.7));
 
    // Test with temperature out of range and SOC out of range
    assert(!batteryIsOk(50, 85, 0)); // Should fail: Temperature too high and SOC too high
 
    // Test with temperature too low
    assert(!batteryIsOk(-1, 50, 0.5)); // Should fail: Temperature too low
 
    // Test with SOC too high
    assert(!batteryIsOk(25, 85, 0.5)); // Should fail: SOC too high
 
    // Test with SOC too low
    assert(!batteryIsOk(25, 15, 0.5)); // Should fail: SOC too low
 
    // Test with charge rate too high
    assert(!batteryIsOk(25, 50, 0.9)); // Should fail: Charge Rate too high
 
   
}
   
int main() {
    runTests(); // Run all test cases
   
            return 0; // Return success status
            }

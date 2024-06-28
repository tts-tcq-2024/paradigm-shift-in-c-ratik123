#include <stdio.h>
#include <assert.h>
int isTemperatureOk(float temperature) {
if (temperature < 0) {
printf("Temperature too low!\n"); return 0;
} else if (temperature > 45) {
printf("Temperature too high!\n"); return 0;
}
return 1;
}
int isSocOk(float soc) {
if (soc < 20) {
printf("State of Charge too low!\n"); return 0;
} else if (soc > 80) {
printf("State of Charge too high!\n"); return 0;
}
return 1;
}
int isChargeRateOk(float chargeRate) {
if (chargeRate > 0.8) {
printf("Charge Rate too high!\n"); return 0;
}
return 1;
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
int tempOk = isTemperatureOk(temperature);
int socOk = isSocOk(soc);
int chargeRateOk = isChargeRateOk(chargeRate);
return tempOk && socOk && chargeRateOk;
}
void runTests() {
assert(batteryIsOk(25, 70, 0.7));
assert(!batteryIsOk(50, 85, 0)); // Temperature too high and SOC too high
assert(!batteryIsOk(-1, 50, 0.5)); // Temperature too low
assert(!batteryIsOk(25, 85, 0.5)); // SOC too high
assert(!batteryIsOk(25, 15, 0.5)); // SOC too low
assert(!batteryIsOk(25, 50, 0.9)); // Charge Rate too high
assert(!batteryIsOk(0, 20, 0.8)); // Edge case: Temperature on the lower edge
assert(batteryIsOk(0, 20, 0.8)); // Edge case: Everything on the edge but within range
assert(!batteryIsOk(45.1, 80, 0.8)); // Temperature just above high range
assert(batteryIsOk(45, 80, 0.8)); // Edge case: Everything on the upper edge
}
int main() {
runTests();
printf("All tests passed!\n");
return 0;
}

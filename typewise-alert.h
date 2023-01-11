#pragma once
#define SET   1
#define RESET 0

typedef enum {
  PASSIVE_COOLING,
  MED_ACTIVE_COOLING,
  HI_ACTIVE_COOLING,
  MAX_COOLING_TYPE
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_MAX
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
typedef struct{
  int flagHighTemp = RESET;
  int flagLowTemp  = RESET;
}TempFlag

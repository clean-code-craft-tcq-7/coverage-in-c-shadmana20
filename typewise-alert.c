#include "typewise-alert.h"
#include <stdio.h>


int CoolingUpperLimits[MAX_COOLING_TYPE] = {35 , 40, 45};

void (*AlertTarget_func_ptr[TO_MAX])(BreachType) = {&sendToController, &sendToEmail};

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = 0;
  int upperLimit = 0;
  
  upperLimit = CoolingUpperLimits[coolingType];
  
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
 {

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  
  (*AlertTarget_func_ptr[alertTarget])(breachType);
  
}




#include "typewise-alert.h"
#include "stdio.h"

TempFlags Tempflag = {.FlagHighTemp = TEMPLOW ,.FlagLowTemp = TEMPHIGH,.FlagTypeMail = UNUSED, .FlagTypeController = UNUSED};

void sendToController(BreachType breachType) 
{
 
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  Tempflag.FlagTypeController = USED;
}

void sendToEmail(BreachType breachType) 
{
  
  
  Tempflag.FlagTypeMail = USED;
  const char* recepient = "a.b@c.com";
  if(breachType == TOO_LOW)
  {
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
    Tempflag.FlagLowTemp = TEMPLOW;
  }

  if(breachType == TOO_HIGH)
  {
     printf("To: %s\n", recepient);
     printf("Hi, the temperature is too high\n");
    Tempflag.FlagHighTemp = TEMPHIGH;
  }
}

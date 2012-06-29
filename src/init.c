#include <pthread.h>

#include "guiNetwork.h"
#include "sensorsNetwork.h"
#include "../parse/rules.tab.h"
#include "sensors.h"
#include "actions.h"
#include "actionneurs.h"
#include "initCheckRules.h"
#include "timedCheck.h"
#include "common.h"

#include "init.h"
#include "rules.h"

void init()
{
  pthread_mutex_init(&sensorsMutex, NULL);

  parseAll();
  parseConfig();

  initRules();
  startTimedCheck(60);

  //sensorsNetworkStart();
  guiNetworkStart();

}

void destroy()
{
  guiNetworkStop();
  //sensorsNetworkStop();

  stopTimedCheck();
  stopRules();
  pthread_mutex_destroy(&sensorsMutex);

  cleanMemory();
}

void cleanMemory(){
  cleanActions();
  cleanRules();
  cleanActionneurs();
  cleanSensors();
}

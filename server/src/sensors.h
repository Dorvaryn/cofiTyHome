#include "stdio.h"
#include "string.h"

// ########################### Capteurs ##############################

typedef enum typeCapteur {
    TEMPERATURE,
    CONTACT,
    INTERRUPTEUR,
    PRESENCE
} typeCapteur;

typedef struct sensorType {
 typeCapteur type;
 char id[8];
 void *data;
 struct sensorType* nextSensor;
 void (*decode)(char* trame, struct sensorType*);
};

struct sensorType * sensors;

struct sensorType * getSensor(char id[8]);

//sensorType sensorList;


//----- TEMPERATURE --------------------------------------------------------------------
typedef struct dataTEMPERATURE {
    int temp;
} dataTEMPERATURE;

extern void decodeTemperature(char* trame, struct sensorType* capteur);

//----- CONTACT ------------------------------------------------------------------------
typedef struct dataCONTACT {
    char contact;
} dataCONTACT;

extern void decodeContact(char* trame, struct sensorType* capteur);

//----- PRESENCE ------------------------------------------------------------------------
typedef struct dataPRESENCE {
    char presence;
    char luminosite;
} dataPRESENCE;

#
extern void decodePresence(char* trame, struct sensorType* capteur);


//----- INTERRUPTEUR --------------------------------------------------------------------

typedef enum buttonPressed {
    A0,
    A1,
    B0,
    B1,
    NONE
} buttonPressed;

typedef struct dataINTERRUPTEUR {
    buttonPressed switchButton;
} dataINTERRUPTEUR;


extern void decodeInterrupteur(char* trame, struct sensorType* capteur);
#if ! defined ( ACTIONNEURS_H_ )
#define ACTIONNEURS_H_

// ########################### Actionneurs ###########################

typedef enum typeActionneur {
    COURRANT
} typeActionneur;

typedef struct actionneur_t {
 typeActionneur type;
 char id[8];
 struct actionneur_t* nextActionneur;
};

struct actionneur_t * actionneurs;

struct actionneur_t * getActionneur(char id[8]);

void caca();
//----- COURRANT --------------------------------------------------------------------
void openCOURRANT(char id[8]);
void closeCOURRANT(char id[8]);

#endif /*ACTIONNEURS_H_*/
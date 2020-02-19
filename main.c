#include "pro.h"


//-------STRUCTURE TABLEAU-------
//-------------------------------


struct vtab {
 int nbe;
 char* tabl;
};
typedef struct vtab vtab_t;

//////////////////////////////////////////

static const char filename[] = "instruction.txt";
static char line[189][200];
static char tableau_transaction[100][4][20];
static int nb_char=0;
static char bande_final[1000];
static int  instruction_line=0;
static int  chargement_line=0;


//////////////////////////////////////////

int main ( void ){

vtab_t tb;
int nbe;
tb.tabl = malloc(nb_char*sizeof(vtab_t));
tb=lecture(tb);
//voirbande(tb);

chargement_line=charger_fichier();
chargement_instruction();
traitement(tb);

}


#include <stdio.h>
#include<string.h>
#include<stdlib.h>


//-------------STATIC------------
//-------------------------------

static const char filename[] = "instruction.txt";
static char line[189][200];
static char tableau_transaction[100][4][20];
static int nb_char=0;
static char bande_final[1000];
static int  instruction_line=0;
static int  chargement_line=0;


//-------STRUCTURE TABLEAU-------
//-------------------------------


struct vtab {
 int nbe;
 char* tabl;
};
typedef struct vtab vtab_t;


//--------------------------------------------------------------------------------------------------------

vtab_t lecture (vtab_t nb) {
 int i=0;
 nb.nbe=100;
 vtab_t ptrc;
 nb.tabl = malloc((nb.nbe)*sizeof(vtab_t));
 ptrc.tabl = nb.tabl;
 FILE* fichier = NULL;
 fichier = fopen("test.txt", "r");

 if (fichier != NULL) {
  while((nb.tabl[i]=fgetc(fichier))!=EOF){  
      nb.nbe=i;
      i++; 
  }
  //nb.tabl = malloc((nb_char)*sizeof(vtab_t));

  //printf("\n%d",i-1); 
 {
 fclose(fichier);

 }
 }
 return nb;
}

//----------------------------------------------------------------------------------------------------------


void voirbande(vtab_t tableau) {
int i;

  for(i=0;i<tableau.nbe;i++){
   printf("%c", tableau.tabl[i]);
  
  }
printf("\n");
}




//---------------------------------chargement des chaque instruction dans le vecteur tableau transaction(Mohamed)-----------------------

int charger_fichier() {
  
   FILE *file = fopen ( filename, "r" );
   int i=0;
  
   if ( file != NULL ){
 
       //perror ( filename ); /*  cette fonction verifie que le fichier a bien été chargé et y a t'il eu une erreur */  
            
       while ( fgets( line[i], 200 , file ) != NULL ){            
                 
 
          printf("\n%s",line[i]);
          i++;
                
       }

       fclose ( file );
   }
   
   
   return i;
   
}

//int traitement()







//--------------------------------------------------CHARGEMENT INSTRUCTION-------------------------------------------------------

void chargement_instruction(){


    int ligne=0;
    int char_line = 0;
    int char_i = 0;
    int mot_instruction = 0;
    int char_instruction = 0;
    int nb_char_sp=0;
    int l=0;
    char bande_final;
    
    
    while (ligne<chargement_line){
    
    
        while(line[ligne][char_line]=='#'){
            ligne++;
        }
        
        if(line[ligne][char_line] == '\n' || line[ligne][char_line] =='\0'){
            
            ligne++;
            l++;
            mot_instruction=0;
            char_line=0;
            char_i=0;            
            //printf("\n\n");                    
        }
            
        if 
        (line[ligne][char_line] != ' ' 
        && line[ligne][char_line] != '\n' 
        && line[ligne][char_line] != '\t' 
        && line[ligne][char_line] !='\0'){
        
            nb_char_sp=0;
            tableau_transaction[l][mot_instruction][char_i]=line[ligne][char_line];
            char_i++;
                           
        }
        
        
        if(line[ligne][char_line] == ' ' || line[ligne][char_line] == '\t'){
            
            if(nb_char_sp<1){ 
                nb_char_sp++;
                char_i=0;
                //printf("mot: %d\n",mot_instruction);       
                mot_instruction++;

                char_i=0;
            }
            
       }
                 
        char_line++;
                
    }

instruction_line=l;  
//printf("%d",instruction_line);  

        
}





int search(char state , char current_char){
    int ligne=0;
    //printf("currence:%c\n",current_char);
    //printf("state:%c\n",state);

    for(int i=-1;i<instruction_line;i++){
        if(state==tableau_transaction[i][0][0] && current_char==tableau_transaction[i][1][0]){
            ligne=i;
        }
    }
    return ligne;
}





int traitement(vtab_t b){
    int i;
    int instr;
    int mot =1;
    
    int cha=0;
    int c=0;
    int continuer=1;
    char current_state;

    current_state=tableau_transaction[0][0][0];

        
    int l=0;
    int char_b=0;
    int indice_commande=0;

    while(continuer){

        indice_commande=search(current_state,b.tabl[char_b]);
        b.tabl[char_b]=tableau_transaction[indice_commande][2][0];
        current_state=tableau_transaction[indice_commande][4][0];
        //printf("currence:%c\n",b.tabl[char_b]);
        //printf("char:%d\n",char_b);
        if (tableau_transaction[indice_commande][3][0]=='>'){
            char_b++;
        }
        else{char_b--;}
        if (current_state=='!')
        {
        continuer=0;    /* code */
        }

    }
        printf("\n%s\n",b.tabl);
}


    




    
//-------------------------------------------------MAIN----------------------------------------------    




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



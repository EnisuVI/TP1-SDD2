#include "es.h" 	 
#include <assert.h>
#include <stdlib.h>
#define SEUIL 5 

typedef struct
{
T_Elt *Elts; // pointeur sur un élément
int nbElts;
} T_PileD; //type pile dynamique


void initPile( T_PileD * ); //mettre nbElts à 0
int pilepleine(  T_PileD *); //renvoie 1  qd nbElts == MAX
int pilevide(const  T_PileD *); // renvoie 1  qd nbElts == 0 
int empiler( T_PileD *, T_Elt ); //push de e dans la case nbElts de Elts, renvoie 1 si empiler OK, 0 sinon (qd pilePleine) 
int depiler( T_PileD *, T_Elt *); //pop retourne le T_Elt via pelt et renvoie 0 si pile vide, 1 sinon.
T_Elt sommet(const  T_PileD *);// valeur au sommet de la pile
int hauteur(const  T_PileD *);
void afficherPile(T_PileD *); //vous devez depiler la pile pour afficher chacune de ses valeurs (puis surtout la rempiler)


int rpn(T_PileD *, char*);
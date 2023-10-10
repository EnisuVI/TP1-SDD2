#include "pile.h"

void initPile(T_PileD *P)
{
  P->Elts = (T_Elt *)malloc(SEUIL * sizeof(T_Elt));
  P->nbElts = 0; // important
  assert(P->Elts);
  printf("Initialisation réussie de la pile dynamique");
}

int pilepleine(T_PileD *P)
{
  int nouvelleTaille;
  if (P->nbElts % SEUIL == 0)
  {
    nouvelleTaille = ((P->nbElts / SEUIL) + 1) * SEUIL;
    P->Elts = realloc(P->Elts, nouvelleTaille * sizeof(T_Elt));
    //printf("\n==>La pile est de taille %d.", nouvelleTaille);
    assert(P->Elts);
    return 0;
  }
}

int pilevide(const T_PileD *P)
{
  if (P->nbElts == 0)
    return 1;
  return 0;
}

int empiler(T_PileD *P, T_Elt e) // renvoie 0 si pile pleine, sinon 1
{
  if (!pilepleine(P))
  {
    P->Elts[P->nbElts] = e;
    //affecterElt(&P->Elts[P->nbElts], &e);
    P->nbElts++;
    return 1;
  }
  else
  {
    return 0;
  }
}

int depiler(T_PileD *P, T_Elt *pelt) // renvoie 0 si pile vide, sinon 1
{
  int nouvelleTaille;
  if (!pilevide(P))
  {
    *pelt = P->Elts[--P->nbElts];
    if (P->nbElts > 0 && P->nbElts % SEUIL == 0)
    {
      nouvelleTaille = (((P->nbElts) / SEUIL)) * SEUIL;
      P->Elts = realloc(P->Elts, nouvelleTaille * sizeof(T_Elt));
      //printf("\n==> La pile est de taille %d ", nouvelleTaille);
      assert(P->Elts);
    }
    return 1;
  }
  return 0;
}

void afficherPile(T_PileD *P)
{
  T_Elt elt;
  T_PileD P2;
  initPile(&P2);
  while (!pilevide(P))
  {
    depiler(P, &elt);
    empiler(&P2, elt);
  }
  while (!pilevide(&P2))
  {
    depiler(&P2, &elt);
    empiler(P, elt);
    printf("\n%c", elt);
  }
}
int estOperateur(T_Elt c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/')
  {
    return 1;
  }
  return 0;
}

int estPrioritaire(T_Elt e1, T_Elt e2)
{
  if (e1 == '*' || e2 == '/')
    return 1;
  if (e1 == '+' || e2 == '-')
    return 1;
  return 0;
}

int estOperande(T_Elt e)
{
  if (e >= 'a' && e <= 'z')
    return 1;
  if (e >= 'A' && e <= 'Z')
    return 1;
  if (e >= '0' && e <= '9')
    return 1;
  return 0;
}

T_Elt sommet(const T_PileD *P){
  return P->Elts[P->nbElts-1];
}

int rpn(T_PileD *P, char* chaine) {
  T_Elt elt;
  int i = 0;
  printf("\n");
  while(chaine[i] != '\0'){
    if(estOperande(chaine[i]))  printf("%c", chaine[i]);
    if(chaine[i] == '(') empiler(P, chaine[i]);
    if(estOperateur(chaine[i])){
      if(pilevide(P)) empiler(P, chaine[i]);
      else if(sommet(P) == '(') empiler(P, chaine[i]);
      else if(estPrioritaire(chaine[i], sommet(P))) empiler(P, chaine[i]);
      else{
        depiler(P, &elt);
        printf("%c", elt);
        empiler(P, chaine[i]);
      }
    }
    else if(chaine[i] == ')'){
      while(sommet(P) != '('){
        depiler(P, &elt);
        printf("%c", elt);
      }
      depiler(P, &elt);
    }
    i++;
  }
  while(!pilevide(P)){
    depiler(P, &elt);
    printf("%c", elt);
  }
  printf("\n");
}
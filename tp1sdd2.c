// SDD2 TP 1 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"


int menu()
{

int choix;
printf("\n\n\nSDD2 TP1");
printf("\n\n\n1 - Tester mon fichier pile.c");
printf("\n2 - Afficher et compter les permutations d'une chaine");
printf("\n3 - Afficher et compter les solutions pour un échiquier ");
printf("\n0 - QUITTER  ");
printf("\n\nVotre choix ?  ");
scanf("%d",&choix);
return choix;
}

int main()
{
T_PileD mapile;
int chx;
// int taille;
//char chaine[20];

do
{
chx=menu();
switch (chx)
	{
	case 1 :  
		//testez toutes vos fonctions par un jeu de test de votre choix
		testPile(); //TP9 partie 1 : à ecrire 
		break;
	case 2 : 
		//scanf("%s",chaine); //une chaine de longueur <=MAX
		//permut(&mapile,chaine); //TP9 partie 2: ecrire permut
		break;
	case 3 : 
		//scanf("%d",&taille);//taille echiquier <=MAX
		//echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
		break;



	}
}while(chx!=0);

printf("\nAu plaisir de vous revoir ...\n");
return 0;
}

int testPile()
{
	int choixTest;
	T_Elt elemAj;
	T_Elt elemDe;
	char chaine[100];

	T_PileD mapile;
	T_PileD mapile1;
	initPile(&mapile1);
	
	
	do
	{
		printf("\n\n\nTester la pile");
		printf("\n\n\n1 - Afficher la pile");
		printf("\n2 - Ajouter des éléments à la pile");
		printf("\n3 - Supprimer des éléments de la pile");
		printf("\n4 - Notation Polonaise Inverse");
		printf("\nVotre choix ?  ");
		scanf("%d",&choixTest);

		switch (choixTest){
			case 1:
				afficherPile(&mapile1);
				break;
			case 2:
				printf("Quel élément voulez-vous empiler ? ");
				scanf(" %c",&elemAj);
				empiler(&mapile1,elemAj);
				break;
			case 3:
				depiler(&mapile1,&elemDe);
				printf("Elément dépilé : %c", elemDe);
				break;
			case 4:
				printf("Valeur ? ");
				scanf(" %s", chaine);
				initPile(&mapile);
				rpn(&mapile, chaine);
				break;
		}
	}while (choixTest!=0);
	
}
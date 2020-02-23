#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <windows.h>

// Varaibles générales qu'il faudra changer en structures

char Lac [20] = "Lac";
char Arbre [20] = "Arbre";
char Grotte [20] = "Grotte";
char Vallee [20] = "Vallee";
char Plaine [20] = "Plaine";
char Montagne [20] = "Montagne";
char Village [20] = "Village";
char choix [20];
char localisation [20];
char delete [20]="...";

// Fonction principale

int main (){

		printf("========================================\n\n");
		printf("Ou voulez-vous aller ?\n\n");
		Sleep(1000);
		printf("Plaine   : Entrez Plaine\nMontagne : Entrez Montagne \n\n ");

		scanf("%s",&choix);
		Sleep(1000);
		printf("========================================");

// Premier embranchement
// Boucle du premier choix Plaine

if(strcmp (choix,Plaine) == 0) {

		printf("\n\n");
		printf("Vous allez sur la Plaine\n\n");

		strcpy(localisation,Plaine);

}

// Boucle du deuxième choix

if(strcmp (choix,Montagne) == 0) {

		printf("\n\n");
		printf("=============================\n");
		printf("Vous examinez \n\n");

// Pour le délai entre les boites de dialogue
/*
	Sleep(2000);
	printf("Le chemin est escarpé, vous prenez du temps");
	printf(".");
	Sleep(2000);
	printf(".");
	Sleep(2000);
	printf(".");
	Sleep(2000);
*/

		strcpy(localisation,Montagne);

		printf("%s\n\n",localisation);


 	

}

// Deuxième embranchement
	
if(strcmp(localisation,Montagne) == 0){

		printf("\n=============================\n");
		printf("Ou voulez-vous aller ?\n\n");
		printf("Grotte : Entrez Grotte\nVallee : Entrez Vallee \nRetrouner au Village : Entrez Village ");

		scanf("%s",&choix);

		printf("========================================");
}

// Boucle premier choix

if(strcmp(choix,Grotte) == 0){

		printf("\n\n");
		printf("Vous entrez dans la Grotte");

		strcpy(localisation,Grotte);

		
}

// Boucle second choix

if(strcmp(choix,Vallee) == 0){

		printf("\n\n");
		printf("Vous entrez dans la Vallee");

		strcpy(localisation,Vallee);		
}

//Boucle Retour

if(strcmp(choix,Vallee) == 0){

		printf("\n\n");
		printf("Vous rentrez au Village");

		strcpy(localisation,Village);		
}




}
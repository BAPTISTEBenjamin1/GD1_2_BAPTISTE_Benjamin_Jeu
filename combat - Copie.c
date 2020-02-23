#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <windows.h>

//Structure pour les stats du perso et des ennemis

struct generatemonster{

	int pv;
	int mana;
	int attack;
	int force;

	int state;
	int choice;

	int xp;
	int pvmax;
	int manamax;
	int xpmax;
};
//Définition de l'appelation de la structure

typedef struct generatemonster g;


int attack (int a,int f){

	

	a = rand()%a+3;

	a = a*f;

	return a;
}

int attackConc (int a,int f){

	a = rand()%a+1;

	a = a*f;

	a = a*3;

	return a;
}

int attackDef (int d, int f){

	d = rand()%d+1;

	d = d*f;

	d = d/4;

	return d;
}



int mChoice (int c){

	c = rand()%3+1;

	return c;
}



//Début du programme

int main (){

//Génération des variables joueur et ennemi
srand(time(NULL));

g bandit = {20,6,8,1,1,0,10,20,6,0};// pv - mana - attack - force - state - choice - xp - pvmax - mana max - xpmax
g player = {50,10,5,2,1,0,0,50,10,30};



//Début du combat
printf("\n==================\n");
printf("Un ennemi apparait !\n\n");

while(player.pv >= 0 || bandit.pv >= 0 || player.choice == 0){

	printf("\n============================\n");
	printf("\nQue voulez-vous faire ?\n\n1 - Attaquer\n2 - Defendre\n3 - Concentration (5pm)\n\n");

	scanf("%d",&player.choice);






// Choix Attaque du joueur
if(player.choice == 1){

	printf("Vous Attaquez l'ennemi !\n");

	bandit.pv = bandit.pv - attack (player.attack,player.force);

	printf("\nBandit : %d/%d\n",bandit.pv,bandit.pvmax);

//Ne pas oublier de mettre ça à touts les scénarios

	bandit.choice = mChoice(bandit.choice);
}


//Choix Défense du joueur
if(player.choice == 2){

	printf("Vous vous defendez ...\n");

	player.pv = player.pv - attackDef (bandit.attack,bandit.force);
	printf("Il vous reste %d/%d points de vie ...\n",player.pv,player.pvmax );

}

// Choix Concentration du joueur

if(player.choice == 3){

	printf("Vous analysez la posture de l'ennemi ...\n");

	player.mana = player.mana - 5;

	Sleep (1000);

	bandit.choice = mChoice(bandit.choice);

	Sleep (1000);

	bandit.pv = bandit.pv - attackConc (player.attack,player.force);

	printf("\nBandit : %d/%d\n",bandit.pv,bandit.pvmax);

	Sleep (2000);

		if(player.mana<player.manamax){

		player.mana = player.mana +1;

		printf("Il vous reste %d/%d points de mana\n",player.mana,player.manamax);
}


//Ne pas oublier de mettre ça à touts les scénarios
	
}





// Choix Attaque Bandit 1

if(bandit.choice == 1){

	printf("L'ennemi vous attaque !\n");

	player.pv = player.pv - attack (bandit.attack,bandit.force);

	printf("Il vous reste %d/%d points de vie ...\n",player.pv,player.pvmax );

	bandit.choice == 0;

}








if (bandit.pv<=0){

	printf("\n===================================\n");
	printf("Bravo, vous avez vaincu l ennemi !\n\n");

	printf("Le combat vous rapporte %d points d'experience !\n",bandit.xp );
	
	player.xp = 30;

	printf("Vous avez %d/%d points d'experience avant d'atteindre le prochain niveau !\n",player.xp,player.xpmax );

	break;
}

if (player.pv<=0){

	printf("\n==============\n");
	printf("Vous etes mort\n");

	break;

}

if(player.xp = player.xpmax){

	player.xp == 0;
	player.xpmax = player.xpmax*2;

	printf("%d/%d\n",player.xp,player.xpmax);	
}	

}

}
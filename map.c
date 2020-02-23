#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <windows.h>
#include <conio.h>

// Varaibles générales qu'il faudra changer en structures

char Lac [20] = "Lac";
char Arbre [20] = "Arbre";
char Grotte [20] = "Grotte";
char Vallee [20] = "Vallee";
char Plaine [20] = "Plaine";
char Montagne [20] = "Montagne";
char Village [20] = "Village";
char choix [20];
char localisation [20] = "Village";
char retour [20]="retour";

int Spawn = 0;
int temps = 0;
int loup = 0;
int hydre = 0;
int bandi = 0;
int ermite = 0;


//Structure pour les stats du perso et des ennemis

struct generatemonster{

	char Nom [20];

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


//Fonctions de génération des ennemis

void createBandit (g *p){

	strcpy ((*p).Nom,"Bandit");
	(*p).pv = 30;
	(*p).mana =0;
	(*p).attack = 8;
	(*p).force =1;
	(*p).state =1;
	(*p).choice =0;
	(*p).xp =15;
	(*p).pvmax =20;
	(*p).manamax =0;
	(*p).xpmax =0;

}

void createErmiteFou (g *p){

	strcpy ((*p).Nom,"Ermite Fou");
	(*p).pv = 50;
	(*p).mana =0;
	(*p).attack = 3;
	(*p).force = 2;
	(*p).state = 0;
	(*p).choice = 0;
	(*p).xp = 20;
	(*p).pvmax = 50;
	(*p).manamax = 0;
	(*p).xpmax = 0;

}

void createLoup (g *p){

	strcpy ((*p).Nom,"Loup");
	(*p).pv = 15;
	(*p).mana =0;
	(*p).attack = 6;
	(*p).force = 1;
	(*p).state = 1;
	(*p).choice = 0;
	(*p).xp = 10; //TEST A CHANGER
	(*p).pvmax = 10;
	(*p).manamax = 0;
	(*p).xpmax = 0;

}

void createHydre (g *p){

	strcpy ((*p).Nom,"Hydre");
	(*p).pv = 75;
	(*p).mana =0;
	(*p).attack = 10;
	(*p).force = 2;
	(*p).state = 1;
	(*p).choice = 0;
	(*p).xp = 30;
	(*p).pvmax = 75;
	(*p).manamax = 0;
	(*p).xpmax = 0;

}

void createDemon (g *p){

	strcpy ((*p).Nom,"Demon");
	(*p).pv = 200;
	(*p).mana =0;
	(*p).attack = 20;
	(*p).force = 3;
	(*p).state = 1;
	(*p).choice = 0;
	(*p).xp = 1000;
	(*p).pvmax = 200;
	(*p).manamax = 0;
	(*p).xpmax = 0;

}

void Lveling (g *p){

	(*p).manamax = (*p).manamax + 5;
	(*p).xpmax = (*p).xpmax *2;
	(*p).pvmax = (*p).pvmax + 10;
	(*p).pv = (*p).pvmax;
	(*p).mana = (*p).manamax;
	(*p).attack = (*p).attack +2;
	(*p).force = (*p).force + 1;
	(*p).state = 1;
	(*p).choice = 0;
	(*p).xp = 0;
}


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

	c = rand()%2+1;
	return c;
}

int cyclejouernuit (int n){

	n = n + 1;

	return n;
}

int repos(int z,int n){

	z == n;

	return z;
}

void afficherstats (int pv,int pvmax,int mana, int manamax, int attack, int force, int xp, int xpmax){

	printf("Voila vos statiques :\n\nPoints de vie  :%d/%d\nPoints de mana :%d/%d\nAttaque        :%d\nForce          :%d\nExperience     :%d/%d\n",pv,pvmax,mana,manamax,attack,force,xp,xpmax);
}


// Fonction principale

int main (){

srand(time(NULL));

//Nom - pv - mana - attack - force - state - choice - xp - pvmax - mana max - xpmax
g player = {"YOU",50,10,5,2,1,0,0,50,10,30};
g bandit = {"Bandit",20,6,8,1,1,0,10,20,6,0};


// Début du programme

// Menu Stats

retourmenu:

if(strcmp(localisation,Village) == 0){


				printf("====================================================================\nApres que ces derniers mois le village connu de nombreux malheurs,\n la chaman vous convoque dans sa hutte. Apres un rituel\n et des paroles en l air ses yeux se revulsent, elle vous\n dit que 'Le mal ne pourra etre purrifie tant que le sang \nne sera pas verse en abondance'.\n====================================================================\n\n");
				
				

				/*Sleep(5000);*/

				printf("\n\nLe Village est un endroit sur, vous pouvez y retourner a tout moment pour vous y reposer\n\n");

				retourvillage:

				repos (player.pv,player.pvmax);

				afficherstats (player.pv,player.pvmax,player.mana,player.manamax,player.attack,player.force,player.xp,player.xpmax);
				
				if(hydre >= 2 && loup >= 2 && bandi >= 2 && ermite >= 2){

							Spawn = 1;
							createDemon (&bandit);
							if(Spawn == 1) goto spawnEnnemi;
							finJeu:
							printf("Bravo vous avez vaincu le mal dans votre région !");
							}

							printf("===========================\n\n");
							printf("Ou voulez-vous aller ?\n\n");
							printf("Plaine   : Entrez 'Plaine'\nMontagne : Entrez 'Montagne'\n\n ");
							scanf("%s",&choix);

							if(strcmp(choix,Plaine) == 0){strcpy(localisation,Plaine); temps = cyclejouernuit (temps); printf("%d\n",temps);}
							if(strcmp(choix,Montagne) == 0){strcpy(localisation,Montagne); temps = cyclejouernuit (temps); printf("%d\n",temps);}
							if(strcmp(choix,Plaine) != 0 && strcmp(choix,Montagne) !=0)  {

							printf("\n- Destination inconnue -\n");
							goto retourvillage;



							}

						
					
		}


// Premier embranchement Plaine Montagne
// Boucle du premier choix Plaine
// Plaine - Choix
				
			if(strcmp(localisation,Plaine) == 0){

	//Event ennemi

							Spawn = 1;

							createLoup (&bandit);

							if(Spawn == 1) goto spawnEnnemi;

							finCombatLoup:
							loup = loup + 1;
							erreurPlaine:

							

							printf("\nOu voulez-vous aller ?\n\n");
							printf("Lac : Entrez 'Lac'\nArbre : Entrez 'Arbre' \nRetourner au Village : Entrez 'Village'\n\n");
							scanf("%s",&choix);

							if(strcmp(choix,Lac) ==0){strcpy(localisation,Lac); temps = cyclejouernuit (temps); printf("%d\n",temps);}
							if(strcmp(choix,Arbre) ==0){strcpy(localisation,Arbre); temps = cyclejouernuit (temps); printf("%d\n",temps);}
							if(strcmp(choix,Village) ==0) goto retourVillage; temps = cyclejouernuit (temps); printf("%d\n",temps);}
							if(strcmp(choix,Lac) != 0 && strcmp(choix,Arbre) !=0 && strcmp(choix,Village) !=0)  {

								printf("\n- Destination inconnue -\n");
								goto erreurPlaine;

							}
					
			}

	// Plaine - Lac

							if(strcmp(localisation,Lac) == 0){

									printf("\n\n");
									printf("=============================\n");
									printf("Vous vous dirigez vers le Lac\n");
									printf("=============================\n\n");

									Spawn = 1;
									createHydre (&bandit);
									if(Spawn == 1) goto spawnEnnemi;

									finCombatHydre:
									hydre = hydre + 1;
									erreurLac:
									

									printf("Ou voulez-vous aller ?\n\n");
									printf("Retourner a la Plaine : Entrez 'Plaine'\n\n");
									scanf("%s",&choix);

									if(strcmp(choix,Plaine) != 0)  {

											printf("\n- Destination inconnue -\n");
											goto erreurLac;

									}
									
									if(strcmp(choix,Plaine) == 0) printf("=============================\n");printf("\n\nVous retournez a la Plaine\n"); goto erreurPlaine; temps = cyclejouernuit (temps); 	
									printf("=============================\n");
							}


	// Plaine - Arbre

									if(strcmp(choix,Arbre) == 0){

											printf("\n\n");
											printf("Vous vous dirigez vers l'Arbre\n\n");
											repos (player.pv,player.pvmax);
											printf("Une etrange sensation vous envahit. Vous regagnez tous vos points de vie !\n");
											erreurArbre:
											printf("Ou voulez-vous aller ?\n\n");
											printf("Retourner a la Plaine : Entrez 'Plaine'\n\n");
											scanf("%s",&choix);

											if(strcmp(choix,Plaine) != 0)  {

											printf("\n- Destination inconnue -\n");
											goto erreurArbre;

									}

									if(strcmp(choix,Plaine) == 0) printf("\n\nVous retournez a la Plaine\n"); goto erreurPlaine; temps = cyclejouernuit (temps); printf("%d\n",temps);

											
									}


	// Plaine - retour Village

									if(strcmp(choix,Village) == 0){


											printf("\n\n");
											printf("Vous rentrez au Village\n\n");
											
											goto retourvillage;		
									}


// Boucle du deuxième choix Montagne
// Montagne - Choix
				
			if(strcmp(localisation,Montagne) == 0){

					printf("\nVous commencer l'ascension de la montagne\n");
					printf("\n=============================\n");
					Spawn = 1;
					createBandit (&bandit);
					if(Spawn == 1) goto spawnEnnemi;
					finCombatBandit:
					bandi = bandi + 1;
					erreurMontagne:
					printf("Ou voulez-vous aller ?\n\n");
					printf("Grotte : Entrez 'Grotte'\nVallee : Entrez 'Vallee' \nRetourner au 'Village' : Entrez 'Village'\n\n");
					scanf("%s",&choix);
					printf("========================================");

							if(strcmp(choix,Grotte) ==0){strcpy(localisation,Grotte); temps = cyclejouernuit (temps); printf("%d\n",temps);}
							if(strcmp(choix,Vallee) ==0){strcpy(localisation,Vallee); temps = cyclejouernuit (temps); printf("%d\n",temps);}
							if(strcmp(choix,Village) ==0){strcpy(localisation,Village); goto retourvillage; repos (player.pv,player.pvmax);temps = cyclejouernuit (temps); printf("%d\n",temps);
							if(strcmp(choix,Grotte) != 0 && strcmp(choix,Vallee) !=0 && strcmp(choix,Village) !=0)  {

								printf("\n- Destination inconnue -\n");
								goto erreurMontagne;

							}
			}



	// Montagne - Grotte

							if(strcmp(choix,Grotte) == 0){

									printf("\n\n");
									printf("Vous entrez dans la Grotte\n\n");

									Spawn = 1;
									createErmiteFou (&bandit);
									if(Spawn == 1) goto spawnEnnemi;

									finCombatErmite:
									ermite = ermite + 1;
									erreurGrotte:

									printf("Ou voulez-vous aller ?\n\n");
									printf("Retourner sur le flan de la Montagne : Entrer 'Montagne'\n\n");
									scanf("%s",&choix);

									if(strcmp(choix,Montagne) ==0) goto erreurMontagne; temps = cyclejouernuit (temps); printf("%d\n",temps);
									if(strcmp(choix,Montagne) != 0){

									printf("\n-Destination inconnue -\n");
									goto erreurGrotte;

							}
		
							}

	// Montagne Vallee

							if(strcmp(choix,Vallee) == 0){

									printf("\n\n");
									printf("Vous entrez dans la Vallee\n\n");

									erreurVallee:

									printf("Ou voulez-vous aller ?\n\n");
									printf("Remonter le flan de la Montagne : Entrer 'Montagne\n\n'");
									printf("Retourner au Village : Entrer 'Village'\n\n");
									scanf("%s",&choix);

									if(strcmp(choix,Village) ==0) goto retourvillage; repos (player.pv,player.pvmax); temps = cyclejouernuit (temps); printf("%d\n",temps);
									if(strcmp(choix,Montagne) ==0) goto erreurMontagne; temps = cyclejouernuit (temps); printf("%d\n",temps);
									if(strcmp(choix,Village) != 0 && strcmp(choix,Montagne) !=0){

									printf("\n-Destination inconnue -\n");
									goto erreurVallee;

							}
							}

	

						
	//Début du combat

			while (Spawn == 1){

			spawnEnnemi:

	
			printf("\n\n====================\n");
			printf("Un(e) %s apparait !\n",bandit.Nom);
			printf("====================\n\n");

								while(player.pv >= 0 || bandit.pv >= 0 || player.choice == 0){

									
									errorchoice:

									player.choice == 0;
								
									printf("\nQue voulez-vous faire ?\n\n1 - Attaquer\n2 - Defendre\n3 - Concentration (5pm)\n\n");
									scanf("%d",&player.choice);

									
								if(player.choice != 1 && player.choice != 2 && player.choice != 3) goto errorchoice;




	// Choix Attaque du joueur
								if(player.choice == 1){

									printf("Vous Attaquez l'ennemi !\n");
									bandit.pv = bandit.pv - attack (player.attack,player.force);
									printf("\n%s : %d/%d\n",bandit.Nom,bandit.pv,bandit.pvmax);
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
									bandit.choice = mChoice(bandit.choice);
									bandit.pv = bandit.pv - attackConc (player.attack,player.force);
									printf("\n%s : %d/%d\n",bandit.Nom,bandit.pv,bandit.pvmax);


												if(player.mana<player.manamax){

												player.mana = player.mana +1;
												printf("Il vous reste %d/%d points de mana\n",player.mana,player.manamax);
												}
											
								}


	// Choix Attaque Bandit 1

								if(bandit.choice == 1){

									printf("L'ennemi vous attaque !\n");
									player.pv = player.pv - attack (bandit.attack,bandit.force);
									printf("Il vous reste %d/%d points de vie ...\n",player.pv,player.pvmax );
									bandit.choice == 0;

				}






		if (bandit.pv<=0){


			Sleep(1000);
			printf("\n===========================================================================\n");
			printf("Bravo, vous avez vaincu %s !\n\n",bandit.Nom);
			Sleep(2000);
			printf("Le combat vous rapporte %d points d'experience !\n",bandit.xp );
			player.xp = player.xp + bandit.xp;
			printf("Vous avez %d/%d points d'experience avant d'atteindre le prochain niveau !\n",player.xp,player.xpmax );
			printf("\n===========================================================================\n");
					if(player.xp >= player.xpmax){

					
					printf("%d/%d\n",player.xp,player.xpmax);
					Sleep(2000);
					printf("Vous gagnez un niveau !\n");

					Lveling (&player);	
					Sleep(1000);
					//Nom - pv - mana - attack - force - state - choice - xp - pvmax - mana max - xpmax
					printf("%s\n\nPoints de vie maximum  :  %d (+10)\nPoints de mana maximum :  %d (+5)\nAttaque maximum        :  %d  (+1)\nForce maximum          :  %d  (+1)\n",player.Nom,player.pv,player.mana,player.attack,player.force);	
					
					Spawn = Spawn - 1;


					}

					
			if(strcmp(bandit.Nom,"Hydre") == 0) goto finCombatHydre; 
			if(strcmp(bandit.Nom,"Loup") == 0) goto finCombatLoup; 
			if(strcmp(bandit.Nom,"Ermite Fou") == 0) goto finCombatErmite;
			if(strcmp(bandit.Nom,"Bandit") == 0) goto finCombatBandit;
			if(strcmp(bandit.Nom,"Demon") == 0) goto finJeu;
			}



				if (player.pv<=0){

					printf("\n==============\n");
					printf("Vous etes mort. La malediction aura bientot raison de votre village et votre nom est terni par la lachete que l'on attribuera bientot a votre decendance\n");

					Spawn = Spawn - 1;

					break;

				}





		}


		}
					


		}

		

		}

			


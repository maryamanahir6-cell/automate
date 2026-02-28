#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <stdbool.h>
Automate protocol;
int menu(void){
		int choice;
		printf("-----------AUTOMATE--------\n""1. Charger l'automate depuis graph.dot\n""2. Lire l'automate\n""3. EXIT\n");
		scanf("%d",&choice);
		return choice;
	}
bool rechercherEtat(char etatChar)
{
	int i ;
	for(i = 0 ; i<10;i++)
	{
		if(protocol.etats[i] == etatChar )
		{
			return true;
		}
	}
		return false;

}
bool rechercherAlphabet(char etatChar)
{
	int i ;
	for(i = 0 ; i<5;i++)
	{
		if(protocol.Alphabet[i] == etatChar )
		{
			return true;
		}
	}
		return false;

}

void readDot(){
		char src,dest,val,ligne[20];
		int i=0,lengthEt = 0,lengthAlp = 0;
	FILE* f;
	f = fopen("demo.dot","r");
	if(f == NULL){
			printf("Fichier introuvable, veuillez vous assurez de l'emplacement du fichier.");
	}
	fgets(ligne,20,f);
	while( fscanf(f," %c -> %c [label=\" %c\"];\n",&src,&dest,&val) == 3){
				protocol.transitions[i].etat_dep = src;
				protocol.transitions[i].etat_arriv = dest;
				protocol.transitions[i].lettre = val;
				i++;
				
				if(lengthEt < 10){
				if(rechercherEtat(src) == false)
				{
					protocol.etats[lengthEt] = src;
					lengthEt++;
				}
				if(rechercherEtat(dest) == false)
				{
					protocol.etats[lengthEt] = dest;
					lengthEt++;
				}
				}
				//alphabet

				if(lengthAlp < 5){
				if(rechercherAlphabet(val) == false)
				{
					protocol.Alphabet[lengthAlp] = val;
					lengthAlp++;
				}
				}

				
				
			}
			fclose(f);
	}
void automateShow(){
	int i,j,k;
	printf("Voici l'etat initial : %c\n",protocol.etat_initial);
	printf("Voici la liste des etats :\n");	
	for( j = 0; j<10 ; j++){
		printf("[%c] ",protocol.etats[j]);
	}
	printf("\nVoici la liste d'alphabet : \n");	
	for(k = 0; k<10 ; k++){
		printf("[%c] ", protocol.Alphabet[k]);
	}
	printf("\nVoici la liste des transitions :\n");	
	for( i = 0; i<20 ; i++){
		printf("[%c] -> %c -> [%c]\n",protocol.transitions[i].etat_dep,protocol.transitions[i].lettre,protocol.transitions[i].etat_arriv);
	}
	printf("l'etat finale est %c", protocol.etat_final);
}

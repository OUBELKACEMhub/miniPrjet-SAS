#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
   {
    char Nom[100];
	char NumTele[100];
    char email[200];
}contacts;

void ajouter(contacts contact[],char Nom[], char num[],char email[],int *nmbr){
	strcpy(contact[*nmbr].Nom,Nom);
	strcpy(contact[*nmbr].NumTele,num);
	strcpy(contact[*nmbr].email,email);
	(*nmbr)++;
}
void Modifier(contacts contact[],char Nom[],char num[],char email[],int *nmbr){

	for(int i=0;i<*nmbr;i++){
		if(strcmp(contact[i].Nom,Nom)==0){
		strcpy(contact[i].NumTele,num);
		strcpy(contact[i].email,email);

		 	printf("\nLivre Modifier !!\n");
	   }
	   printf("\nLivre introuvable \n");
	}


}


void Supprimer(contacts contact[],char Nom[],int *nmbr){

	for(int i=0;i<*nmbr;i++){
		if(strcmp(contact[i].Nom,Nom)==0){
		 for(int j=i;j<*nmbr-1;j++){
		 	contact[j]=contact[j+1];
		 }
		  (*nmbr)--;
		  	printf("\nLivre supprimé !!\n");
	   }
	        	printf("\nLivre introuvable \n");
	}


}


void afficher(contacts contact[],int *nmbr){
	for(int i=0;i<*nmbr;i++){
		printf("%s\n", contact[i].Nom);
		printf("%s \n",contact[i].NumTele);
		printf("%s \n",contact[i].email);
	}
}


void Rechercher(contacts contact[],char Nom[], int *nmbr){
		for(int i=0;i<*nmbr;i++){
	     if(strcmp(contact[i].Nom,Nom)==0){
	     	printf(" son Nom : %s \n",contact[i].Nom);
	     	printf(" son Numero : %s \n",contact[i].NumTele);
	     	printf(" son Email : %s \n",contact[i].email);
		 }
		 break;
	}
		printf("\nLivre introuvable \n");
}

int main()
{
	 contacts   contact[50];
     char Nom[50];
     char NumTele[50];
    char email[50];
    int nmbr=0;
    int choix;
do {
        printf("\n--- Menu ---");
        printf("\n1. Ajouter un contact");
        printf("\n2. Afficher tous les contacts");
        printf("\n3. Modifier l'information d'un contact");
        printf("\n4. Supprimer un contact");
        printf("\n5. rachercher un contact");
        printf("\n0. Quitter");
        printf("\nVotre choix : ");
        scanf("%d", &choix);
        getchar(); // vider buffer

        switch (choix) {
            case 1:
             	printf("donner nom de contact :");
             	gets(Nom);
             	printf("donner son numero de telephone  :");
	            gets(NumTele);
            	printf("donner son adress Email :");
	            gets(email);
   	            ajouter( contact,Nom,  NumTele, email, &nmbr);
                break;
            case 2:
                 afficher(contact,&nmbr);
                break;

            case 3:
                printf("\nTitre du Nom de contact  à modifier : ");
                gets(Nom);
                printf("Nouvelle email : ");
                gets(email);
                printf("Nouvelle numero telephone : ");
                gets(NumTele);
                getchar();
                 Modifier(contact,Nom,NumTele,email,&nmbr);
                break;

            case 4:
                printf("\nTitre du contact à supprimer : ");
                gets(Nom);
                 Supprimer(contact,Nom,&nmbr);
                break;

            case 5:
                printf("\n Recherche a contact n");
                printf("\nTitre du Nom de contact  à modifier : ");
                gets(Nom);
                Rechercher(contact,Nom,&nmbr);
                break;


            default:
                printf("\nChoix invalide.\n");
        }
    } while (choix != 0);





    return 0;
}


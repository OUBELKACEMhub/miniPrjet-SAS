#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void Ajouter(char titre[][50], char Auteur[][50], float prix[], int quantite[], int *nmbr, char t[], char a[], float p, int q) {
    strcpy(titre[*nmbr], t);
    strcpy(Auteur[*nmbr], a);
    prix[*nmbr] = p;
    quantite[*nmbr] = q;
    printf("\nLivre %d ajouté !!\n", *nmbr + 1);
    (*nmbr)++;
}

void Afficher(char titre[][50], char Auteur[][50], float prix[], int quantite[], int nmbr) {
    for (int i = 0; i < nmbr; i++) {
        printf("\n--- Livre %d ---", i + 1);
        printf("\nTitre   : %s", titre[i]);
        printf("\nAuteur  : %s", Auteur[i]);
        printf("\nPrix    : %.2f", prix[i]);
        printf("\nQuantité: %d\n", quantite[i]);
    }
}

void Modifier(char titre[][50], int quantite[], int nmbr, char t[], int Nq) {
    for (int i = 0; i < nmbr; i++) {
        if (strcmp(titre[i], t) == 0) {
            quantite[i] = Nq;
            printf("\nQuantité modifiée !!\n");
            return;
        }
    }
    printf("\nLivre introuvable.\n");
}

void Supprimer(char titre[][50], char Auteur[][50], float prix[], int quantite[], int *nmbr, char t[]) {
    for (int i = 0; i < *nmbr; i++) {
        if (strcmp(titre[i], t) == 0) {
            for (int j = i; j < *nmbr - 1; j++) {
                strcpy(titre[j], titre[j+1]);
                strcpy(Auteur[j], Auteur[j+1]);
                prix[j] = prix[j+1];
                quantite[j] = quantite[j+1];
            }
            (*nmbr)--;
            printf("\nLivre supprimé !!\n");
            return;
        }
    }
    printf("\nLivre introuvable.\n");
}

int quantite_Total(int quantite[], int nmbr) {
    int s = 0;
    for (int i = 0; i < nmbr; i++) {
        s += quantite[i];
    }
    return s;
}

int main() {
    int choix, nmbr = 0;
    char titre[MAX][50], Auteur[MAX][50], t[50], a[50];
    float prix[MAX];
    int quantite[MAX];
    float p;
    int q;

    do {
        printf("\n--- Menu ---");
        printf("\n1. Ajouter un livre");
        printf("\n2. Afficher tous les livres");
        printf("\n3. Modifier la quantité d'un livre");
        printf("\n4. Supprimer un livre");
        printf("\n5. Quantité totale");
        printf("\n0. Quitter");
        printf("\nVotre choix : ");
        scanf("%d", &choix);
        getchar(); // vider buffer

        switch (choix) {
            case 1:
                printf("\nTitre : ");
                gets(t);
                printf("Auteur : ");
                gets(a);
                printf("Prix : ");
                scanf("%f", &p);
                printf("Quantité : ");
                scanf("%d", &q);
                getchar();
                Ajouter(titre, Auteur, prix, quantite, &nmbr, t, a, p, q);
                break;

            case 2:
                Afficher(titre, Auteur, prix, quantite, nmbr);
                break;

            case 3:
                printf("\nTitre du livre à modifier : ");
                gets(t);
                printf("Nouvelle quantité : ");
                scanf("%d", &q);
                getchar();
                Modifier(titre, quantite, nmbr, t, q);
                break;

            case 4:
                printf("\nTitre du livre à supprimer : ");
                gets(t);
                Supprimer(titre, Auteur, prix, quantite, &nmbr, t);
                break;

            case 5:
                printf("\nQuantité totale = %d\n", quantite_Total(quantite, nmbr));
                break;

            case 0:
                printf("\nAu revoir !\n");
                break;

            default:
                printf("\nChoix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "G6_graphe.h"

int main()
{
    Graphe graphe;
    int table;
    int choix;
    char fichier[100];
    do
    {
        printf("\n   MENU   \n");
        printf("   1. Tester un graphe\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        choix = -1;
        scanf("%d", &choix);
        while (getchar() != '\n');
    switch (choix)
    {
    case 1:
        printf("entrer le numéro de la table:\n");
        scanf("%d", &table);
        while (getchar() != '\n');
        sprintf(fichier,"../Test/table %d.txt", table);
        initialiser_graphe(&graphe);
        if (charger_graphe(fichier, &graphe)==1)
        {
            afficher_triplets(&graphe);
            afficher_matrice(&graphe);
            int v= verifier_ordonnancement(&graphe);

            if (v==1)
            {
                rang(&graphe);
                calendrier_tot(&graphe);
                calendrier_tard(&graphe);
                marges(&graphe);
                afficher_chemin_critique(&graphe);

            }
            else printf("Ordonnancement impossible. Choisissez un autre tableau\n");

        }
        else
            printf("Ouverture du %s impossible\n", fichier);

        break;
    case 0:
        printf("Fin\n");
        break;
    default:
        printf("Choix invalide! Choisissez 1 ou 0\n");
        break;
    }

    }while (choix!=0);
    return 0;
}

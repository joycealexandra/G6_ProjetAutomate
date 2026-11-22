//
// Created by HP on 20/11/2026.
//

#ifndef G6_PROJRTAUTOMATE_GRAPHE_H
#define G6_PROJRTAUTOMATE_GRAPHE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max_sommets 50

typedef struct
{
    int nb_taches;
    int duree[max_sommets];
    int matrice[max_sommets][max_sommets];
    int rang[max_sommets];
    int date_tot[max_sommets];
    int date_tard[max_sommets];
    int marge_libre[max_sommets];
    int marge_totale[max_sommets];
}Graphe;
void initialiser_graphe(Graphe* G);
int charger_graphe(const char *f, Graphe* G);
void afficher_triplets(const Graphe* G);
void afficher_matrice(const Graphe* G);
int verifier_ordonnancement(const Graphe* G);
void rang(const Graphe* G);
void calendrier_tot(const Graphe* G);
void calendrier_tard(const Graphe* G);
void marges(const Graphe* G);
void afficher_chemin_critique(const Graphe* G);

#endif //G6_PROJRTAUTOMATE_GRAPHE_H

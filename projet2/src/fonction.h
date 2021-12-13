#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <gtk/gtk.h>

typedef struct date{
char jour[100];
char mois[100];
char annee[100];
}date;

typedef struct produit{
char ref[100];
char nom[100];
date dp ;
char qte[100];
char cat[100];
char stk[100];
}produit;

int verif(char rf);
void ajouter_produit(produit prd);
produit recherche_produit(char ref_rech[]);
void supprimer_produit(char ref_supp[]);
void modifier_produit(produit prd,char ref_modf[]);
void afficher_produit(produit prd);
void rupture_stock();
void afficherstock(GtkWidget *liste);
void afficherrupture(GtkWidget *liste);

#endif


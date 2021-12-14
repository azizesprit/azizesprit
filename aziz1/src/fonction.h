#include <gtk/gtk.h>
#ifndef FONCTIONS_H_
#define FONCTIONS_H_
int verif (char username[], char motdepasse[]);
typedef struct {
char username[20];
char motdepasse[20];
char nom [20];
char prenom[20];
char role[20];
char niveau[20];
int iniveau;
} utulisateur;
int verif1 (char username[]);
void utsexe(int s,char sexe1[]);
void ajouter_utulisateur(utulisateur u);
void afficher_utulisateur(GtkWidget *liste);
void supprimer_utulisateur(char usersupp []);
void modifier_utulisateur(utulisateur u,char usermodiff[]);
int verif3 (utulisateur u);
void afficher_niveau(GtkWidget *liste);
void nb_etudiant(utulisateur u);
typedef struct {
 char ID[30];
 char type[30];
 char etat[30];
 char valeur[30];


} capteur;

void capteur_affiche(GtkWidget *liste);


void capteur_recherche(GtkWidget *liste,char ID[]);

void capteur_modifier(capteur c ,char ID[]);

void capteur_supprimer(char ID[]);

void capteur_ajouter(capteur c);
//bool reche(char ID1[]);
void afficherrr(GtkWidget *liste);
 

typedef struct {
int jour;
int heure;
int numcap;
float valucap;
}temperature;
void capteurdef();
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

int veriff(char rf);
void ajouter_produit(produit prd);
produit recherche_produit(char ref_rech[]);
void supprimer_produit(char ref_supp[]);
void modifier_produit(produit prd,char ref_modf[]);
void afficher_produit(produit prd);
void rupture_stock();
void afficherstock(GtkWidget *liste);
void afficherrupture(GtkWidget *liste);

#endif


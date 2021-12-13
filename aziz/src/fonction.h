#include <gtk/gtk.h>

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
int verif1 (utulisateur u);
void utsexe(int s,char sexe1[]);
void ajouter_utulisateur(utulisateur u);
void afficher_utulisateur(GtkWidget *liste);
void supprimer_utulisateur(utulisateur u);
void modifier_utulisateur(utulisateur u);
int verif3 (char role[]);
void afficher_niveau(GtkWidget *liste);
void nb_etudiant(utulisateur u);

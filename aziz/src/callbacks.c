#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>
int checkbutton[0];
char msg[20];
int s=1;

void
on_inscription_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
FILE *f1=NULL;
int n1=0;
int n2=0;
int n3=0;
int n4=0;
int n5=0;
char nv1[20];
char nv2[20];
char nv3[20];
char nv4[20];
char nv5[20];
GtkWidget *username,*motdepasse,*nom,*prenom,*role,*iniveau,*objet_graphique, *az_connexion;
char nom1[20];
char prenom1[20];
char username1[20];
char role1[20];
char motdepasse1[20];
char niveau1[20];
int iniveau1=0;
char ch1[20];
nom = lookup_widget(button, "az_vn");
prenom = lookup_widget(button,"az_vp");
username = lookup_widget(button,"az_un");
role = lookup_widget(button,"az_rl1");
iniveau = lookup_widget(button,"az_nv");
motdepasse = lookup_widget(button,"az_mdp");
iniveau1 = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (iniveau));
strcpy(username1, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(motdepasse1, gtk_entry_get_text(GTK_ENTRY(motdepasse)));
strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(prenom1, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(role1, gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
sprintf(niveau1, "%d", iniveau1);
f=fopen("utulisateur.txt","a+");
if (f!=NULL)
{
fprintf(f," %s %s %s %s %s %s \n",username1,motdepasse1,nom1,prenom1,role1,niveau1);
}
f1=fopen("niveau.txt","a+");
if (strcmp("etudiant",role1)==0)
{
	if (strcmp("1",niveau1)==0)
	{
		n1+=1;
	}
	else 
	{
		if(strcmp("2",niveau1)==0)
        	{
		   n2+=1;
		}
	
		else
		{
			if (strcmp("3",niveau1)==0)
			{
			n3+=1;
			}
		    	else
			{
				if (strcmp("4",niveau1)==0)
				{
				n4+=1;
				}
				else
				{
					if (strcmp("5",niveau1)==0)
					{
						n5+=1;
					}
				}
			}
		}
	}
}
sprintf(nv1, "%d", n1);
sprintf(nv2, "%d", n2);
sprintf(nv3, "%d", n3);
sprintf(nv4, "%d", n4);
sprintf(nv5, "%d", n5);
f1=fopen("niveau.txt","a+");
if (f1!=NULL)
{
fprintf(f1," %s %s %s %s %s \n",nv1,nv2,nv3,nv4,nv5);
fclose(f1);
fclose(f);
}
if (checkbutton[0] == 1) 
{
GtkWidget  *az_connexion, *az_inscription; 
az_connexion=create_az_connexion();
gtk_widget_show(az_connexion);
az_inscription=lookup_widget(button,"az_inscription");
gtk_widget_destroy(az_inscription);
}
}
void
on_radiomasculin_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
s=1;
}


void
on_radiofeminin_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
s=2;
}


void
on_admincheck_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
checkbutton[0]=1;
}

void
on_az_cnx_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username,*motdepasse, *az_admin, *az_connexion;
char user[20];
char mdp[20];
username = lookup_widget(button,"az_us1");
motdepasse = lookup_widget(button,"az_mdp1");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(mdp, gtk_entry_get_text(GTK_ENTRY(motdepasse)));
if (verif(user,mdp)==1)
{
az_admin=create_az_admin();
gtk_widget_show(az_admin);
az_connexion=lookup_widget(button,"az_connexion");
gtk_widget_destroy(az_connexion);
}

}
void
on_affiche_tab_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *az_admin;
GtkWidget *adminaffiche;
GtkWidget *treeview1;
az_admin=lookup_widget(button,"az_admin");
gtk_widget_destroy(az_admin);
adminaffiche=lookup_widget(button,"adminaffiche");
adminaffiche=create_adminaffiche();
gtk_widget_show(adminaffiche);
treeview1=lookup_widget(adminaffiche,"treeview1");
afficher_utulisateur(treeview1);

}
void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *az_admin, *adminaffiche;
az_admin=lookup_widget(button,"az_admin");
az_admin=create_az_admin();
gtk_widget_show(az_admin);
adminaffiche=lookup_widget(button,"adminaffiche");
gtk_widget_destroy(adminaffiche);
}

void
on_tab_ajout_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *adminajout,*az_admin; 
adminajout=create_adminajout();
gtk_widget_show(adminajout);
az_admin=lookup_widget(button,"az_admin");
gtk_widget_destroy(az_admin);
}
void
on_ad_ajout1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ad_nom,*ad_prenom,*ad_username,*ad_role,*ad_motdepasse,*adminajout,*az_admin;
char username2[20];
char motdepasse2[20];
char nom2[20];
char prenom2[20];
char role2[20];
ad_username = lookup_widget(button,"ad_username1");
ad_motdepasse = lookup_widget(button,"ad_motdepasse1");
ad_nom = lookup_widget(button, "ad_nom1");
ad_prenom = lookup_widget(button,"ad_prenom1");
ad_role = lookup_widget(button,"ad_role1");
strcpy(username2, gtk_entry_get_text(GTK_ENTRY(ad_username)));
strcpy(motdepasse2, gtk_entry_get_text(GTK_ENTRY(ad_motdepasse)));
strcpy(nom2, gtk_entry_get_text(GTK_ENTRY(ad_nom)));
strcpy(prenom2, gtk_entry_get_text(GTK_ENTRY(ad_prenom)));
strcpy(role2, gtk_entry_get_text(GTK_ENTRY(ad_role)));
FILE *f;
f=fopen("utulisateur.txt","a+");
if (f!=NULL)
{
fprintf(f," %s %s %s %s %s \n",username2,motdepasse2,nom2,prenom2,role2);
fclose(f);
}
else 
printf(" \n not found ");
az_admin=lookup_widget(button,"az_admin");
az_admin=create_az_admin();
gtk_widget_show(az_admin);
adminajout=lookup_widget(button,"adminajout");
gtk_widget_destroy(adminajout);
}
void
on_radiomasculin1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
s=1;
}


void
on_radiofeminin1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
s=2;
}
void
on_tab_supp_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *az_supression,*az_admin; 
az_supression=create_az_supression();
gtk_widget_show(az_supression);
az_admin=lookup_widget(button,"az_admin");
gtk_widget_destroy(az_admin);;
}
void
on_delete_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *usersup,*az_supression,*az_admin;
utulisateur u;
usersup = lookup_widget(button,"as_username1");
strcpy(u.username, gtk_entry_get_text(GTK_ENTRY(usersup)));
supprimer_utulisateur(u);
az_admin=lookup_widget(button,"az_admin");
az_admin=create_az_admin();
gtk_widget_show(az_admin);
az_supression=lookup_widget(button,"az_supression");
gtk_widget_destroy(az_supression);

}


void
on_tab_modif_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *az_modif,*az_admin; 
az_modif=create_az_modif();
gtk_widget_show(az_modif);
az_admin=lookup_widget(button,"az_admin");
gtk_widget_destroy(az_admin);
}
void
on_md_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *usermodif,*az_modif,*ad_modif;
utulisateur u;
usermodif = lookup_widget(button,"modifusername");
strcpy(u.username, gtk_entry_get_text(GTK_ENTRY(usermodif)));
if (verif1(u)==1)
{
supprimer_utulisateur(u);
ad_modif=create_ad_modif();
gtk_widget_show(ad_modif);
az_modif=lookup_widget(button,"az_modif");
gtk_widget_destroy(az_modif);
}
}


void
on_md_OK_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *username,*motdepasse,*nom,*prenom,*role, *az_admin, *az_modif, *ad_modif;
char username4[20];
char motdepasse4[20];
char nom4[20];
char prenom4[20];
char role4[20];
username = lookup_widget(button,"md_username1");
motdepasse = lookup_widget(button,"md_motdepasse1");
nom = lookup_widget(button,"md_nom1");
prenom = lookup_widget(button,"md_prenom1");
role = lookup_widget(button,"md_role1");
strcpy(username4, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(motdepasse4, gtk_entry_get_text(GTK_ENTRY(motdepasse)));
strcpy(nom4, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(prenom4, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(role4, gtk_entry_get_text(GTK_ENTRY(role)));
FILE *f;
f=fopen("utulisateur.txt","a+");
if (f!=NULL)
{
fprintf(f," %s %s %s %s %s \n",username4,motdepasse4,nom4,prenom4,role4);
fclose(f);
}
az_admin=create_az_admin();
gtk_widget_show(az_admin);
az_admin=lookup_widget(button,"ad_modif");
gtk_widget_destroy(ad_modif);
}



void
on_nvaffiche_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *adminaffiche;
GtkWidget *affichage_niveau;
GtkWidget *treeview2;
adminaffiche=lookup_widget(button,"adminaffiche");
gtk_widget_destroy(adminaffiche);
affichage_niveau=lookup_widget(button,"affichage_niveau");
affichage_niveau=create_affichage_niveau();
gtk_widget_show(affichage_niveau);
treeview2=lookup_widget(affichage_niveau,"treeview2");
afficher_niveau(treeview2);

}


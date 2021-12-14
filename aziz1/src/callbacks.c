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
if (strcmp("etudiant",role1)==0)
{
fprintf(f," %s %s %s %s %s %s \n",username1,motdepasse1,nom1,prenom1,role1,niveau1);
}
else fprintf(f," %s %s %s %s %s %s \n",username1,motdepasse1,nom1,prenom1,role1,"X");
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
GtkWidget *username,*motdepasse, *az_admin, *az_connexion, *MA_Interface_Acceuil, *affiche;
utulisateur u;
FILE *f;
char user[20];
char mdp[20];
f=fopen("utulisateur.txt","r");
username = lookup_widget(button,"az_us1");
motdepasse = lookup_widget(button,"az_mdp1");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(mdp, gtk_entry_get_text(GTK_ENTRY(motdepasse)));
if (verif(user,mdp)==1)
{
while (fscanf(f,"%s %s %s %s %s %s \n",u.username,u.motdepasse,u.nom,u.prenom,u.role,u.niveau)!=EOF)
{
	if (strcmp(user,u.username)==0)
{
	if (strcmp(u.role,"Administrateur")==0)
	{
		az_admin=create_az_admin();
		gtk_widget_show(az_admin);
		az_connexion=lookup_widget(button,"az_connexion");
		gtk_widget_destroy(az_connexion);
 		
	}
	else
	 	if (strcmp(u.role,"Agent_du_restaurant")==0)
		{
			MA_Interface_Acceuil=create_MA_Interface_Acceuil();
			gtk_widget_show(MA_Interface_Acceuil);
			az_connexion=lookup_widget(button,"az_connexion");
			gtk_widget_destroy(az_connexion);
			
		}
			else 
				if (strcmp(u.role,"Technicien")==0)
				{
					affiche=create_affiche();
					gtk_widget_show(affiche);
					az_connexion=lookup_widget(button,"az_connexion");
					gtk_widget_destroy(az_connexion);
					
				}
}
}
}
}
void
on_affiche_tab_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *az_admin;
GtkWidget *adminaffiche;
GtkWidget *azaf;
az_admin=lookup_widget(button,"az_admin");
gtk_widget_destroy(az_admin);
adminaffiche=lookup_widget(button,"adminaffiche");
adminaffiche=create_adminaffiche();
gtk_widget_show(adminaffiche);
azaf=lookup_widget(adminaffiche,"azaf");
afficher_utulisateur(azaf);

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
GtkWidget *ad_nom,*ad_prenom,*ad_username,*ad_role,*ad_niveau,*ad_motdepasse,*adminajout,*az_admin;
char username2[20];
char motdepasse2[20];
char nom2[20];
char prenom2[20];
char role2[20];
char niveau2[20];
ad_username = lookup_widget(button,"ad_username1");
ad_motdepasse = lookup_widget(button,"ad_motdepasse1");
ad_nom = lookup_widget(button, "ad_nom1");
ad_prenom = lookup_widget(button,"ad_prenom1");
ad_role = lookup_widget(button,"ad_role1");
ad_niveau = lookup_widget(button,"ad_niveau1");
strcpy(username2, gtk_entry_get_text(GTK_ENTRY(ad_username)));
strcpy(motdepasse2, gtk_entry_get_text(GTK_ENTRY(ad_motdepasse)));
strcpy(nom2, gtk_entry_get_text(GTK_ENTRY(ad_nom)));
strcpy(prenom2, gtk_entry_get_text(GTK_ENTRY(ad_prenom)));
strcpy(role2, gtk_entry_get_text(GTK_ENTRY(ad_role)));
strcpy(niveau2, gtk_entry_get_text(GTK_ENTRY(ad_niveau)));
FILE *f;
f=fopen("utulisateur.txt","a+");
if (f!=NULL)
{
if (strcmp("etudiant",role2)==0)
{
fprintf(f," %s %s %s %s %s %s \n",username2,motdepasse2,nom2,prenom2,role2,niveau2);
}
else
fprintf(f," %s %s %s %s %s %s \n",username2,motdepasse2,nom2,prenom2,role2,"X");
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
char usersupp[20];
usersup = lookup_widget(button,"as_username1");
strcpy(usersupp, gtk_entry_get_text(GTK_ENTRY(usersup)));
if (verif1(usersupp)==1)
{
supprimer_utulisateur(usersupp);
az_admin=lookup_widget(button,"az_admin");
az_admin=create_az_admin();
gtk_widget_show(az_admin);
az_supression=lookup_widget(button,"az_supression");
gtk_widget_destroy(az_supression);
}
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
char user[20];
GtkWidget *usermodif,*az_modif,*ad_modif;
utulisateur u;
usermodif = lookup_widget(button,"modifusername");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(usermodif)));
if (verif1(user)==1)
{
supprimer_utulisateur(user);
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

GtkWidget *md_nom,*md_prenom,*md_username,*md_role,*md_motdepasse,*md_niveau, *az_modif, *ad_modif,*az_admin;
utulisateur u;
md_nom = lookup_widget(button, "md_nom1");
md_prenom = lookup_widget(button,"md_prenom1");
md_username = lookup_widget(button,"md_username1");
md_role = lookup_widget(button,"md_role1");
md_niveau = lookup_widget(button,"md_niveau1");
md_motdepasse = lookup_widget(button,"md_motdepasse1");
strcpy(u.username, gtk_entry_get_text(GTK_ENTRY(md_username)));
strcpy(u.motdepasse, gtk_entry_get_text(GTK_ENTRY(md_motdepasse)));
strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(md_nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(md_prenom)));
strcpy(u.role, gtk_entry_get_text(GTK_ENTRY(md_role)));
strcpy(u.niveau, gtk_entry_get_text(GTK_ENTRY(md_niveau)));
FILE *f;
f=fopen("utulisateur.txt","a+");
if (f!=NULL)
{
fprintf(f," %s %s %s %s %s %s  \n",u.username,u.motdepasse,u.nom,u.prenom,u.role,u.niveau);
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
GtkWidget *azaf1;
adminaffiche=lookup_widget(button,"adminaffiche");
gtk_widget_destroy(adminaffiche);
affichage_niveau=lookup_widget(button,"affichage_niveau");
affichage_niveau=create_affichage_niveau();
gtk_widget_show(affichage_niveau);
azaf1=lookup_widget(affichage_niveau,"azaf1");
afficher_niveau(azaf1);

}


void
on_azaf_row_activated                  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* username;
gchar* motdepasse;
gchar* nom;
gchar* prenom;
gchar* role;
gchar* niveau;
utulisateur u;
GtkWidget *warn;
GtkWidget *adminaffiche;
GtkWidget *azaf;
char usersupp[20];
GtkTreeModel *Model = gtk_tree_view_get_model((treeview));
	if (gtk_tree_model_get_iter(Model,&iter,path)){
			gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,0,&username,1,&motdepasse,2,&nom,3,&prenom,4,&role,5,&niveau,-1);
                        strcpy(usersupp,username);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Vouler vous vraiment supprimer se produit ?");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(warn);
	break;
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(warn);
	supprimer_utulisateur(usersupp);
	
	break;	
}
afficher_utulisateur(azaf);
}
}
void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window_ajout;
window_ajout=create_Ajout();
gtk_widget_show(window_ajout);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_suppr;
window_suppr=create_suppression();
gtk_widget_show(window_suppr);
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_modif;
window_modif=create_modification();
gtk_widget_show(window_modif);
}

char ID[30];

void
on_button4_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *id,*affiche,*treeview,*affiche1; 

id=lookup_widget(objet,"entry1"); 
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));


affiche=lookup_widget(objet,"affiche");

affiche1=create_affiche();

gtk_widget_show(affiche1);

gtk_widget_hide(affiche);

treeview=lookup_widget(affiche1,"treeview1");

capteur_recherche(treeview,ID);


}





int typ;
int choix;
void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*val,*warn,*windowajout;
capteur c;
char TYPE[30];
char ETAT[30];
char ID[30],type[30],etat[30],valeur[30];
id = lookup_widget (button,"entry3");
if (typ==1)
{strcpy(TYPE,"Actif");}
else if (typ==2)
{strcpy(TYPE,"Passif");}
if (choix==1)
{strcpy(ETAT,"Bonne");}
else if (choix==2)
{strcpy(ETAT,"Deffectueux");}
val = lookup_widget (button,"entry4");
strcpy(c.ID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(c.type,TYPE);
strcpy(c.etat,ETAT);
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(val)));
capteur_ajouter(c);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur ajouté avec succeès");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(warn);
	break;}




}


void
on_button6_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *Ajout;


Ajout=lookup_widget(objet,"Ajout");
gtk_widget_hide(Ajout);
}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *id,*warn;
char ID[30];
id = lookup_widget (button,"entry5");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));
capteur_supprimer(ID);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Supprimé avec succeès");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(warn);
	break;
	}


}


void
on_button9_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *suppression;
suppression=lookup_widget(objet,"suppression");
gtk_widget_hide(suppression);



}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*ii,*vv,*warn;
char ID[30];
char ee[30];
char tt [30];
capteur c;
id = lookup_widget (button,"entry6");
ii = lookup_widget (button,"entry7");
if (typ==1)
{strcpy(tt,"Actif");}
else if (typ==2)
{strcpy(tt,"Passif");}
if (choix==1)
{strcpy(ee,"Deffectueu");}
else if (choix==2)
{strcpy(ee,"Bonne");}
vv = lookup_widget (button,"entry8");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(c.ID,gtk_entry_get_text(GTK_ENTRY(ii)));
strcpy(c.type,tt);
strcpy(c.etat,ee);
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(vv)));
capteur_modifier(c,ID);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Modifié avec succeès");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(warn);
	break;
	}

}


void
on_button12_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modification;
modification=lookup_widget(objet,"modification");
gtk_widget_destroy(modification);

}


void
on_afficher_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *treeview1;
affiche=lookup_widget(objet,"affiche");

gtk_widget_destroy(affiche);
affiche=lookup_widget(objet,"affiche");
affiche=create_affiche();
gtk_widget_show(affiche);
treeview1=lookup_widget(affiche,"treeview1");
capteur_affiche(treeview1);
}


void
on_radio1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
typ=1;

}

void
on_radio2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
typ=2;

}
void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
typ=1;

}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
typ=2;
}

int choix;

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix=1;

}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix=2;

}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix=1;

}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix=2;

}





void
on_button_actu_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *treeview1;
affiche=lookup_widget(objet,"affiche");

gtk_widget_destroy(affiche);
affiche=lookup_widget(objet,"affiche");
affiche=create_affiche();
gtk_widget_show(affiche);
treeview1=lookup_widget(affiche,"treeview1");
capteur_affiche(treeview1);
}


void
on_cptdef_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
char jjj[30];
char hhh[30];
char numr[30];
char vale[30];
int cond1=10;
int cond2=30;
int nb=0;

GtkWidget *treeview2;
GtkWidget *affiche;
GtkWidget *cptdef;
FILE *T,*FL ;
T = fopen ("temperature.txt", "r");
FL= fopen ("temp.txt", "w+");
if((FL!=NULL)&&(T!=NULL))
{
while (fscanf(T,"%s %s %s %s\n",jjj,hhh,numr,vale)!=EOF )
{
int c=atoi(vale);
if (cond1>c || c>cond2)
{

fprintf(FL,"%s %s %s %s\n",jjj,hhh,numr,vale);
//nb+=1;}

}
}
  
  fclose(T);

fclose(FL);
}


affiche=lookup_widget(objet,"affiche");
 cptdef= create_cptdef ();
  gtk_widget_show (cptdef);

treeview2=lookup_widget(cptdef,"treeview2");
afficherrr(treeview2);

}


void
on_retourcptdef_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *cptdef;
cptdef=lookup_widget(objet,"cptdef");
gtk_widget_hide(cptdef);

}





void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
capteur c;
GtkWidget *warn;
GtkWidget *window_suppr;

GtkTreeModel *Model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(Model,&iter,path)){
			gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,0,&id,-1);
                        strcpy(c.ID,id);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Vouler vous vraiment supprimer se produit ?");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(warn);
	break;
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(warn);
	capteur_supprimer(id);
	break;
			
}

}
}
char sa[100];
char sm[100];
char cs[100];


void
on_MA_Modifier_acceuil_clicked(GtkButton *button,gpointer user_data)
{


}


void
on_MA_Supprimer_acceuil_clicked(GtkButton *button,gpointer user_data)
{


}


void
on_MA_Ajouter_acceuil_clicked(GtkButton *button,gpointer user_data)
{


}


void
on_MA_button_recherche_acceuil_clicked (GtkWidget *objet,gpointer user_data)
{
GtkWidget *windowsrecherche,*window1;
window1=lookup_widget(objet,"MA_Interface_Acceuil");
gtk_widget_destroy(window1);
windowsrecherche=create_MA_Interface_Rechercher();
gtk_widget_show(windowsrecherche);


}


void
on_MA_button_acceuil_ajouter_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsacceuil;
windowsacceuil=create_MA_Interface_Acceuil ();
gtk_widget_show(windowsacceuil);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_Interface_Ajouter");
gtk_widget_destroy(window1);

}


void
on_MA_button_confirmer_ajouter_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *refa,*noma,*dpja,*dpma,*dpaa,*qtea,*cata,*stka;
produit p;
int j,m,a;
refa = lookup_widget(objet,"MA_entry_ref_ajouter");
noma= lookup_widget(objet,"MA_entry_nomproduit_ajouter");
dpja= lookup_widget(objet,"MA_spinbutton_dpj_ajouter");


dpma= lookup_widget(objet,"MA_spinbutton_dpm_ajouter");
dpaa= lookup_widget(objet,"MA_spinbutton_dpa_ajouter");

qtea= lookup_widget(objet,"MA_entry_qte_ajouter");
cata= lookup_widget(objet,"MA_comboboxentry_cat_ajouter");



strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(refa)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(noma)));
strcpy(p.qte,gtk_entry_get_text(GTK_ENTRY(qtea)));



strcpy(p.cat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cata)));



j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dpja));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dpma));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dpaa));
sprintf(p.dp.jour,"%d",j);
sprintf(p.dp.mois,"%d",m);
sprintf(p.dp.annee,"%d",a);

strcpy(p.stk,sa);




ajouter_produit(p);
GtkWidget *windowajouter;
GtkWidget *window1;
windowajouter=lookup_widget(objet,"MA_Interface_Ajouter");
window1=create_MA_Interface_Acceuil();
gtk_widget_show(window1);
gtk_widget_destroy(windowajouter);

}


void
on_MA_button_Modifier_acceuil_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsmodifier;
windowsmodifier=create_MA_interface_modifier ();
gtk_widget_show(windowsmodifier);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_Interface_Acceuil");
gtk_widget_destroy(window1);

}


void
on_MA_button_Supprimer_acceuil_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowssupprimer;
windowssupprimer=create_MA_Interface_Supprimer ();
gtk_widget_show(windowssupprimer);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_Interface_Acceuil");
gtk_widget_destroy(window1);

}


void
on_MA_treeview_LS_acceuil_row_activated(GtkTreeView     *treeview,GtkTreePath     *path, GtkTreeViewColumn *column,gpointer         user_data)
{
GtkTreeIter iter;
gchar* ref;
gchar* nom;
gchar* dpj;
gchar* dpm;
gchar* dpa;
gchar* qte;
gchar* cat;
gchar* stk;

produit p;
date dp;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ref,1,&nom,2,&dpj,3,&dpm,4,&dpa,5,&qte,6,&cat,7,&stk-1);

strcpy(p.ref,ref);
strcpy(p.nom,nom);

strcpy(p.dp.jour,dpj);
strcpy(p.dp.jour,dpm);
strcpy(p.dp.mois,dpa);

strcpy(p.qte,qte);
strcpy(p.cat,cat);

strcpy(p.stk,stk);


afficherstock(treeview);
}
}


void
on_MA_button_Ajouter_acceuil_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsajouter;
windowsajouter=create_MA_Interface_Ajouter ();
gtk_widget_show(windowsajouter);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_Interface_Acceuil");
gtk_widget_destroy(window1);

}


void
on_MA_radiobutton_tts_acceuil_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{




}


void
on_MA_radiobutton_rps_acceuil_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


}


void
on_MA_button_actualiser_acceuil_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affiche,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"MA_Interface_Acceuil");
fenetre_affiche=create_MA_Interface_Acceuil();
gtk_widget_show(fenetre_affiche);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_affiche,"MA_treeview_LS_acceuil");
afficherstock(treeview1);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_MA_button_supprimer_supprimer_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *refs;
produit p;
GtkWidget *windowsacceuil;
GtkWidget *window1;
refs = lookup_widget(objet,"MA_entry_ref_supprimer");
 
strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(refs)));
if (strcmp(cs,"cs")==0)
{
supprimer_produit(p.ref);
windowsacceuil=create_MA_Interface_Acceuil ();
gtk_widget_show(windowsacceuil);
window1=lookup_widget(objet,"MA_Interface_Supprimer");
gtk_widget_destroy(window1);

}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_MA_button_acceuil_supprimer_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsacceuil;
windowsacceuil=create_MA_Interface_Acceuil ();
gtk_widget_show(windowsacceuil);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_Interface_Supprimer");
gtk_widget_destroy(window1);

}


void
on_MA_checkbutton_confirmer_supprimer_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//produit prd;
//if(gtk_toggle_button_get_active(togglebutton)) {
strcpy(cs,"cs");
//}
}


void
on_MA_button_rechercher_rechercher_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
produit rech;
produit p;
GtkWidget *refr,*nom1,*dpj1,*dpm1,*dpa1,*qte1,*cat1,*stk1;
refr = lookup_widget(objet,"MA_entry_refr_chercher");
strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(refr)));

rech=recherche_produit(p.ref);
nom1 = lookup_widget(objet,"MA_label_nomO_rechercher");
dpj1 = lookup_widget(objet,"MA_label_dpjO_rechercher");
dpm1 = lookup_widget(objet,"MA_label_dpmO_rechercher");
dpa1 = lookup_widget(objet,"MA_label_dpaO_rechercher");
qte1 = lookup_widget(objet,"MA_label_qteO_rechercher");
cat1 = lookup_widget(objet,"MA_label_catO_rechercher");
stk1 = lookup_widget(objet,"MA_label_stockageO_rechercher");
gtk_label_set_text(GTK_LABEL(nom1),rech.nom);
gtk_label_set_text(GTK_LABEL(dpj1),rech.dp.jour);
gtk_label_set_text(GTK_LABEL(dpm1),rech.dp.mois);
gtk_label_set_text(GTK_LABEL(dpa1),rech.dp.annee);
gtk_label_set_text(GTK_LABEL(qte1),rech.qte);
gtk_label_set_text(GTK_LABEL(cat1),rech.cat);
gtk_label_set_text(GTK_LABEL(stk1),rech.stk);

}


void
on_MA_button_acceuil_rechercher_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsacceuil;
windowsacceuil=create_MA_Interface_Acceuil ();
gtk_widget_show(windowsacceuil);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_Interface_Rechercher");
gtk_widget_destroy(window1);

}


void
on_MA_button_acceuil_modifier_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsacceuil;
windowsacceuil=create_MA_Interface_Acceuil ();
gtk_widget_show(windowsacceuil);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_interface_modifier");
gtk_widget_destroy(window1);

}


void
on_MA_button_modifier_modifier_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ref,*refm,*nomm,*dpjm,*dpmm,*dpam,*qtem,*catm,*stkm;
produit p;
char mod[100];
int j,m,a;

refm = lookup_widget(objet,"MA_entry_ref_modifier");
nomm= lookup_widget(objet,"MA_entry_nom_modifier");
dpjm= lookup_widget(objet,"MA_spinbutton_dpj_modifier");


dpmm= lookup_widget(objet,"MA_spinbutton_dpm_modifier");
dpam= lookup_widget(objet,"MA_spinbutton_dpa_modifier");

qtem= lookup_widget(objet,"MA_entry_qte_modifier");
catm= lookup_widget(objet,"MA_comboboxentry_cat_modifier");




strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(refm)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nomm)));
strcpy(p.qte,gtk_entry_get_text(GTK_ENTRY(qtem)));



strcpy(p.cat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(catm)));



j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dpjm));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dpmm));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dpam));

sprintf(p.dp.jour,"%d",j);
sprintf(p.dp.mois,"%d",m);
sprintf(p.dp.annee,"%d",a);

strcpy(p.stk,sm);

ref = lookup_widget(objet,"MA_entry_refm_modifier");

strcpy(mod,gtk_entry_get_text(GTK_ENTRY(ref)));



modifier_produit(p,mod);

GtkWidget *windowmodifier;
GtkWidget *window1;
windowmodifier=lookup_widget(objet,"MA_interface_modifier");
window1=create_MA_Interface_Acceuil();
gtk_widget_show(window1);
gtk_widget_destroy(windowmodifier);

}


void
on_MA_button_rps_acceuil_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsrupture;
windowsrupture=create_MA_Interface_Rupture ();
gtk_widget_show(windowsrupture);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_Interface_Acceuil");
gtk_widget_destroy(window1);
}


void
on_MA_radiobutton_congele_ajouter_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 
strcpy(sa,"Congelé");
}


void
on_MA_radiobutton_refrigere_ajouter_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 
strcpy(sa,"Réfrigéré");
}


void
on_MA_radiobutton_TA_ajouter_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 
strcpy(sa,"ambiante");
}


void
on_MA_radiobutton_congele_modifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 
strcpy(sm,"Congelé");
}


void
on_MA_radiobutton_refrigere_modifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 
strcpy(sm,"Réfrigéré");
}


void
on_MA_radiobutton_TA_modifier_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 
strcpy(sm,"ambiante");
}


void
on_MA_treeview_LR_rupture_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* ref;
gchar* nom;
gchar* dpj;
gchar* dpm;
gchar* dpa;
gchar* qte;
gchar* cat;
gchar* stk;

produit p;
date dp;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ref,1,&nom,2,&dpj,3,&dpm,4,&dpa,5,&qte,6,&cat,7,&stk-1);

strcpy(p.ref,ref);
strcpy(p.nom,nom);

strcpy(p.dp.jour,dpj);
strcpy(p.dp.jour,dpm);
strcpy(p.dp.mois,dpa);

strcpy(p.qte,qte);
strcpy(p.cat,cat);

strcpy(p.stk,stk);


afficherrupture(treeview);
}

}
void
on_MA_button_actualiser_rupture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affiche,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"MA_Interface_Rupture");
fenetre_affiche=create_MA_Interface_Rupture();
gtk_widget_show(fenetre_affiche);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_affiche,"MA_treeview_LR_rupture");
afficherrupture(treeview1);
}


void
on_MA_button_acceuil_rupture_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsacceuil;
windowsacceuil=create_MA_Interface_Acceuil ();
gtk_widget_show(windowsacceuil);
GtkWidget *window1;
window1=lookup_widget(objet,"MA_Interface_Rupture");
gtk_widget_destroy(window1);

}


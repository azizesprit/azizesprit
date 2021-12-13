#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>
int verif (char username[], char motdepasse[])
{
int trouve=0;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utulisateur.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s",ch1,ch2)!=EOF)
{
if (strcmp(ch1,username)==0)
{
	if (strcmp(ch2,motdepasse)==0)
{
	trouve=1;
}
}
}
fclose(f);
}
return (trouve);
}
int verif1 (utulisateur u)
{
int trouve1=0;
FILE *f=NULL;
char ch1[20];
f=fopen("utulisateur.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s",ch1)!=EOF)
{
if (strcmp(ch1,u.username)==0)
{

	trouve1=1;
}
}
fclose(f);
}
return (trouve1);
}
void utsexe(int s ,char sexe1[])
{
if (s == 1)
strcpy(sexe1,"masculin");
else
	if(s ==2)
		 strcpy(sexe1,"feminin");
}
void resultat(int choix[],char texte[])
{
	strcpy(texte,"j'ai lu et j'accepte les conditions generales");
	if (choix[0]==1)
	strcat(texte,"accepté");
}
enum
{
	USERNAME,
	MOTDEPASSE,
	NOM,
	PRENOM,
	ROLE,
	NIVEAU,
	COLUMNS,
};
void afficher_utulisateur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char username[20];
	char motdepasse[20];
	char nom[20];
	char prenom[20];
	char role[20];
	char sexe[20];
	char niveau[20];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("username",renderer, "text",USERNAME,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("motdepasse",renderer, "text",MOTDEPASSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("role",renderer, "text",ROLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("niveau",renderer, "text",NIVEAU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("utulisateur.txt","r");
	if (f==NULL)
	{
	return;
	}
	else
	{f =fopen("utulisateur.txt","a+");
		while(fscanf(f," %s %s %s %s %s %s \n ",username,motdepasse,nom,prenom,role,niveau)!=EOF)
		{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,USERNAME,username,MOTDEPASSE,motdepasse,NOM,nom,PRENOM,prenom,ROLE,role,NIVEAU,niveau,-1);
		}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}
void supprimer_utulisateur(utulisateur u)
{
        char nom[20];
	char prenom[20];
	char username[20];
	char motdepasse[20];
	char role[20];
FILE *f,*g;
f= fopen("utulisateur.txt","r");
g=fopen("sp.txt","w");
	if(f==NULL || g==NULL)
	{
		return;
	}
	else{
		while(fscanf(f,"%s %s %s %s %s \n",username,motdepasse,nom,prenom,role)!=EOF)
		{
			if(strcmp(u.username,username)!=0)
			fprintf(g,"%s %s %s %s %s \n",username,motdepasse,nom,prenom,role);
		}
		fclose(f);
		fclose(g);
remove("utulisateur.txt");
rename("sp.txt","utulisateur.txt");
}
}
void modifier_utulisateur(utulisateur u)
{
FILE *F2;
FILE *F1;
    char username3[20];
    char motdepasse3[20];
    char nom3[20];
    char prenom3[20];
    char role3[20];
    F1=fopen("utulisateur.txt","r");
    F2=fopen("modif.txt","w");
    if(F1 != NULL)
    {
        while(fscanf(F1,"%s %s %s %s %s \n",u.username,u.motdepasse,u.nom,u.prenom,u.role)!=EOF)
        {
            if(strcmp(u.username,username3)!=0)
            {
                printf("ecrire nom \n");
                scanf("%s",u.nom);
                printf("ecrire prenom");
                scanf("%s",u.prenom);
                printf("ecrire username ");
                scanf("%s",u.username);
                printf("ecrire motdepasse");
                scanf("%s",u.motdepasse);
		printf("ecrire role ");
                scanf("%s",u.role);
                strcpy(nom3,u.nom);
                strcpy(prenom3,u.prenom);
                strcpy(username3,u.username);
                strcpy(motdepasse3,u.motdepasse);
		strcpy(role3,u.role);
                fprintf(F2,"%s %s %s %s %s \n",username3,motdepasse3,nom3,prenom3,role3);


            }



        }

    }
    fclose(F1);
    fclose(F2);
    remove("utulisateur.txt");
    rename("modif.txt","utulisateur.txt");
    getchar();
}
int verif3 (char role[])
{
int trouve3=0;
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
int s;
f=fopen("utulisateur.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %d ",ch1,ch2,ch3,ch4,ch5,s)!=EOF)
{
if (strcmp(ch5,role)==0)
{

	trouve3=1;
}
}
}
fclose(f);
}

enum 
{
	NV1,
	NV2,
	NV3,
	NV4,	
	NV5,
};
void afficher_niveau(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nv1[20];
	char nv2[20];
	char nv3[20];
	char nv4[20];
	char nv5[20];
	store=NULL;
	FILE *f1;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nv1",renderer, "text",NV1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nv2",renderer, "text",NV2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nv3",renderer, "text",NV3,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nv4",renderer, "text",NV4,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nv5",renderer, "text",NV5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f1=fopen("niveau.txt","r");
	if (f1==NULL)
	{
	return;
	}
	else
	{f1 =fopen("niveau.txt","a+");
		while(fscanf(f1," %s %s %s %s %s \n ",nv1,nv2,nv3,nv4,nv5)!=EOF)
		{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,NV1,nv1,NV2,nv2,NV3,nv3,NV4,nv4,NV5,nv5,-1);
		}
	fclose(f1);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}
void nb_etudiant(utulisateur u)
{
FILE *f1;
FILE *f2=NULL;
char nv1[20];
char nv2[20];
char nv3[20];
char nv4[20];
char nv5[20];
int ni1;
int ni2;
int ni3;
int ni4;
int ni5;
char niv1[20];
char niv2[20];
char niv3[20];
char niv4[20];
char niv5[20];
f1=fopen("niveau.txt","r");
f2=fopen("nb.txt","a+");
if(f1 != NULL)
    {
        while(fscanf(f1,"%s %s %s %s %s \n",nv1,nv2,nv3,nv4,nv5)!=EOF)
        {
	if (strcmp(nv1,"1")==0)
		ni1+=1;
	else
		if (strcmp(nv2,"2")==0)
			ni2+=1;
		else
			if (strcmp(nv3,"3")==0)
				ni3+=1;
			else
				if (strcmp(nv4,"4")==0)
					ni4+=1;
				else 
					if (strcmp(nv5,"5")==0)
						ni5+=1;
        }
fclose(f1);
    }
sprintf(niv1, "%d", ni1);
sprintf(niv2, "%d", ni2);
sprintf(niv3, "%d", ni3);
sprintf(niv4, "%d", ni4);
sprintf(niv5, "%d", ni5);
fprintf(f2," %s %s %s %s %s  \n",niv1,niv2,niv3,niv4,niv5);
fclose(f2);
}


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
utulisateur u;
f=fopen("utulisateur.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s",u.username,u.motdepasse)!=EOF)
{
if (strcmp(username,u.username)==0)
{
	if (strcmp(motdepasse,u.motdepasse)==0)
{
	trouve=1;
}
}
}
fclose(f);
}
return (trouve);
}
int verif1 (char username[])
{
int trouve1=0;
FILE *f=NULL;
utulisateur u;
f=fopen("utulisateur.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s",u.username)!=EOF)
{
if (strcmp(username,u.username)==0)
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
void supprimer_utulisateur(char usersupp[])
{
 utulisateur u;       
FILE *f,*g;
f= fopen("utulisateur.txt","r");
g=fopen("sp.txt","w");
	if(f==NULL || g==NULL)
	{
		return;
	}
	else{
		while(fscanf(f,"%s %s %s %s %s %s \n",u.username,u.motdepasse,u.nom,u.prenom,u.role,u.niveau)!=EOF)
		{
			if(strcmp(u.username,usersupp)!=0)
			fprintf(g,"%s %s %s %s %s %s \n",u.username,u.motdepasse,u.nom,u.prenom,u.role,u.niveau);
		}
		fclose(f);
		fclose(g);
remove("utulisateur.txt");
rename("sp.txt","utulisateur.txt");
}
}
void modifier_utulisateur(utulisateur u,char usermodiff[20])
{
FILE *F2;
FILE *F1;
utulisateur u1;
    F1=fopen("utulisateur.txt","r");
    F2=fopen("modif.txt","w");
    if(F1 != NULL)
    {
        while(fscanf(F1,"%s %s %s %s %s %s  \n",u1.username,u1.motdepasse,u1.nom,u1.prenom,u1.role,u1.niveau)!=EOF)
        {
            if(strcmp(u1.username,usermodiff)!=0)
            {
         	if (strcmp("etudiant",u1.role)==0)
		{
			fprintf(F2," %s %s %s %s %s %s \n",u.username,u.motdepasse,u.nom,u.prenom,u.role,u.niveau);
		}
		else
                fprintf(F2,"%s %s %s %s %s %s \n",u.username,u.motdepasse,u.nom,u.prenom,u.role,"X");


            }


        }

    }
    fclose(F1);
    fclose(F2);
    remove("utulisateur.txt");
    rename("modif.txt","utulisateur.txt");
    getchar();
}
int verif3 (utulisateur u)
{
int trouve3=0;
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
char  ch6[20];
f=fopen("utulisateur.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s ",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{
if (strcmp(ch5,u.role)==0)
{

	trouve3=1;
}
}
}
fclose(f);
return (trouve3);
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
FILE *f;
char niv1[20];
char niv2[20];
char niv3[20];
char niv4[20];
char niv5[20];
int ni1;
int ni2;
int ni3;
int ni4;
int ni5;
f1=fopen("niveau.txt","a+");
f=fopen("utulisateur.txt","r");
if(f != NULL)
    {
        while(fscanf(f1,"%s %s %s %s %s %s \n",u.username,u.motdepasse,u.nom,u.prenom,u.motdepasse,u.role,u.niveau)!=EOF)
        {
	if (strcmp(u.niveau,"1")==0)
		ni1++;
	else
		if (strcmp(u.niveau,"2")==0)
			ni2++;
		else
			if (strcmp(u.niveau,"3")==0)
				ni3++;
			else
				if (strcmp(u.niveau,"4")==0)
					ni4++;
				else 
					if (strcmp(u.niveau,"5")==0)
						ni5++;
        }
    }
sprintf(niv1, "%d", ni1);
sprintf(niv2, "%d", ni2);
sprintf(niv3, "%d", ni3);
sprintf(niv4, "%d", ni4);
sprintf(niv5, "%d", ni5);
fprintf(f1," %s %s %s %s %s  \n",niv1,niv2,niv3,niv4,niv5);
fclose(f1);
fclose(f);
}
void capteur_ajouter(capteur c)
{
FILE*f;

char ID[30];
f=fopen("capteur.txt","a+");

if (f!=NULL)
{

fprintf(f,"%s %s %s %s \n",c.ID,c.type,c.etat,c.valeur);
}
fclose(f);

}
void capteur_modifier(capteur c ,char ID[])

{

    capteur c1;
    FILE *f;
    FILE *f2;
    f=fopen("capteur.txt","r");
    f2=fopen("capteur1.txt","w");

       while
        (fscanf(f,"%s %s %s %s \n",c1.ID,c1.type,c1.etat,c1.valeur)!=EOF)
        {
            if
            (strcmp(c1.ID,ID)==0)
             
            {

fprintf(f2,"%s %s %s %s  \n",c.ID,c.type,c.etat,c.valeur);}
else /*rien ne change*/
            
fprintf(f2,"%s %s %s %s \n",c1.ID,c1.type,c1.etat,c1.valeur);       
  }  
        fclose(f);    
        fclose(f2);
        remove("capteur.txt");
        rename("capteur1.txt","capteur.txt");
    
}

void capteur_supprimer(char ID[])
{
     capteur c;

    FILE*f=NULL;
    FILE*f1=NULL;

    f=fopen("capteur.txt","r");
    f1=fopen("capteur1.txt","a+");
if(f==NULL || f1==NULL)
{ 
return;
}
else
{
    
 while(fscanf(f,"%s %s %s %s  \n",c.ID,c.type,c.etat,c.valeur)!=EOF)
        {
            if(strcmp(ID,c.ID)!=0)
fprintf(f1,"%s %s %s %s  \n",c.ID,c.type,c.etat,c.valeur);
}
        fclose(f);
        fclose(f1);
        remove("capteur.txt");
        rename("capteur1.txt","capteur.txt");
    
    }
}

 
/*bool reche (char ID1[])
{//debut
capteur c;
char ID [30];
char type[30];
char etat[30];
char valeur[30] ;
char reche=false;

    FILE*f=NULL;

    f=fopen("capteur.txt","r");

if(f==NULL)
{ 
return;
}
else
{//else
    
 while(fscanf(f,"%s %s %s %s \n",ID,type,etat,valeur)!=EOF)
        {//while
            if(strcmp(ID1,ID)==0){
           reche=true;}
            
}//else
        
 
fclose(f);
}
return (reche);
}//fin*/

void capteur_recherche(GtkWidget *liste,char ID[])
{
enum
{
	id,         
        TYPE,
     	ETAT,  
        VALEUR,
	
	COLUMNS
};
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;	
GtkListStore *store;
/*
char type[30];
char etat[30];
char valeur[30] ;
*/

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	
	column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",id,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	

char id1[100];
char etat1[100];
char valeur1[100];
char type1[100];
	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("capteur.txt","r");

	
	
	
		while(fscanf(f,"%s %s %s %s \n",id1,type1,etat1,valeur1)!=EOF)
                       {
			if (strcmp(ID,id1)==0){ 
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,id,id1,TYPE,type1,ETAT,etat1,VALEUR,valeur1,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	
	
}
}
}



void capteur_affiche(GtkWidget *liste )
{

enum
{
	id,         
        TYPE,
     	ETAT,  
        VALEUR,
	
	COLUMNS
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;	
GtkListStore *store;

char ID [30];
char type[30];
char etat[30];
char valeur[30] ;

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	
	column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",id,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	

       
	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("capteur.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("capteur.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",ID,type,etat,valeur)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,id,ID,TYPE,type,ETAT,etat,VALEUR,valeur,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	
	}
}
}

 
/*void capteurdef()
{
FILE *f,*g;
f=fopen("temperature.txt","r");
g=fopen("capteurdefectueux.txt","a+");
temperature t,T[5000];
int i=0,n=0,nb=0;
if(f!=NULL)
{
while(!feof(f))
{
fscanf(f,"%d %d %d %f\n",&t.jour,&t.heure,&t.numcap,&t.valucap);
T[i].jour=t.jour;
T[i].heure=t.heure;
T[i].numcap=t.numcap;
T[i].valucap=t.valucap;
i++;
}
fclose(f);
n=i;
}
for(i=0;i<n;i++)
{
if (T[i].valucap<0 || T[i].valucap>30)
{
fprintf(g,"%d %d %d %f\n",T[i].jour,T[i].heure,T[i].numcap,T[i].valucap);
nb++;
}
}
printf("le nombre des capteurs defectueux est:%d/%d\n",nb,n);
}*/
void afficherrr(GtkWidget *liste)
{



GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
enum
{
	JOUR,         
        HEURE,
     	NUMERO,  
        VALEUR,
		
	COLUMNS
};

char jjj[30];
char hhh[30];
char numr[30];
char vale[30];


store =NULL;

FILE *FL;
//FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();

	
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JOUR",renderer,"text",jjj,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("HEURE",renderer,"text",hhh,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("NUMERO",renderer,"text",numr,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("VALEUR",renderer,"text",vale,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	

       
	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	FL=fopen("temp.txt","r");

	if(FL==NULL)
	{
		return;
	}
	else
	
	{ 
	FL=fopen("temp.txt","r");
		while(fscanf(FL,"%s %s %s %s\n",jjj,hhh,numr,vale)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter, jjj,JOUR,hhh,HEURE,numr,NUMERO,vale,VALEUR,-1);}

		fclose(FL);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}}}

enum 
{
EREF,
ENOM,
EDPJ,
EDPM,
EDPA,
EQTE,
ECAT,
ESTK,
};





int veriff(char rf)
{
FILE *f=NULL;
produit prd;

int trouve=-1;
f =fopen("stock.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat,prd.stk)!=EOF)
{
if(strcmp(rf,prd.ref)==0)
trouve=1;
}
fclose(f);
}
return trouve ; 
}





void ajouter_produit(produit prd)
{
FILE *f=NULL;
f=fopen("stock.txt","a");
if(f!=NULL);
{
//if(verif(prd.ref)!=1)

//else 
//printf("produit déja entré! \n");
fprintf(f,"%s %s %s %s %s %s %s %s \n",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat,prd.stk);
}
fclose(f);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficherstock(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;
   produit p;
   
char ref[20];
char nom[20];
char dpj[20];
char dpm[20];
char dpa[20];
char qte[20];
char cat[20];
char stk[20];
store=NULL;
FILE *f;
   store = gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("ref", renderer, "text",EREF, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("dpj", renderer, "text",EDPJ, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("dpm", renderer, "text",EDPM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("dpa", renderer, "text",EDPA, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("qte", renderer, "text",EQTE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("cat", renderer, "text",ECAT, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("stk", renderer, "text",ESTK, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("stock.txt", "r"); 

  if(f==NULL)
   {
  return;
   }
  else
  { 
f=fopen("stock.txt", "a+");
       while(fscanf(f,"%s %s %s %s %s %s %s %s\n",ref,nom,dpj,dpm,dpa,qte,cat,stk)!= EOF)
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,EREF,ref,ENOM,nom,EDPJ,dpj,EDPM,dpm,EDPA,dpa,EQTE,qte,ECAT,cat,ESTK,stk,-1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  
g_object_unref (store);


}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


produit recherche_produit(char ref_rech[])

{
produit prd,rech;
FILE *f=NULL;
int trouver=0;
f=fopen("stock.txt","r");
while (fscanf(f,"%s %s %s %s %s %s %s %s\n",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat,prd.stk)!=EOF)
{
if(strcmp(prd.ref,ref_rech)==0)
{
trouver=1;
strcpy(rech.ref,prd.ref);
strcpy(rech.nom,prd.nom);
strcpy(rech.dp.jour,prd.dp.jour);
strcpy(rech.dp.mois,prd.dp.mois);
strcpy(rech.dp.annee,prd.dp.annee);
strcpy(rech.qte,prd.qte);
strcpy(rech.cat,prd.cat);
strcpy(rech.stk,prd.stk);
}

}
fclose(f);
return rech;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void supprimer_produit(char ref_supp[])
{
	produit prd;
	FILE *f=NULL;
	FILE *f1=NULL;
	f=fopen("stock.txt","r");
	f1=fopen("stock1.txt","a");
	//if(f!=NULL)
	//{
		
			while(fscanf(f,"%s %s %s %s %s %s %s %s\n",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat,prd.stk)!=EOF)
			{
				if(strcmp(ref_supp,prd.ref)!=0)
				fprintf(f1,"%s %s %s %s %s %s %s %s\n",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat,prd.stk);
			}
		
		fclose(f);
		fclose(f1);
		remove("stock.txt");
		rename("stock1.txt","stock.txt");
	//}
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modifier_produit(produit prdm,char ref_modf[])
{
	produit prd;
	FILE *f=NULL;
	FILE *f1=NULL;
	f=fopen("stock.txt","r");
	f1=fopen("stock1.txt","a");
	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat,prd.stk)!=EOF)
			{
				if(strcmp(ref_modf,prd.ref)!=0)
				fprintf(f1,"%s %s %s %s %s %s %s %s\n",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat,prd.stk);
				else
				{
					
					fprintf(f1,"%s %s %s %s %s %s %s %s\n",prdm.ref,prdm.nom,prdm.dp.jour,prdm.dp.mois,prdm.dp.annee,prdm.qte,prdm.cat,prdm.stk);
				
			
			
		}
		fclose(f);
		fclose(f1);
		remove("stock.txt");
		rename("stock1.txt","stock.txt");
	}
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void afficher_produit(produit prd)
{
FILE *f=NULL;
f=fopen("stock.txt","r");
if(f!=NULL);
{
while(fscanf(f,"%s %s %d %d %d %s %s",prd.ref,prd.nom,&prd.dp.jour,&prd.dp.mois,&prd.dp.annee,prd.qte,prd.cat)!=EOF)
printf("%s \t %s \t %d/%d/%d \t %s \t %s \n",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat);
}
fclose(f);
}

*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rupture_stock()
{
produit prd;
FILE *f=NULL;
f=fopen("stock.txt","r");
if(f!=NULL);
{
while(fscanf(f,"%s %s %d %d %d %s %s",prd.ref,prd.nom,&prd.dp.jour,&prd.dp.mois,&prd.dp.annee,prd.qte,prd.cat)!=EOF)
{
if (prd.qte==0)
printf("%s \t %s \t %d/%d/%d \t %s \t %s \n",prd.ref,prd.nom,prd.dp.jour,prd.dp.mois,prd.dp.annee,prd.qte,prd.cat);
}
}
fclose(f);
}


void afficherrupture(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;
   produit p;
   
char ref[20];
char nom[20];
char dpj[20];
char dpm[20];
char dpa[20];
char qte[20];
char cat[20];
char stk[20];
store=NULL;
FILE *f;
   store = gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("ref", renderer, "text",EREF, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("dpj", renderer, "text",EDPJ, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("dpm", renderer, "text",EDPM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("dpa", renderer, "text",EDPA, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("qte", renderer, "text",EQTE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("cat", renderer, "text",ECAT, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("stk", renderer, "text",ESTK, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("stock.txt", "r"); 

  if(f==NULL)
   {
  return;
   }
  else
  { 
f=fopen("stock.txt", "a+");
       while(fscanf(f,"%s %s %s %s %s %s %s %s\n",ref,nom,dpj,dpm,dpa,qte,cat,stk)!= EOF)
    {
	if(strcmp(qte,"0")==0){
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,EREF,ref,ENOM,nom,EDPJ,dpj,EDPM,dpm,EDPA,dpa,EQTE,qte,ECAT,cat,ESTK,stk,-1);
	}	
	}
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  
g_object_unref (store);
}

















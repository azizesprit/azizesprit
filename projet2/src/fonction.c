#include "fonction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

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
COLUMNS,
};





int verif(char rf)
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







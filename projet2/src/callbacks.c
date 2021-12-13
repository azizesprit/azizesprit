#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "fonction.h"

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "string.h"

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


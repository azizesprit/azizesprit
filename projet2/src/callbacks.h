#include <gtk/gtk.h>


void
on_MA_Modifier_acceuil_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_MA_Supprimer_acceuil_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_MA_Ajouter_acceuil_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_MA_button_recherche_acceuil_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_acceuil_ajouter_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_confirmer_ajouter_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_Modifier_acceuil_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_Supprimer_acceuil_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_treeview_LS_acceuil_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MA_button_Ajouter_acceuil_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_radiobutton_tts_acceuil_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_radiobutton_rps_acceuil_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_button_actualiser_acceuil_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_supprimer_supprimer_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_acceuil_supprimer_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_checkbutton_confirmer_supprimer_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_button_rechercher_rechercher_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_acceuil_rechercher_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_acceuil_modifier_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_modifier_modifier_clicked (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_MA_button_rps_acceuil_clicked       (GtkWidget       *obje,
                                        gpointer         user_data);

void
on_MA_radiobutton_congele_ajouter_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_radiobutton_refrigere_ajouter_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_radiobutton_TA_ajouter_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_radiobutton_congele_modifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_radiobutton_refrigere_modifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_radiobutton_TA_modifier_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MA_treeview_LR_rupture_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MA_button_actualiser_rupture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MA_button_acceuil_rupture_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

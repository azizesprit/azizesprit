/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *az_inscription;
  GtkWidget *adminajout;
  GtkWidget *az_connexion;
  GtkWidget *az_admin;
  GtkWidget *adminaffiche;
  GtkWidget *az_modif;
  GtkWidget *ad_modif;
  GtkWidget *az_supression;
#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  az_inscription = create_az_inscription ();
  gtk_widget_show (az_inscription);
  az_connexion = create_az_connexion ();
  az_admin = create_az_admin ();
  adminaffiche =create_adminaffiche ();
  adminajout = create_adminajout ();
  az_supression = create_az_supression ();
  az_modif = create_az_modif ();

  ad_modif = create_ad_modif ();
  
  gtk_main ();
  return 0;
}

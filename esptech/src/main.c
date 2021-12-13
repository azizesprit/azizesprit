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
  GtkWidget *affiche;
  GtkWidget *Ajout;
  GtkWidget *suppression;
  GtkWidget *modification;

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
  affiche = create_affiche ();
  gtk_widget_show (affiche);
  Ajout = create_Ajout ();
  gtk_widget_show (Ajout);
  suppression = create_suppression ();
  gtk_widget_show (suppression);
  modification = create_modification ();
  gtk_widget_show (modification);

  gtk_main ();
  return 0;
}

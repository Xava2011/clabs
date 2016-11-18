#ifndef INCLUDED__DRAW_H
#define INCLUDED__DRAW_H

#include <gtk/gtk.h>
#include "mazelib.h"

/* Wielko�� wy�wietlanych ikon */
#define ICON_WIDTH  30
#define ICON_HEIGHT 30

/* Narysuj labirynt */
void update_view(GtkWidget* widget);

/* Callback */
gint on_expose_event(GtkWidget* widget, GdkEventExpose* event);

/* Rysuj labirynt na zewn�trznej pixmapie -- nie powoduje od�wie�enia obrazu */
void draw_pixmap(GtkWidget* widget);

/* Rysuj ikon� 'p' na g��wnej pixmapie na logicznej pozycji (xpos, ypos), skorzystaj
 * z graficznego kontekstu widgeta 'widget' */
void draw_icon_in_pos(GtkWidget* widget, int terrain_type, int xpos, int ypos);

/* Spowoduj od�wie�enie r�nych cz�ci labiryntu */
void invalidate_all(GtkWidget* widget);
void invalidate_point(GtkWidget* widget, pointT pt);
void invalidate_near(GtkWidget* widget, pointT pt);

#endif


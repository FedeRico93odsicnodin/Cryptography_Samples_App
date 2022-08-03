#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

// algorithms inclusion
#include "general_algorithms/Caesar.h"

// reference to main win
GtkWidget	*win_main_ref;

// different algorithms windows
GtkWidget	*win_caesar;

// allows to initialize windows for current context 
void Gen_Alg_Init_Windows(GtkWidget *win_main, GtkBuilder *builder) {

    // ref to main win
    win_main_ref = win_main;
    win_caesar = GTK_WIDGET(gtk_builder_get_object(builder, "caesar_win"));

    // initialization for the program interface 
    InitMainWindow_Caesar(win_caesar, builder);
}


void on_caesar_start_clicked(GtkButton *b) 
{
    gtk_widget_hide(win_main_ref);
    gtk_widget_show(win_caesar);
}

void on_caesar_win_delete_event(GtkWidget *w) {
    gtk_widget_hide(win_caesar);
    gtk_widget_show(win_main_ref);
}

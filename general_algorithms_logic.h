#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

#include "frm_enc_dec_1.h"



// the builder for the view
GtkBuilder *_builder;

// reference to main win
GtkWidget	*win_main_ref;

// different algorithms windows
GtkWidget	*win_gen_alg;
GtkWidget	*runtime_enc_form;

// allows to initialize windows for current context 
void Gen_Alg_Init_Windows(GtkWidget *win_main, GtkBuilder *builder) {

    // ref to the builder
    _builder = builder;

    // ref to main win
    win_main_ref = win_main;
    win_gen_alg = GTK_WIDGET(gtk_builder_get_object(_builder, "gen_win_1"));
    runtime_enc_form = GTK_WIDGET(gtk_builder_get_object(_builder, "runtime_enc_form"));
    
}

//////////////////// GENERAL ALGORITHMS ////////////////////
void on_caesar_win_delete_event(GtkWidget *w) {
    gtk_widget_hide(win_gen_alg);
    gtk_widget_show(win_main_ref);
}

void on_caesar_start_clicked(GtkButton *b) 
{
    gtk_widget_hide(win_main_ref);

    // init for the Caesar 
    initMainWindow_Gen(win_gen_alg, _builder, caesar);
    gtk_widget_show(win_gen_alg);
}

void on_vigenère_start_clicked(GtkButton *b) 
{
    gtk_widget_hide(win_main_ref);

    // init for the Vigenère
    initMainWindow_Gen(win_gen_alg, _builder, vigenere);
    gtk_widget_show(win_gen_alg);
}
////////////////////////////////////////////////////////////

////////// STREAM ALGORITHMS //////////
void on_otp_start_clicked(GtkButton *b) {
     gtk_widget_hide(win_main_ref);

    // init for the otp
    // initMainWindow_Gen(win_gen_alg, _builder, otp); // TODO: substitute this method with one in the form for stream ciphers 
    gtk_widget_show(runtime_enc_form);
}

////////////////////////////////////////////////////////////
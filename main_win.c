#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

// application files
#include "general_algorithms_logic.h"


// the main builder
GtkBuilder	*builder; 

// main window
GtkWidget	*win_main;


// grids to display and visibility properties
GtkWidget	*grid_gen;
gboolean _isGridGenVisible = False;

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk
    
//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("Main_Cryptography.glade");
 
	win_main = GTK_WIDGET(gtk_builder_get_object(builder, "win_main"));
	

    // general algorithms display grid
    grid_gen = GTK_WIDGET(gtk_builder_get_object(builder, "grid_gen"));


    // initializations of the contexts for the application
    Gen_Alg_Init_Windows(win_main, builder);


	g_signal_connect(win_main, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

	gtk_widget_show(win_main);

	gtk_main();

	return EXIT_SUCCESS;
	}


////////// menu iterms actions //////////
void	on_gen_alg_button_press_event (GtkMenuItem *gen) {
    if(_isGridGenVisible == False) {
        gtk_widget_show(grid_gen);
        _isGridGenVisible = True;
    }
    else 
    {
        gtk_widget_hide(grid_gen);
        _isGridGenVisible = False;
    }
	
	}



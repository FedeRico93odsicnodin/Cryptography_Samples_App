/*
    THose methods are common to all the different algorithms and allows to 
    make it easy to do certain operations 
*/
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

/////////// GTKTEXTVIEW UTILS /////////// 

// getting the text from a GtkTextView
gchar *GetTextFromGTKTextView(GtkTextView *txt_view) {

        GtkTextIter start, end;
        GtkTextBuffer *buffer = gtk_text_view_get_buffer (txt_view);
        gchar *text;
        gtk_text_buffer_get_bounds (buffer, &start, &end);
        text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);
        return text;
}




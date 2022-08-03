#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>


#include "../utils_form_encrypt.h"
// the builder for the view
GtkBuilder *_builder;

// different algorithms windows
GtkWidget	*_win_caesar;
// reverse action for the current form 
gboolean _isDecryption = False;

// text views used 
GtkTextView *encr_txt;
GtkTextView *decr_txt;
GtkTextView *key_length;



// window for the algorithm initialization 
void InitMainWindow_Caesar(GtkWidget *win_caesar, GtkBuilder *builder) {

    _win_caesar = win_caesar;
    _builder = builder;

    // getting the wanted text view for encryption / decryption
    encr_txt = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "text_to_encrypt"));
    decr_txt = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "encrypted_text"));
    key_length = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "key_length"));
}

////////// ALGORITHM USED FOR THE ENCRYPTION //////////

gchar *encrypt_caesar(gchar *txtToEncrypt, int key) {

    gchar *s;
    s = "aaaa";    

    // TODO: implementation 

    return s;

}

////////////////////////////////////////////////////////////

// button action for encryption / descryption
void on_enc_action_btn_clicked(GtkButton *b) {

    if(!_isDecryption) {

        GtkTextBuffer *buffer_res = gtk_text_view_get_buffer (decr_txt);
        gchar *text;
        gchar *key_text;
        gchar *encrypted_txt; 

        // retrieving the text to encrypt 
        text = GetTextFromGTKTextView(encr_txt);
        // retrieving the key for the encryption 
        key_text = GetTextFromGTKTextView(key_length);
        int key;
        key = atoi(key_text);

        // printing key info
        printf("attemp = %d\n",key);

        // encrypting the text 
        encrypted_txt = encrypt_caesar(text, key);

        gtk_text_buffer_set_text(buffer_res, encrypted_txt, -1);
    }

}



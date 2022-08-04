/*
    those are all the common functions for starting the main form for encryption
    and decryption for the current context 
    current algorithm is passed by the mean of enumerator 
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

// utils inclusion
#include "../utils_form_encrypt.h"

// algorithms inclusion
//#include "../general_algorithms/Caesar.h"
//#include "../general_algorithms/Vigenère.h"

// the current selected algorithm
general_agorithms _currAlg;

// the builder for the view
GtkBuilder *_builder;

// different algorithms windows
GtkWidget	*_win_gen;
// reverse action for the current form 
gboolean _isDecryption = False;

// text views used 
GtkTextView *encr_txt;
GtkTextView *decr_txt;
GtkTextView *key_length;

// label and button for decription updates
GtkLabel *descr_txt_label;
GtkButton *action_btn;

// window for the algorithm initialization 
void InitMainWindow_Gen(GtkWidget *win_gen, GtkBuilder *builder) {

    /*
    _win_gen = win_caesar;
    _builder = builder;
    _currAlg = currAlg;

    // getting the wanted text view for encryption / decryption
    encr_txt = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "text_to_encrypt"));
    decr_txt = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "encrypted_text"));
    key_length = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "key_length"));

    // getting the change text elements 
    descr_txt_label = GTK_LABEL(gtk_builder_get_object(builder, "txt_1_descr_lbl"));
    action_btn = GTK_BUTTON(gtk_builder_get_object(builder, "enc_action_btn"));
    */
}


// button action for encryption / decryption
void on_enc_action_btn_clicked(GtkButton *b) {


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
        printf("key = %d\n",key);

        // encrypting the text 
        encrypted_txt = encrypt_caesar(text, key);

        gtk_text_buffer_set_text(buffer_res, encrypted_txt, -1);
}

// reverting the actions for the algorithm (from enc to dec)
void on_revert_caesar_btn_clicked(GtkButton *b) {

    // empty text 
    gchar *empty_text;
    empty_text = "";

    // emptying the text 
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (encr_txt);
    GtkTextBuffer *buffer_res = gtk_text_view_get_buffer (decr_txt);
    GtkTextBuffer *buffer_key = gtk_text_view_get_buffer (key_length);
    gtk_text_buffer_set_text(buffer, empty_text, -1);
    gtk_text_buffer_set_text(buffer_res, empty_text, -1);
    gtk_text_buffer_set_text(buffer_key, empty_text, -1);

    if(!_isDecryption) {
        
        // setting labels for the decryption explanation
        gtk_label_set_markup (descr_txt_label, LBL_TXT_2_DEC);
        gtk_button_set_label(action_btn, LBL_BTN_2_DEC);

        _isDecryption = True;
    }
    else {

        // setting labels for the encryption explanation
        gtk_label_set_markup (descr_txt_label, LBL_TXT_1_ENC);
        gtk_button_set_label(action_btn, LBL_BTN_1_ENC);

        _isDecryption = False;
    }

}

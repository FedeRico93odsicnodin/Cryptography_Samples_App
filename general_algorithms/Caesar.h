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


////////// CONST STRINGS FOR THE FORM //////////
const char *LBL_TXT_1_ENC = "please insert the text to encrypt";
const char *LBL_TXT_2_DEC = "please insert the text to decrypt";
const char *LBL_BTN_1_ENC = "encrypt!";
const char *LBL_BTN_2_DEC = "decrypt!";

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

// label and button for decription updates
GtkLabel *descr_txt_label;
GtkButton *action_btn;



// window for the algorithm initialization 
void InitMainWindow_Caesar(GtkWidget *win_caesar, GtkBuilder *builder) {

    _win_caesar = win_caesar;
    _builder = builder;

    // getting the wanted text view for encryption / decryption
    encr_txt = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "text_to_encrypt"));
    decr_txt = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "encrypted_text"));
    key_length = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "key_length"));

    // getting the change text elements 
    descr_txt_label = GTK_LABEL(gtk_builder_get_object(builder, "txt_1_descr_lbl"));
    action_btn = GTK_BUTTON(gtk_builder_get_object(builder, "enc_action_btn"));
    
}

////////// ALGORITHM USED FOR THE ENCRYPTION //////////

gchar *encrypt_caesar(gchar *txtToEncrypt, int key) {

    int txt_len = strlen(txtToEncrypt);
    for (int i = 0; i < txt_len; i++) {

        char ch;
        // decision for encrypt / decrypt 
        if(!_isDecryption) {
            ch = txtToEncrypt[i] + key;
        }
        else {
            ch = txtToEncrypt[i] - key;
        }
           
        txtToEncrypt[i] = ch;
    }
    // done encryption 
    printf("caesar encryption done!\n");
    return txtToEncrypt;

}

////////////////////////////////////////////////////////////

// button action for encryption / decryption
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
        printf("key = %d\n",key);

        // encrypting the text 
        encrypted_txt = encrypt_caesar(text, key);

        gtk_text_buffer_set_text(buffer_res, encrypted_txt, -1);
    }

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



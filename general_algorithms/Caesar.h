#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

////////// ALGORITHM USED FOR THE ENCRYPTION //////////

gchar *encrypt_caesar(gchar *txtToEncrypt, gchar *key, gboolean isDecryption) {

    int key_int = atoi(key);
    int txt_len = strlen(txtToEncrypt);
    for (int i = 0; i < txt_len; i++) {

        char ch;
        // decision for encrypt / decrypt 
        if(!isDecryption) {
            ch = txtToEncrypt[i] + key_int;
        }
        else {
            ch = txtToEncrypt[i] - key_int;
        }
           
        txtToEncrypt[i] = ch;
    }
    // done encryption 
    printf("caesar encryption done!\n");
    return txtToEncrypt;

}

////////////////////////////////////////////////////////////

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

gchar *encrypt_vigenere(gchar *txtToEncrypt, gchar *key, gboolean isDecryption) {

    int key_len = strlen(key);
    printf("key length %d\n", key_len);
    int txt_len = strlen(txtToEncrypt);
    int key_p = 0;

    for(int i = 0; i < txt_len; i++) {
        // calculating the current index for the key 
        int key_ind = (key_p % key_len);
        char ch = key[key_ind];
        int curr_key = atoi(&ch);
        key_p++;

        // conversion of curr char on basis of the key indexù
        char ch_1;
        
        // decision for encrypt / decrypt 
        if(!isDecryption) {
            ch_1 = txtToEncrypt[i] + curr_key;
        }
        else {
            ch_1 = txtToEncrypt[i] - curr_key;
        }
        printf("new char val %c\n", ch_1);
        txtToEncrypt[i] = ch_1;
    }



    // done encryption 
    printf("vigenere encryption done!\n");
    return txtToEncrypt;

}



////////////////////////////////////////////////////////////




#include <des.h>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // define the key and plaintext
    unsigned char key[] = "secretke";
    unsigned char plaintext[] = "thisisatestmesgxx";

    // create a DES key object
    DES_cblock des_key;
    memcpy(des_key, key, 8);
    DES_key_schedule key_schedule;
    DES_set_key_unchecked(&des_key, &key_schedule);

    // encrypt the plaintext using DES
    unsigned char ciphertext[16];
    memset(ciphertext, 0, sizeof(ciphertext));
    DES_ecb_encrypt((DES_cblock*)plaintext, (DES_cblock*)ciphertext, &key_schedule, DES_ENCRYPT);

    // print the ciphertext
    for (int i = 0; i < 8; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // decrypt the ciphertext using DES
    unsigned char decryptedtext[16];
    memset(decryptedtext, 0, sizeof(decryptedtext));
    DES_ecb_encrypt((DES_cblock*)ciphertext, (DES_cblock*)decryptedtext, &key_schedule, DES_DECRYPT);

    // print the decrypted plaintext
    printf("%s\n", decryptedtext);

    return 0;
}

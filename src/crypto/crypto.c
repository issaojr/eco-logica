#include <string.h>
#include "crypto.h"
#include <stdio.h>

void xor_cipher(char *data, char key) {
    size_t len = strlen(data);
    for(size_t i = 0; i < len; i++) {
        data[i] ^= key;
    }
}

void hash_senha(const char *senha, char *output, char key) {
    size_t len = strlen(senha);
    if (output == NULL) {
        fprintf(stderr, "Error: Output buffer is NULL.\n");
        return;
    }
    for (size_t i = 0; i < len; i++) {
        unsigned char x = (unsigned char)senha[i] ^ key;
        sprintf(output + (i * 2), "%02X", x);
    }
    output[len * 2] = '\0';
}

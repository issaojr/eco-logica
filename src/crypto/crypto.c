#include <string.h>
#include "crypto.h"

void xorCipher(char *data, char key) {
    size_t len = strlen(data);
    for(size_t i = 0; i < len; i++) {
        data[i] ^= key;
    }
}

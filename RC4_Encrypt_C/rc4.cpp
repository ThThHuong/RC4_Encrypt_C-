#include "rc4.h"

RC4::RC4(unsigned char* key, int keylen) {
    for (int i = 0; i < 256; i++) S[i] = i;
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keylen]) & 255;
        std::swap(S[i], S[j]);
    } 
}

void RC4::crypt(unsigned char* data, int len) {
    int i = 0, j = 0;
    for (int k = 0; k < len; k++) {
        i = (i + 1) & 255;
        j = (j + S[i]) & 255;
        std::swap(S[i], S[j]);
        data[k] ^= S[(S[i] + S[j]) & 255];
    }
}

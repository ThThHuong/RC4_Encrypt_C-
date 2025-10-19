#pragma once
class RC4 {
private:
    unsigned char S[256];
public:
    RC4(unsigned char* key, int keylen);
    void crypt(unsigned char* data, int len);
};

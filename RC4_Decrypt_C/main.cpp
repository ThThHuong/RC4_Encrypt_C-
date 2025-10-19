#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "rc4.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: decrypt <input_file> <output_file> <key>\n";
        return 1;
    }

    ifstream fin(argv[1], ios::binary);
    if (!fin) {
        cout << "Cannot open input file.\n";
        return 1;
    }

    ofstream fout(argv[2], ios::binary);
    if (!fout) {
        cout << "Cannot create output file.\n";
        return 1;
    }

    string key = argv[3];
    vector<unsigned char> data((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    RC4 rc4((unsigned char*)key.c_str(), key.length());
    rc4.crypt(data.data(), data.size());

    fout.write((char*)data.data(), data.size());
    fout.close();

    cout << "Decryption done successfully.\n";
    return 0;
}


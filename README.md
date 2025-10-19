
#  RC4 Encryption & Decryption in C++

This repository implements RC4 encryption and decryption using C++.

---

##  Folder structure


---

##  Compile
```bash
cd RC4_Encrypt_C
g++ main.cpp rc4.cpp -o encrypt

cd ../RC4_Decrypt_C
g++ main.cpp rc4.cpp -o decrypt
# Encrypt a text file
./encrypt input.txt encrypted.txt mykey

# Decrypt the encrypted file
./decrypt encrypted.txt output.txt mykey

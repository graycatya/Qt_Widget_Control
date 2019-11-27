#ifndef ENCPSSL_H
#define ENCPSSL_H

/*
 * 基于openssl加解密封装 作者:Graycatya(graycatya@163.com)
 * 1:Base64编解码
 * 2:Rsa非对称加解密
*/

#include "openssl/bio.h"
#include "openssl/buffer.h"
#include "openssl/evp.h"
#include "openssl/sha.h"
#include "openssl/rsa.h"
#include "openssl/rand.h"
#include "openssl/objects.h"
#include "openssl/pem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <string>

class EncpSsl
{
public:
    EncpSsl();
    ~EncpSsl();

    //base64
    char * Base64Encode(const char * input, int length, bool with_new_line);
    char * Base64Decode(char * input, int length, bool with_new_line);
    std::string Base64Encode(const std::string input, bool with_new_line);
    std::string Base64Decode(std::string input, bool with_new_line);

    //Rsa
    void Rsa_InitKey(int bits);
    std::string Rsa_Pub_Encrypt(const std::string &Text, std::string &PubKey);
    std::string Rsa_Pub_Decrypt(const std::string &Text, std::string &PubKey);
    std::string Rsa_Pri_Encrypt(const std::string &Text, std::string &PriKey);
    std::string Rsa_Pri_Decrypt(const std::string &Text, std::string &PriKey);
    std::string Get_Rsa_Pub_Key();
    std::string Get_Rsa_Pri_Key();

    //StrToHex
    std::string StrToHex_Lowercase(const unsigned char* str, int length);
    std::string StrToHex_Capital(const unsigned char* str, int length);


protected:

private:
    //Rsa
    //RSA *m_pRsa;
    std::string m_sRsaPublic_Key;
    std::string m_sRsaPrivate_Key;

};

#endif // ENCPSSL_H

#include "encpssl.h"

EncpSsl::EncpSsl()
{
    //m_pRsa = nullptr;
}

EncpSsl::~EncpSsl()
{
    /*
    if(m_pRsa != nullptr)
    {
        RSA_free(m_pRsa);
        m_pRsa = nullptr;
    }*/
}

char * EncpSsl::Base64Encode(const char * input, int length, bool with_new_line)
{
    BIO * bmem = nullptr;
    BIO * b64 = nullptr;
    BUF_MEM * bptr = nullptr;

    b64 = BIO_new(BIO_f_base64());
    if(!with_new_line) {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input, length);
    BIO_ctrl(b64,BIO_CTRL_FLUSH,0,nullptr);
    //BIO_flush(b64);
    BIO_ctrl(b64,BIO_C_GET_BUF_MEM_PTR, 0, &bptr);
    //BIO_get_mem_ptr(b64, &bptr);

    char * buff = new char[bptr->length + 1];//(char *)malloc(bptr->length + 1);
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;

    BIO_free_all(b64);

    return buff;
}

char * EncpSsl::Base64Decode(char * input, int length, bool with_new_line)
{
    BIO * b64 = nullptr;
    BIO * bmem = nullptr;
    char * buffer = new char[length];//(char *)malloc(length);
    memset(buffer, 0, static_cast<size_t>(length));

    b64 = BIO_new(BIO_f_base64());
    if(!with_new_line) {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new_mem_buf(input, length);
    bmem = BIO_push(b64, bmem);
    BIO_read(bmem, buffer, length);

    BIO_free_all(bmem);

    return buffer;
}

std::string EncpSsl::Base64Encode(const std::string input, bool with_new_line)
{
    BIO * bmem = nullptr;
    BIO * b64 = nullptr;
    BUF_MEM * bptr = nullptr;
    std::string buffer;
    b64 = BIO_new(BIO_f_base64());
    if(!with_new_line) {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input.c_str(), static_cast<int>(input.size()));
    BIO_ctrl(b64,BIO_CTRL_FLUSH,0,nullptr);
    //BIO_flush(b64);
    BIO_ctrl(b64,BIO_C_GET_BUF_MEM_PTR, 0, &bptr);

    char * buff = new char[bptr->length + 1];
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;
    buffer = std::string(buff, bptr->length);
    BIO_free_all(b64);
    delete[] buff;
    return buffer;
}

std::string EncpSsl::Base64Decode(std::string input, bool with_new_line)
{
    BIO * b64 = nullptr;
    BIO * bmem = nullptr;
    std::string buff;
    char * buffer = new char[input.size()];//(char *)malloc(input.size());
    memset(buffer, 0, input.size());

    b64 = BIO_new(BIO_f_base64());
    if(!with_new_line) {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new_mem_buf(input.c_str(), static_cast<int>(input.size()));
    bmem = BIO_push(b64, bmem);
    int lenght = -1;
    lenght = BIO_read(bmem, buffer, static_cast<int>(input.size()));
    buff = std::string(buffer, lenght);
    BIO_free_all(bmem);
    delete[] buffer;
    return buff;
}

void EncpSsl::Rsa_InitKey(int bits)
{
    RSA *m_pRsa = RSA_new();
    int ret = 0;
    BIGNUM* bne = BN_new();
    ret=BN_set_word(bne,RSA_F4);
    ret = RSA_generate_key_ex(m_pRsa,bits,bne,nullptr);
    if(ret!=1)
    {
        //FAILED
    } else {
        //获取公钥
        size_t pub_len;
        size_t pri_len;
        char *pub_key = nullptr;
        char *pri_key = nullptr;
        BIO *pub = BIO_new(BIO_s_mem());
        BIO *pri = BIO_new(BIO_s_mem());
        PEM_write_bio_RSAPublicKey(pub, m_pRsa);
        PEM_write_bio_RSAPrivateKey(pri, m_pRsa, nullptr, nullptr, 0, nullptr, nullptr);
        pub_len = static_cast<size_t>(BIO_ctrl(pub,BIO_CTRL_PENDING,0,nullptr));
        pri_len = static_cast<size_t>(BIO_ctrl(pri,BIO_CTRL_PENDING,0,nullptr));
        pub_key = new char[pub_len];
        pri_key = new char[pri_len];
        BIO_read(pub, pub_key, static_cast<int>(pub_len));
        BIO_read(pri, pri_key, static_cast<int>(pri_len));
        m_sRsaPublic_Key = std::string(pub_key, pub_len);
        m_sRsaPrivate_Key = std::string(pri_key, pri_len);
        //std::cout << "Publickey: " << Public_Key << std::endl;
        delete[] pub_key;
        pub_key = nullptr;
        delete[] pri_key;
        pri_key = nullptr;
        BIO_free(pub);
        BIO_free(pri);

    }
    BN_free(bne);
}

std::string EncpSsl::Rsa_Pub_Encrypt(const std::string &Text, std::string &PubKey)
{
    std::string StrBuffer;
    RSA *rsa = RSA_new();
    BIO *keybio = BIO_new_mem_buf(PubKey.c_str(), -1);
    rsa = PEM_read_bio_RSAPublicKey(keybio, &rsa, nullptr, nullptr);
    if(!rsa)
    {
        BIO_free_all(keybio);
        return std::string("Error");
    }
    int length = RSA_size(rsa);
    char *Cbuffer = new char[length + 1];
    memset(Cbuffer, 0, static_cast<size_t>(length + 1));
    int encrypt_length = -1;
    encrypt_length = RSA_public_encrypt(static_cast<int>(Text.length()),
                                        reinterpret_cast<const unsigned char *>(Text.c_str()),
                                        reinterpret_cast<unsigned char *>(Cbuffer), rsa, RSA_PKCS1_PADDING);
    if(encrypt_length < 0)
    {

        BIO_free_all(keybio);
        delete[] Cbuffer;
        return std::string("Error");
    }
    StrBuffer = std::string(Cbuffer, static_cast<size_t>(encrypt_length));
    delete[] Cbuffer;
    BIO_free_all(keybio);
    RSA_free(rsa);
    return StrBuffer;
}

std::string EncpSsl::Rsa_Pub_Decrypt(const std::string &Text, std::string &PubKey)
{
    std::string StrBuffer;
    RSA *rsa = RSA_new();
    BIO *keybio = BIO_new_mem_buf(PubKey.c_str(), -1);
    rsa = PEM_read_bio_RSAPublicKey(keybio, &rsa, nullptr, nullptr);
    if(!rsa)
    {
        BIO_free_all(keybio);
        return std::string("Error");
    }
    int length = RSA_size(rsa);
    char *Cbuffer = new char[length + 1];
    memset(Cbuffer, 0, static_cast<size_t>(length + 1));
    int decrypt_length = -1;
    decrypt_length = RSA_public_decrypt(static_cast<int>(Text.length()),
                                        reinterpret_cast<const unsigned char *>(Text.c_str()),
                                        reinterpret_cast<unsigned char *>(Cbuffer), rsa, RSA_PKCS1_PADDING);
    if(decrypt_length < 0)
    {
        BIO_free_all(keybio);
        delete[] Cbuffer;
        return std::string("Error");
    }
    StrBuffer = std::string(Cbuffer, static_cast<size_t>(decrypt_length));
    delete[] Cbuffer;
    BIO_free_all(keybio);
    RSA_free(rsa);
    return StrBuffer;
}

std::string EncpSsl::Rsa_Pri_Encrypt(const std::string &Text, std::string &PriKey)
{
    std::string StrBuffer;
    RSA *rsa = RSA_new();
    BIO *keybio = BIO_new_mem_buf(PriKey.c_str(), -1);
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, nullptr, nullptr);
    if(!rsa)
    {
        BIO_free_all(keybio);
        return std::string("Error");
    }
    int length = RSA_size(rsa);
    char *Cbuffer = new char[length + 1];
    memset(Cbuffer, 0, static_cast<size_t>(length + 1));
    int encrypt_length = -1;
    encrypt_length = RSA_private_encrypt(static_cast<int>(Text.length()),
                              reinterpret_cast<const unsigned char *>(Text.c_str()),
                              reinterpret_cast<unsigned char *>(Cbuffer), rsa, RSA_PKCS1_PADDING);
    if(encrypt_length < 0)
    {
        BIO_free_all(keybio);
        delete[] Cbuffer;
        return std::string("Error");
    }
    StrBuffer = std::string(Cbuffer, static_cast<size_t>(encrypt_length));
    delete[] Cbuffer;
    BIO_free_all(keybio);
    RSA_free(rsa);
    return StrBuffer;
}

std::string EncpSsl::Rsa_Pri_Decrypt(const std::string &Text, std::string &PriKey)
{
    std::string StrBuffer;
    RSA *rsa = RSA_new();
    BIO *keybio = BIO_new_mem_buf(PriKey.c_str(), -1);
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, nullptr, nullptr);
    if(!rsa)
    {
        BIO_free_all(keybio);
        return std::string("Error");
    }
    int length = RSA_size(rsa);
    char *Cbuffer = new char[length + 1];
    memset(Cbuffer, 0, static_cast<size_t>(length + 1));
    int decrypt_length = -1;
    decrypt_length = RSA_private_decrypt(static_cast<int>(Text.length()),
                              reinterpret_cast<const unsigned char *>(Text.c_str()),
                              reinterpret_cast<unsigned char *>(Cbuffer), rsa, RSA_PKCS1_PADDING);
    if(decrypt_length < 0)
    {
        BIO_free_all(keybio);
        delete[] Cbuffer;
        return std::string("Error");
    }
    StrBuffer = std::string(Cbuffer, static_cast<size_t>(decrypt_length));
    delete[] Cbuffer;
    BIO_free_all(keybio);
    RSA_free(rsa);
    return StrBuffer;
}

std::string EncpSsl::Get_Rsa_Pub_Key()
{
    return this->m_sRsaPublic_Key;
}

std::string EncpSsl::Get_Rsa_Pri_Key()
{
    return this->m_sRsaPrivate_Key;
}





std::string EncpSsl::StrToHex_Lowercase(const unsigned char* str, int length)
{
    std::string strhex;
    strhex.clear();
    char Hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    for(int i = 0; i < length; i++)
    {
        int Hex1 = static_cast<unsigned int>(str[i]) / 16;
        int Hex2 = static_cast<unsigned int>(str[i]) % 16;
        strhex.push_back(Hex[Hex1]);
        strhex.push_back(Hex[Hex2]);
    }
    return strhex;
}

std::string EncpSsl::StrToHex_Capital(const unsigned char* str, int length)
{
    std::string strhex;
    strhex.clear();
    char Hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for(int i = 0; i < length; i++)
    {
        int Hex1 = static_cast<unsigned int>(str[i]) / 16;
        int Hex2 = static_cast<unsigned int>(str[i]) % 16;
        strhex.push_back(Hex[Hex1]);
        strhex.push_back(Hex[Hex2]);
    }
    return strhex;
}

// Copyright (c) 2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ROICOIN_CRYPTO_RIPEMD160_H
#define ROICOIN_CRYPTO_RIPEMD160_H

#include <stdint.h>
#include <stdlib.h>
#include <openssl/ripemd.h>
#include <openssl/evp.h>

/** A hasher class for RIPEMD-160. */
class CRIPEMD160
{
private:
    EVP_MD_CTX *context;
    void initContext();

public:
    static const size_t OUTPUT_SIZE = RIPEMD160_DIGEST_LENGTH;

    CRIPEMD160();
    ~CRIPEMD160();
    CRIPEMD160& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CRIPEMD160& Reset();
};

#endif // ROICOIN_CRYPTO_RIPEMD160_H

#include <openssl/bn.h>
#include <openssl/rand.h>
#include <iostream>
using namespace std;

// Print BIGNUM
void printBN(const char* msg, BIGNUM* a) {
    char* num_str = BN_bn2hex(a);
    cout << msg << num_str << "\n";
    OPENSSL_free(num_str);
}

// Generate RSA parameters
void KeyGen(int bits, BIGNUM* e, BIGNUM* n, BIGNUM* d) {
    BN_CTX* ctx = BN_CTX_new();

    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *phi = BN_new();
    BIGNUM *p_minus_1 = BN_new();
    BIGNUM *q_minus_1 = BN_new();

    // Generate random primes p and q
    BN_generate_prime_ex(p, bits/2, 0, NULL, NULL, NULL);
    BN_generate_prime_ex(q, bits/2, 0, NULL, NULL, NULL);

    // n = p * q
    BN_mul(n, p, q, ctx);

    // phi = (p-1)*(q-1)
    BN_sub(p_minus_1, p, BN_value_one());
    BN_sub(q_minus_1, q, BN_value_one());
    BN_mul(phi, p_minus_1, q_minus_1, ctx);

    // d = e^-1 mod phi(n)
    BN_mod_inverse(d, e, phi, ctx);

    BN_free(p);
    BN_free(q);
    BN_free(phi);
    BN_free(p_minus_1);
    BN_free(q_minus_1);
    BN_CTX_free(ctx);
}

// Encrypt: c = m^e mod n
void Encrypt(BIGNUM* c, BIGNUM* m, BIGNUM* e, BIGNUM* n) {
    BN_CTX* ctx = BN_CTX_new();
    BN_mod_exp(c, m, e, n, ctx);
    BN_CTX_free(ctx);
}

// Decrypt: m = c^d mod n
void Decrypt(BIGNUM* m, BIGNUM* c, BIGNUM* d, BIGNUM* n) {
    BN_CTX* ctx = BN_CTX_new();
    BN_mod_exp(m, c, d, n, ctx);
    BN_CTX_free(ctx);
}

int main() {
    BN_CTX* ctx = BN_CTX_new();

    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();

    // Set e = 65537
    BN_set_word(e, 65537);

    cout << "Generating RSA parameters...\n";

    // Key Generation
    KeyGen(1024, e, n, d);

    printBN("n = ", n);
    printBN("e = ", e);
    printBN("d = ", d);

    // Message (int)
    BIGNUM *m = BN_new();
    BN_set_word(m, 123456);

    // Encrypt
    BIGNUM* c = BN_new();
    Encrypt(c, m, e, n);
    printBN("Encrypted c = ", c);

    // Decrypt
    BIGNUM* decrypted = BN_new();
    Decrypt(decrypted, c, d, n);
    printBN("Decrypted m = ", decrypted);

    BN_free(e);
    BN_free(n);
    BN_free(d);
    BN_free(m);
    BN_free(c);
    BN_free(decrypted);
    BN_CTX_free(ctx);

    return 0;
}
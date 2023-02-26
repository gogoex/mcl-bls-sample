#define BLS_ETH 1
#include <bls/bls384_256.h>
#include <cstdio>
#include <stdexcept>
#include "./pretty-printer.h"

int main() {
    {
        printf(">>> blsSignature (before blsInit)\n");
        for(size_t i=0; i<3; ++i) {
            blsSignature a;
            print_mclBnG2(a.v);
            printf("\n");
        }
    }

    if (blsInit(MCL_BLS12_381, MCLBN_COMPILED_TIME_VAR) != 0) {
        throw std::runtime_error("blsInit failed");
    }
    {
        printf(">>> blsSignature (after blsInit)\n");
        for(size_t i=0; i<3; ++i) {
            blsSignature a;
            mclBnG2_clear(&a.v);
            print_mclBnG2(a.v);
            printf("\n");
        }
    }
    return 0;
}
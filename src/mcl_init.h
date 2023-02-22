#ifndef MCL_INIT_H
#define MCL_INIT_H

#include <stdexcept>

#define BLS_ETH 1
#include "./bls/include/bls/bls384_256.h"

struct MclInit {
    MclInit() {
        if (blsInit(MCL_BLS12_381, MCLBN_COMPILED_TIME_VAR) != 0) {
            throw std::runtime_error("blsInit failed");
        }
    }
};

#endif // MCL_INIT_H

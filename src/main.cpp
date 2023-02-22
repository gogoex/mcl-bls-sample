#include <stdio.h>
#include <stdexcept>

#define BLS_ETH 1
#include "./bls/include/bls/bls384_256.h"
#include "./mcl_g1point.h"

struct SampleFixture {
    static MclG1Point p;

    SampleFixture() {
        if (blsInit(MCL_BLS12_381, MCLBN_COMPILED_TIME_VAR) != 0) {
            throw std::runtime_error("blsInit failed");
        }
        mclBn_setETHserialization(1);
    }
};

MclG1Point SampleFixture::p;

int main() {
    SampleFixture sf;
    printf("hello\n");
    return 0;
}
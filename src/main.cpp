#define BLS_ETH 1
#include <bls/bls384_256.h>
#include "./pretty-printer.h"

#include <cstdio>
#include <functional>
#include <stdexcept>

void do_test(const char* name, const std::function <void ()>& body) {
    printf(">> %s\n", name);
    for(size_t i=0; i<3; ++i) {
        body();
        printf("\n");
    }
}

static mclBnFr a1;
static mclBnG1 a2;
static blsSignature a3;

int main() {
    printf(">>>>>> before blsInit, not calling clear function\n");
    do_test("mclBnFr", []() {
        print_mclBnFr(a1);
    });
    do_test("mclBnG1", []() {
        print_mclBnG1(a2);
    });
    do_test("blsSignature (mclBnG2)", []() {
        print_mclBnG2(a3.v);
    });

    if (blsInit(MCL_BLS12_381, MCLBN_COMPILED_TIME_VAR) != 0) {
        throw std::runtime_error("blsInit failed");
    }

    printf(">>>>>> after blsInit, calling clear function\n");
    do_test("mclBnFr", []() {
        mclBnFr a;
        mclBnFr_clear(&a);
        print_mclBnFr(a);
    });
    do_test("mclBnG1", []() {
        mclBnG1 a;
        mclBnG1_clear(&a);
        print_mclBnG1(a);
    });
    do_test("blsSignature (mclBnG2)", []() {
        blsSignature a;
        mclBnG2_clear(&a.v);
        print_mclBnG2(a.v);
    });

    return 0;
}
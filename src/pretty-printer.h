#ifndef PRETTY_PRINTER_H
#define PRETTY_PRINTER_H

#define BLS_ETH 1
#include <bls/bls384_256.h>
#include <cstdio>

void print_uint64_t(const uint64_t& x) {
    for(size_t i=0; i<6; ++i) {
        printf("%02X", ((uint8_t*) &x)[i]);
    }
    printf(" ");
}

void print_mclBnFp(const mclBnFp& fp) {
    for(size_t i=0; i<6; ++i) {
        print_uint64_t(fp.d[i]);
    }
}

void print_mclBnFp2(const mclBnFp2& fp2) {
    for(size_t i=0; i<2; ++i) {
        print_mclBnFp(fp2.d[i]);
    }
}

void print_mclBnG2(const mclBnG2& p) {
    print_mclBnFp2(p.x);
    print_mclBnFp2(p.y);
    print_mclBnFp2(p.z);
}

#endif
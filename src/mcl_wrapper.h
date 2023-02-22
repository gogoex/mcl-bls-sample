#ifndef MCL_WRAPPER_H
#define MCL_WRAPPER_H

#define BLS_ETH 1
#include <bls/bls384_256.h>

struct MclWrapper
{
    MclWrapper();

    mclBnG1 m_p;

    static mclBnG1 m_g;  // generator point
};

#endif // MCL_WRAPPER_H

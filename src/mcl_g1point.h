#ifndef MCL_G1POINT_H
#define MCL_G1POINT_H

#include <stddef.h>
#include <string>
#include <vector>

#define BLS_ETH 1
#include <bls/bls384_256.h>

class MclG1Point
{
public:
    MclG1Point();

    mclBnG1 m_p;
    static mclBnG1 m_g;
};

#endif // MCL_G1POINT_H

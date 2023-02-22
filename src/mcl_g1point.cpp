#include "./mcl_g1point.h"

mclBnG1 MclG1Point::m_g;

MclG1Point::MclG1Point()
{
    mclBnG1_clear(&m_p);
}

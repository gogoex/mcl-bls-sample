#include "./mcl_wrapper.h"

mclBnG1 MclWrapper::m_g;

MclWrapper::MclWrapper()
{
    mclBnG1_clear(&m_p);
}

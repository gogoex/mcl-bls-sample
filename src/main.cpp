#include <stdio.h>
#include <stdexcept>

#define BLS_ETH 1
#include "./bls/include/bls/bls384_256.h"
#include "./mcl_g1point.h"

# define BOOST_TEST_MAIN
#include "../depends/aarch64-apple-darwin22.2.0/include/boost/test/included/unit_test.hpp"

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

BOOST_FIXTURE_TEST_SUITE(sample_tests, SampleFixture)

BOOST_AUTO_TEST_CASE(test1)
{
    BOOST_CHECK(1 == 1);
}

BOOST_AUTO_TEST_SUITE_END()
#include "./mcl_wrapper.h"

struct A {
    static MclWrapper p;
};

MclWrapper A::p;

int main() {
    A sf;
    return 0;
}
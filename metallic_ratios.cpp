#include <iostream>
#include <functional>
#include "constants.h"
using namespace std;

/* This was my attempt at a fibonacci generator */
std::function<int()> generator = [] {
    int i, a, b, c;
    i = 0; a = 0; b = 1; c = 0;
    return [=]() mutable {
        if (i < constants::sentinal) {
            c=a; a=b; b=(constants::metallicRatio*b)+c; i++;
            return c;       // Yes I start with {0, 1}
        } else { return -1; }
    };
}();

int main(int argc, char const *argv[]) {

    int ret = 0;
    while ((ret = generator()) != -1) {
        std::cout << "[]: " << ret << std::endl;
    }

    return 0;
}

// Std includes
#include <algorithm>
#include <vector>
#include <string>
// Lib includes
#include "s0ve/bin/save.h"

int main () {
    std::vector<double> data(10, 1.0);
    s0ve::bin::save(std::string("../data/save.bin"), data.data(), data.size());
}

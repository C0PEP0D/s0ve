// Std includes
#include <algorithm>
#include <vector>
#include <string>
// Lib includes
#include "s0ve/double.h"

int main () {
    std::vector<double> data(10, 1.0);
    s0ve::saveDouble(std::string("../data/save.csv"), data.data(), data.size());
}

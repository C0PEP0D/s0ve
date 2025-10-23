// Std includes
#include <vector>
#include <map>
#include <string>
// Lib includes
#include "s0ve/ascii/double.h"

int main () {
    std::map<std::string, double> data;
    data["t"] = 0.0;
    data["x"] = 1.0;
    data["y"] = 2.0;
    data["z"] = 3.0;
    s0ve::ascii::saveMapToCsvDouble(std::string("../data/save.csv"), data, std::string(","), std::string("#"));
}

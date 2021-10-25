// Std includes
#include <vector>
#include <map>
#include <string>
// Lib includes
#include "s0ve/double.h"

int main () {
    std::map<std::string, std::vector<double>> data;
    data["t"] = std::vector<double>(10, 0.0);
    data["x"] = std::vector<double>(10, 1.0);
    data["y"] = std::vector<double>(10, 2.0);
    data["z"] = std::vector<double>(10, 3.0);
    s0ve::saveMapToCsvDouble(std::string("../data/save.csv"), data, std::string(","), std::string("#"));
}

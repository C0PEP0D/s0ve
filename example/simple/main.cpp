// Std includes
#include <algorithm>
#include <vector>
#include <string>
// Lib includes
#include "s0ve/double.h"

int main () {
	const double valueToSave = 1.0;
	s0ve::saveDouble(std::string("../data/save.txt"), &valueToSave, 1);
}

#ifndef S0VE_BIN_SAVE_H
#define S0VE_BIN_SAVE_H
#pragma once

// include std
#include <fstream> // ofstream
// include modules

namespace s0ve {

namespace bin {

template<typename TypeData>
void save(const std::string& fileName, const TypeData* pData, const std::size_t n) {
	// open file
	std::ofstream file(fileName, std::ios::binary);
	// save
	file.write(reinterpret_cast<const char*>(pData), n * sizeof(TypeData));
	// close file
	file.close();
}

}

}

#endif

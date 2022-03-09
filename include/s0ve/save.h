#ifndef S0VE_SAVE_H
#define S0VE_SAVE_H
#pragma once

// include std
#include <fstream> // ofstream
#include <string> // string
// include modules

namespace s0ve {

template<typename TypeConverted>
class Converter {
	public:
		virtual std::string operator()(const TypeConverted& val) const = 0;
};

template<typename TypeConverter, typename TypeData>
void save(const std::string& fileName, const TypeData* pData, const std::size_t n, const std::string& delimiter, const TypeConverter& converter) {
	// open file
	std::ofstream file(fileName);
	// save
	for (unsigned int i = 0; i < n - 1; i++) {
		file << converter(pData[i]) << delimiter;
	}
	file << converter(pData[n - 1]);
	// close file
	file.close();
}

template<typename TypeConverter, typename TypeMap>
void saveMapToCsv(const std::string& fileName, const TypeMap& data, const std::string& delimiter, const std::string& headerPrefix, const TypeConverter& converter) {
	// open file
	std::ofstream file(fileName);
	// header
	file << headerPrefix;
	auto endIt = data.end();
	--endIt;
	for(auto it = data.begin(); it != endIt; it++) {
		file << (*it).first << delimiter;
	}
	file << (*endIt).first << "\n";
	// // data vector
	// const std::size_t n = (*data.begin()).second.size();
	// for (unsigned int i = 0; i < n - 1; i++) {
	// 	for(auto it = data.begin(); it != endIt; it++) {
	// 		file << converter((*it).second[i]) << delimiter;
	// 	}
	// 	file << converter((*endIt).second[i]) << "\n";
	// }
	// for(auto it = data.begin(); it != endIt; it++) {
	// 	file << converter((*it).second[n - 1]) << delimiter;
	// }
	// file << converter((*endIt).second[n - 1]);
	// data
	for(auto it = data.begin(); it != endIt; it++) {
		file << converter((*it).second) << delimiter;
	}
	file << converter((*endIt).second);
	// close file
	file.close();
}

}

#endif

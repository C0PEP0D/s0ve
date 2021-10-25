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
void save(const std::string& fileName, const TypeConverter& converter, const TypeData& data) {
    // open file
    std::ofstream file(fileName);
    // save
    file << converter(data);
    // close file
    file.close();
}

}

#endif

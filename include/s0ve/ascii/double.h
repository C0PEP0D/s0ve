#ifndef S0VE_ASCII_DOUBLE_H
#define S0VE_ASCII_DOUBLE_H
#pragma once

// include std
#include <string> // string, to_string
// include modules
#include "s0ve/ascii/save.h"

namespace s0ve {

namespace ascii {

class ConverterDouble : public Converter<double> {
    public:
        std::string operator()(const double& val) const override {
            return std::to_string(val);
        }
};


inline void saveDouble(const std::string& fileName, const double* pData, const std::size_t n, const std::string& delimiter = "\n") {
    save(fileName, pData, n, delimiter, ConverterDouble());
}

template<typename TypeMap>
void saveMapToCsvDouble(const std::string& fileName, const TypeMap& data, const std::string& delimiter, const std::string& headPrefix) {
    saveMapToCsv(fileName, data, delimiter, headPrefix, ConverterDouble());
}

}

}

#endif

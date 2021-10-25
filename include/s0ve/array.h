#ifndef S0VE_ARRAY_H
#define S0VE_ARRAY_H
#pragma once

// include std
#include <string> // string, stod
#include <memory> // shared_ptr
// include modules
#include "s0ve/save.h"

namespace s0ve {

template<typename TypeConverterData, typename TypeArray, typename TypeData>
class ConverterArray : public Converter<TypeArray> {
    public:
        ConverterArray(const std::shared_ptr<TypeConverterData>& p_sConverter, const std::string& p_delimiter) : sConverter(p_sConverter), delimiter(p_delimiter) {
        }
    public:
        std::string operator()(const TypeArray& val) const override {
            // Copy line
            std::string str;
            for(auto it = val.begin(); it != val.end() - 1; it++) {
                str += (*sConverter)(*it) + delimiter;
            }
            str += (*sConverter)(*(val.end() - 1));
            return str;
        }
    public:
        std::shared_ptr<TypeConverterData> sConverter;
        std::string delimiter;
};


template<typename TypeConverterData, typename TypeArray, typename TypeData>
void saveArray(const std::string& fileName, const TypeArray& data, const std::string& delimiter) {
    save(fileName, ConverterArray<TypeConverterData, TypeArray, TypeData>(std::make_shared<TypeConverterData>(), delimiter), data);
}

}

#endif

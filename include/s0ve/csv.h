#ifndef S0VE_MAP_H
#define S0VE_MAP_H
#pragma once

// include std
#include <string> // string
#include <memory> // shared_ptr
// include modules
#include "s0ve/save.h"

namespace s0ve {

template<typename TypeConverterData, template<typename, typename...> class TypeMap, typename TypeArray, typename TypeData>
class ConverterMapToCsv : public Converter<TypeMap<std::string, TypeArray>> {
    public:
        ConverterMapToCsv(const std::shared_ptr<TypeConverterData>& p_sConverter, const std::string& p_delimiter, const std::string& p_headerPrefix) : sConverter(p_sConverter), delimiter(p_delimiter), headerPrefix(p_headerPrefix) {
        }
    public:
        std::string operator()(const TypeMap<std::string, TypeArray>& data) const override {
            // Header
            std::string str = headerPrefix;
            for(auto it = data.begin(); it != data.end(); it++) {
                str += (*it).first + delimiter;
            }
            str.resize(str.size() - delimiter.size());
            str += "\n";
            // Data
            for(std::size_t n = 0; n < (*data.begin()).second.size(); n++) {
                for(auto it = data.begin(); it != data.end(); it++) {
                    str += (*sConverter)(*((*it).second.begin() + n)) + delimiter;
                }
                str.resize(str.size() - delimiter.size());
                str += "\n";
            }
            return str;
        }
    public:
        std::shared_ptr<TypeConverterData> sConverter;
        std::string delimiter;
        std::string headerPrefix;
};


template<typename TypeConverterData, template<typename, typename...> class TypeMap, typename TypeArray, typename TypeData>
void saveMapToCsv(const std::string& fileName, const TypeMap<std::string, TypeArray>& data, const std::string& delimiter, const std::string& headerPrefix) {
    save(fileName, ConverterMapToCsv<TypeConverterData, TypeMap, TypeArray, TypeData>(std::make_shared<TypeConverterData>(), delimiter, headerPrefix), data);
}

}

#endif

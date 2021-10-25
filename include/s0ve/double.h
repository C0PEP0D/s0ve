#ifndef S0VE_DOUBLE_H
#define S0VE_DOUBLE_H
#pragma once

// include std
#include <string> // string, to_string
// include modules
#include "s0ve/save.h"
#include "s0ve/array.h"
#include "s0ve/csv.h"

namespace s0ve {

class ConverterDouble : public Converter<double> {
    public:
        std::string operator()(const double& val) const override {
            return std::to_string(val);
        }
};


void saveDouble(const std::string& fileName, const double& data) {
    save(fileName, ConverterDouble(), data);
}

template<typename TypeArray>
void saveArrayDouble(const std::string& fileName, const TypeArray& data, const std::string& delimiter) {
    saveArray<ConverterDouble, TypeArray, double>(fileName, data, delimiter);
}

template<template<typename, typename...> class TypeMap, typename TypeArray>
void saveMapToCsvDouble(const std::string& fileName, const TypeMap<std::string, TypeArray>& data, const std::string& delimiter, const std::string& headPrefix) {
    saveMapToCsv<ConverterDouble, TypeMap, TypeArray, double>(fileName, data, delimiter, headPrefix);
}

}

#endif

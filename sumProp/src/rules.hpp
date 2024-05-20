#pragma once

#include <map>
#include <base.hpp>


class Rules{
    std::map<int, WordConstructor> rules;
    
public:
    Rules();

    bool check_num(const short& num);

    std::wstring convert_num(const short& num, const wchar_t& sCase, const wchar_t& sGender);
    std::wstring convert_rank(short last_num, const char& rank, const wchar_t& sCase);
    std::wstring convert_zero(const wchar_t& sCase, const wchar_t& sGender);
};
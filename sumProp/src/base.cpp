#include "base.hpp"



std::wstring IWordConstructor::operator()(const wchar_t& sCase, const wchar_t& sGender){
    return this->result;
}


ByWordConstructor::ByWordConstructor(const wchar_t* sWord){
    this->result = sWord;
}


std::wstring ByCaseConstructor::operator()(const wchar_t& sCase, const wchar_t& sGender){
    return this->init()[sCase];
}


ByCaseAndGenderConstructor::ByCaseAndGenderConstructor(const wchar_t& sGender): preset_gender(sGender) {}

std::wstring ByCaseAndGenderConstructor::operator()(const wchar_t& sCase, const wchar_t& sGender){
    if (this->preset_gender)
        return this->init()[this->preset_gender][sCase];
    return this->init()[sGender][sCase];
}


WordConstructor::WordConstructor(parts_vec& parts){ 
    for (auto& part: parts){
        this->parts.emplace_back(std::move(part));
    }
}

std::wstring WordConstructor::operator()(const wchar_t& sCase, const wchar_t& sGender){
    this->result.clear();
    for(auto& part: this->parts){
        this->result += part->operator()(sCase, sGender);
    }
    return this->result;
}

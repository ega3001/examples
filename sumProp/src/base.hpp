#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>


class IWordConstructor{
protected:
    std::wstring result = L"";
public:
    virtual std::wstring operator()(const wchar_t& sCase, const wchar_t& sGender);
};


using case_map = std::map<const wchar_t, std::wstring>;
using case_gender_map = std::map<const wchar_t, case_map>;
using parts_vec = std::vector<std::unique_ptr<IWordConstructor>>;


class ByWordConstructor: public IWordConstructor{
public:
    ByWordConstructor(const wchar_t* sWord);
};


class ByCaseConstructor: public IWordConstructor{
protected:
    virtual case_map init() = 0;
public:
    std::wstring operator()(const wchar_t& sCase, const wchar_t& sGender) override;
};


class ByCaseAndGenderConstructor: public IWordConstructor{
protected:
    wchar_t preset_gender;
    virtual case_gender_map init() = 0;
public:
    ByCaseAndGenderConstructor(const wchar_t& sGender = L'\0');
    std::wstring operator()(const wchar_t& sCase, const wchar_t& sGender) override;
};


class WordConstructor: protected IWordConstructor{
    parts_vec parts;
public:
    WordConstructor(parts_vec& parts);
    std::wstring operator()(const wchar_t& sCase, const wchar_t& sGender) override;
};
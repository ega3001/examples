#include <map>
#include <stdexcept>
#include <rules.hpp>
#include <numbers.hpp>


Rules::Rules(){
    parts_vec vec{};
    // 1
    vec.clear();
    vec.emplace_back(std::make_unique<OneConstructor>());
    this->rules.emplace(1, WordConstructor(vec));
    // 2
    vec.clear();
    vec.emplace_back(std::make_unique<TwoConstructor>());
    this->rules.emplace(2, WordConstructor(vec));
    // 3
    vec.clear();
    vec.emplace_back(std::make_unique<ThreeConstructor>());
    this->rules.emplace(3, WordConstructor(vec));
    // 4
    vec.clear();
    vec.emplace_back(std::make_unique<FourConstructor>());
    this->rules.emplace(4, WordConstructor(vec));
    // 5
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"пят"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(5, WordConstructor(vec));
    // 6
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"шест"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(6, WordConstructor(vec));
    // 7
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"сем"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(7, WordConstructor(vec));
    // 8
    vec.clear();
    vec.emplace_back(std::make_unique<EightConstructor>());
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(8, WordConstructor(vec));
    // 9
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"девят"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(9, WordConstructor(vec));
    // 10
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"десят"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(10, WordConstructor(vec));
    // 11
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"одиннадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(11, WordConstructor(vec));
    // 12
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"двенадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(12, WordConstructor(vec));
    // 13
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"тринадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(13, WordConstructor(vec));
    // 14
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"четырнадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(14, WordConstructor(vec));
    // 15
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"пятнадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(15, WordConstructor(vec));
    // 16
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"шестнадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(16, WordConstructor(vec));
    // 17
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"семнадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(17, WordConstructor(vec));
    // 18
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"восемнадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(18, WordConstructor(vec));
    // 19
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"девятнадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(19, WordConstructor(vec));
    // 20
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"двадцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(20, WordConstructor(vec));
    // 30
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"тридцат"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    this->rules.emplace(30, WordConstructor(vec));
    // 40
    vec.clear();
    vec.emplace_back(std::make_unique<FourtyConstructor>());
    this->rules.emplace(40, WordConstructor(vec));
    // 50
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"пят"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"десят"));
    vec.emplace_back(std::make_unique<FiftyToEightyEndConstructor>());
    this->rules.emplace(50, WordConstructor(vec));
    // 60
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"шест"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"десят"));
    vec.emplace_back(std::make_unique<FiftyToEightyEndConstructor>());
    this->rules.emplace(60, WordConstructor(vec));
    // 70
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"сем"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"десят"));
    vec.emplace_back(std::make_unique<FiftyToEightyEndConstructor>());
    this->rules.emplace(70, WordConstructor(vec));
    // 80
    vec.clear();
    vec.emplace_back(std::make_unique<EightConstructor>());
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"десят"));
    vec.emplace_back(std::make_unique<FiftyToEightyEndConstructor>());
    this->rules.emplace(80, WordConstructor(vec));
    // 90
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"девяно"));
    vec.emplace_back(std::make_unique<HundredConstructor>());
    this->rules.emplace(90, WordConstructor(vec));
    // 100
    vec.clear();
    vec.emplace_back(std::make_unique<HundredConstructor>());
    this->rules.emplace(100, WordConstructor(vec));
    // 200
    vec.clear();
    vec.emplace_back(std::make_unique<TwoConstructor>(L'Ж'));
    vec.emplace_back(std::make_unique<HundredsEndConstructor>(L'2'));
    this->rules.emplace(200, WordConstructor(vec));
    // 300
    vec.clear();
    vec.emplace_back(std::make_unique<ThreeConstructor>());
    vec.emplace_back(std::make_unique<HundredsEndConstructor>(L'3'));
    this->rules.emplace(300, WordConstructor(vec));
    // 400
    vec.clear();
    vec.emplace_back(std::make_unique<FourConstructor>());
    vec.emplace_back(std::make_unique<HundredsEndConstructor>(L'3'));
    this->rules.emplace(400, WordConstructor(vec));
    // 500
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"пят"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<HundredsEndConstructor>(L'5'));
    this->rules.emplace(500, WordConstructor(vec));
    // 600
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"шест"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<HundredsEndConstructor>(L'5'));
    this->rules.emplace(600, WordConstructor(vec));
    // 700
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"сем"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<HundredsEndConstructor>(L'5'));
    this->rules.emplace(700, WordConstructor(vec));
    // 800
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"восем"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<HundredsEndConstructor>(L'5'));
    this->rules.emplace(800, WordConstructor(vec));
    // 900
    vec.clear();
    vec.emplace_back(std::make_unique<ByWordConstructor>(L"девят"));
    vec.emplace_back(std::make_unique<FiveToTwentyAndThirtyEndConstructor>());
    vec.emplace_back(std::make_unique<HundredsEndConstructor>(L'5'));
    this->rules.emplace(900, WordConstructor(vec));
}

bool Rules::check_num(const short& num){
    auto iter = this->rules.find(num);
    if (iter == this->rules.end())
        return false;
    else
        return true;
}

std::wstring Rules::convert_num(const short& num, const wchar_t& sCase, const wchar_t& sGender){
    return this->rules.find(num)->second(sCase, sGender);
}

std::wstring Rules::convert_rank(short last_num, const char& rank, const wchar_t& sCase){
    wchar_t sGender = L'\0';
    if (last_num > 4)
        sGender = L'5';
    else if (last_num > 1)
        sGender = L'2';
    else
        sGender = L'1';
    switch(rank){
        case 't': return ThousandConstructor()(sCase, sGender);
        case 'm': return MillionConstructor()(sCase, sGender);
        case 'b': return BillionConstructor()(sCase, sGender);
        default: throw std::invalid_argument("Cannot convert rank!");
    };
}

std::wstring Rules::convert_zero(const wchar_t& sCase, const wchar_t& sGender){
    return ZeroConstructor()(sCase, sGender);
}
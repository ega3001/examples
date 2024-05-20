#include <string>
#include <iostream>
#include "convert.hpp"


int main(){
    setlocale(LC_CTYPE,"Russian");
    std::wcout << sumProp(31, L"М", L"Р") << std::endl;
    std::wcout << sumProp(22, L"С", L"Т") << std::endl;
    std::wcout << sumProp(154323, L"М", L"И") << std::endl;
    std::wcout << sumProp(154323, L"М", L"Т") << std::endl;
    std::wcout << sumProp(100456001321, L"Ж", L"Т") << std::endl;
    return 0;
}
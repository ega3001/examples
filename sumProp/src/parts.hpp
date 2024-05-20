#pragma once

#include <string>


class Parted{
    std::wstring result_;

public:
    Parted();
    Parted(std::wstring str);

    Parted operator+=(const Parted& right);
    Parted operator+(const Parted& right);

    bool is_empty();
    std::wstring to_str();
};
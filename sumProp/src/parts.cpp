#include <parts.hpp>


Parted::Parted(): result_() {}

Parted::Parted(std::wstring str): result_(str) {}

Parted Parted::operator+=(const Parted& right){
    if (!right.result_.empty()){
        if (!this->result_.empty())
            this->result_ += L" " + right.result_;
        else
            this->result_ = right.result_;
    }
    return *this;
}

Parted Parted::operator+(const Parted& right){
    if (!right.result_.empty()){
        if (!this->result_.empty())
            return Parted(this->result_ + L" " + right.result_);
        else
            return right;
    }
    return *this;
}

bool Parted::is_empty(){
    return this->result_.empty();
}
std::wstring Parted::to_str(){
    return this->result_;
}
#include "twelve.h"
#include <stdexcept>
#include <string>
#include <iostream>

namespace twelve {
    unsigned char Twelve::CharToDigit(char c) {
        if (c >= '0' && c <= '9') {
            return static_cast<unsigned char>(c - '0');
        } else if (c == 'A') {
            return 10;
        } else if (c == 'B') {
            return 11;
        } else {
            throw std::invalid_argument("Digit must be 0-B");
        }
    }

    Twelve::Twelve(): arr_(vector::Vector()) {};

    Twelve::Twelve(const size_t& n, unsigned char t): arr_(vector::Vector(n, t)) {};

    Twelve::Twelve(const std::initializer_list<unsigned char>& value) : arr_() {
        if (value.size() == 0) {
            throw std::invalid_argument("Initializer list can't be empty");
        }
        for (unsigned char i : value) {
            if (i > 11) {
                throw std::invalid_argument("Digit must be 0-11");
            }
            arr_.PushBack(i);
        }
        while (arr_.Size() > 1 && arr_.Back() == 0) {
            arr_.PopBack();
        }
    }

    Twelve::Twelve(const std::string& s) {
        if (s.empty()) {
            arr_.PushBack(0);
            return;
        }
        for (int i = static_cast<int>(s.size()); i > 0; --i) {
            arr_.PushBack(CharToDigit(s[i - 1]));
        }
        while (arr_.Size() > 1 && arr_.Back() == 0) {
            arr_.PopBack();
        }
    }

    Twelve::Twelve(const Twelve& other) noexcept: arr_(other.arr_) {}

    Twelve::Twelve(Twelve&& other): arr_(std::move(other.arr_)) {};

    Twelve::~Twelve() noexcept {
        arr_.Clear();
    }

    Twelve Twelve::Add(const Twelve& number1, const Twelve& number2) {
        Twelve answ;
        answ.arr_.Clear();
        size_t max_length = number1.arr_.Size() > number2.arr_.Size() ? number1.arr_.Size() : number2.arr_.Size();
        size_t cur = 0;
        size_t n;
        for(size_t i = 0; i < max_length; ++i) {
            size_t a = (i < number1.arr_.Size()) ? number1.arr_.Get(i) : 0;
            size_t b = (i < number2.arr_.Size()) ? number2.arr_.Get(i) : 0;
            n = a + b + cur;
            answ.arr_.PushBack(n % 12);
            cur = n / 12;
        }
        if (cur != 0) {
            answ.arr_.PushBack(1);
        }
        return answ;
    }

    Twelve Twelve::Substract(const Twelve& number1, const Twelve& number2) {
        if (number1.Less(number2)) {
            throw std::invalid_argument("First must be >= to second");
        }
        if(number1.Equals(number2)) {
            return Twelve{0};
        }
        Twelve answ;
        int bor = 0;
        size_t max_size = number1.arr_.Size();
        for  (size_t i = 0; i < max_size; ++i) {
            int digit_a = number1.arr_.Get(i);
            int a = (i < number2.arr_.Size()) ? number2.arr_.Get(i) : 0;
            digit_a -= bor;
            bor = 0;
            if (digit_a < a) {
                digit_a += 12;
                bor = 1;
            }
            answ.arr_.PushBack(static_cast<unsigned char>(digit_a - a));
        }
        while (answ.arr_.Size() > 1 && answ.arr_.Back() == 0) {
            answ.arr_.PopBack();
        }
        return answ;
    }

    bool Twelve::Equals(const Twelve& other) const {
        if (arr_.Size() != other.arr_.Size()) {
            return false;
        }
        for (size_t i = 0; i < arr_.Size(); ++i) {
            if (arr_.Get(i) != other.arr_.Get(i)) {
                return false;
            }
        }
        return true;
    }

    bool Twelve::Greaters(const Twelve& other) const {
        if (arr_.Size() != other.arr_.Size()) {
            return arr_.Size() > other.arr_.Size();
        }
        for (int i = arr_.Size(); i > 0; --i) {
            if (arr_.Get(i -1 ) < other.arr_.Get(i - 1)) {
                return false;
            }
            if (arr_.Get(i - 1) > other.arr_.Get(i - 1)) {
                return true;
            }
        }
        return false;
    }

    bool Twelve::Less(const Twelve& other) const {
        return !Greaters(other) && !Equals(other);
    }

    void Twelve::Print(std::ostream& os) const {
        if (arr_.Size() == 0) {
            os << '0';
            return;
        }
        for (int i = arr_.Size(); i > 0; --i) {
            unsigned char num = arr_.Get(i - 1);
            if (num < 10) {
                os << static_cast<char>('0' + num);
            } else if ( num == 10) {
                os << 'A';
            } else {
                os << 'B';
            }
        }
    }

}
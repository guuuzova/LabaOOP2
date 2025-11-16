#pragma once

#include <iostream>
#include <string>
#include "vector.h"

namespace twelve {
class Twelve {
  public:
    Twelve();
    Twelve(const size_t& size, unsigned char t = 0);
    Twelve(const std::initializer_list<unsigned char>& initialvalue);
    Twelve(const std::string& s);

    Twelve(const Twelve& other) noexcept;
    Twelve(Twelve&& other);
    ~Twelve() noexcept;

    static Twelve Add(const Twelve& first, const Twelve& second);
    static Twelve Substract(const Twelve& first, const Twelve& second);
    
    bool Equals(const Twelve& other) const;
    bool Greaters(const Twelve& other) const;
    bool Less(const Twelve& other) const;

    void Print(std::ostream& os) const; 
  private:
    unsigned char CharToDigit(char c);
    vector::Vector arr_;
};
}
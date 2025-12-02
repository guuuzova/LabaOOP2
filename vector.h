#pragma once

#include <initializer_list>
#include <utility>
#include <cstdint>
#include <cstddef>


namespace vector{
const int8_t DEFAULT_CAP = 10;
class Vector {
public:
    Vector();
    Vector(size_t count, unsigned char value);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    Vector(const std::initializer_list<unsigned char> init);

    unsigned char& Get(size_t pos);
    const unsigned char& Get(size_t pos) const;
    unsigned char& Front();
    const unsigned char& Front() const noexcept;
    unsigned char& Back();
    const unsigned char& Back() const noexcept;
    void Reserve(size_t new_cap);
    bool IsEmpty() const noexcept;
    size_t Size() const noexcept;
    size_t Capacity() const noexcept;
    void PushBack(unsigned char value);
    void PopBack();
    void Clear() noexcept;
    void Swap(Vector& v) noexcept;
    ~Vector();

private:
    size_t sz_;
    size_t cap_;
    unsigned char* arr_;
};
}
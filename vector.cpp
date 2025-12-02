#include <vector.h>
#include <cstring>
#include <utility>

namespace vector {
    Vector::Vector(): sz_(0), cap_(0), arr_(nullptr) {}

    Vector::Vector(size_t count, unsigned char value) : arr_(nullptr), sz_(0), cap_(0) {
        for (size_t i = 0; i < count; ++i) {
            PushBack(value);
        }
    }

    Vector::Vector(const Vector& other) : arr_(nullptr), sz_(0), cap_(0) {
        for (size_t i = 0; i < other.sz_; ++i) {
            PushBack(other.arr_[i]);
        }
    }

    Vector::Vector(Vector&& other) noexcept : sz_(other.sz_), cap_(other.cap_), arr_(other.arr_) {
        other.arr_ = nullptr;
        other.sz_ = 0;
        other.cap_ = 0;
    }

    Vector::Vector(std::initializer_list<unsigned char> init) : arr_(nullptr), sz_(0), cap_(0) {
        for (const auto& x : init) {
            PushBack(x);
        }
    }

    unsigned char& Vector::Get(size_t pos) {
        return arr_[pos];
    }

    const unsigned char& Vector::Get(size_t pos) const {
        return arr_[pos];
    }

    unsigned char& Vector::Front() {
        return arr_[0];
    }

    const unsigned char& Vector::Front() const noexcept {
        return arr_[0];
    }

    unsigned char& Vector::Back() {
        return arr_[sz_ - 1];
    }

    const unsigned char& Vector::Back() const noexcept {
        return arr_[sz_ - 1];
    }

    void Vector::Reserve(size_t new_cap) {
        if (new_cap <= cap_) {
            return;
        }
        unsigned char* new_arr = new unsigned char[new_cap];
        for (size_t i = 0; i < sz_; i++) {
            new_arr[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr;
        cap_ = new_cap;
    }

    bool Vector::IsEmpty() const noexcept {
        return sz_ == 0;
    }

    size_t Vector::Size() const noexcept {
        return sz_;
    }

    size_t Vector::Capacity() const noexcept {
        return cap_;
    }

    void Vector::PushBack(unsigned char value) {
        if (sz_ >= cap_) {
            Reserve(cap_ == 0 ? DEFAULT_CAP : cap_ * 2);
        }
        arr_[sz_++] = value;
    }

    void Vector::PopBack() {
        if (sz_ > 0) {
            --sz_;
        }
    }

    void Vector::Clear() noexcept {
        delete[] arr_;
        arr_ = nullptr;
        sz_ = 0;
        cap_ = 0;
    }

    void Vector::Swap(Vector& other) noexcept {
        std::swap(arr_, other.arr_);
        std::swap(sz_, other.sz_);
        std::swap(cap_, other.cap_);
    }
    
    Vector::~Vector() {
        delete[] arr_;
    }
}
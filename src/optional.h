#pragma once

#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <utility>

template <typename T>
class MyOptional {
private:
    alignas(T) unsigned char data_[sizeof(T)];
    bool has_value_ = false;

public:
    MyOptional() noexcept : has_value_(false) {}

    MyOptional(const T& value) : has_value_(true) {
        new (data_) T(value);
    }

    MyOptional(const MyOptional& other) : has_value_(other.has_value_) {
        if (has_value_) {
            new (data_) T(*reinterpret_cast<const T*>(other.data_));
        }
    }

    ~MyOptional() {
        if (has_value_) {
            reinterpret_cast<T*>(data_)->~T();
        }
    }

    bool has_value() const noexcept { return has_value_; }

    T& value() & {
        if (!has_value_) throw std::runtime_error("No value!");
        return *reinterpret_cast<T*>(data_);
    }

    const T& value() const & {
        if (!has_value_) throw std::runtime_error("No value!");
        return *reinterpret_cast<const T*>(data_);
    }
};
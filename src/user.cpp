#include "user.h"
#include <utility>

// Конструктор
User::User(int id, std::string name, std::string bio) 
    : id_(id), name_(std::move(name)), bio_(std::move(bio)) {
}

// Сеттеры
void User::setBio(const std::string& bio) {
    bio_ = bio; // Здесь bio_ - это поле класса, bio - аргумент функции
}

void User::setName(const std::string& name) {
    name_ = name; // Здесь name_ - это поле класса, name - аргумент функции
}
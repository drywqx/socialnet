#include "user.h"
#include <utility>

User::User(int id, std::string name, std::string bio) 
    : id_(id), name_(std::move(name)), bio_(std::move(bio)) {
}

void User::setBio(const std::string& bio) {
    bio_ = bio;
}

void User::setName(const std::string& name) {
    name_ = name;
}
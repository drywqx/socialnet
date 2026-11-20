// user.h
#pragma once
#include <string>
#include "optional.h"

class User {
private:
    int id_;
    std::string name_;
    std::string bio_;

public:
    User(int id, std::string name, std::string bio = "");

    int getId() const { return id_; }
    const std::string& getName() const { return name_; }
    const std::string& getBio() const { return bio_; }

    void setBio(const std::string& bio);
    void setName(const std::string& name);
};
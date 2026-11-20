#include <iostream>
#include "optional.h"
#include "user.h"

int main() {
    User alice(1, "Alice", "Love C++");

    MyOptional<User> opt_user(alice);

    if (opt_user.has_value()) {
        std::cout << "Found user: " << opt_user.value().getName() << "\n";
    }

    MyOptional<User> empty_opt;

    try {
        empty_opt.value();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
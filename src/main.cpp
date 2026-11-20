// main.cpp
#include <iostream>
#include "optional.h"
#include "user.h"

int main() {
    // Создаем пользователя
    User alice(1, "Alice", "Love C++");

    // Кладем его в Optional
    MyOptional<User> opt_user(alice);

    if (opt_user.has_value()) {
        std::cout << "Found user: " << opt_user.value().getName() << "\n";
    }

    // Создаем пустой Optional
    MyOptional<User> empty_opt;

    // Пытаемся достать значение (должно выбросить исключение)
    try {
        empty_opt.value();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
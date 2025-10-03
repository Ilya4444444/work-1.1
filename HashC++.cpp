#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, double> prices = {
        {"Apple", 0.99},
        {"Bread", 1.50},
        {"Milk", 0.89}
    };
    // Добавляем новый товар
    prices["Cheese"] = 2.50;

    // Выводим все товары и их цены
    for (const auto& [item, price] : prices) {
        std::cout << item << ": $" << price << std::endl;
    }
    return 0;
}

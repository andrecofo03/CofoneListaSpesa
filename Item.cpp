//
// Created by cofon on 14/12/2024.
//

#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& category, int quantity)
    : name(name), category(category), quantity(quantity) {}

void Item::print() const {
    std::cout << "- " << name << " (" << category << "): " << quantity << std::endl;
}
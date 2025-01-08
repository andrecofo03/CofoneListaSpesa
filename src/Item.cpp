//
// Created by cofon on 14/12/2024.
//

#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& category, int quantity, bool bought)
    : name(name), category(category), quantity(quantity), bought(false) {
    if (quantity < 1) {
        throw std::invalid_argument("La quantità deve essere almeno 1.");
    }
    this->quantity=quantity;
}

void Item::print() const {
    std::cout << "- " << name << " (" << category << "): " << quantity << std::endl;
    if (bought) {
        std::cout << " [Acquistato]";
    }
    std::cout << std::endl;
}


void Item::setBought(bool bought) {
    this->bought = bought;
}

bool Item::isBought() const {
    return bought;
}



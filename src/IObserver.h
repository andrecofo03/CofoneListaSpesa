//
// Created by cofon on 14/12/2024.
//

#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <vector>
#include "Item.h"
#include <string>

class IObserver {
    public:
        virtual ~IObserver() = default;

        virtual void update(const std::string& listName, const std::string& operation, const Item& item, const std::vector<Item>& items) = 0;
};
#endif //IOBSERVER_H

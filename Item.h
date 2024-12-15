
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    friend class ShoppingList;
private:
    std::string name;
    std::string category;
    int quantity;
public:
    Item(const std::string &name, const std::string &category, int quantity);
    void print() const;
};



#endif //ITEM_H

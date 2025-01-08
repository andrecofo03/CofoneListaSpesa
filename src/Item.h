
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    friend class ShoppingList;

    std::string name;
    std::string category;
    int quantity;
    bool bought;

public:
    Item(const std::string &name, const std::string &category, int quantity, bool bought);
    void print() const;

    int getQuantity() const;
    void setQuantity(int quantity);
    int getBought() const;
    void setBought(bool bought);
    bool isBought() const;


};



#endif //ITEM_H

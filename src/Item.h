
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    std::string name;
    std::string category;
    int quantity;
    bool bought;

public:
    Item(const std::string &name, const std::string &category, int quantity, bool bought);
    void print() const;

    std::string getName() const;
    std::string getCategory() const;
    int getQuantity() const;
    bool isBought() const;

    void setBought(bool bought);
};



#endif //ITEM_H

//
// Created by cofon on 14/12/2024.
//

#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <set>
#include "IObserver.h"
#include "ISubject.h"
#include <vector>
#include <string>
#include "Item.h"

class ShoppingList : public ISubject {
    std::string name;
    std::string owner;
    std::vector<Item> items;
    std::vector<IObserver*> observers;
    std::set<std::string> sharedUsers;

public:
    ShoppingList(const std::string& name, const std::string& owner);

    std::string getOwner();

    void addItem(const std::string& username, const Item& item);
    void updateItem(const std::string& username, const Item& item);
    void removeItem(const std::string& username, const std::string& itemName);

    void addObserver(IObserver* observer) override;
    void removeObserver(IObserver* observer) override;
    void notifyObservers(const std::string& operation, const Item& item) override;

    void shareWith(const std::string& username);
    void revokeAccess(const std::string& username);
    bool isSharedWith(const std::string& username) const;
    bool canModify(const std::string& username) const;

    void searchByCategory(const std::string& category) const;
    void searchMissingItems() const;
    void buyItem(const std::string& username, const std::string& itemName, int quantity);
    void showRemainingQuantities() const;

    void printList() const;
};


#endif //SHOPPINGLIST_H

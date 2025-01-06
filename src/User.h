//
// Created by cofon on 14/12/2024.
//

#ifndef USER_H
#define USER_H

#include <map>
#include <memory>
#include "IObserver.h"
#include "ShoppingList.h"

class User final : public IObserver {
        std::string username;
        std::map<std::string, std::shared_ptr<ShoppingList>> lists;
public:
        explicit User(const std::string& username);
        void update(const std::string& listName, const std::string& operation, const Item& item) override;
        void createList(const std::string& listName);
        void shareListWith(const std::string& listName, User& otherUser);
        void revokeListAccess(const std::string& listName, User& otherUser);
        void addItemToList(const std::string& listName, const Item& item);
        void updateItemInList(const std::string& listName, const Item& item);
};


#endif //USER_H

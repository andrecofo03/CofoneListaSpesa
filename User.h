//
// Created by cofon on 14/12/2024.
//

#ifndef USER_H
#define USER_H

#include <map>
#include <memory>
#include <string>
#include "IObserver.h"
#include "ShoppingList.h"


class User : public IObserver{
    private:
        std::string username;
        std::map<std::string, std::shared_ptr<ShoppingList>> lists;
    public:
        User(const std::string &username);
        void createList(const std::string &listName);
        void shareListWith(std::string &listName, User &otherUser);
        void revokeListFrom(std::string &listName, User &otherUser);
};



#endif //USER_H

//
// Created by cofon on 14/12/2024.
//

#include "User.h"
#include <iostream>
#include "ShoppingList.h"

User::User(const std::string& username) : username(username) {}

//chiamato quando un observer riceve una notifica
void User::update(const std::string& listName, const std::string& operation, const Item& item, const std::vector<Item>& items) {
    std::cout << "Utente " << username << " - Lista aggiornata: " << listName << std::endl;
    std::cout << "Operazione: " << operation << " - ";
    item.print();
    std::cout << std::endl;
}

// Crea una nuova lista
void User::createList(const std::string& listName) {
    if (lists.find(listName) == lists.end()) {
        lists[listName] = std::make_shared<ShoppingList>(listName, username);
        lists[listName]->addObserver(this);
        std::cout << "Utente " << username << " ha creato la lista: " << listName << std::endl;
    } else {
        std::cout << "La lista " << listName << " esiste già!" << std::endl;
    }
}

// Condivide una lista con un altro utente
void User::shareListWith(const std::string& listName, User& otherUser) {
    if (lists.find(listName) != lists.end()) {
        lists[listName]->shareWith(otherUser.username);
        otherUser.lists[listName] = lists[listName];
    } else {
        std::cout << "La lista " << listName << " non esiste!" << std::endl;
    }
}

// Revoca l'accesso a un utente ad una lista
void User::revokeListAccess(const std::string& listName, User& otherUser) {
    if (lists.find(listName) != lists.end()) {
        lists[listName]->revokeAccess(otherUser.username);
        otherUser.lists.erase(listName);
        std::cout << "Accesso alla lista \"" << listName << "\" revocato a " << otherUser.username << ".\n";
    } else {
        std::cout << "La lista \"" << listName << "\" non esiste o non è gestita da te.\n";
    }
}






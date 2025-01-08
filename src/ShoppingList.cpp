//
// Created by cofon on 14/12/2024.
//

#include "ShoppingList.h"
#include <iostream>
#include <algorithm>
#include "Item.h"



ShoppingList::ShoppingList(const std::string& name, const std::string& owner)
    : name(name), owner(owner) {}

// Aggiunge un nuovo elemento o aggiorna un elemento esistente nella lista
void ShoppingList::addItem(const std::string& username, const Item& item) {
        if (!canModify(username)) {
            std::cout <<  username << " non ha i permessi per modificare la lista \"" << name << "\".\n";
            throw std::runtime_error("Accesso negato");
        }

    auto it = std::find_if(items.begin(), items.end(),[&item](const Item& i) {
        return i.name == item.name;
    });

    if (it != items.end()) {
        std::cout << "L'elemento \"" << item.name << "\" è già presente nella lista \"" << name << "\" con quantità " << it->quantity << ".\n";
        std::cout << "Aggiorno la quantità di \"" << item.name << "\" a " << it->quantity + item.quantity << ".\n";
        it->quantity += item.quantity;
            if (it->quantity <= 0) {
                removeItem(username, it->name);
            } else {
                notifyObservers("Updated", *it);
            }
    } else {
        items.push_back(item);
        notifyObservers("Added", item);
    }
    printList();
}

// Aggiorna un elemento esistente
void ShoppingList::updateItem(const std::string& username, const Item& item) {
    if (!canModify(username)) {
        std::cout << "Accesso negato: " << username << " non ha i permessi per modificare la lista \"" << name << "\".\n";
        return;
    }

    auto it = std::find_if(items.begin(), items.end(),
                           [&item](const Item& i) { return i.name == item.name; });

    if (it != items.end()) {
        it->quantity = item.quantity;
        if (it->quantity <= 0) {
            removeItem(username, it->name);
        } else {
            notifyObservers("Updated", *it);
        }
    } else {
        std::cout << "L'elemento \"" << item.name << "\" non esiste nella lista \"" << name << "\".\n";
        std::cout << "Vuoi aggiungerlo? (s/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 's' || choice == 'S') {
            if (item.quantity > 0) {
                items.push_back(item);
                notifyObservers("Added", item);
            } else {
                std::cout << "Errore: la quantità di un nuovo elemento deve essere almeno 1.\n";
            }
        } else {
            std::cout << "Operazione annullata.\n";
        }
    }
    printList();
}

// Rimuove un elemento dalla lista
void ShoppingList::removeItem(const std::string& username, const std::string& itemName) {
    if (!canModify(username)) {
        std::cout << "Accesso negato: " << username << " non ha i permessi per modificare la lista \"" << name << "\".\n";
        return;
    }

    auto it = std::find_if(items.begin(), items.end(),
                           [&itemName](const Item& item) { return item.name == itemName; });

    if (it != items.end()) {
        Item removed = *it;
        items.erase(it);
        notifyObservers("Removed", removed);
    }
}

// Aggiunge un observer
void ShoppingList::addObserver(IObserver* observer) {
    observers.push_back(observer);
}

// Rimuove un observer
void ShoppingList::removeObserver(IObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

// Notifica gli observer delle modifiche
void ShoppingList::notifyObservers(const std::string& operation, const Item& item) {
    for (auto observer : observers) {
        observer->update(name, operation, item);
    }
}

// Condivide la lista con un altro utente
void ShoppingList::shareWith(const std::string& username) {
    sharedUsers.insert(username);
    std::cout << "Lista \"" << name << "\" condivisa con " << username << ".\n";
}

// Revoca l'accesso a un utente
void ShoppingList::revokeAccess(const std::string& username) {
    if (username == owner) {
        std::cout << "Richiesta rifiutata: non puoi revocare l'accesso al proprietario della lista." << std::endl;
        return;
    }
    if (sharedUsers.erase(username)) {
        std::cout << "Accesso revocato a " << username << " per la lista \"" << name << "\"." << std::endl;
    } else {
        std::cout << username << " non ha accesso alla lista \"" << name << "\"." << std::endl;
    }
}

// Verifica se la lista è condivisa con un utente
bool ShoppingList::isSharedWith(const std::string& username) const {
    return sharedUsers.find(username) != sharedUsers.end();
}

// Verifica se un utente può modificare la lista
bool ShoppingList::canModify(const std::string& username) const {
    return username == owner || isSharedWith(username);
}

// Stampa gli elementi nella lista
void ShoppingList::printList() const {
    std::cout << "Lista \"" << name << "\" aggiornata:" << std::endl;
    std::cout << "Proprietario: " << owner << std::endl;

    for (const auto& user : sharedUsers) {
        std::cout << "Lista \"" << user << "\" aggiornata:" << std::endl;
    }

    if (items.empty()) {
        std::cout << "La lista è vuota." << std::endl;
    } else {
        for (const auto& item : items) {
            item.print();
        }
    }
    std::cout << std::endl;
}

void ShoppingList::searchByCategory(const std::string& category) const {
    std::cout << "Elementi della categoria \"" << category << "\":" << std::endl;
    for (const auto& item : items) {
        if (item.category == category) {
            item.print();
        }
    }
}

void ShoppingList::searchMissingItems() const {
    std::cout << "Elementi non ancora acquistati :" << std::endl;
    for (const auto& item : items) {
        if (!item.isBought()) {
            item.print();
        }
    }
}

void ShoppingList::buyItem(const std::string& username, const std::string& itemName, int quantity) {
    if (!canModify(username)) {
        std::cout << "Accesso negato: " << username << " non ha i permessi per modificare la lista \"" << name << "\".\n";
        return;
    }

    auto it = std::find_if(items.begin(), items.end(), [&itemName](const Item& item) {
        return item.name == itemName;
    });

    if (it != items.end()) {
        if (quantity <= 0) {
            std::cout << "Errore: la quantita' di acquisto deve essere almeno 1.\n";
        } else if (quantity > it->quantity) {
            std::cout << "Errore: non puoi acquistare piu' della quantita' che hai inserito nella lista \n";
        } else {
            it->quantity -= quantity;
            std::cout << "Acquistati " << quantity << " su \"" << itemName << "\"." << it->quantity <<" Rimanenti "<< std::endl;
            if (it->quantity == 0) {
                Item removedItem = *it;
                items.erase(it);
                notifyObservers("Removed", removedItem);
                std::cout << "Elemento \"" << itemName << "\" acquistato.\n";
            } else {
                notifyObservers("Updated", *it);
            }
        }
    } else {
        std::cout << "Elemento \"" << itemName << "\" non presente nella lista.\n";
    }
}


void ShoppingList::showRemainingQuantities() const {
    std::cout << "Quantita' di ogni elemento nella lista \"" << name << "\":" << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item.name << ": " << item.quantity << " rimanenti" << std::endl;
    }
    if (items.empty()) {
        std::cout << "La lista e' vuota" << std::endl;
    }
}

std::string ShoppingList::getOwner() {
    return owner;
}

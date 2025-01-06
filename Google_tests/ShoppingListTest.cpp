#include <iostream>
#include <gtest/gtest.h>
#include <sstream>
#include "../src/User.h"
#include "../src/ShoppingList.h"
#include "../src/Item.h"


class ShoppingListTest : public ::testing::Test {
protected:
    void SetUp() override {
        oldCout = std::cout.rdbuf(output.rdbuf());
    }

    std::stringstream output;
    std::streambuf* oldCout{};
};


TEST_F(ShoppingListTest, AggiuntaElemento) {
    User user("Pippo");
    user.createList("Spesa");

    Item item("Mele", "Frutta", 3);
    user.addItemToList("Spesa", item);

    EXPECT_TRUE(output.str().find("Mele (Frutta): 3") != std::string::npos);
}


TEST_F(ShoppingListTest, AccessoNegato) {
    ShoppingList list("Test", "Alice");
    Item item("Mele", "Frutta", 3);

    list.addItem("Bob", item);
    EXPECT_TRUE(output.str().find("Accesso negato") != std::string::npos);
}

TEST_F(ShoppingListTest, AggiornaElemento) {
    ShoppingList list("Test", "Pippo");
    Item item1("Mele", "Frutta", 3);
    Item item2("Mele", "Frutta", 5);

    list.addItem("Pippo", item1);
    output.str("");
    list.updateItem("Pippo", item2);

    EXPECT_TRUE(output.str().find("Mele (Frutta): 5") != std::string::npos);
}

TEST_F(ShoppingListTest, NotificaObserver) {
    User user1("Pippo");
    User user2("Pluto");

    user1.createList("Spesa");
    user1.shareListWith("Spesa", user2);

    output.str("");
    Item item("Mele", "Frutta", 3);
    user2.addItemToList("Spesa", item);

    std::string outputStr = output.str();
    EXPECT_TRUE(outputStr.find("Utente Pippo - Lista aggiornata") != std::string::npos);
}

TEST_F(ShoppingListTest, RevocaAccesso) {
    User user1("Pippo");
    User user2("Pluto");

    user1.createList("Spesa");
    user1.shareListWith("Spesa", user2);
    user1.revokeListAccess("Spesa", user2);

    output.str("");
    Item item("Mele", "Frutta", 3);
    user2.addItemToList("Spesa", item);

    EXPECT_TRUE(output.str().find("non esiste o non hai i permessi") != std::string::npos);
}


TEST_F(ShoppingListTest, StampaListaVuota) {
    ShoppingList list("Test", "Pippo");
    list.printList();
    EXPECT_TRUE(output.str().find("La lista è vuota") != std::string::npos);
}

TEST_F(ShoppingListTest, QuantitàNegativa) {
    ShoppingList list("Test", "Pippo");
    Item item("Mele", "Frutta", -1);

    list.addItem("Pippo", item);
    EXPECT_TRUE(output.str().find("la quantità di un nuovo elemento deve essere almeno 1") != std::string::npos);
}


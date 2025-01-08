#include <iostream>
#include <gtest/gtest.h>
#include "../src/ShoppingList.h"
#include <sstream>


class ShoppingListTest : public ::testing::Test {};

TEST_F(ShoppingListTest, CreaLista) {
    ShoppingList list("Alimentari", "Pippo");
    EXPECT_EQ(list.getOwner(), "Pippo");
}

TEST_F(ShoppingListTest, AggiungiEAggiornaItem) {
    ShoppingList list("Alimentari", "Pippo");

    Item item("Latte", "Latticini", 2, false);
    list.addItem("Pippo", item);
    EXPECT_NO_THROW(list.updateItem("Pippo", Item("Latte", "Latticini", 5, false)));
}

TEST_F(ShoppingListTest, AccessoNonAutorizzato) {
    ShoppingList list("Alimentari", "Pippo");

    Item item("Latte", "Latticini", 2, false);
    EXPECT_THROW(list.addItem("Pluto", item), std::runtime_error);
}

TEST_F(ShoppingListTest, CondividiERevoca) {
    ShoppingList list("Alimentari", "Pippo");
    list.shareWith("Pluto");

    EXPECT_TRUE(list.isSharedWith("Pluto"));

    list.revokeAccess("Pluto");
    EXPECT_FALSE(list.isSharedWith("Pluto"));
}


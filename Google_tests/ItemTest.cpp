#include <iostream>
#include <gtest/gtest.h>
#include "../src/Item.h"
#include <sstream>

class ItemTest : public ::testing::Test {};

TEST_F(ItemTest, ItemValido) {
    EXPECT_NO_THROW(Item("Latte", "Latticini", 2, false));
}

TEST_F(ItemTest, QuantitaNegativa) {
    EXPECT_THROW(Item("Latte", "Latticini", -1, false), std::invalid_argument);
}

TEST_F(ItemTest, ImpostaStatoAcquisto) {
    Item item("Latte", "Latticini", 2, false);
    EXPECT_FALSE(item.isBought());

    item.setBought(true);

    EXPECT_TRUE(item.isBought());
}
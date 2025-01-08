#include <iostream>
#include <gtest/gtest.h>
#include "../src/User.h"
#include <sstream>


class UserTest : public ::testing::Test {};

TEST_F(UserTest, CreaUtente) {
    User user("Pippo");
    EXPECT_EQ(user.getUsername(), "Pippo");
}

TEST_F(UserTest, CreazioneLista) {
    User user("Pippo");
    user.createList("Alimentari");

    EXPECT_NO_THROW(user.addItemToList("Alimentari", Item("Latte", "Latticini", 2, false)));
}


TEST_F(UserTest, AggiornaItem) {
    User user("Pippo");
    user.createList("Alimentari");

    user.addItemToList("Alimentari", Item("Latte", "Latticini", 2, false));
    EXPECT_NO_THROW(user.updateItemInList("Alimentari", Item("Latte", "Latticini", 5, false)));
}

#include <iostream>
#include <gtest/gtest.h>
#include "../src/User.h"
#include <sstream>


class UserTest : public ::testing::Test {
protected:
    void SetUp() override {
        oldCout = std::cout.rdbuf(output.rdbuf());
    }

    std::stringstream output;
    std::streambuf* oldCout{};
};

TEST_F(UserTest, CreazioneUser) {
    User user("Pippo");
    user.createList("Spesa");
    EXPECT_TRUE(output.str().find("Pippo ha creato la lista: Spesa") != std::string::npos);
}

TEST_F(UserTest, CreazioneListaDuplicata) {
    User user("Pippo");
    user.createList("Spesa");
    output.str("");
    user.createList("Spesa");
    EXPECT_TRUE(output.str().find("esiste già") != std::string::npos);
}

TEST_F(UserTest, CondivisoneLista) {
    User user1("Pippo");
    User user2
    ("Pluto");

    user1.createList("Spesa");
    user1.shareListWith("Spesa", user2);

    EXPECT_TRUE(output.str().find("condivisa con Pluto") != std::string::npos);
}

TEST_F(UserTest, CondivioneListaInesistente) {
    User user1("Pippo");
    User user2("Pluto");

    user1.shareListWith("ListaNonEsistente", user2);
    EXPECT_TRUE(output.str().find("non esiste") != std::string::npos);
}
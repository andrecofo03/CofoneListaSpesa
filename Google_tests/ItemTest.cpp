#include <gtest/gtest.h>
#include "../src/Item.h"
#include <sstream>
#include <gtest/gtest_pred_impl.h>

class ItemTest : public ::testing::Test {
protected:
    void SetUp() override {
        oldCout = std::cout.rdbuf(output.rdbuf());
    }
    std::stringstream output;
    std::streambuf* oldCout;
};

TEST_F(ItemTest, CreazioneItem) {
    Item item("Mele", "Frutta", 3);
    item.print();
    EXPECT_EQ(output.str(), "- Mele (Frutta): 3\n");
}

TEST_F(ItemTest, CostruzioneBase) {
    Item item("Mele", "Frutta", 5);
    item.print();

    EXPECT_TRUE(output.str().find("Mele") != std::string::npos);
    EXPECT_TRUE(output.str().find("Frutta") != std::string::npos);
    EXPECT_TRUE(output.str().find("5") != std::string::npos);
}

TEST_F(ItemTest, CampiVuoti) {
    Item item("", "", 1);
    item.print();

    EXPECT_TRUE(output.str().find("()") != std::string::npos);
}

TEST_F(ItemTest, CaratteriSpeciali) {
    Item item("Test!@#$%", "Cat&*()", 1);
    item.print();

    EXPECT_TRUE(output.str().find("Test!@#$%") != std::string::npos);
    EXPECT_TRUE(output.str().find("Cat&*()") != std::string::npos);
}

TEST_F(ItemTest, GestioneSpazi) {
    Item item("  Spaced Name  ", " Category ", 1);
    item.print();
    EXPECT_TRUE(output.str().find("Spaced Name") != std::string::npos);
    EXPECT_TRUE(output.str().find("Category") != std::string::npos);
}

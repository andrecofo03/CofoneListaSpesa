project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_FILES ShoppingListTest.cpp
        ../src/ShoppingList.cpp
        ../src/User.cpp
        ../src/Item.cpp
        ItemTest.cpp
        UserTest.cpp)
add_executable(Google_Tests_run ${SOURCE_FILES})
target_link_libraries(Google_Tests_run gtest gtest_main)
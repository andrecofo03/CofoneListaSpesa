cmake_minimum_required(VERSION 3.28.1)
project(CofoneListaSpesa)

set(CMAKE_CXX_STANDARD 20)

add_executable(CofoneListaSpesa main.cpp
        Google_tests/ShoppingListTest.cpp
        src/User.h
        src/ShoppingList.cpp
        src/User.cpp
        src/ShoppingList.h
        src/Item.cpp
        src/Item.h
        src/IObserver.h
        src/ISubject.h
        )
add_subdirectory(Google_tests)
cmake_minimum_required(VERSION 3.29)
project(CofoneListaSpesa)

set(CMAKE_CXX_STANDARD 20)

add_executable(CofoneListaSpesa main.cpp
        Google_tests/test1.cpp
        Item.cpp
        Item.h
        User.cpp
        User.h
        IObserver.h
        ShoppingList.cpp
        ShoppingList.h
        ISubject.h)
add_subdirectory(Google_tests)
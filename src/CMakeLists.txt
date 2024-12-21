project(CofoneListaSpesa)

set(HEADER_FILES
        IObserver.h
        ISubject.h
        Item.h
        ShoppingList.h
        User.h
)

set(SOURCE_FILES
        Item.cpp
        ShoppingList.cpp
        User.cpp
)

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})
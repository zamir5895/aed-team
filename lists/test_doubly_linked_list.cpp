//
// Created by mateo on 4/09/2024.
//

#include <gtest/gtest.h>
#include "Doubly_Linked_List.h"

TEST(DoublyLinkedListTest, PushFrontTest) {
    Doubly_Linked_List list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.front(), 3); // Debería ser 3
    EXPECT_EQ(list.back(), 1);  // Debería ser 1
}

TEST(DoublyLinkedListTest, PushBackTest) {
    Doubly_Linked_List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.front(), 1); // Debería ser 1
    EXPECT_EQ(list.back(), 3);  // Debería ser 3
}

TEST(DoublyLinkedListTest, PopFrontTest) {
    Doubly_Linked_List list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.pop_front(), 3); // Debería eliminar y retornar 3
    EXPECT_EQ(list.front(), 2);     // Debería ser 2
}

TEST(DoublyLinkedListTest, PopBackTest) {
    Doubly_Linked_List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.pop_back(), 3);  // Debería eliminar y retornar 3
    EXPECT_EQ(list.back(), 2);      // Debería ser 2
}

TEST(DoublyLinkedListTest, InsertTest) {
    Doubly_Linked_List list;
    list.push_back(1);
    list.push_back(3);
    list.insert(2, 1);              // Insertar 2 en la posición 1
    EXPECT_EQ(list[1], 2);          // Debería ser 2
}

TEST(DoublyLinkedListTest, SizeTest) {
    Doubly_Linked_List list;
    EXPECT_EQ(list.size(), 0);      // Debería ser 0
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.size(), 2);      // Debería ser 2
}

TEST(DoublyLinkedListTest, ClearTest) {
    Doubly_Linked_List list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_EQ(list.size(), 0);      // Debería ser 0
    EXPECT_TRUE(list.empty());      // Debería estar vacío
}

TEST(DoublyLinkedListTest, ReverseTest) {
    Doubly_Linked_List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.reverse();
    EXPECT_EQ(list.front(), 3);     // Debería ser 3
    EXPECT_EQ(list.back(), 1);      // Debería ser 1
}

TEST(DoublyLinkedListTest, EmptyTest) {
    Doubly_Linked_List list;
    EXPECT_TRUE(list.empty());      // Debería estar vacío
    list.push_back(1);
    EXPECT_FALSE(list.empty());     // No debería estar vacío
}

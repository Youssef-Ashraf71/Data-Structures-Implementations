// 020-TestCase-2.cpp
// Source: https://github.com/catchorg/Catch2/blob/master/examples/020-TestCase-2.cpp

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../da.h"
#include "../da.cpp"
TEST_CASE("Constructor", "[multi-file:2]"){
 // My_DA* my_arr = new My_DA();
    My_DA<int>* my_arr = new My_DA<int>();
  REQUIRE( my_arr->get_size() == 0 );
  REQUIRE( my_arr->get_capacity() == 1 );
}

TEST_CASE("Push and Add", "[multi-file:2]"){
  // My_DA* my_arr = new My_DA();
    My_DA<int>* my_arr = new My_DA<int>();
  my_arr->push(5);
  my_arr->insert(0, 10);
  REQUIRE( my_arr->get(0) == 10 );
  REQUIRE( my_arr->get(1) == 5 );
}

TEST_CASE("Pop and Remove", "[multi-file:2]"){
    int arr[] = {5, 3, 2};
    // My_DA* my_arr = new My_DA(arr, 3);
    My_DA<int>* my_arr = new My_DA<int>(arr,3);
    REQUIRE( my_arr->remove(3) == -1 );
    REQUIRE( my_arr->remove(1) == 3 );
    REQUIRE( my_arr->pop() == 2 );
    REQUIRE( my_arr->remove(0) == 5 );
    REQUIRE( my_arr->pop() == -1 );
    REQUIRE( my_arr->get_size() == 0 );
    REQUIRE( my_arr->get_capacity() == 1 );
}

TEST_CASE("Expansion", "[multi-file:2]"){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
   // My_DA* my_arr = new My_DA(arr, 8);
    My_DA<int>* my_arr = new My_DA<int>(arr,8);
    my_arr->push(9);
    REQUIRE( my_arr->get_size() == 9 );
    REQUIRE( my_arr->get_capacity() == 16 );
}

TEST_CASE("Expansion with constructor", "[multi-file:2]"){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
 //   My_DA* my_arr = new My_DA(arr, 9);
    My_DA<int>* my_arr = new My_DA<int>(arr,9);
    REQUIRE( my_arr->get_size() == 9 );
    REQUIRE( my_arr->get_capacity() == 16 );
}

TEST_CASE("Shrink", "[multi-file:2]"){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  //  My_DA* my_arr = new My_DA(arr, 9);
    My_DA<int>* my_arr = new My_DA<int>(arr,9);
    my_arr->pop();
    my_arr->pop();
    my_arr->pop();
    my_arr->pop();
    my_arr->pop();
    REQUIRE( my_arr->get_size() == 4 );
    REQUIRE( my_arr->get_capacity() == 8 );
}
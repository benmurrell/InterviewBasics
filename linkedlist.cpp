// Copyright (C) 2014 Ben Murrell

#include <iostream>
using std::cout;
using std::endl;

#include <string>
#include <sstream>

#include "List.hpp"

int main( int argc, char** argv ) {

    List<int> myList;

    // Test adding to front of empty list
    myList.addFront( 5 );
    cout << myList.contents() << endl; // 5

    // Test adding to front of non-empty list
    myList.addFront( 9 );
    cout << myList.contents() << endl; // 9 5

    // Test adding to back of non-empty list
    myList.addBack( 11 );
    cout << myList.contents() << endl; // 9 5 11

    myList.addFront( 7 );
    cout << myList.contents() << endl; // 7 9 5 11

    // Remove by index
    myList.remove( 2 );
    cout << myList.contents() << endl; // 7 9 11

    // Remove front
    myList.removeFront();
    cout << myList.contents() << endl; // 9 11

    // Remove back
    myList.removeBack();
    cout << myList.contents() << endl; // 9

    // Remove back & cause empty
    myList.removeBack();
    cout << myList.contents() << endl; //

    // Remove front from empty list
    myList.removeFront();
    cout << myList.contents() << endl; //

    // Test adding to back of empty list
    myList.addBack( 27 );
    cout << myList.contents() << endl; // 27

    // Remove front & cause empty
    myList.removeFront();
    cout << myList.contents() << endl; //

    // Remove back from empty list
    myList.removeBack();
    cout << myList.contents() << endl; //

    // Reverse list with 1 element
    myList.addFront( 1 );
    myList.reverse();
    cout << myList.contents() << endl; // 1

    // Reverse list with 2 elements
    myList.addBack( 2 );
    myList.reverse();
    cout << myList.contents() << endl; // 2 1

    // Reverse list with 3 elements
    myList.addFront( 3 );
    myList.reverse();
    cout << myList.contents() << endl; // 1 2 3

    return 0;
}

// Copyright (C) 2014 Ben Murrell

#include <iostream>
using std::endl;
using std::cout;

void reverseStringInPlace( char* aString );

const char* ORIGINAL_STRING = "12345";

int main( int argc, char** argv ) {

    // Allocate a string & initialize it
    char* toReverse = (char*)malloc( sizeof( char ) * ( strlen( ORIGINAL_STRING ) + 1 ) );
    strcpy( toReverse, ORIGINAL_STRING );
    cout << "String:   " << toReverse << endl;

    // Reverse string
    reverseStringInPlace( toReverse );

    // Print result
    cout << "Reversed: " << toReverse << endl;

    // Test... general case (n characters)
    const char* expectedResult = "54321";
    cout << "Reversed correctly? " << ( strcmp( expectedResult, toReverse ) == 0 ? "yes" : "no" ) << endl;

    // Test... edge case (0 characters)
    toReverse[0] = '\0';
    reverseStringInPlace( toReverse );
    cout << "With 0 chars: " << ( toReverse[0] == '\0' ? "PASS" : "FAIL" ) << endl;

    // Test... edge case (1 character)
    toReverse[0] = 'H';
    toReverse[1] = '\0';
    reverseStringInPlace( toReverse );
    cout << "With 1 chars: " << ( ( toReverse[0] == 'H' && toReverse[1] == '\0' ) ? "PASS" : "FAIL" ) << endl;

    return 0;
}

// Reverse a C string in place, leaving null terminator in place
void reverseStringInPlace( char* aString ) {
    int len = strlen( aString );
    int midpt = len / 2;

    char tmp;
    for( int i = 0; i < midpt; i++ ) {
        tmp = aString[i];
        aString[i] = aString[len-1-i];
        aString[len-1-i] = tmp;
    }
}

// Copyright (C) 2014 Ben Murrell

#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

// LIFO Stack
class Stack {
    public:
        // Constructor
        Stack( int aDefaultCapacity = 64 ) {
            mCapacity = aDefaultCapacity;
            mData = new int[mCapacity];
        }

        // Destructor
        ~Stack() {
            // Release resources
            delete[] mData;
        }

        // Push value to top of stack
        void push( int aItem ) {

            // Need to expand internal storage?
            if( mTop >= mCapacity ) {
                // Alloc 2x the current space
                int newCapacity = mCapacity * 2;
                int* newStorage = new int[newCapacity];

                // Copy data into new memory
                memcpy( newStorage, mData, mCapacity * sizeof( int ) );

                // Free old data
                delete[] mData;

                // Use new memory
                mData = newStorage;
                mCapacity = newCapacity;
            }

            mData[mTop] = aItem;
            mTop++;
        }

        // Pop value from top of stack
        int pop() {
            int value = 0;

            // Only get value if stack is not empty
            if( mTop >= 1 ) {
                mTop--;
                value = mData[mTop];
            }

            return value;
        }

        // Peek at value on top of stack
        int peek() const {
            int value = 0;

            if( mTop >= 1 ) {
                value = mData[mTop - 1];
            }

            return value;
        }

        // Get size of stack
        int size() const {
            return mTop;
        }

        // Get string contents for testing
        std::string contents() const {
            std::ostringstream sout;

            for( int i = 0; i < mTop; i++ ) {
                sout << mData[i] << ", ";
            }

            return sout.str();
        }

    private:
        int mCapacity;  // Capacity of stack
        int* mData;     // Container of stack
        int mTop;       // Top of stack (location of *next* item)
};

int main( int argc, char** argv ) {
    Stack myStack(2);

    // Test adding to empty stack
    myStack.push( 1 );
    cout << myStack.contents() << endl; // 1

    // Test adding to non-empty stack
    myStack.push( 2 );
    cout << myStack.contents() << endl; // 1 2

    // Test adding beyond current capacity
    myStack.push( 3 );
    cout << myStack.contents() << endl; // 1 2 3

    myStack.push( 4 );
    cout << myStack.contents() << endl; // 1 2 3 4

    // Test size
    cout << myStack.size() << endl; // 4

    // Test peek
    cout << myStack.peek() << endl; // 4

    // Test popping from stack
    cout << myStack.pop() << endl;  // 4
    cout << myStack.pop() << endl;  // 3
    cout << myStack.pop() << endl;  // 2
    cout << myStack.pop() << endl;  // 1
    cout << myStack.size() << endl; // 0

    // Test popping from empty stack
    cout << myStack.pop() << endl;  // 0

    return 0;
}


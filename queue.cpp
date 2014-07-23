// Copyright (C) 2014 Ben Murrell

#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

// FIFO Queue
class Queue {
    public:
        // Constructor
        Queue( int aDefaultCapacity = 64 ) {
            mCapacity = aDefaultCapacity;
            mData = new int( mCapacity );
            mFront = 0;
            mBack = 0;
        }

        // Destructor
        ~Queue() {
            // Release resources
            delete[] mData;
        }

        // Add an item to the queue
        void enqueue( int aItem ) {
            // Need to expand internal storage?
            if( mBack - mFront >= mCapacity ) {
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

            mData[mBack % mCapacity] = aItem;
            mBack++;
        }

        // Remove an item from the queue
        int dequeue() {
            int value = 0;

            // Only dequeue if there is something in the queue
            if( mFront < mBack ) {
                value = mData[mFront % mCapacity];
                mFront++;
            }

            return value;
        }

        // Get the number of items in the queue
        int size() const {
            return mBack - mFront;
        }

        // Get the contents in string form for testing & verification
        std::string contents() const {
            std::ostringstream sout;

            for( int i = mFront; i < mBack; i++ ) {
                sout << mData[i % mCapacity] << ", ";
            }

            return sout.str();
        }

    private:
        int mCapacity;  // Current capacity of the circular buffer
        int* mData;     // Circular buffer containing queue
        int mFront;     // Front of circular buffer
        int mBack;      // Back of circular buffer (location of *next* item)
};

int main( int argc, char** argv ) {
    Queue myQ(2);

    // Test adding to empty
    myQ.enqueue( 1 );
    cout << myQ.contents() << endl; // 1

    // Test adding to non-empty
    myQ.enqueue( 2 );
    cout << myQ.contents() << endl; // 1 2

    // Test adding beyond current capacity
    myQ.enqueue( 3 );
    cout << myQ.contents() << endl; // 1 2 3

    myQ.enqueue( 4 );
    cout << myQ.contents() << endl; // 1 2 3 4

    // Test size
    cout << myQ.size() << endl;     // 4

    // Test removing
    cout << myQ.dequeue() << endl;  // 1
    cout << myQ.dequeue() << endl;  // 2
    cout << myQ.dequeue() << endl;  // 3
    cout << myQ.dequeue() << endl;  // 4
    cout << myQ.size() << endl;     // 0

    // Test removing from empty
    cout << myQ.dequeue() << endl;  // 0

    return 0;
}

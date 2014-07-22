// Copyright (C) 2014 Ben Murrell

#ifndef _LIST_HPP
#define _LIST_HPP

// Singly linked list node
template<typename T>
struct ListNode {
    ListNode<T>* next;
    ListNode<T>* prev;
    T value;
};

// Singly linked list
template<typename T>
class List {
    public:
        // Constructor
        List() : mHead( NULL ), mTail( NULL ) {}

        // Destructor
        ~List() {
            ListNode<T>* cur = mHead;

            while( NULL != cur ) {
                ListNode<T>* next = cur->next;
                delete cur;
                cur = next;
            }
        }

    public:
        // Add to front of list
        void addFront( T aToAdd ) {
            // Create & init new node
            ListNode<T>* newHead = new ListNode<T>;
            newHead->next = mHead;
            newHead->prev = NULL;
            newHead->value = aToAdd;

            if( NULL == mHead ) {
                // Set tail if this is only node
                mTail = newHead;
            } else {
                // Update old head to point to new head if there is a head
                mHead->prev = newHead;
            }

            // Set node as new head
            mHead = newHead;
        }

        // Add to back of list
        void addBack( T aToAdd ) {
            // Create & init new node
            ListNode<T>* newTail = new ListNode<T>;
            newTail->next = NULL;
            newTail->prev = mTail;
            newTail->value = aToAdd;

            if( NULL == mTail ) {
                // Set head if this is the only node
                mHead = newTail;
            } else {
                // Update old tail to point to new tail if there is a tail
                mTail->next = newTail;
            }

            // Set node as new tail
            mTail = newTail;
        }

        // Remove element at given index
        void remove( int aIndex ) {
            ListNode<T>* toRemove = mHead;

            for( int i = 0; i < aIndex && NULL != toRemove; i++ ) {
                toRemove = toRemove->next;
            }

            // Got one
            if( toRemove == mHead ) {
                // Removing head, already handle that case in removeFront
                removeFront();
            } else if( toRemove == mTail ){
                // Removing tail, already handle that case in removeTail
                removeBack();
            } else {
                // Removing node that is not head or tail, patch it out
                toRemove->next->prev = toRemove->prev;
                toRemove->prev->next = toRemove->next;

                // Release resources
                delete toRemove;
            }
        }

        // Remove from front of list
        void removeFront() {
            if( mHead != NULL ) {
                ListNode<T>* oldHead = mHead;
                mHead = mHead->next;
                delete oldHead;

                if( NULL == mHead ) {
                    // We removed the only node, clear tail too
                    mTail = NULL;
                } else {
                    // Clear prev pointer for new head
                    mHead->prev = NULL;
                }
            }
        }

        // Remove from back of list
        void removeBack() {
            if( mTail != NULL ) {
                ListNode<T>* oldTail = mTail;
                mTail = oldTail->prev;
                delete oldTail;

                if( NULL == mTail ) {
                    // We removed the only node, clear the head too
                    mHead = NULL;
                } else {
                    // Clear next pointer for new tail
                    mTail->next = NULL;
                }
            }
        }

        // Reverse the linked list
        void reverse() {
            // Swap next/prev for each node
            for( ListNode<T>* cur = mHead; cur != NULL; ) {
                ListNode<T>* tmp = cur->next;
                cur->next = cur->prev;
                cur->prev = tmp;

                cur = tmp;
            }

            // Swap head and tail
            ListNode<T>* tmp = mHead;
            mHead = mTail;
            mTail = tmp;
        }

        // Count number of elements in list
        int size() {
            int count = 0;

            for( ListNode<T>* cur = mHead; cur != NULL; cur = cur->next ) {
                count++;
            }

            return count;
        }

        // Spit out contents as a string for verification
        std::string contents() {
            std::ostringstream sout;
            for( ListNode<T>* cur = mHead; cur != NULL; cur = cur->next ) {
                sout << cur->value << ", ";
            }
            return sout.str();
        }

    private:
        ListNode<T>* mHead;
        ListNode<T>* mTail;
};

#endif

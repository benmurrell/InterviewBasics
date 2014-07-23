InterviewBasics
===============

This repository contains basic C++ implementations of the following typical interview coding question topics:
* Reverse a string
* Implement and test a linked list
* Implement and test a queue
* Implement and test a stack

String Reversal
---------------

The string reversal implementation reverses C strings in place with linear time complexity and constant space complexity.

Linked List
-----------

The linked list is implemented as a doubly linked list. Additionally, it is implemented using the C++ template system, so it can be a generic container.

API:
* addFront
* addBack
* remove(index)
* removeFront
* removeBack
* reverse

Queue
-----

The queue is implemented internally using a circular buffer that automatically increases in size as needed. It is a container of int's.

API: 
* enqueue
* dequeue
* size

Stack
-----

The stack is implemented internally using an array that automatically increases in size as needed. It is a container of int's.

API:
* push
* pop
* peek
* size

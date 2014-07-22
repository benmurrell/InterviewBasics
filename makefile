all: strings linkedlist queue stack

strings: strings.cpp
	clang++ -o strings strings.cpp -I. -g

linkedlist: linkedlist.cpp List.hpp
	clang++ -o linkedlist linkedlist.cpp -I. -g

queue: queue.cpp List.hpp
	clang++ -o queue queue.cpp -I. -g

stack: stack.cpp
	clang++ -o stack stack.cpp -I. -g

//
// Created by rohtanza on 10/7/23.
//

#ifndef STACKLINKEDLIST_STACKLINKEDLIST_H
#define STACKLINKEDLIST_STACKLINKEDLIST_H

#include <iostream>
#include <memory>
#include <optional>

using namespace std;

template<typename dataType>
class StackLinkedList {

    class Node {

        dataType data;
        unique_ptr<Node> next;

    public:
        explicit Node(dataType data) : data(data), next(nullptr) {}

        /* Making node class friend of StackLinkedList will
         * allow StackLinkedList to directly manage the memory of
         * The node objects, without needing to expose the node
         * class.
         * */

        friend class StackLinkedList;

    };

    unique_ptr<Node> top;

    size_t size;

public:
    explicit StackLinkedList() : size(0), top(nullptr) {};

    bool push(dataType data);

    dataType pop();

    /* using optional as I am not sure if the stack is empty
     * what if the stack is empty? then it will return the nullopt
     * meaning the stack is empty.
    */
    optional<dataType> topElement();

    size_t sizeStack();

    bool empty();

    void display();

};
template<typename dataType>
size_t StackLinkedList<dataType>::sizeStack() {
    return size;
}

template<typename dataType>
bool StackLinkedList<dataType>::empty() {
    return size == 0;
}

template<typename dataType>
optional<dataType> StackLinkedList<dataType>::topElement() {
    if (empty())
        return nullopt;
    return optional<dataType>(top->data);

}

template<typename dataType>
dataType StackLinkedList<dataType>::pop() {
    // Checking if the stack is empty.
    if (empty())
        throw out_of_range("Stack underflow\n");
    dataType temp = top->data;
    top = move(top->next);
    size--;
    return temp;
}

template<typename dataType>
bool StackLinkedList<dataType>::push(dataType data) {
    /* First check in the push function is if the
     * memory for new node is allocated, I am using
     * the try and catch block for this. Try will
     * create a new node using unique ptr, if it
     * doesn't happen, it will catch the bad_alloc
     * exception, then an error using the standard
     * error stream will be shown, and that .what()
     * will return a string matching the exception.
     */
    unique_ptr<Node> newNode;
    try {
        //newNode will be automatically deleted when it's no longer needed, preventing memory leaks.
        newNode = make_unique<Node>(data);
    } catch (const bad_alloc &node) {
        cerr << "Memory Allocation failed " << node.what() << endl;
        return false;
    }
    newNode->next = move(top);
    top = move(newNode);
    size++;
    return true;
}

template<typename dataType>
void StackLinkedList<dataType>::display() {
    const Node *current = top.get(); // Using a const pointer to avoid modifying top
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next.get();
    }
    std::cout << " End." << std::endl;
}




#endif //STACKLINKEDLIST_STACKLINKEDLIST_H


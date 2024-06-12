#include <iostream>
#include "StackLinkedList.h"

int main() {
    auto *list = new StackLinkedList<int>;

    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);
    list->push(5);
    list->display();

    cout << list->pop() << endl;

    list->display();

    list->push(6);
    list->display();

    if (list->empty())
        cout << "yes empty" << endl;
    cout << "not empty" << endl;

    optional<int> topValue = list->topElement();
    if (topValue) {
        cout << topValue.value() << endl;
    } else {
        cout << "Stack is empty." << endl;
    }
    cout << list->sizeStack() << endl;

    return 0;
}

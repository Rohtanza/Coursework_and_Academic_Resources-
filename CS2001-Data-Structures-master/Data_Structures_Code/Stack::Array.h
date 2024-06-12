
#include <iostream>

using namespace std;

template<typename T>
class Stack {
private:
    T *stackArray;
    int top;
    int capacity;
public:
    Stack(int size) {
          if (size <= 0) {
       throw invalid_argument("Size must be greater than 0");
   }
        capacity = size;
        stackArray = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[top];
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        stackArray[++top] = value;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Can't use pop, the stack is empty" << endl;
            return -1;
        }
        return stackArray[top--];
    }

    int getLength() {
        return top + 1;
    }
};



#include <iostream>

using namespace std;

template<typename T>
class LL {
    class Node {
    public:
        Node *next;
        T value;

        Node(T value) : value(value), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t size;

public:
    LL() : head(nullptr), tail(nullptr), size(0) {}

    void insertFirst(T value) {
        Node *newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insertEnd(T value) {
        Node *newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insert(T value, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position." << endl;
            return;
        }

        if (pos == 0) {
            insertFirst(value);
        } else if (pos == size) {
            insertEnd(value);
        } else {
            Node *newNode = new Node(value);
            Node *current = head;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void deleteFirst() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deleteIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }

        if (index == 0) {
            deleteFirst();
        } else {
            Node *current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            if (index == size - 1) {
                tail = current;
            }
            size--;
        }
    }

    void deleteLast() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = tail = nullptr;
        } else {
            Node *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
    }

    Node *get(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return nullptr;
        }

        Node *current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }

    void printList() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LL() {
        Node *current = head;
        while (current) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};


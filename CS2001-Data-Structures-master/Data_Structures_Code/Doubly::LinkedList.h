 
#include <iostream>

template<typename T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node *prev;
        Node *next;

        Node(const T &data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertFirst(const T &value) {
        Node *newNode = new Node(value);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertEnd(const T &value) {
        Node *newNode = new Node(value);

        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insert(const T &value, size_t position) {
        if (position > size) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        if (position == 0) {
            insertFirst(value);
        } else if (position == size) {
            insertEnd(value);
        } else {
            Node *newNode = new Node(value);
            Node *current = head;
            for (size_t i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
    }

    void deleteFirst() {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteLast() {
        if (!tail) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteIndex(size_t position) {
        if (position >= size || !head) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        if (position == 0) {
            deleteFirst();
        } else if (position == size - 1) {
            deleteLast();
        } else {
            Node *current = head;
            for (size_t i = 0; i < position; ++i) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
        }
    }

    void printList() const {
        Node *current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    size_t getSize() const {
        return size;
    }

    T get(size_t index) const {
        if (index >= size || !head) {
            throw std::out_of_range("Invalid index");
        }

        Node *current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    ~DoublyLinkedList() {
        Node *current = head;
        while (current) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};

#include <iostream>

template<typename T>
class CircularLinkedList {
    struct Node {
        T data;
        Node *next;

        Node(const T &data) : data(data), next(nullptr) {}
    };

    Node *head;
    size_t size;

public:
    CircularLinkedList() : head(nullptr), size(0) {}

    void insertFirst(const T &value) {
        Node *newNode = new Node(value);

        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insertEnd(const T &value) {
        Node *newNode = new Node(value);

        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
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
            Node *temp = head;
            for (size_t i = 0; i < position - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    void deleteFirst() {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
        size--;
    }

    void deleteLast() {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node *temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node *lastNode = temp->next;
            temp->next = head;
            delete lastNode;
        }
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
            Node *temp = head;
            for (size_t i = 0; i < position - 1; ++i) {
                temp = temp->next;
            }
            Node *nodeToRemove = temp->next;
            temp->next = temp->next->next;
            delete nodeToRemove;
            size--;
        }
    }

    void printList() const {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node *temp = head;
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "Head" << std::endl;
    }

    size_t getSize() const {
        return size;
    }

    ~CircularLinkedList() {
        if (!head) {
            return;
        }

        Node *temp = head;
        do {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);

        head = nullptr;
        size = 0;
    }

    T get(size_t index) const {
        if (index >= size || !head) {
            throw std::out_of_range("Invalid index");
        }

        Node *temp = head;
        for (size_t i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

};


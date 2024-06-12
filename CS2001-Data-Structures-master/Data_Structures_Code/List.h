

#include <iostream>

using namespace std;

class List {
private:
    int *arr;
    mutable int *curr;
    int capacity;
    int length;
public:
    List(int c);

    ~List();

    void start();

    void tail();

    void next();

    void back();

    void insert(int val, int pos);

    void remove(int pos);

    bool find(int val);

    void update(int val, int pos);

    int get(int pos) const;

    void print();

    void clear();

    void copy(const List &l2);


};

List::List(int c) : capacity(c), length(0) {
    arr = new int[c];
    curr = arr;
}


List::~List() {
    delete[] arr;
}

void List::start() {
    curr = arr;
}

void List::tail() {
    curr = arr + length - 1;
}

void List::next() {
    curr++;
}

void List::back() {
    curr--;
}

void List::insert(int val, int pos) {
    if (length >= capacity) {
        cout << "The List is full" << endl;
        return;
    }
    if (pos < 1 || pos > length + 1) {
        cout << "The Pos is Invalid" << endl;
        return;
    }

    tail();

    for (int i = length; i >= pos; i--) {
        *(curr + 1) = *curr;
        back();
    }
    *(curr + 1) = val;
    length++;


}

void List::remove(int pos) {

    if (length == 0) {
        cout << "List is empty" << endl;
        return;
    }
    if (pos < 1 || pos > length) {
        cout << "Position is Invalid" << endl;
        return;
    }
    curr = arr + pos - 1;

    for (int i = pos; i < length; i++) {
        *curr = *(curr + 1);
        next();

    }
    length--;

}

bool List::find(int val) {

    if (length == 0) {
        cout << "the List is empty" << endl;
        return false;
    }

    start();
    for (int i = 0; i < length; ++i) {
        if (*curr == val)
            return true;
        next();
    }
    return false;

}

void List::update(int val, int pos) {

    if (length == 0) {
        cout << "the list is empty" << endl;
    }
    if (pos < 1 || pos > length) {
        cout << "The pos is invalid" << endl;
    }

    curr = arr + pos - 1;

    *curr = val;

}

int List::get(int pos) const {

    if (length == 0) {
        cout << " the list is empty" << endl;
        return -1;
    }
    if (pos < 1 || pos > length) {
        cout << "the pos is invalid" << endl;
        return -1;
    }
    return arr[pos - 1];
}

void List::print() {

    start();
    for (int i = 0; i < length; ++i) {
        cout << *curr << " ";
        next();

    }
    cout << endl;

}

void List::clear() {

    length = 0;


}

void List::copy(const List &l2) {

    clear();


    if (capacity < l2.length) {
        delete[]arr;
        capacity = l2.capacity;
        arr = new int[capacity];
        curr = arr;
    }

    for (int i = 1; i <= l2.length; ++i) {
        int element = l2.get(i);
        insert(element, i);


    }

}


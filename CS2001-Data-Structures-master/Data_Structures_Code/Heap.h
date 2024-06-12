#include <vector>
#include <iostream>

using namespace std;

/*
 * if you want to use it as a min heap, you would use heapifyUp to maintain the heap property
 * after insertions and heapifyDown to maintain the heap property after deletions.
 * If you want to use it as a max heap, you would use heapifyDown to maintain
 * the heap property after insertions and heapifyUp
 * to maintain the heap property after deletions
 *
 * */

template<typename T>
class Heap {
public:
    std::vector<T> htree;

    int getParent(int child) {
        return (child - 1) / 2;
    }

    int getLeft(int parent) {
        return parent * 2 + 1;
    }

    int getRight(int parent) {
        return parent * 2 + 2;
    }

    void swap(T *a, T *b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) {
        int parent = getParent(node);
        if (node != 0 && htree[node].urgency < htree[parent].urgency) {
            swap(&htree[node], &htree[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int node) {
        int left = getLeft(node);
        int right = getRight(node);
        int smallest = node;
        if (left < htree.size() && htree[left].urgency < htree[smallest].urgency)
            smallest = left;
        if (right < htree.size() && htree[right].urgency < htree[smallest].urgency)
            smallest = right;
        if (smallest != node) {
            swap(&htree[node], &htree[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(T Node) {
        htree.push_back(Node);
        heapifyUp(htree.size() - 1);
    }

    void del() {
        if (htree.empty()) {
            cout << "heap is empty." << endl;
            return;
        }
        swap(&htree[0], &htree[htree.size() - 1]);
        htree.pop_back();
        heapifyDown(0);
    }

    void updateUrgency(string patientName, int newUrgency) {
        for (int i = 0; i < htree.size(); i++) {
            if (htree[i].name == patientName) {
                htree[i].urgency = newUrgency;
                heapifyUp(i);
                break;
            }
        }
    }

    void display() {
        if (htree.empty()) {
            cout << "Nothing to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++) {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
};


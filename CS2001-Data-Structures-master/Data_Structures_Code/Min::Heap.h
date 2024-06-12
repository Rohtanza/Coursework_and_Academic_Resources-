#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class MinHeap {
private:
    std::vector<T> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void siftDown(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            siftDown(smallest);
        }
    }

public:
    void insert(T key) {
        heap.push_back(key);
        int i = heap.size() - 1;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteMin() {
        if (heap.size() == 0)
            return;
        if (heap.size() == 1) {
            heap.clear();
            return;
        }
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        siftDown(0);
    }

    T getMin() {
        if (heap.empty()) {
            return T{};
        }
        return heap[0];
    }

    void display() {
        for (int i = 0; i < heap.size(); ++i)
            std::cout << heap[i] << " ";
        std::cout << std::endl;
    }
};

#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
private:
    std::vector<int> heap;

    // HELPER: Calculate parent index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // HELPER: Calculate left child index
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // HELPER: Calculate right child index
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // HELPER: Move an element up to its correct position
    void bubbleUp(int index) {
        int currentIndex = index;
        int parentIndex = parent(currentIndex);

        while(currentIndex > 0 && heap[currentIndex] < heap[parentIndex]) {
            std::swap(heap[currentIndex], heap[parentIndex]);

            currentIndex = parentIndex;
            parentIndex = parent(currentIndex);
        }
    }

    // HELPER: Move an element down to its correct position
    void bubbleDown(int index) {
        int currentIndex = index;
        int leftChildIndex = leftChild(currentIndex);
        int rightChildIndex = rightChild(currentIndex);

        while(leftChildIndex < heap.size()) {
            int smallerChildIndex = leftChildIndex;

            if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[leftChildIndex]) {
                smallerChildIndex = rightChildIndex;
            }

            if (heap[currentIndex] <= heap[smallerChildIndex]) break;

            std::swap(heap[currentIndex], heap[smallerChildIndex]);
            
            currentIndex = smallerChildIndex;
            leftChildIndex = leftChild(currentIndex);
            rightChildIndex = rightChild(currentIndex);
        }
    }

public:
    // Returns the minimum element (root) without removing it
    int peek() {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        return heap[0];
    }

    // Adds a new element to the heap
    void push(int value) {
        heap.emplace_back(value);
        bubbleUp(heap.size() - 1);
    }

    // Removes and returns the minimum element
    int pop() {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) bubbleDown(0);

        return root;
    }

    int size() {
        return heap.size();
    }
    
    bool isEmpty() {
        return heap.empty();
    }
};

// --- Test Driver ---
#ifndef UNIT_TESTING
int main() {
    MinHeap h;
    
    std::cout << "Pushing: 10, 5, 3, 2, 8" << std::endl;
    h.push(10);
    h.push(5);
    h.push(3);
    h.push(2);
    h.push(8);

    // Expected Min: 2
    std::cout << "Current Min: " << h.peek() << " (Expected: 2)" << std::endl;

    std::cout << "Popping elements: ";
    while (!h.isEmpty()) {
        std::cout << h.pop() << " ";
    }
    std::cout << std::endl;
    // Expected Output: 2 3 5 8 10 (Sorted order)

    return 0;
}
#endif
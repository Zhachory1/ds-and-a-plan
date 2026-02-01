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
        // TODO: Return the index of the left child
        return 0; // Placeholder
    }

    // HELPER: Calculate right child index
    int rightChild(int i) {
        // TODO: Return the index of the right child
        return 0; // Placeholder
    }

    // HELPER: Move an element up to its correct position
    void bubbleUp(int index) {
        // TODO
    }

    // HELPER: Move an element down to its correct position
    void bubbleDown(int index) {
        // TODO
    }

public:
    // Returns the minimum element (root) without removing it
    int peek() {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        return heap[0];
    }

    // Adds a new element to the heap
    void push(int value) {
        // TODO
    }

    // Removes and returns the minimum element
    int pop() {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        
        // TODO
        
        return -1; // Placeholder return
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
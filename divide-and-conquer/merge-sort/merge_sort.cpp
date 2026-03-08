/**
 * HW1 — Merge Sort
 * YOUR CODE GOES HERE.
 * Look for TODO comments — that's where you implement.
 */

#include "merge_sort.h"
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    // TODO: Implement the merge step.
    //
    // Bonus: after writing the merged result back, print arr[left..right]
    // to visualize the algorithm (e.g., "Merged [1, 3, 5, 7]")
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    // TODO: Implement the recursive divide-and-conquer sort.
}

// ── Demo main (excluded when running tests) ──────────────────────────────────
#ifndef UNIT_TESTING
void printArray(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "Before: ";
    printArray(arr);
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    std::cout << "After:  ";
    printArray(arr);
    return 0;
}
#endif

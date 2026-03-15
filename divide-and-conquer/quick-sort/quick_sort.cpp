/**
 * HW2 — Quick Sort with Randomized Pivot
 * YOUR CODE GOES HERE.
 * Look for TODO comments — that's where you implement.
 */

#include "quick_sort.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high, int& max_depth, int current_depth) {
    // Track depth and sort using partition()
    // ** Update max_depth: if current_depth > max_depth, max_depth = current_depth
    
    if (current_depth > max_depth) max_depth = current_depth;

    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1, max_depth, current_depth + 1);
        quickSort(arr, pivot + 1, high, max_depth, current_depth + 1);
    }
}

void quickSortRandomized(std::vector<int>& arr, int low, int high, int& max_depth, int current_depth) {
    // ** Update max_depth: if current_depth > max_depth, max_depth = current_depth
    // Before calling partition, pick a random index in [low, high]
    // and swap that element with arr[high]. Then proceed exactly as quickSort.
    //
    // Random index formula: low + rand() % (high - low + 1)
    //
    // Why does this help? Add a comment below explaining it:
    // EXPLANATION: Randomizing the pivot reduces the chance of consistently bad splits.

    if (current_depth > max_depth) max_depth = current_depth;

    if (low < high) {
        int random_index = low + rand() % (high - low + 1);
        std::swap(arr[random_index], arr[high]);

        int pivot = partition(arr, low, high);

        quickSortRandomized(arr, low, pivot - 1, max_depth, current_depth + 1);
        quickSortRandomized(arr, pivot + 1, high, max_depth, current_depth + 1);
    }
}

// ── Demo main (excluded when running tests) ──────────────────────────────────
#ifndef UNIT_TESTING
void printArray(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    srand(42);

    // Show depth difference on a sorted array
    std::vector<int> sorted(20);
    for (int i = 0; i < 20; i++) sorted[i] = i + 1;

    std::vector<int> a = sorted, b = sorted;
    int depth_det = 0, depth_rand = 0;

    quickSort(a, 0, static_cast<int>(a.size()) - 1, depth_det);
    quickSortRandomized(b, 0, static_cast<int>(b.size()) - 1, depth_rand);

    std::cout << "Sorted input (n=20):\n";
    std::cout << "  Deterministic max depth: " << depth_det << "\n";
    std::cout << "  Randomized   max depth: " << depth_rand << "\n";

    return 0;
}
#endif

/**
 * HW3 — Count Inversions
 * YOUR CODE GOES HERE.
 * Look for TODO comments — that's where you implement.
 */

#include "inversions.h"
#include <iostream>
#include <vector>

long long countInversionsBrute(const std::vector<int>& arr) {
    // TODO: Count inversions with two nested loops.
    //
    // For every pair (i, j) where i < j, check if arr[i] > arr[j].
    // If yes, that's an inversion — increment your counter.
    //
    // This is intentionally O(n²). Use it to verify your D&C answer is correct.

    return 0; // placeholder
}

long long mergeCount(std::vector<int>& arr, int left, int right) {
    // TODO: Modified merge sort that counts inversions.
    //
    // Hint: Return leftInv + rightInv + mergeInversions

    return 0; // placeholder
}

// Provided for you — do not modify.
long long countInversionsDC(std::vector<int> arr) {
    if (arr.empty()) return 0;
    return mergeCount(arr, 0, static_cast<int>(arr.size()) - 1);
}

// ── Demo main (excluded when running tests) ──────────────────────────────────
#ifndef UNIT_TESTING
int main() {
    std::vector<int> arr = {2, 4, 1, 3, 5};

    long long brute = countInversionsBrute(arr);
    long long dc    = countInversionsDC(arr);

    std::cout << "Array: 2 4 1 3 5\n";
    std::cout << "Brute force inversions: " << brute << "  (expected 3)\n";
    std::cout << "D&C   inversions:       " << dc    << "  (expected 3)\n";
    std::cout << "Inversions are: (2,1), (4,1), (4,3)\n";

    return 0;
}
#endif

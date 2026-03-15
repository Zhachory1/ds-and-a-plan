/**
 * HW3 — Count Inversions
 * YOUR CODE GOES HERE.
 * Look for TODO comments — that's where you implement.
 */

#include "inversions.h"
#include <iostream>
#include <vector>

long long countInversionsBrute(const std::vector<int>& arr) {
    // For every pair (i, j) where i < j, check if arr[i] > arr[j].
    // If yes, that's an inversion — increment your counter.
    // This is intentionally O(n²). Use it to verify your D&C answer is correct.

    long long inversions = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                inversions++;
            }
        }
    }

    return inversions;
}

long long mergeCount(std::vector<int>& arr, int left, int right) {
    // Hint: Return leftInv + rightInv + mergeInversions
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    long long inversions = 0;

    inversions += mergeCount(arr, left, mid);
    inversions += mergeCount(arr, mid + 1, right);

    std::vector<int> merged;
    merged.reserve(right - left + 1);

    int i = left, j = mid + 1;

    while (i <= mid || j <= right) {
        if (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                merged.push_back(arr[i]);
                i++;
            } else {
                merged.push_back(arr[j]);
                j++;
                inversions += mid - i + 1;
            }
        } else if (i <= mid) {
            merged.push_back(arr[i]);
            i++;
        } else if (j <= right) {
            merged.push_back(arr[j]);
            j++;
        }
    }

    for (int k = 0; k < merged.size(); k++) {
        arr[left + k] = merged[k];
    }

    return inversions;
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

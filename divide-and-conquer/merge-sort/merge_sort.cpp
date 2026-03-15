/**
 * HW1 — Merge Sort
 * YOUR CODE GOES HERE.
 * Look for TODO comments — that's where you implement.
 */

#include "merge_sort.h"
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftArr(mid - left + 1);
    std::vector<int> rightArr(right - mid);

    for (int i = 0; i < leftArr.size(); i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < rightArr.size(); i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int arrCounter = left;
    
    while (i < leftArr.size() || j < rightArr.size()) {
        if (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[arrCounter] = leftArr[i];
                i++;
            }
            else {
                arr[arrCounter] = rightArr[j];
                j++;
            }
        } else if (i < leftArr.size()) {
            arr[arrCounter] = leftArr[i];
            i++;
        } else if (j < rightArr.size()) {
            arr[arrCounter] = rightArr[j];
            j++;
        }
        arrCounter++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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

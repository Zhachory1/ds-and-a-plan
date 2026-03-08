/**
 * HW1 — Merge Sort
 * Implement the two functions below in merge_sort.cpp.
 * Do NOT modify this file.
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

/**
 * Merge two sorted halves — arr[left..mid] and arr[mid+1..right] —
 * back into arr[left..right] in ascending order.
 *
 * Tip: allocate a temporary vector, fill it with the merged result,
 * then copy it back into arr.
 *
 * Bonus: print the subarray after merging to visualize the algorithm.
 */
void merge(std::vector<int>& arr, int left, int mid, int right);

/**
 * Sort arr[left..right] in ascending order using divide-and-conquer.
 *
 * Steps:
 *   1. Base case: if left >= right, return (nothing to sort)
 *   2. Calculate mid = left + (right - left) / 2   <-- avoids integer overflow!
 *   3. Recursively sort the left half
 *   4. Recursively sort the right half
 *   5. Call merge() to combine the two sorted halves
 */
void mergeSort(std::vector<int>& arr, int left, int right);

#endif // MERGE_SORT_H

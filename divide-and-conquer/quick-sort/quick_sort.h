/**
 * HW2 — Quick Sort with Randomized Pivot
 * Implement the functions below in quick_sort.cpp.
 * Do NOT modify this file.
 */

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

/**
 * Lomuto partition scheme.
 * Rearranges arr[low..high] so that the pivot (arr[high]) is in its
 * final sorted position, elements to its left are <= pivot, and
 * elements to its right are > pivot.
 *
 * @return The final index of the pivot.
 */
int partition(std::vector<int>& arr, int low, int high);

/**
 * Sort arr[low..high] using deterministic Quick Sort (last element as pivot).
 * Increment max_depth whenever current_depth exceeds it — this tracks how
 * deep the call stack gets.
 *
 * @param max_depth   Updated to the maximum recursion depth seen so far.
 * @param current_depth  Current depth in the recursion tree (pass 0 initially).
 */
void quickSort(std::vector<int>& arr, int low, int high,
               int& max_depth, int current_depth = 0);

/**
 * Same as quickSort, but before calling partition, swap arr[high] with a
 * randomly chosen element in arr[low..high]. This prevents worst-case O(n²)
 * on already-sorted input.
 */
void quickSortRandomized(std::vector<int>& arr, int low, int high,
                         int& max_depth, int current_depth = 0);

#endif // QUICK_SORT_H

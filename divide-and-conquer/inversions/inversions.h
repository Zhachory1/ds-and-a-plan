/**
 * HW3 — Count Inversions (Divide & Conquer Application)
 * Implement the functions below in inversions.cpp.
 * Do NOT modify this file.
 *
 * An inversion is a pair (i, j) where i < j but arr[i] > arr[j].
 * Brute force: O(n²). Your D&C solution must run in O(n log n).
 */

#ifndef INVERSIONS_H
#define INVERSIONS_H

#include <vector>

/**
 * Count inversions using brute force nested loops — O(n²).
 * Use this to verify the correctness of your D&C solution.
 */
long long countInversionsBrute(const std::vector<int>& arr);

/**
 * Count inversions in arr[left..right] using a modified merge sort — O(n log n).
 *
 * Key insight: when merging two sorted halves and you pick arr[j] from the
 * RIGHT half before finishing the left half, arr[j] is out of order with
 * ALL remaining elements in the left half. That means you've found
 * (mid - i + 1) new inversions in one step, where i is your current
 * left-half pointer.
 *
 * NOTE: this function SORTS arr[left..right] as a side effect (just like
 * merge sort). That's intentional — the sorting is what enables the O(n log n)
 * inversion count.
 *
 * @return Number of inversions in arr[left..right].
 */
long long mergeCount(std::vector<int>& arr, int left, int right);

/**
 * Public interface — counts inversions in O(n log n).
 * Takes arr by VALUE (makes a copy) so the original is not modified.
 * You do NOT need to implement this — it's provided for you.
 */
long long countInversionsDC(std::vector<int> arr);

#endif // INVERSIONS_H

# Divide & Conquer — Homework

## Structure

```
merge-sort/      # HW1 — Implement Merge Sort from memory
quick-sort/      # HW2 — Quick Sort with randomized pivot
inversions/      # HW3 — Count Inversions using D&C
```

Each directory is self-contained: implement the TODO functions in the `.cpp` file, then run `make test`.

## Commands

```bash
# Run tests for a specific homework
cd merge-sort  && make test
cd quick-sort  && make test
cd inversions  && make test

# Run the demo main (visualize your algorithm with print statements)
make run

# Clean build artifacts
make clean
```

## Do not modify

- `*.h` header files — these are the fixed interfaces
- `tests.cpp` — provided test suites

## HW1 — Merge Sort

Implement in `merge-sort/merge_sort.cpp`:
- `merge(arr, left, mid, right)` — merge two sorted halves using a temp vector
- `mergeSort(arr, left, right)` — recursive divide-and-conquer

Use `mid = left + (right - left) / 2` to avoid integer overflow.

**Performance test:** must sort 100,000 random elements in under 2 seconds. (n^2 would like 5-30 seconds, this should take less than 1/10 of a second)

## HW2 — Quick Sort with Randomized Pivot

Implement in `quick-sort/quick_sort.cpp`:
- `partition(arr, low, high)` — Lomuto scheme, pivot = `arr[high]`
- `quickSort(arr, low, high, max_depth, depth)` — increment `max_depth` each call
- `quickSortRandomized(arr, low, high, max_depth, depth)` — swap a random element into `arr[high]` before partitioning; add a comment explaining why this prevents O(n²)

**Depth test:** on sorted input of 1,000 elements, deterministic depth should be ≥ 500 (O(n)); randomized should be < 250.

**Performance test:** randomized must sort 100,000 already-sorted elements in under 2 seconds. (n^2 would like 5-30 seconds, this should take less than 1/10 of a second)

## HW3 — Count Inversions ⭐⭐⭐

An inversion is a pair (i, j) where `i < j` but `arr[i] > arr[j]`.

Implement in `inversions/inversions.cpp`:
- `countInversionsBrute(arr)` — O(n²) nested loops (use to verify D&C)
- `mergeCount(arr, left, right)` — O(n log n) modified merge sort; when picking from the right half during merge, add `(mid - i + 1)` to the inversion count

`countInversionsDC` is provided — it just calls your `mergeCount`.

**Verification:** `[2, 4, 1, 3, 5]` → 3 inversions: (2,1), (4,1), (4,3).

**Performance test:** reverse-sorted 100,000 elements (maximum inversions = n*(n-1)/2 ≈ 5 billion) must complete in under 2 seconds. This will timeout if you accidentally implemented O(n²). (n^2 would like 5-30 seconds, this should take less than 1/10 of a second)

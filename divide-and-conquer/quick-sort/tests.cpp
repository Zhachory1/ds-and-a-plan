/**
 * HW2 — Quick Sort Tests
 * Do NOT modify this file.
 */

#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define UNIT_TESTING
#include "quick_sort.cpp"

// ── Test harness ─────────────────────────────────────────────────────────────

int passed = 0;
int failed = 0;

void logPass(const std::string& name) {
    std::cout << "[\033[32mPASS\033[0m] " << name << "\n";
    passed++;
}

void logFail(const std::string& name, const std::string& msg) {
    std::cout << "[\033[31mFAIL\033[0m] " << name << " — " << msg << "\n";
    failed++;
}

bool isSorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

// Sort a copy with deterministic quickSort and return it.
std::vector<int> runDet(std::vector<int> arr) {
    int d = 0;
    if (arr.size() > 1)
        quickSort(arr, 0, static_cast<int>(arr.size()) - 1, d);
    return arr;
}

// Sort a copy with randomized quickSort and return it.
std::vector<int> runRand(std::vector<int> arr) {
    int d = 0;
    if (arr.size() > 1)
        quickSortRandomized(arr, 0, static_cast<int>(arr.size()) - 1, d);
    return arr;
}

// ── Correctness: deterministic ────────────────────────────────────────────────

void testDetEmpty() {
    try {
        auto r = runDet({});
        if (r.empty()) logPass("Det — empty array");
        else logFail("Det — empty array", "Expected empty");
    } catch (const std::exception& e) { logFail("Det — empty array", e.what()); }
}

void testDetSingleElement() {
    try {
        if (runDet({99}) == std::vector<int>{99}) logPass("Det — single element");
        else logFail("Det — single element", "Value changed");
    } catch (const std::exception& e) { logFail("Det — single element", e.what()); }
}

void testDetReverseSorted() {
    try {
        auto r = runDet({5, 4, 3, 2, 1});
        if (r == std::vector<int>{1, 2, 3, 4, 5}) logPass("Det — reverse sorted");
        else logFail("Det — reverse sorted", "Expected [1,2,3,4,5]");
    } catch (const std::exception& e) { logFail("Det — reverse sorted", e.what()); }
}

void testDetAllSame() {
    try {
        auto r = runDet({3, 3, 3, 3});
        if (r == std::vector<int>{3, 3, 3, 3}) logPass("Det — all same");
        else logFail("Det — all same", "Values changed");
    } catch (const std::exception& e) { logFail("Det — all same", e.what()); }
}

void testDetMixed() {
    try {
        auto r = runDet({3, 1, 4, 1, 5, 9, 2, 6});
        if (isSorted(r) && r.size() == 8) logPass("Det — mixed array");
        else logFail("Det — mixed array", "Not sorted");
    } catch (const std::exception& e) { logFail("Det — mixed array", e.what()); }
}

// ── Correctness: randomized ───────────────────────────────────────────────────

void testRandReverseSorted() {
    try {
        auto r = runRand({5, 4, 3, 2, 1});
        if (r == std::vector<int>{1, 2, 3, 4, 5}) logPass("Rand — reverse sorted");
        else logFail("Rand — reverse sorted", "Expected [1,2,3,4,5]");
    } catch (const std::exception& e) { logFail("Rand — reverse sorted", e.what()); }
}

void testRandMixed() {
    try {
        auto r = runRand({3, 1, 4, 1, 5, 9, 2, 6});
        if (isSorted(r) && r.size() == 8) logPass("Rand — mixed array");
        else logFail("Rand — mixed array", "Not sorted");
    } catch (const std::exception& e) { logFail("Rand — mixed array", e.what()); }
}

// ── Depth comparison on sorted input ─────────────────────────────────────────

void testDepthComparison() {
    // On a sorted array, deterministic Lomuto always picks the max element
    // as pivot, producing O(n) recursion depth. Randomized should do much better.
    const int N = 1000;
    std::vector<int> sorted_arr(N);
    std::iota(sorted_arr.begin(), sorted_arr.end(), 1);  // [1, 2, ..., 1000]

    std::vector<int> a = sorted_arr, b = sorted_arr;
    int depth_det = 0, depth_rand = 0;

    quickSort(a, 0, N - 1, depth_det);
    srand(42);
    quickSortRandomized(b, 0, N - 1, depth_rand);

    // Deterministic should hit depth close to N on sorted input
    bool det_deep = (depth_det >= N / 2);
    // Randomized should stay well under N/2 on average
    bool rand_shallow = (depth_rand < N / 4);

    if (det_deep && rand_shallow) {
        std::string msg = "det=" + std::to_string(depth_det) +
                          ", rand=" + std::to_string(depth_rand);
        logPass("Depth comparison (sorted n=1000) — " + msg);
    } else {
        std::string msg = "det_depth=" + std::to_string(depth_det) +
                          ", rand_depth=" + std::to_string(depth_rand);
        if (!det_deep)
            logFail("Depth comparison", "Deterministic depth too shallow (" + msg + ") — Lomuto on sorted input should be O(n)");
        else
            logFail("Depth comparison", "Randomized depth not shallow enough (" + msg + ") — check your randomization");
    }
}

// ── Performance: randomized on sorted input (worst case for deterministic) ───

void testRandPerformanceOnSorted() {
    const int N = 100000;
    std::vector<int> arr(N);
    std::iota(arr.begin(), arr.end(), 1);  // already sorted — worst case for deterministic

    int max_depth = 0;
    srand(12345);

    auto start = std::chrono::high_resolution_clock::now();
    quickSortRandomized(arr, 0, N - 1, max_depth);
    auto end = std::chrono::high_resolution_clock::now();

    double elapsed = std::chrono::duration<double>(end - start).count();
    std::string timing = std::to_string(elapsed).substr(0, 5) + "s";

    if (!isSorted(arr)) {
        logFail("Rand performance — sorted 100K", "Array not sorted correctly");
    } else if (elapsed > 2.0) {
        logFail("Rand performance — sorted 100K",
                "Too slow (" + timing + ") — randomization should prevent O(n²)");
    } else {
        logPass("Rand performance — sorted 100K — " + timing +
                ", max_depth=" + std::to_string(max_depth));
    }
}

// ── Main ──────────────────────────────────────────────────────────────────────

int main() {
    srand(42);
    std::cout << "--- HW2: Quick Sort Tests ---\n\n";

    std::cout << "Correctness (deterministic):\n";
    testDetEmpty();
    testDetSingleElement();
    testDetReverseSorted();
    testDetAllSame();
    testDetMixed();

    std::cout << "\nCorrectness (randomized):\n";
    testRandReverseSorted();
    testRandMixed();

    std::cout << "\nDepth comparison:\n";
    testDepthComparison();

    std::cout << "\nPerformance:\n";
    testRandPerformanceOnSorted();

    std::cout << "\n---------------------------------\n";
    std::cout << "Results: " << passed << " passed, " << failed << " failed.\n";
    return failed == 0 ? 0 : 1;
}

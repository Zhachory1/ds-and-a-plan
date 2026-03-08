/**
 * HW1 — Merge Sort Tests
 * Do NOT modify this file.
 */

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#define UNIT_TESTING
#include "merge_sort.cpp"

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

// Sort arr using student's mergeSort and return it.
std::vector<int> run(std::vector<int> arr) {
    if (!arr.empty())
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    return arr;
}

bool isSorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

// ── Correctness tests ─────────────────────────────────────────────────────────

void testEmpty() {
    try {
        auto result = run({});
        if (result.empty()) logPass("Empty array");
        else logFail("Empty array", "Expected empty result");
    } catch (const std::exception& e) {
        logFail("Empty array", e.what());
    }
}

void testSingleElement() {
    try {
        auto result = run({42});
        if (result == std::vector<int>{42}) logPass("Single element");
        else logFail("Single element", "Value changed");
    } catch (const std::exception& e) {
        logFail("Single element", e.what());
    }
}

void testTwoElements() {
    try {
        auto result = run({2, 1});
        if (result == std::vector<int>{1, 2}) logPass("Two elements (unsorted)");
        else logFail("Two elements (unsorted)", "Expected [1, 2]");
    } catch (const std::exception& e) {
        logFail("Two elements (unsorted)", e.what());
    }
}

void testAlreadySorted() {
    try {
        std::vector<int> input = {1, 2, 3, 4, 5};
        auto result = run(input);
        if (result == input) logPass("Already sorted");
        else logFail("Already sorted", "Array changed");
    } catch (const std::exception& e) {
        logFail("Already sorted", e.what());
    }
}

void testReverseSorted() {
    try {
        auto result = run({5, 4, 3, 2, 1});
        if (result == std::vector<int>{1, 2, 3, 4, 5}) logPass("Reverse sorted");
        else logFail("Reverse sorted", "Expected [1, 2, 3, 4, 5]");
    } catch (const std::exception& e) {
        logFail("Reverse sorted", e.what());
    }
}

void testAllSame() {
    try {
        auto result = run({7, 7, 7, 7, 7});
        if (result == std::vector<int>{7, 7, 7, 7, 7}) logPass("All same elements");
        else logFail("All same elements", "Values changed");
    } catch (const std::exception& e) {
        logFail("All same elements", e.what());
    }
}

void testMixedArray() {
    try {
        auto result = run({3, 1, 4, 1, 5, 9, 2, 6, 5, 3});
        if (isSorted(result) && result.size() == 10)
            logPass("Mixed array");
        else
            logFail("Mixed array", "Not sorted or wrong size");
    } catch (const std::exception& e) {
        logFail("Mixed array", e.what());
    }
}

void testNegativeNumbers() {
    try {
        auto result = run({-3, 5, -1, 0, -7, 2});
        if (result == std::vector<int>{-7, -3, -1, 0, 2, 5}) logPass("Negative numbers");
        else logFail("Negative numbers", "Expected [-7, -3, -1, 0, 2, 5]");
    } catch (const std::exception& e) {
        logFail("Negative numbers", e.what());
    }
}

// ── Performance test ──────────────────────────────────────────────────────────

void testLargePerformance() {
    const int N = 100000;
    std::vector<int> arr(N);
    srand(12345);
    for (int& x : arr) x = rand();

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, N - 1);
    auto end = std::chrono::high_resolution_clock::now();

    double elapsed = std::chrono::duration<double>(end - start).count();
    std::string timing = std::to_string(elapsed).substr(0, 5) + "s";

    if (!isSorted(arr)) {
        logFail("Large random (100K elements)", "Array not sorted correctly");
    } else if (elapsed > 2.0) {
        logFail("Large random (100K elements)",
                "Too slow (" + timing + ") — is your algorithm O(n log n)?");
    } else {
        logPass("Large random (100K elements) — " + timing);
    }
}

// ── Main ──────────────────────────────────────────────────────────────────────

int main() {
    std::cout << "--- HW1: Merge Sort Tests ---\n\n";

    testEmpty();
    testSingleElement();
    testTwoElements();
    testAlreadySorted();
    testReverseSorted();
    testAllSame();
    testMixedArray();
    testNegativeNumbers();

    std::cout << "\n--- Performance ---\n";
    testLargePerformance();

    std::cout << "\n---------------------------------\n";
    std::cout << "Results: " << passed << " passed, " << failed << " failed.\n";
    return failed == 0 ? 0 : 1;
}

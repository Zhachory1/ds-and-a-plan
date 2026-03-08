/**
 * HW3 — Count Inversions Tests
 * Do NOT modify this file.
 */

#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define UNIT_TESTING
#include "inversions.cpp"

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

// ── Brute force tests (verify correctness first) ─────────────────────────────

void testBruteExample() {
    // [2, 4, 1, 3, 5] → inversions: (2,1), (4,1), (4,3) = 3
    try {
        long long result = countInversionsBrute({2, 4, 1, 3, 5});
        if (result == 3) logPass("Brute — example [2,4,1,3,5] = 3");
        else logFail("Brute — example [2,4,1,3,5]",
                     "Expected 3, got " + std::to_string(result));
    } catch (const std::exception& e) { logFail("Brute — example", e.what()); }
}

void testBruteSorted() {
    try {
        long long result = countInversionsBrute({1, 2, 3, 4, 5});
        if (result == 0) logPass("Brute — sorted array = 0");
        else logFail("Brute — sorted array", "Expected 0, got " + std::to_string(result));
    } catch (const std::exception& e) { logFail("Brute — sorted array", e.what()); }
}

void testBruteReverseSorted() {
    // Reverse sorted [5,4,3,2,1]: every pair is an inversion → n*(n-1)/2 = 10
    try {
        long long result = countInversionsBrute({5, 4, 3, 2, 1});
        if (result == 10) logPass("Brute — reverse sorted [5,4,3,2,1] = 10");
        else logFail("Brute — reverse sorted", "Expected 10, got " + std::to_string(result));
    } catch (const std::exception& e) { logFail("Brute — reverse sorted", e.what()); }
}

void testBruteAllSame() {
    try {
        long long result = countInversionsBrute({7, 7, 7, 7});
        if (result == 0) logPass("Brute — all same = 0");
        else logFail("Brute — all same", "Expected 0, got " + std::to_string(result));
    } catch (const std::exception& e) { logFail("Brute — all same", e.what()); }
}

void testBruteEmpty() {
    try {
        long long result = countInversionsBrute({});
        if (result == 0) logPass("Brute — empty = 0");
        else logFail("Brute — empty", "Expected 0, got " + std::to_string(result));
    } catch (const std::exception& e) { logFail("Brute — empty", e.what()); }
}

// ── D&C tests ─────────────────────────────────────────────────────────────────

void testDCExample() {
    try {
        long long result = countInversionsDC({2, 4, 1, 3, 5});
        if (result == 3) logPass("D&C — example [2,4,1,3,5] = 3");
        else logFail("D&C — example [2,4,1,3,5]",
                     "Expected 3, got " + std::to_string(result));
    } catch (const std::exception& e) { logFail("D&C — example", e.what()); }
}

void testDCSorted() {
    try {
        long long result = countInversionsDC({1, 2, 3, 4, 5});
        if (result == 0) logPass("D&C — sorted array = 0");
        else logFail("D&C — sorted array", "Expected 0, got " + std::to_string(result));
    } catch (const std::exception& e) { logFail("D&C — sorted array", e.what()); }
}

void testDCReverseSorted() {
    try {
        long long result = countInversionsDC({5, 4, 3, 2, 1});
        if (result == 10) logPass("D&C — reverse sorted [5,4,3,2,1] = 10");
        else logFail("D&C — reverse sorted", "Expected 10, got " + std::to_string(result));
    } catch (const std::exception& e) { logFail("D&C — reverse sorted", e.what()); }
}

void testDCMatchesBrute() {
    // Verify D&C matches brute force on several random-ish arrays
    struct Case { std::vector<int> arr; std::string label; };
    std::vector<Case> cases = {
        {{3, 1, 2},       "[3,1,2]"},
        {{1, 3, 2, 4},    "[1,3,2,4]"},
        {{6, 5, 4, 3, 2, 1}, "[6,5,4,3,2,1]"},
        {{1, 2, 3, 4, 5, 6}, "[1,2,3,4,5,6]"},
        {{4, 2, 3, 1},    "[4,2,3,1]"},
    };
    for (auto& c : cases) {
        try {
            long long brute = countInversionsBrute(c.arr);
            long long dc    = countInversionsDC(c.arr);
            if (brute == dc)
                logPass("D&C matches brute — " + c.label + " = " + std::to_string(dc));
            else
                logFail("D&C matches brute — " + c.label,
                        "brute=" + std::to_string(brute) + " dc=" + std::to_string(dc));
        } catch (const std::exception& e) {
            logFail("D&C matches brute — " + c.label, e.what());
        }
    }
}

void testDCDoesNotModifyInput() {
    // countInversionsDC takes arr by value, so the original must be unchanged
    try {
        std::vector<int> original = {3, 1, 4, 1, 5};
        std::vector<int> copy     = original;
        countInversionsDC(original);
        if (original == copy) logPass("D&C — does not modify original array");
        else logFail("D&C — does not modify original array",
                     "Original was changed (should take arr by value)");
    } catch (const std::exception& e) {
        logFail("D&C — does not modify original array", e.what());
    }
}

// ── Performance test ──────────────────────────────────────────────────────────

void testDCLargePerformance() {
    const int N = 100000;
    // Reverse-sorted — maximum possible inversions, hardest case
    std::vector<int> arr(N);
    std::iota(arr.begin(), arr.end(), 1);
    std::reverse(arr.begin(), arr.end());  // [N, N-1, ..., 2, 1]

    long long expected = static_cast<long long>(N) * (N - 1) / 2;

    auto start = std::chrono::high_resolution_clock::now();
    long long result = countInversionsDC(arr);
    auto end   = std::chrono::high_resolution_clock::now();

    double elapsed = std::chrono::duration<double>(end - start).count();
    std::string timing = std::to_string(elapsed).substr(0, 5) + "s";

    if (result != expected) {
        logFail("D&C performance — reverse 100K",
                "Wrong count: expected " + std::to_string(expected) +
                ", got " + std::to_string(result));
    } else if (elapsed > 2.0) {
        logFail("D&C performance — reverse 100K",
                "Too slow (" + timing + ") — must be O(n log n)");
    } else {
        logPass("D&C performance — reverse 100K — " + timing +
                " (inversions=" + std::to_string(result) + ")");
    }
}

// ── Main ──────────────────────────────────────────────────────────────────────

int main() {
    std::cout << "--- HW3: Count Inversions Tests ---\n\n";

    std::cout << "Brute force (O(n²) — verify these first):\n";
    testBruteEmpty();
    testBruteSorted();
    testBruteAllSame();
    testBruteReverseSorted();
    testBruteExample();

    std::cout << "\nDivide & Conquer (O(n log n)):\n";
    testDCSorted();
    testDCReverseSorted();
    testDCExample();
    testDCMatchesBrute();
    testDCDoesNotModifyInput();

    std::cout << "\nPerformance:\n";
    testDCLargePerformance();

    std::cout << "\n---------------------------------\n";
    std::cout << "Results: " << passed << " passed, " << failed << " failed.\n";
    return failed == 0 ? 0 : 1;
}

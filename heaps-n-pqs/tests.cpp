#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>

#define UNIT_TESTING 

#include "minheap.cpp"
#include "kclosest.cpp"

// --- Simple Testing Framework ---
int passed = 0;
int failed = 0;

void logPass(const std::string& testName) {
    std::cout << "[\033[32mPASS\033[0m] " << testName << std::endl;
    passed++;
}

void logFail(const std::string& testName, const std::string& msg) {
    std::cout << "[\033[31mFAIL\033[0m] " << testName << " - " << msg << std::endl;
    failed++;
}

// --- MinHeap Tests ---
void testHeapPushPop() {
    try {
        MinHeap h;
        h.push(10);
        h.push(5);
        h.push(30);
        h.push(2);

        if (h.pop() != 2) throw std::runtime_error("1st pop was not 2");
        if (h.pop() != 5) throw std::runtime_error("2nd pop was not 5");
        if (h.pop() != 10) throw std::runtime_error("3rd pop was not 10");
        if (h.pop() != 30) throw std::runtime_error("4th pop was not 30");

        logPass("Heap Push/Pop Sorting Logic");
    } catch (const std::exception& e) {
        logFail("Heap Push/Pop Sorting Logic", e.what());
    }
}

void testHeapBubbleUp() {
    try {
        MinHeap h;
        h.push(1); // Smallest first
        h.push(10);
        h.push(20); 
        // Logic check: The root should remain 1
        if (h.peek() != 1) throw std::runtime_error("Root is not 1");
        
        h.push(0); // New smallest, should bubble to top
        if (h.peek() != 0) throw std::runtime_error("New smallest 0 did not bubble to top");
        
        logPass("Heap Bubble Up Logic");
    } catch (const std::exception& e) {
        logFail("Heap Bubble Up Logic", e.what());
    }
}

// --- KClosest Tests ---
void testKClosestBasic() {
    Solution sol;
    std::vector<Point> points = {{1, 3}, {-2, 2}};
    // (-2,2) distSq = 8. (1,3) distSq = 10.
    // Closest is {-2, 2}
    
    std::vector<Point> result = sol.kClosest(points, 1);
    
    if (result.size() != 1) {
        logFail("KClosest Basic", "Result size is incorrect");
        return;
    }
    
    if (result[0].x == -2 && result[0].y == 2) {
        logPass("KClosest Basic");
    } else {
        logFail("KClosest Basic", "Did not return [-2, 2]");
    }
}

void testKClosestLarger() {
    Solution sol;
    // Points: (3,3)=18, (5,-1)=26, (-2,4)=20
    std::vector<Point> points = {{3,3}, {5,-1}, {-2,4}};
    int k = 2;
    // Expected closest 2: (3,3) and (-2,4)
    
    std::vector<Point> result = sol.kClosest(points, k);
    
    if (result.size() != 2) {
        logFail("KClosest Larger", "Incorrect size");
        return;
    }

    // Helper to check if a point exists in result
    auto contains = [&](int x, int y) {
        for(auto& p : result) if(p.x==x && p.y==y) return true;
        return false;
    };

    if (contains(3,3) && contains(-2,4)) {
        logPass("KClosest Larger Input");
    } else {
        logFail("KClosest Larger Input", "Missing correct points");
    }
}

int main() {
    std::cout << "--- Running MinHeap Tests ---" << std::endl;
    testHeapBubbleUp();
    testHeapPushPop();

    std::cout << "\n--- Running KClosest Tests ---" << std::endl;
    testKClosestBasic();
    testKClosestLarger();

    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "Results: " << passed << " Passed, " << failed << " Failed." << std::endl;
    
    return failed == 0 ? 0 : 1;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;

    long distanceSq() const {
        return (x * x) + (y * y);
    }

    bool operator<(const Point& other) const {
        return distanceSq() < other.distanceSq();
    }
};

class Solution {
public:
    vector<Point> kClosest(vector<Point>& points, int k) {
        // STRATEGY HINT:
        // We want the K *smallest* distances.
        // If we use a Max-Heap of size K:
        //    - We keep the K smallest elements seen SO FAR.
        //    - If a new point is smaller than the heap's root (the largest of the smalls),
        //      we pop the root and push the new point.
        
        // 1. Define a Max-Heap (priority_queue).
        //    C++ priority_queue is a Max-Heap by default.
        //    You will need to store pairs of {distance, index} OR custom Point objects.
        std::priority_queue<Point> max_heap;
        
        // 2. Iterate through points and maintain the heap size at K.
        for (Point point : points) {
            max_heap.push(point);

            if (max_heap.size() > k) max_heap.pop();
        }
        
        // 3. Extract results from heap into a vector.
        std::vector<Point> k_closest;

        while (!max_heap.empty()) {
            k_closest.emplace_back(max_heap.top());
            max_heap.pop();
        }
        
        return k_closest;
    }
};

// --- Test Driver ---
#ifndef UNIT_TESTING
int main() {
    Solution sol;
    
    // Input: (1,3), (-2,2) with K=1
    // Distances: (1,3) -> 1+9=10. (-2,2) -> 4+4=8.
    // Closest is (-2,2).
    vector<Point> points = {{1, 3}, {-2, 2}};
    int k = 1;
    
    vector<Point> result = sol.kClosest(points, k);
    
    cout << "K Closest Points: " << endl;
    for (const auto& p : result) {
        cout << "[" << p.x << ", " << p.y << "]" << endl;
    }
    
    return 0;
}
#endif
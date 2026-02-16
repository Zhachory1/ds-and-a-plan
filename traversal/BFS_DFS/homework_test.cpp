/**
 * Unit tests for Graph Search Homework
 * Students should run these tests to verify their implementations.
 *
 * Compile: make test
 * Run: ./test_homework
 */

#include "student_solutions.h"
#include <iostream>
#include <cassert>
#include <string>

// Simple test framework
int tests_passed = 0;
int tests_failed = 0;

void test(const std::string& test_name, bool condition) {
    if (condition) {
        std::cout << "✓ " << test_name << std::endl;
        tests_passed++;
    } else {
        std::cout << "✗ " << test_name << std::endl;
        tests_failed++;
    }
}

// ============================================================================
// Connected Components Tests
// ============================================================================

void testSingleComponent() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    
    test("test_single_component", findConnectedComponents(g) == 1);
}

void testTwoComponents() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    
    test("test_two_components", findConnectedComponents(g) == 2);
}

void testAllIsolated() {
    Graph g(5);
    test("test_all_isolated", findConnectedComponents(g) == 5);
}

void testThreeComponents() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(5, 6);
    
    test("test_three_components", findConnectedComponents(g) == 3);
}

void testEmptyGraph() {
    Graph g(0);
    test("test_empty_graph", findConnectedComponents(g) == 0);
}

// ============================================================================
// Shortest Path Tests
// ============================================================================

void testSimplePath() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    
    test("test_simple_path", shortestPathGrid(grid, {0, 0}, {2, 2}) == 4);
}

void testWithObstacles() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    test("test_with_obstacles", shortestPathGrid(grid, {0, 0}, {3, 3}) == 6);
}

void testNoPath() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0}
    };
    
    test("test_no_path", shortestPathGrid(grid, {0, 0}, {2, 2}) == -1);
}

void testStartEqualsEnd() {
    std::vector<std::vector<int>> grid = {
        {0, 0},
        {0, 0}
    };
    
    test("test_start_equals_end", shortestPathGrid(grid, {0, 0}, {0, 0}) == 0);
}

void testComplexMaze() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    
    test("test_complex_maze", shortestPathGrid(grid, {0, 0}, {4, 4}) == 8);
}

void testBlockedStart() {
    std::vector<std::vector<int>> grid = {
        {1, 0},
        {0, 0}
    };
    
    test("test_blocked_start", shortestPathGrid(grid, {0, 0}, {1, 1}) == -1);
}

// ============================================================================
// Main Test Runner
// ============================================================================

int main() {
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "Running Graph Search Homework Tests" << std::endl;
    std::cout << std::string(70, '=') << "\n" << std::endl;
    
    std::cout << "Testing findConnectedComponents..." << std::endl;
    testSingleComponent();
    testTwoComponents();
    testAllIsolated();
    testThreeComponents();
    testEmptyGraph();
    
    std::cout << "\nTesting shortestPathGrid..." << std::endl;
    testSimplePath();
    testWithObstacles();
    testNoPath();
    testStartEqualsEnd();
    testComplexMaze();
    testBlockedStart();
    
    std::cout << "\n" << std::string(70, '=') << std::endl;
    if (tests_failed == 0) {
        std::cout << "🎉 Congratulations! All " << tests_passed << " tests passed!" << std::endl;
    } else {
        std::cout << "❌ " << tests_failed << " test(s) failed, " 
                  << tests_passed << " test(s) passed" << std::endl;
        std::cout << "Keep working on your implementation!" << std::endl;
    }
    std::cout << std::string(70, '=') << std::endl;
    
    return tests_failed;
}

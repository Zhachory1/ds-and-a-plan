/**
 * Student Solutions Implementation
 * Implement the functions declared in student_solutions.h
 */

#include "student_solutions.h"
#include <iostream>

int findConnectedComponents(const Graph& graph) {
    // TODO: Implement this function
    
    // Hint: Use a set to track visited vertices
    // For each unvisited vertex, start a DFS
    
    return 0; // Replace with your implementation
}

void dfsHelper(const Graph& graph, int vertex, std::set<int>& visited) {
    // TODO: Implement this helper function
}

int shortestPathGrid(const std::vector<std::vector<int>>& grid, 
                     std::pair<int, int> start, 
                     std::pair<int, int> end) {
    // TODO: Implement this function
    
    // Hint: Use BFS with a queue
    
    return -1; // Replace with your implementation
}

// ============================================================================
// Example test code - run this to test your implementations manually
// ============================================================================

int main() {
    std::cout << "Testing findConnectedComponents:" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    // Test case 1: Two components
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    
    std::cout << "Graph:" << std::endl;
    std::cout << g.toString() << std::endl;
    std::cout << "Expected components: 2" << std::endl;
    std::cout << "Your result: " << findConnectedComponents(g) << std::endl;
    
    std::cout << "\n" << std::string(70, '=') << "\n" << std::endl;
    
    std::cout << "Testing shortestPathGrid:" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    // Test case 2: Simple grid
    std::vector<std::vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
    std::cout << "Grid:" << std::endl;
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nStart: (0, 0), End: (2, 2)" << std::endl;
    std::cout << "Expected steps: 4" << std::endl;
    std::cout << "Your result: " << shortestPathGrid(grid, {0, 0}, {2, 2}) << std::endl;
    
    std::cout << "\n" << std::string(70, '=') << std::endl;
    std::cout << "\nRun 'make test' to test all cases!" << std::endl;
    
    return 0;
}

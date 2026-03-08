/**
 * Student Solutions Implementation
 * Implement the functions declared in student_solutions.h
 */

#include "student_solutions.h"
#include <iostream>

int findConnectedComponents(const Graph& graph) {
    std::set<int> visited;
    std::vector<int> stack;
    stack.resize(graph.getNumVertices());

    int components = 0;
    for (int vertex = 0; vertex < graph.getNumVertices(); vertex++) {
        if (visited.find(vertex) != visited.end()) {
            continue;
        }

        components++;
        visited.insert(vertex);
        stack.push_back(vertex);

        while (!stack.empty()) {
            int current = stack.back();
            stack.pop_back();

            for (int neighbor : graph.getNeighbors(current)) {
                // Check if neighbor was not visited before
                if (visited.insert(neighbor).second) {
                    stack.push_back(neighbor);
                }
            }
        }
    }

    return components;
}

void dfsHelper(const Graph& graph, int vertex, std::set<int>& visited) {
    // TODO: Implement this helper function
}

int shortestPathGrid(const std::vector<std::vector<int>>& grid, 
                     std::pair<int, int> start, 
                     std::pair<int, int> end) {
    GridGraph graph(grid);

    std::queue<std::pair<int, int>> queue;
    std::vector<std::vector<int>> distances(graph.getRows(), std::vector<int>(graph.getCols(), -1));

    queue.push(start);
    distances[start.first][start.second] = 0;

    while (!queue.empty()) {
        std::pair<int, int> current = queue.front();
        queue.pop();

        if (current == end) {
            return distances[current.first][current.second];
        }

        for (std::pair<int, int> neighbor : graph.getNeighbors(current.first, current.second)) {
            distances[neighbor.first][neighbor.second] = distances[current.first][current.second] + 1;
            queue.push(neighbor);
        }
    }

    return -1;
}

// ============================================================================
// Example test code - run this to test your implementations manually
// ============================================================================

#ifndef HOMEWORK_TEST_BUILD
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
#endif

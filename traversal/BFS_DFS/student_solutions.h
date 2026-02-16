/**
 * Student Solutions File
 * Complete the functions below to solve the homework problems.
 *
 * Your task:
 * 1. Implement findConnectedComponents using DFS
 * 2. Implement shortestPathGrid using BFS
 *
 * Good luck! 🚀
 */

#ifndef STUDENT_SOLUTIONS_H
#define STUDENT_SOLUTIONS_H

#include "Graph.h"
#include <vector>
#include <set>
#include <queue>

/**
 * Count the number of connected components in an undirected graph using DFS.
 * 
 * A connected component is a group of vertices where there is a path between
 * any two vertices in the group.
 * 
 * @param graph The graph to analyze
 * @return Number of connected components
 * 
 * Example:
 *     Graph with edges: (0-1), (2-3)
 *     This has 2 components: {0,1} and {2,3}
 * 
 * Hint:
 *     - Keep track of visited vertices
 *     - For each unvisited vertex, start a DFS and mark all reachable vertices
 *     - Each DFS traversal represents one component
 */
int findConnectedComponents(const Graph& graph);

/**
 * Helper function for DFS traversal.
 * 
 * @param graph The graph to traverse
 * @param vertex Current vertex to visit
 * @param visited Set of already visited vertices
 * 
 * Hint:
 *     - Mark current vertex as visited
 *     - Recursively visit all unvisited neighbors
 */
void dfsHelper(const Graph& graph, int vertex, std::set<int>& visited);

/**
 * Find the shortest path in a grid from start to end using BFS.
 * 
 * The grid contains:
 *     0 = walkable cell
 *     1 = obstacle (cannot pass through)
 * 
 * You can move up, down, left, or right (not diagonally).
 * 
 * @param grid 2D grid with 0s and 1s
 * @param start Starting position (row, col)
 * @param end Ending position (row, col)
 * @return Minimum number of steps, or -1 if no path exists
 * 
 * Example:
 *     grid = [[0, 0, 0],
 *             [0, 1, 0],
 *             [0, 0, 0]]
 *     start = (0, 0)
 *     end = (2, 2)
 *     
 *     Shortest path: (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) = 4 steps
 * 
 * Hint:
 *     - Use BFS with a queue
 *     - Store (row, col, distance) in the queue
 *     - Keep track of visited cells to avoid cycles
 *     - Use GridGraph helper methods: isValid() and getNeighbors()
 */
int shortestPathGrid(const std::vector<std::vector<int>>& grid, 
                     std::pair<int, int> start, 
                     std::pair<int, int> end);

#endif // STUDENT_SOLUTIONS_H

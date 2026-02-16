/**
 * Boilerplate Graph classes for homework
 * Students should use these classes for their implementations
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

/**
 * A simple undirected graph represented as an adjacency list
 */
class Graph {
private:
    int num_vertices;
    std::vector<std::vector<int>> adj_list;

public:
    /**
     * Initialize a graph with num_vertices vertices
     * @param vertices Number of vertices in the graph
     */
    explicit Graph(int vertices) : num_vertices(vertices) {
        adj_list.resize(vertices);
    }

    /**
     * Add an undirected edge between vertices u and v
     * @param u First vertex
     * @param v Second vertex
     */
    void addEdge(int u, int v) {
        if (u >= num_vertices || v >= num_vertices || u < 0 || v < 0) {
            throw std::out_of_range("Vertex out of bounds");
        }
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    /**
     * Get all neighbors of a given vertex
     * @param vertex The vertex to get neighbors for
     * @return Vector of neighboring vertices
     */
    const std::vector<int>& getNeighbors(int vertex) const {
        return adj_list[vertex];
    }

    /**
     * Get the number of vertices in the graph
     * @return Number of vertices
     */
    int getNumVertices() const {
        return num_vertices;
    }

    /**
     * String representation of the graph
     */
    std::string toString() const {
        std::ostringstream oss;
        for (int i = 0; i < num_vertices; i++) {
            oss << i << ": [";
            for (size_t j = 0; j < adj_list[i].size(); j++) {
                oss << adj_list[i][j];
                if (j < adj_list[i].size() - 1) oss << ", ";
            }
            oss << "]\n";
        }
        return oss.str();
    }
};

/**
 * A grid-based graph for pathfinding problems
 * 0 = walkable cell, 1 = obstacle
 */
class GridGraph {
private:
    std::vector<std::vector<int>> grid;
    int rows;
    int cols;

public:
    /**
     * Initialize a grid graph
     * @param g 2D grid where 0 is walkable and 1 is obstacle
     */
    explicit GridGraph(const std::vector<std::vector<int>>& g) : grid(g) {
        rows = g.size();
        cols = rows > 0 ? g[0].size() : 0;
    }

    /**
     * Check if a cell is within bounds and walkable
     * @param row Row index
     * @param col Column index
     * @return True if cell is valid and walkable
     */
    bool isValid(int row, int col) const {
        return row >= 0 && row < rows && 
               col >= 0 && col < cols && 
               grid[row][col] == 0;
    }

    /**
     * Get valid neighboring cells (up, down, left, right)
     * @param row Current row
     * @param col Current column
     * @return Vector of (row, col) pairs for valid neighbors
     */
    std::vector<std::pair<int, int>> getNeighbors(int row, int col) const {
        std::vector<std::pair<int, int>> neighbors;
        // Directions: right, down, left, up
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];
            if (isValid(new_row, new_col)) {
                neighbors.push_back({new_row, new_col});
            }
        }

        return neighbors;
    }

    /**
     * Get number of rows
     */
    int getRows() const { return rows; }

    /**
     * Get number of columns
     */
    int getCols() const { return cols; }

    /**
     * String representation of the grid
     */
    std::string toString() const {
        std::ostringstream oss;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                oss << grid[i][j];
                if (j < cols - 1) oss << " ";
            }
            oss << "\n";
        }
        return oss.str();
    }
};

#endif // GRAPH_H

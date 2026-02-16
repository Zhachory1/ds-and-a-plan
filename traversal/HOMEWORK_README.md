# Graph Search Algorithms - Homework Assignment (C++)

Welcome to the Graph Search Homework! This assignment will help you master BFS, DFS, and understand computational complexity through hands-on implementation in C++.

## 📚 Learning Objectives

By completing this homework, you will:
- Understand the difference between BFS (Breadth-First Search) and DFS (Depth-First Search)
- Learn when to use each algorithm
- Implement graph traversal algorithms from scratch in C++
- Experience exponential time complexity firsthand
- Practice backtracking and recursive problem-solving
- Work with STL containers (vectors, sets, queues)

## 📁 Project Structure

```
├── BFS_DFS/
│   ├── Graph.h               # Graph classes (provided - do not modify)
│   ├── student_solutions.h   # Function declarations
│   ├── student_solutions.cpp # YOUR CODE GOES HERE
│   ├── homework_test.cpp     # Unit tests to verify your solutions
│   ├── solution.cpp          # Reference solutions (don't peek!)
│   └── Makefile              # Build configuration
├── TSP/
│   ├── tsp_solver.cpp        # YOUR CODE GOES HERE
│   ├── cities.json           # City data for TSP
│   ├── solution.cpp          # Reference solution (don't peek!)
│   ├── json.hpp              # JSON library (provided)
│   └── Makefile              # Build configuration
└── HOMEWORK_README.md        # This file
```

## 🛠️ Prerequisites

- C++ compiler (g++ or clang++) with C++11 support
- Make (for building)
- Basic knowledge of C++ STL containers

### Installation

**macOS:**
```bash
# Xcode command line tools
xcode-select --install
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get install build-essential
```

**Windows:**
Install MinGW or use WSL with the Linux instructions

## 🎯 Assignment Tasks

### Task 1: Connected Components (DFS) 🏝️

**Files:** `BFS_DFS/student_solutions.h`, `BFS_DFS/student_solutions.cpp`

**Function to implement:** `int findConnectedComponents(const Graph& graph)`

**Description:** Count the number of "islands" (connected components) in an undirected graph using DFS.

**Example:**
```
Graph edges: (0-1), (1-2), (3-4)

Visualization:
0---1---2    3---4

Components: 2 (one containing {0,1,2}, one containing {3,4})
```

**Time Complexity Goal:** O(V + E)

---

### Task 2: Shortest Path in a Grid (BFS) 🗺️

**Files:** `BFS_DFS/student_solutions.h`, `BFS_DFS/student_solutions.cpp`

**Function to implement:** `int shortestPathGrid(const std::vector<std::vector<int>>& grid, std::pair<int, int> start, std::pair<int, int> end)`

**Description:** Find the shortest path from start to end in a grid with obstacles using BFS.

**Grid Rules:**
- `0` = walkable cell
- `1` = obstacle (cannot pass)
- Can move: up, down, left, right (no diagonals)

**Example:**
```
Grid:
0 0 0
0 1 0
0 0 0

Start: (0,0)  End: (2,2)

Shortest path: (0,0) → (0,1) → (0,2) → (1,2) → (2,2)
Distance: 4 steps
```

**Time Complexity Goal:** O(rows × cols)

**Why BFS?** BFS guarantees the shortest path in unweighted graphs!

---

### Task 3: The Mini-TSP (Backtracking DFS) 🌍

**File:** `TSP/tsp_solver.cpp`

**Function to implement:** `TSPResult solveTSPBruteforce(const std::vector<City>& cities)`

**Description:** Solve the Traveling Salesperson Problem for up to 15 cities using brute-force DFS.

**Problem:** Given cities with coordinates, find the shortest route that:
- Visits each city exactly once
- Returns to the starting city

---

## 🚀 Getting Started

### Building and Running

#### For Tasks 1 & 2 (BFS/DFS):

1. **Navigate to the directory:**
   ```bash
   cd BFS_DFS
   ```

2. **Build everything:**
   ```bash
   make
   ```

3. **Run your code manually:**
   ```bash
   make run
   # or directly: ./student_solutions
   ```

4. **Run all unit tests:**
   ```bash
   make test
   # or directly: ./test_homework
   ```

5. **View the reference solution (after completing):**
   ```bash
   make demo
   # or directly: ./solution
   ```

6. **Clean build files:**
   ```bash
   make clean
   ```

#### For Task 3 (TSP):

1. **Navigate to the directory:**
   ```bash
   cd TSP
   ```

2. **Download json.hpp (nlohmann/json library):**
   ```bash
   wget https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp
   # or on macOS: curl -O https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp
   ```

3. **Build the solver:**
   ```bash
   make
   ```

4. **Run your implementation:**
   ```bash
   make run
   # or directly: ./tsp_solver
   ```

5. **View the reference solution (after completing):**
   ```bash
   make demo
   # or directly: ./solution
   ```

---

## 🎓 Conceptual Questions

After completing the homework, you should be able to answer:

1. **Why use BFS for shortest path?**
   <details>
   <summary>Click to reveal answer</summary>
   BFS explores nodes level by level, guaranteeing that when you reach the destination, you've found the shortest path (in terms of number of edges).
   </details>

2. **Why use DFS for connected components?**
   <details>
   <summary>Click to reveal answer</summary>
   DFS is simpler to implement recursively and efficiently explores all reachable vertices. For connected components, we don't need shortest paths, just reachability.
   </details>

3. **Why is TSP so slow?**
   <details>
   <summary>Click to reveal answer</summary>
   TSP requires checking all possible orderings of cities. For n cities, there are (n-1)!/2 unique routes. This factorial growth makes it intractable for large n.
   </details>

4. **When should you use BFS vs DFS?**
   <details>
   <summary>Click to reveal answer</summary>
   
   **Use BFS when:**
   - Finding shortest paths (unweighted graphs)
   - Level-order traversal
   - Finding nearest neighbors
   
   **Use DFS when:**
   - Detecting cycles
   - Topological sorting
   - Finding connected components
   - Backtracking problems
   - Memory is limited (DFS uses O(h) space vs O(w) for BFS)
   </details>

---

## 🏆 Extension Challenges (Optional)

If you finish early and want more practice:

### Challenge 1: Bidirectional BFS
Modify your shortest path solution to search from both start and end simultaneously. This can be up to 2x faster!

### Challenge 2: Cycle Detection
Add a function to detect if a graph contains a cycle using DFS.

### Challenge 3: TSP with Pruning
Optimize your TSP solver by pruning branches that are already longer than the best route found. Measure the speedup!

### Challenge 4: A* Pathfinding
Implement A* algorithm for grid pathfinding (using Manhattan distance as heuristic). Compare with BFS.

---

## 🐛 Debugging Tips

### Compilation Errors:
```bash
# Check which compiler you have
g++ --version

# Compile with verbose errors
g++ -std=c++11 -Wall -Wextra -g student_solutions.cpp -o test
```

### Runtime Errors:
```bash
# Run with valgrind (Linux/macOS) to check for memory issues
valgrind ./student_solutions

# Use gdb for debugging
gdb ./student_solutions
```

### Print Debugging:
```cpp
// Use std::cout to trace execution
std::cout << "Visiting vertex: " << vertex << std::endl;
std::cout << "Queue size: " << queue.size() << std::endl;
```

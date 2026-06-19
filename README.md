# ds-and-a-plan

Data structures and algorithms homework repository.

## Quick Start

### Run All Tests

From the repository root:

```bash
make test
```

This runs all homework module tests and reports a summary.

### Run Individual Module Tests

Each module has its own test command:

```bash
# Graphs
cd graphs && make test

# Heaps and Priority Queues
cd heaps-n-pqs && make test

# Traversal (BFS/DFS)
cd traversal/BFS_DFS && make test

# Divide and Conquer
cd divide-and-conquer/merge-sort && make test
cd divide-and-conquer/quick-sort && make test
cd divide-and-conquer/inversions && make test
```

## Structure

```
graphs/                    # Social network graph algorithms
heaps-n-pqs/              # Min-heap and K-Closest implementations
traversal/
  BFS_DFS/                # BFS/DFS homework
  BONUS/                  # Optional stretch problems (not required)
divide-and-conquer/
  merge-sort/             # Merge sort implementation
  quick-sort/             # Quick sort implementation
  inversions/             # Count inversions problem
```

## Bonus Content

The `traversal/BONUS/` directory contains optional stretch problems that are not required for homework completion. See `traversal/BONUS/README.md` for details.

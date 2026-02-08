# Social Network Graph - Homework Assignment

## Overview
This assignment implements a directed graph to model social media follower/following relationships. You will build the core functionality to analyze "The Influencer Algorithm" using graph theory concepts.

## Learning Objectives
- Understand the difference between directed and undirected graphs
- Implement adjacency lists for directed relationships
- Calculate in-degree and out-degree metrics
- Detect cycles in directed graphs (echo chambers)
- Apply graph algorithms to real-world social network problems

## Files Provided

### 1. `social_network.h`
Header file defining the `SocialNetwork` class interface. **Do not modify this file.**

### 2. `social_network.cpp`
Implementation file with skeleton code. **This is where you will write your code.**
Look for `// TODO:` comments that indicate where you need to add implementation.

### 3. `users.csv`
Sample dataset of follower relationships in the format: `FollowerID,TargetID`

### 4. `test_network.cpp`
Comprehensive unit tests to verify your implementation. **Do not modify this file.**

### 5. `Makefile`
Build system for compilation and testing.

## Getting Started

### Prerequisites
- C++ compiler with C++17 support (g++ or clang++)
- Make utility

### Build and Test
```bash
# Build the project
make

# Run all tests
make test

# Clean build artifacts
make clean

# Rebuild from scratch
make rebuild

# Show help
make help
```

## Your Tasks

### Required Implementations

#### 1. `add_edge(follower, target)`
- Add a directed edge from `follower` to `target`
- Update both the forward adjacency list and reverse adjacency list
- Handle initialization of new users

#### 2. `load_from_csv(filename)`
- Parse the CSV file line by line
- Extract follower and target from each line
- Call `add_edge()` for each relationship
- Handle file I/O errors gracefully

#### 3. `get_followers(user)`
- Return all users who follow the given user
- Use the `reverse_adj_list` for efficient lookup
- Return an empty vector if the user has no followers

#### 4. `get_following(user)`
- Return all users that the given user follows
- Simple lookup in the `adj_list`
- Return an empty vector if the user follows nobody

#### 5. `is_mutual(user_a, user_b)`
- Check if both users follow each other
- Must verify: A follows B **AND** B follows A
- Return `false` if either user doesn't exist

#### 6. `find_top_influencer()`
- Calculate the "clout ratio" for each user: `Followers / Following`
- Handle division by zero (if following count is 0, treat as infinite ratio)
- Return the username with the highest ratio

### Bonus Task

#### 7. `detect_echo_chambers()` (Advanced)
- Implement cycle detection using Depth-First Search (DFS)
- Find closed loops of users who only follow each other
- Return a vector of cycles, where each cycle is a vector of usernames
- Use the provided `has_cycle_helper()` function for DFS logic

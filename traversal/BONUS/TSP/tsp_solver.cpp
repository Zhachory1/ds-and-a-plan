/**
 * Traveling Salesperson Problem (TSP) Solver
 * Complete the brute-force DFS solution for a small-scale TSP.
 *
 * Problem: Given a set of cities, find the shortest route that visits each city
 * exactly once and returns to the starting city.
 *
 * This is a classic NP-hard problem!
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>
#include <iomanip>
#include <limits>
#include "json.hpp"

using json = nlohmann::json;

// ============================================================================
// City Structure
// ============================================================================

struct City
{
    std::string name;
    double x;
    double y;
};

// ============================================================================
// Helper Functions
// ============================================================================

std::vector<City> loadCities(const std::string &filename, int num_cities = 5)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return {};
    }

    json data;
    file >> data;

    std::vector<City> cities;

    int available = static_cast<int>(data["cities"].size());
    int count = std::min(num_cities, available);

    for (int i = 0; i < count; i++)
    {
        City city;
        city.name = data["cities"][i]["name"];
        city.x = data["cities"][i]["x"];
        city.y = data["cities"][i]["y"];
        cities.push_back(city);
    }

    return cities;
}

double calculateDistance(const City &city1, const City &city2)
{
    double dx = city1.x - city2.x;
    double dy = city1.y - city2.y;
    return std::sqrt(dx * dx + dy * dy);
}

double calculateRouteDistance(const std::vector<int> &route, const std::vector<City> &cities)
{
    double total_distance = 0.0;

    // Sum distances between consecutive cities in route
    for (size_t i = 0; i < route.size() - 1; i++)
    {
        total_distance += calculateDistance(cities[route[i]], cities[route[i + 1]]);
    }

    // Add distance from last city back to first city
    total_distance += calculateDistance(cities[route.back()], cities[route[0]]);

    return total_distance;
}

// ============================================================================
// TSP Solver - YOUR IMPLEMENTATION GOES HERE
// ============================================================================

struct TSPResult
{
    std::vector<int> best_route;
    double best_distance;
    int routes_explored;
};

/**
 * Solve TSP using brute-force DFS to try all possible routes.
 *
 * This explores all permutations of city orders to find the optimal route.
 *
 * @param cities Vector of City objects
 * @return TSPResult containing best route, distance, and count of routes explored
 *
 * Your task:
 *     Implement a DFS-based solution that:
 *     1. Starts from city 0
 *     2. Explores all permutations of the remaining cities
 *     3. Tracks the shortest route found
 *     4. Returns the best route, its distance, and count of routes explored
 */
TSPResult solveTSPBruteforce(const std::vector<City> &cities)
{
    // TODO: Implement this function

    TSPResult result;
    result.best_distance = std::numeric_limits<double>::infinity();
    result.routes_explored = 0;

    // TODO: Implement DFS helper function (you can use a lambda or separate function)
    // void dfs(std::vector<int>& current_route, std::vector<bool>& visited) {
    //     ...
    // }

    // TODO: Start DFS from city 0

    return result;
}

// ============================================================================
// Testing and Timing Code
// ============================================================================

std::string formatRoute(const std::vector<int> &route, const std::vector<City> &cities)
{
    std::string result;
    for (size_t i = 0; i < route.size(); i++)
    {
        result += cities[route[i]].name;
        result += " -> ";
    }
    result += cities[route[0]].name;
    return result;
}

long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void runTSPExperiment()
{
    std::cout << std::string(80, '=') << std::endl;
    std::cout << "TRAVELING SALESPERSON PROBLEM - Performance Analysis" << std::endl;
    std::cout << std::string(80, '=') << "\n"
              << std::endl;

    for (int num_cities : {5, 6, 7})
    {
        std::cout << std::string(80, '=') << std::endl;
        std::cout << "Solving TSP with " << num_cities << " cities:" << std::endl;
        std::cout << std::string(80, '-') << std::endl;

        std::vector<City> cities = loadCities("cities.json", num_cities);

        if (cities.empty())
        {
            std::cout << "Error loading cities!" << std::endl;
            continue;
        }

        // Display cities
        std::cout << "\nCities:" << std::endl;
        for (size_t i = 0; i < cities.size(); i++)
        {
            std::cout << "  " << i << ". " << cities[i].name
                      << " at (" << cities[i].x << ", " << cities[i].y << ")" << std::endl;
        }

        // Solve and time it
        auto start_time = std::chrono::high_resolution_clock::now();
        TSPResult result = solveTSPBruteforce(cities);
        auto end_time = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end_time - start_time;

        // Display results
        if (!result.best_route.empty())
        {
            std::cout << "\n✅ Optimal Route Found:" << std::endl;
            std::cout << "   " << formatRoute(result.best_route, cities) << std::endl;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "\n📏 Total Distance: " << result.best_distance << std::endl;
            std::cout << "🔍 Routes Explored: " << result.routes_explored << std::endl;
            std::cout << std::setprecision(4);
            std::cout << "⏱️  Time Taken: " << elapsed.count() << " seconds" << std::endl;

            // Educational note about complexity
            long long factorial_val = factorial(num_cities - 1);
            std::cout << "\n💡 Theoretical routes to check: (" << num_cities
                      << "-1)! = " << factorial_val << std::endl;
        }
        else
        {
            std::cout << "\n❌ No solution found. Did you implement the function?" << std::endl;
        }

        std::cout << std::string(80, '=') << std::endl;
    }

    // Analysis
    std::cout << "\n"
              << std::string(80, '=') << std::endl;
    std::cout << "ANALYSIS: Notice How Time Grows!" << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    std::cout << R"(
As you add more cities, the execution time EXPLODES exponentially!

- 5 cities: (5-1)! = 24 possible routes
- 6 cities: (6-1)! = 120 possible routes (5x more)
- 7 cities: (7-1)! = 720 possible routes (6x more)

This is why TSP is NP-hard! For realistic problems (50+ cities),
brute force is impossible. We need smarter algorithms like:
  • Branch and Bound
  • Dynamic Programming (Held-Karp)
  • Approximation algorithms (Christofides)
  • Heuristics (Genetic Algorithms, Simulated Annealing)
)" << std::endl;
    std::cout << std::string(80, '=') << std::endl;
}

// ============================================================================
// Main
// ============================================================================

int main()
{
    // Check if solve_tsp_bruteforce is implemented
    std::vector<City> test_cities = {
        {"A", 0, 0},
        {"B", 1, 0},
        {"C", 0, 1}};

    TSPResult result = solveTSPBruteforce(test_cities);

    if (result.best_route.empty())
    {
        std::cout << "\n⚠️  solveTSPBruteforce() is not yet implemented!" << std::endl;
        std::cout << "Complete the function, then run this program to see the results.\n"
                  << std::endl;
    }
    else
    {
        runTSPExperiment();
    }

    return 0;
}

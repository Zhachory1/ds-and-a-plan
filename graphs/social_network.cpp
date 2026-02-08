#include "social_network.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

SocialNetwork::SocialNetwork() : is_directed(true) {
    // Initialize as a directed graph
}

void SocialNetwork::add_edge(const std::string& follower, const std::string& target) {
    // TODO: Initialize empty vectors if nodes don't exist yet
    // TODO: Add the edge to the forward adjacency list
    // TODO: Add the edge to the reverse adjacency list for efficient follower lookups
}

bool SocialNetwork::load_from_csv(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        // TODO: Parse each line in the format "FollowerID,TargetID"
        // HINT: Use std::stringstream and std::getline with ',' delimiter
        
        // TODO: Call add_edge with the parsed values
    }

    file.close();
    return true;
}

std::vector<std::string> SocialNetwork::get_followers(const std::string& user) const {
    // TODO: Return the list of users who follow this user
    
    return {};
}

std::vector<std::string> SocialNetwork::get_following(const std::string& user) const {
    // TODO: Return the list of users this user follows
    
    // Student implementation here
    return {};
}

bool SocialNetwork::is_mutual(const std::string& user_a, const std::string& user_b) const {
    // TODO: Check if both users follow each other
    // HINT: Use std::find from <algorithm>
    
    // Student implementation here
    return false;
}

std::string SocialNetwork::find_top_influencer() const {
    std::string top_influencer;
    double max_ratio = -1.0;

    // TODO: Iterate through all users
    // TODO: For each user, calculate their clout ratio
    // TODO: Track the user with the highest ratio
    
    return top_influencer;
}

std::vector<std::vector<std::string>> SocialNetwork::detect_echo_chambers() const {
    std::vector<std::vector<std::string>> cycles;
    
    // State map: 0 = unvisited, 1 = visiting (in current path), 2 = visited
    std::unordered_map<std::string, int> state;
    
    // Initialize all nodes as unvisited
    for (const auto& pair : adj_list) {
        state[pair.first] = 0;
    }

    // TODO: For each unvisited node, start a DFS to detect cycles
    // HINT: Use the has_cycle_helper function
    
    return cycles;
}

bool SocialNetwork::has_cycle_helper(const std::string& node,
                                     std::unordered_map<std::string, int>& state,
                                     std::vector<std::string>& current_path,
                                     std::vector<std::vector<std::string>>& cycles) const {
    // TODO: Implement cycle detection
    
    return false;
}

void SocialNetwork::print_graph() const {
    std::cout << "\n=== Social Network Graph ===" << std::endl;
    for (const auto& pair : adj_list) {
        std::cout << pair.first << " -> [ ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "==========================\n" << std::endl;
}

std::set<std::string> SocialNetwork::get_all_users() const {
    std::set<std::string> users;
    for (const auto& pair : adj_list) {
        users.insert(pair.first);
    }
    return users;
}

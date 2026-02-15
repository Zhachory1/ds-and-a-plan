#include "social_network.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

SocialNetwork::SocialNetwork() {
    // Initialize as a directed graph
    // is_directed = true;
}

void SocialNetwork::add_edge(const std::string& follower, const std::string& target) {
    // Initialize empty vectors if nodes don't exist yet
    if (adj_list.count(follower) == 0) {
        adj_list[follower] = std::vector<std::string>{};
    }

    if (adj_list.count(target) == 0) {
        adj_list[target] = std::vector<std::string>{};
    }

    if (reverse_adj_list.count(target) == 0) {
        reverse_adj_list[target] = std::vector<std::string>{};
    }

    if (reverse_adj_list.count(follower) == 0) {
        reverse_adj_list[follower] = std::vector<std::string>{};
    }

    // Add the edge to the forward adjacency list
    adj_list[follower].emplace_back(target);

    // Add the edge to the reverse adjacency list for efficient follower lookups
    reverse_adj_list[target].emplace_back(follower);
}

bool SocialNetwork::load_from_csv(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Parse each line in the format "FollowerID,TargetID"
        // HINT: Use std::stringstream and std::getline with ',' delimiter
        std::stringstream stream(line);
        std::string follower, target;
        std::getline(stream, follower, ','), std::getline(stream, target);
        
        // Call add_edge with the parsed values
        add_edge(follower, target);
    }

    file.close();
    return true;
}

std::vector<std::string> SocialNetwork::get_followers(const std::string& user) const {
    // Return the list of users who follow this user
    return reverse_adj_list.find(user)->second;
}

std::vector<std::string> SocialNetwork::get_following(const std::string& user) const {
    // Return the list of users this user follows
    return adj_list.find(user)->second;
}

bool SocialNetwork::is_mutual(const std::string& user_a, const std::string& user_b) const {
    // Check if both users follow each other
    // HINT: Use std::find from <algorithm>
    const auto& user_b_follows = adj_list.find(user_b)->second;

    return std::find(user_b_follows.begin(), user_b_follows.end(), user_a) != user_b_follows.end();
}

std::string SocialNetwork::find_top_influencer() const {
    std::string top_influencer;
    double max_ratio = -1.0;

    // Iterate through all users
    for (const auto& user : adj_list) {
        std::string name = user.first;

        int following = adj_list.find(name)->second.size();
        int followers = reverse_adj_list.find(name)->second.size();

        // For each user, calculate their clout ratio
        double ratio = following > 0 ? double(followers) / double(following) : std::numeric_limits<double>::infinity();

        // Track the user with the highest ratio
        if (ratio > max_ratio) {
            top_influencer = name;
            max_ratio = ratio;
        }
    }
    
    return top_influencer;
}

std::vector<std::vector<std::string>> SocialNetwork::detect_echo_chambers() const {
    std::vector<std::vector<std::string>> cycles;
    
    // State map: 0 = unvisited, 1 = visiting (in current path), 2 = visited
    std::unordered_map<std::string, int> state;
    
    // Initialize all nodes as unvisited
    for (const auto& user : adj_list) {
        state[user.first] = 0;
    }

    // For each unvisited node, start a DFS to detect cycles
    // HINT: Use the has_cycle_helper function
    for (const auto& user : adj_list) {
        const std::string& node = user.first;

        if (state.find(node)->second == 0) {
            std::vector<std::string> current_path;
            has_cycle_helper(node, state, current_path, cycles);
        }
    }
    
    return cycles;
}

bool SocialNetwork::has_cycle_helper(const std::string& node,
                                     std::unordered_map<std::string, int>& state,
                                     std::vector<std::string>& current_path,
                                     std::vector<std::vector<std::string>>& cycles) const {
    // Mark node as being visited and add to current DFS path
    state[node] = 1;
    current_path.emplace_back(node);

    bool found_cycle = false;
    auto user = adj_list.find(node);

    for (const auto& follows : user->second) {
        if (state[follows] == 0) {
            found_cycle = has_cycle_helper(follows, state, current_path, cycles);
        } else if (state[follows] == 1) {
            auto start_user = std::find(current_path.begin(), current_path.end(), follows);

            cycles.emplace_back(start_user, current_path.end());
            found_cycle = true;
        }
    }

    current_path.pop_back();
    state[node] = 2;

    return found_cycle;
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

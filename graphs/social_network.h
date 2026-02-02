#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#include <string>
#include <unordered_map>
#include <vector>
#include <set>

/**
 * SocialNetwork: A directed graph implementation for modeling
 * follower/following relationships on a social media platform.
 * 
 * This is a DIRECTED graph where an edge A -> B means "A follows B"
 */
class SocialNetwork {
private:
    // Adjacency list: Key = User, Value = List of users they follow
    std::unordered_map<std::string, std::vector<std::string>> adj_list;
    
    // Reverse adjacency list for efficient follower lookups
    // Key = User, Value = List of users who follow them
    std::unordered_map<std::string, std::vector<std::string>> reverse_adj_list;
    
    bool is_directed;

public:
    /**
     * Constructor: Initialize the social network as a directed graph
     */
    SocialNetwork();

    /**
     * Add a follower relationship: follower follows target
     * @param follower The user who is following
     * @param target The user being followed
     */
    void add_edge(const std::string& follower, const std::string& target);

    /**
     * Load user relationships from a CSV file
     * Format: FollowerID,TargetID
     * @param filename Path to the CSV file
     * @return true if successful, false otherwise
     */
    bool load_from_csv(const std::string& filename);

    /**
     * Get all users who follow the given user
     * @param user The target user
     * @return Vector of usernames who follow this user
     */
    std::vector<std::string> get_followers(const std::string& user) const;

    /**
     * Get all users that the given user follows
     * @param user The source user
     * @return Vector of usernames this user follows
     */
    std::vector<std::string> get_following(const std::string& user) const;

    /**
     * Check if two users have a mutual follow relationship
     * @param user_a First user
     * @param user_b Second user
     * @return true if both users follow each other
     */
    bool is_mutual(const std::string& user_a, const std::string& user_b) const;

    /**
     * Find the user with the highest "clout ratio"
     * Clout Ratio = Followers / Following
     * (Handle division by zero if they follow 0 people)
     * @return Username of the top influencer
     */
    std::string find_top_influencer() const;

    /**
     * BONUS: Detect echo chambers (cycles in the graph)
     * Find groups of users who form closed loops: A → B → C → A
     * @return Vector of cycles (each cycle is a vector of usernames)
     */
    std::vector<std::vector<std::string>> detect_echo_chambers() const;

    /**
     * Print the graph structure for debugging
     */
    void print_graph() const;

    /**
     * Get all users in the network
     * @return Set of all usernames
     */
    std::set<std::string> get_all_users() const;

private:
    /**
     * Helper function for cycle detection (DFS-based)
     */
    bool has_cycle_helper(const std::string& node, 
                         std::unordered_map<std::string, int>& state,
                         std::vector<std::string>& current_path,
                         std::vector<std::vector<std::string>>& cycles) const;
};

#endif // SOCIAL_NETWORK_H

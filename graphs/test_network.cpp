#include "social_network.h"
#include <iostream>
#include <cassert>
#include <algorithm>

// Color codes for terminal output
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void test_load_csv() {
    std::cout << "\n" << YELLOW << "Test 1: Loading CSV File" << RESET << std::endl;
    SocialNetwork network;
    
    bool success = network.load_from_csv("users.csv");
    assert(success && "Failed to load users.csv");
    
    network.print_graph();
    std::cout << GREEN << "✓ CSV loaded successfully" << RESET << std::endl;
}

void test_get_following() {
    std::cout << "\n" << YELLOW << "Test 2: Get Following List" << RESET << std::endl;
    SocialNetwork network;
    network.load_from_csv("users.csv");
    
    auto alice_following = network.get_following("Alice");
    std::cout << "Alice follows: ";
    for (const auto& user : alice_following) {
        std::cout << user << " ";
    }
    std::cout << std::endl;
    
    // Alice follows: Bob, Charlie, Irene
    assert(alice_following.size() == 3 && "Alice should follow 3 people");
    assert(std::find(alice_following.begin(), alice_following.end(), "Bob") != alice_following.end());
    assert(std::find(alice_following.begin(), alice_following.end(), "Charlie") != alice_following.end());
    assert(std::find(alice_following.begin(), alice_following.end(), "Irene") != alice_following.end());
    
    std::cout << GREEN << "✓ get_following() works correctly" << RESET << std::endl;
}

void test_get_followers() {
    std::cout << "\n" << YELLOW << "Test 3: Get Followers List" << RESET << std::endl;
    SocialNetwork network;
    network.load_from_csv("users.csv");
    
    auto irene_followers = network.get_followers("Irene");
    std::cout << "Irene's followers: ";
    for (const auto& user : irene_followers) {
        std::cout << user << " ";
    }
    std::cout << std::endl;
    
    // Irene is followed by: Alice, Bob, Charlie, David
    assert(irene_followers.size() == 4 && "Irene should have 4 followers");
    assert(std::find(irene_followers.begin(), irene_followers.end(), "Alice") != irene_followers.end());
    assert(std::find(irene_followers.begin(), irene_followers.end(), "Bob") != irene_followers.end());
    assert(std::find(irene_followers.begin(), irene_followers.end(), "Charlie") != irene_followers.end());
    assert(std::find(irene_followers.begin(), irene_followers.end(), "David") != irene_followers.end());
    
    std::cout << GREEN << "✓ get_followers() works correctly" << RESET << std::endl;
}

void test_is_mutual() {
    std::cout << "\n" << YELLOW << "Test 4: Mutual Follow Detection" << RESET << std::endl;
    SocialNetwork network;
    network.load_from_csv("users.csv");
    
    // Alice and Bob follow each other
    bool alice_bob_mutual = network.is_mutual("Alice", "Bob");
    std::cout << "Alice <-> Bob mutual: " << (alice_bob_mutual ? "Yes" : "No") << std::endl;
    assert(alice_bob_mutual && "Alice and Bob should be mutual");
    
    // Charlie and David follow each other
    bool charlie_david_mutual = network.is_mutual("Charlie", "David");
    std::cout << "Charlie <-> David mutual: " << (charlie_david_mutual ? "Yes" : "No") << std::endl;
    assert(charlie_david_mutual && "Charlie and David should be mutual");
    
    // Alice follows Irene, but Irene does NOT follow Alice back
    bool alice_irene_mutual = network.is_mutual("Alice", "Irene");
    std::cout << "Alice <-> Irene mutual: " << (alice_irene_mutual ? "Yes" : "No") << std::endl;
    assert(!alice_irene_mutual && "Alice and Irene should NOT be mutual");
    
    // Frank follows Eve, but Eve does NOT follow Frank back
    bool frank_eve_mutual = network.is_mutual("Frank", "Eve");
    std::cout << "Frank <-> Eve mutual: " << (frank_eve_mutual ? "Yes" : "No") << std::endl;
    assert(!frank_eve_mutual && "Frank and Eve should NOT be mutual");
    
    std::cout << GREEN << "✓ is_mutual() works correctly" << RESET << std::endl;
}

void test_find_top_influencer() {
    std::cout << "\n" << YELLOW << "Test 5: Find Top Influencer" << RESET << std::endl;
    SocialNetwork network;
    network.load_from_csv("users.csv");
    
    std::string influencer = network.find_top_influencer();
    std::cout << "Top Influencer: " << influencer << std::endl;
    
    // Let's verify by calculating manually:
    // Irene: 4 followers, 0 following -> ratio = infinity (treat as very high)
    // This should be the highest
    
    std::cout << "\nClout Ratios:" << std::endl;
    for (const auto& user : network.get_all_users()) {
        auto followers = network.get_followers(user);
        auto following = network.get_following(user);
        double ratio = following.size() > 0 ? 
            static_cast<double>(followers.size()) / following.size() : 
            followers.size() * 1000.0; // Large value if following == 0
        
        std::cout << user << ": " << followers.size() << " followers / " 
                  << following.size() << " following = " << ratio << std::endl;
    }
    
    assert(influencer == "Irene" && "Irene should be the top influencer");
    std::cout << GREEN << "✓ find_top_influencer() works correctly" << RESET << std::endl;
}

void test_detect_echo_chambers() {
    std::cout << "\n" << YELLOW << "Test 6 (BONUS): Detect Echo Chambers" << RESET << std::endl;
    SocialNetwork network;
    network.load_from_csv("users.csv");
    
    auto cycles = network.detect_echo_chambers();
    
    std::cout << "Found " << cycles.size() << " echo chamber(s):" << std::endl;
    for (size_t i = 0; i < cycles.size(); ++i) {
        std::cout << "  Chamber " << (i + 1) << ": ";
        for (const auto& user : cycles[i]) {
            std::cout << user << " -> ";
        }
        std::cout << cycles[i][0] << " (cycle)" << std::endl;
    }
    
    // We expect 2 cycles:
    // 1. Alice <-> Bob
    // 2. Charlie <-> David
    
    assert(cycles.size() == 2 && "Should detect exactly 2 echo chambers");
    std::cout << GREEN << "✓ detect_echo_chambers() works correctly" << RESET << std::endl;
}

int main() {
    std::cout << "\n" << GREEN << "========================================" << RESET << std::endl;
    std::cout << GREEN << "  Social Network Graph - Unit Tests" << RESET << std::endl;
    std::cout << GREEN << "========================================" << RESET << std::endl;

    try {
        test_load_csv();
        test_get_following();
        test_get_followers();
        test_is_mutual();
        test_find_top_influencer();
        test_detect_echo_chambers();
        
        std::cout << "\n" << GREEN << "========================================" << RESET << std::endl;
        std::cout << GREEN << "  All Tests Passed! ✓" << RESET << std::endl;
        std::cout << GREEN << "========================================" << RESET << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "\n" << RED << "Test Failed: " << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}

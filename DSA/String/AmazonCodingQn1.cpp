#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<std::string> getRecentDistinctWebsites(const std::vector<std::string>& websites) {
    std::unordered_set<std::string> seen;
    std::vector<std::string> result;

    // Traverse the websites vector from the end to the beginning
    for (auto it = websites.rbegin(); it != websites.rend(); ++it) {
        // If the website has not been seen before, add it to the result and mark it as seen
        if (seen.find(*it) == seen.end()) {
            seen.insert(*it);
            result.push_back(*it);
        }
    }

    // Since we traversed from end to start, the result is already in the correct order
    return result;
}

int main() {
    std::vector<std::string> websites = {"Amazon", "Facebook", "YouTube", "Twitter", "Facebook", "Amazon", "YouTube"};
    std::vector<std::string> result = getRecentDistinctWebsites(websites);

    // Output the result
    for (const auto& site : result) {
        std::cout << site << " ";
    }

    return 0;
}

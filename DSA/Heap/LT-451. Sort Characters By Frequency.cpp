
struct Compare{
    bool operator()(pair<int, char>&a,pair<int, char>& b) {
        if (a.first == b.first){
            return a.second > b.second; // Lexicographically smaller characters should come later if frequencies are the same
        }
        return a.first < b.first; // Higher frequencies should come first
    }
};
class Solution {
public:
    string frequencySort(string s){
     map<char, int>freq;
        for(auto&c : s)  freq[c]++;
        //  Use a max heap to sort by frequency
    priority_queue<pair<int, char>,vector<pair<int, char>>,Compare>maxHeap;
        for (auto&p : freq){
              maxHeap.push({p.second, p.first}); // Push (frequency, character)
        }
       string result;
        while (!maxHeap.empty()) {
            auto p = maxHeap.top();
            maxHeap.pop();
            result.append(p.first, p.second); // Append 'character' frequency times
            // appending character 'c' with no of counts  (char = 'c' , freq = 3 , result = ccc)
        }

        return result;
    }
};

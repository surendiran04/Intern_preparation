// Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.
// Return the size of the largest combination of candidates with a bitwise AND greater than 0.
// For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
// Also, for nums = [7], the bitwise AND is 7.
// Input: candidates = [16,17,71,62,12,24,14]
// Output: 4
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<vector<int>> bits(24);
        for(int c:candidates){
            int t=c;
            for(int i=0;t>0;i++){
                if(t & 1){
                    bits[i].push_back(c);
                }
                t>>=1;
            }
        }
        int largest=0;
        for(auto v:bits){
            largest=max(static_cast<int>(v.size()),largest);
        }
        return largest;
    }
};

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(24, 0);
        for (int i = 0; i < 24; i++) {
            for (int num : candidates) {
                // Check if the i-th bit is set.
                if ((num & (1 << i)) != 0) {
                    bitCount[i]++;
                }
            }
        }
        // Return the maximum count.
        return *max_element(bitCount.begin(), bitCount.end());
    }
};

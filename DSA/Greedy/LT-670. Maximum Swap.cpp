// We can do a max of 1 swap and find the maximum possible integer
// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:
// Input: num = 9973
// Output: 9973
class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.length();
        int maxi=num;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){ //checking out all possible swaps and finding maximum
                swap(s[i],s[j]);
                if(stoi(s)>maxi){
                    maxi=stoi(s);
                }
                swap(s[i],s[j]);
            }
        }
        return maxi;
    }
};
class Solution {  //optimal one
public:
    int maximumSwap(int num) {
        // Convert the number to a string for easier digit manipulation
        string numStr = to_string(num);
        int n = numStr.size();
        
        // Store the last occurrence of each digit (0-9)
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse each digit from left to right
        for (int i = 0; i < n; ++i) {
            // Check if there's a larger digit appearing later
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap the current digit with the larger one
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr); // Convert back to integer and return
                }
            }
        }
        
        // If no swap was made, return the original number
        return num;
    }
};

class Solution { //best soln 
public:
    int maximumSwap(int num) {
        int maxIndex = -1, swap1 = -1, swap2 = -1;
        std::string nums = std::to_string(num);
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (maxIndex == -1 || nums[i] > nums[maxIndex]) {
                maxIndex = i;
            } 
            else if (nums[i] < nums[maxIndex]) { //if the current digit is smaller and it is before the bigger digit which gives us the max number
                swap1 = i;
                swap2 = maxIndex;
            }
        }
        if (swap1 != -1 && swap2 != -1) {
            std::swap(nums[swap1], nums[swap2]);
        }

        return std::stoi(nums);
    }
};

//consider the array as circulr and find the alternative grps(grp=k alternative elements)
// Input: colors = [0,1,0,1,0], k = 3
// Output: 3
// Input: colors = [0,1,0,0,1,0,1], k = 6
// Output: 2  
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int left=0;
        int right=1;
        int res=0,n=colors.size();
        while(right<n){
            if(colors[right]==colors[right-1]){
                left=right;
                right++;
                continue;
            }
            right++;
            if(right-left<k){
                continue;
            }
            left++;
            res++;
        }
        return res;
    }
};

class Solution {   //can also use circular approach
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int length = colors.size();
        int result = 0;
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        // Loop through the array, including the wrap-around (circular check)
        for (int i = 1; i < length + k - 1; i++) {
            // Use modulo to handle circular traversal
            int index = i % length;

            if (colors[index] == lastColor) {
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }

            alternatingElementsCount += 1;

            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
        }

        return result;
    }
};

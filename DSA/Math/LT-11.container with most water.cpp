//calculate the area of the largest rectangle
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1;
        int area=INT_MIN;
        while(i<j && i<n && j>=0){
            int mini=min(heights[i],heights[j]);
            
            long long c_area=1LL*mini*(j-i);

            area=max((int)c_area,area);
            
            if(heights[i]<=heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return area;
    }
};

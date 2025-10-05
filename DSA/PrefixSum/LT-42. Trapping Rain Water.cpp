class Solution {
public:
    int trap(vector<int>& height) {  //SC-O(N) TC-O(3n)
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> left(n);
        vector<int> right(n);
        
        // Fill left array
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }
        
        // Fill right array
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }
        
        // Calculate trapped water
        int trappedWater = 0;
        for (int i = 0; i < n; i++) {
            trappedWater += min(left[i], right[i]) - height[i];
        }
        
        return trappedWater;
    }
};

int trap(vector < int > & height) { ////SC-O(1) TC-O(N)
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}

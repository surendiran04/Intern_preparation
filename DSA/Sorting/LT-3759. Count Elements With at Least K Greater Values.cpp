class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int ans=0;
        for(int i=0;i<n;i++){
            int count=end(nums)-upper_bound(begin(nums),end(nums),nums[i]);
            if(count>=k){
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int,int> mp;
        for(int i : nums) mp[i]++;

        sort(nums.begin(), nums.end());

        int ans = 0;
        set<int> st;
        for(int i=0; i<n; i++){
            int total = n - i - mp[nums[i]];
            if(total >= k) ans++;
            mp[nums[i]]--;
        }

        return ans;
    }
};

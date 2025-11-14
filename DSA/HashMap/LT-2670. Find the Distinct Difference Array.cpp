class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        unordered_map<int,int> map;
        vector<int> pre(n,0),suff(n,0);
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            pre[i]=map.size();
        }
        map.clear();
        for(int i=n-1;i>=0;i--){
            suff[i]=map.size();
            map[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            res[i]=pre[i]-suff[i];
        }
        return res;
    }
};

    vector<int> distinctDifferenceArray(vector<int>& nums) { //using only 2 maps
        vector<int> ans;
        unordered_map<int,int> mp, rmp;
        for(auto n: nums){ rmp[n]++; }
        for(auto n: nums){
            mp[n]++;
            rmp[n]--;
            if(rmp[n] == 0) rmp.erase(n);
            ans.push_back(mp.size() - rmp.size());
        }
        return ans;
    }

class Solution {
public:
    int n;
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        n=nums.size();
        vector<int> ans;
        for(int i=0;i<n-k+1;i++){
            int temp=x_sum(nums,i,i+k,x);
            ans.push_back(temp);
        }
        return ans;
    }
    int x_sum(vector<int>& arr,int l,int r,int x){
        unordered_map<int,int> map;
        int sum=0;
        for(int i=l;i<r;i++){
            map[arr[i]]++;
            sum+=arr[i];
        }
        if(map.size()<x){
            return sum;
        }
        priority_queue<pair<int,int>> pq;
        for(auto m:map){
            pq.push({m.second,m.first});
        }
        sum=0;
        for(int i=0;i<x;i++){
            sum+=pq.top().second*pq.top().first;
            pq.pop();
        }
        return sum;
    }
};

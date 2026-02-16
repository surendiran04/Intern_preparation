class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,pair<int,int>> map;//num:idx,cnt
        int i;
        for(int j=0;j<n;j++){
            i=nums[j];
            map[i].second++;
            if(map[i].second==1){
                map[i].first=j;
            }else{
                map[i].first=min(map[i].first,j);
            }
            
        }
        if(map.size()==1){
            return nums[0];
        }
        vector<vector<pair<int,int>>> bucket(n+1);
        for(auto m:map){
            bucket[m.second.second].push_back({m.first,m.second.first});
            //count:{num,index}
        }
        pair<int,int> ans={INT_MAX,INT_MAX}; //idx,num
        for(int i=0;i<n;i++){
            int cnt=map[nums[i]].second;
            if(bucket[cnt].size()==1){
                if(ans.first>bucket[cnt][0].second){
                    ans.first=bucket[cnt][0].second;
                    ans.second=bucket[cnt][0].first;
                }
            }
        }
        return ans.first<n?ans.second:-1;
    }
};

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) { //two map approach , 1 for freq, another for unique freq
        int n = nums.size();
        unordered_map<int,int> m, m1;

        // Count frequency of each number
        for (int i : nums) {
            m[i]++;
        }

        // Count how many numbers have a particular frequency
        for (auto i : m) {
            m1[i.second]++;
        }

        // Find first number whose frequency is unique
        for (int i = 0; i < n; i++) {
            if (m1[m[nums[i]]] == 1)
                return nums[i];
        }

        return -1;
    }
};

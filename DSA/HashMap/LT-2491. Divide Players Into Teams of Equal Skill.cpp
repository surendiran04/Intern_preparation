class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        unordered_map<long,vector<pair<int,int>>> map;
        int n=skill.size();
        long p;
        for(int i=0;i<n/2;i++){
             p=skill[i]+skill[n-1-i];
            map[p].push_back({skill[i],skill[n-1-i]});
        }
        if(map.size()!=1){
            return -1;
        }
        long long product=0;
        for(auto x:map[p]){
            product+=x.first*x.second;
        }
        return product;
    }
};

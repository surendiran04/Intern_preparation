class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n=bulbs.size();
        unordered_map<int,int> map; //instead of map use a 100 of size hash area which will help us to find the ans in sorted order instead of sorting
        for(int i:bulbs){
            map[i]++;
        }
        vector<int> res;
        for(auto m:map){
            if(m.second & 1){
                res.push_back(m.first);
            }
        }
        sort(begin(res),end(res));
        return res;
    }
};

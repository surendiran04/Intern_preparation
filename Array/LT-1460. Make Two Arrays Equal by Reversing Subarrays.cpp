class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> map;
        for(int num:target){
            map[num]++;
        }
        for(int num:arr){
            map[num]--;
        }
        for(auto m:map){
            if(m.second!=0){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) { //optimal approach is using count sort - remove min(k,i,noEleOfFreq[i]); 
        unordered_map<int,int> map;
        for(int num:arr){
            map[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        for(const pair<int,int>&m:map){
            min_heap.push({m.second,m.first});
        }
        while(k>0){
            if(!min_heap.empty() && k-min_heap.top().first>=0){
                k-=min_heap.top().first;
                min_heap.pop();
            }else{
                break;
            }
        }
        return min_heap.size();
    }
};

//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]

// Merge all elements from all lists and tag them with their corresponding list index.
// Merged: [(4, 1), (10, 1), (15, 1), (24, 1), (26, 1), (0, 2), (9, 2), (12, 2), (20, 2), (5, 3), (18, 3), (22, 3), (30, 3)]
// After sorting the List: [(0, 2), (4, 1), (5, 3), (9, 2), (10, 1), (12, 2), (15, 1), (18, 3), (20, 2), (22, 3), (24, 1), (26, 1), (30, 3)]
// bw 20 - 24 is the range where all 3 diff list are covered and the range is min 5 (20,21,...24)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<pair<int,int>> list;
        for(int i=0;i<k;i++){
            for(int num:nums[i]){
                list.push_back({num,i});
            }
        }
        sort(list.begin(),list.end());
        int listCovered=0;
        unordered_map<int,int> count;
        int minRange=INT_MAX;
        pair<int,int> res;
        int l=0,r=0;
        while(r<list.size()){ //sliding window approach
            int rIdx=list[r].second;
            count[rIdx]++;
            if(count[rIdx]==1) listCovered++; //diff lists are covered
            while(listCovered==k){
                int rangeStart=list[l].first; 
                int rangeEnd=list[r].first;
                if(rangeEnd-rangeStart<minRange){
                    minRange=rangeEnd-rangeStart;
                    res={rangeStart,rangeEnd};
                }
                int lIdx=list[l].second;
                count[lIdx]--;
                if(count[lIdx]==0) listCovered--; //while reducing the window size
                l++;
            }
            r++;
        }
        return {res.first,res.second};
    }
};

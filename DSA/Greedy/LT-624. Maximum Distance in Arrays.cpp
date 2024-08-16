// Input: arrays = [[1,2,3],[4,5],[1,2,3]]
// Output: 4
//since each array is in ascending order the first element will be the smalllest and the last element will be largest but we either pick any one of them 
//to get the max distance
class Solution { 
public:
    int maxDistance(vector<vector<int>>& arrays) { //passed 130/136 testcases
        int mini=arrays[0].front();
        int maxi=arrays[0].back(); 
        int maxDistance=maxi-mini;
        for(vector<int> v:arrays){ //error due to picking 2 elements from the 1st array 
            int tmin=v.front();
            int tmax=v.back();
            maxDistance = max(maxDistance,abs(maxi-tmin));
            maxDistance = max(maxDistance,abs(mini-tmax));
            mini=min(mini,tmin);
            maxi=max(maxi,tmax);
        }
        return maxDistance;
    }
};
class Solution { //passed all testcases
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=arrays[0].front();
        int maxi=arrays[0].back();
        int maxDistance=0;
        for(int i=1;i<arrays.size();i++){
            int tmin=arrays[i].front();
            int tmax=arrays[i].back();
            maxDistance = max(maxDistance,abs(maxi-tmin));
            maxDistance = max(maxDistance,abs(mini-tmax));
            mini=min(mini,tmin);
            maxi=max(maxi,tmax);
        }
        return maxDistance;
    }
};

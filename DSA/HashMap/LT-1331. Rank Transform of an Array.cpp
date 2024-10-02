//Rank the element acc to how large the element is
// Input: arr = [40,10,20,30]
// Output: [4,1,2,3]
// Input: arr = [37,12,28,9,100,56,80,5,12]
// Output: [5,3,4,2,8,6,7,1,3]
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> arr1(arr);
        sort(arr1.begin(),arr1.end());  //sorting the array to rank from 1
        vector<int> res(n);
        unordered_map<int,int>map;
        int ind=0;
        for(int num:arr1){  
            if(map.find(num)==map.end()){ //Existing element will have the same rank
                map[num]=++ind;
            }
        }
        ind=0;
        for(int num:arr){  //output in the order of the original arr
            res[ind++]=map[num];
        }
        return res;
    }
};

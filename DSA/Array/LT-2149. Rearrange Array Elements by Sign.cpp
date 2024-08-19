// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
class Solution { //postive number followed by a negative number 
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        vector<int> v1;
        vector<int> v2;
        for(int i:nums){
            if(i<0){
                v1.push_back(i);
            }else if(i>0){
                v2.push_back(i);
            }
        }
        for(int j=0;j<n/2;j++){
            v.push_back(v2[j]);
            v.push_back(v1[j]);
        }
        return v;
    }
};

class Solution { //best approach 
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);
        int i=1,j=0,k=0;
        while(k<n){
            if(nums[k]<0){
                v[i]=nums[k++];
                i+=2;
            }else if(nums[k]>0){
                v[j]=nums[k++];
                j+=2;
            }
        }
        return v;
    }
};

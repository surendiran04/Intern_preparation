// To a triangle to be valid it needs to satisfy this property a<=b<=c and a+b>c
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        int a,b,c;
        int maxPerimeter=0;
        sort(begin(nums),end(nums));
        for(int i=2;i<n;i++){
            a=nums[i-2];b=nums[i-1],c=nums[i];
            if(a+b>c){
                maxPerimeter=max(maxPerimeter,a+b+c);
            }
        }
        return maxPerimeter;
    }
};

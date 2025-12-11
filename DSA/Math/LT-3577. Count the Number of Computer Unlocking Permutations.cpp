class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        long long ans=1;
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            if(complexity[i]<=complexity[0]){ //suppose it's complexity is less than no need to calculate
                return 0;
            }
            ans=(ans*i)%mod; //factorial of n-1
        }
        return ans;
    }
};

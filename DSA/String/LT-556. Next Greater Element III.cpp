class Solution {
public:
    int nextGreaterElement(int n) { //passed 38/39 ccases
    long mini=INT_MAX;
    string s=to_string(n);
    do{
        long x=min(mini,stol(s));
        (x!=n)?mini=x:mini=mini;
    }while(next_permutation(s.begin(),s.end()));
    return (mini==INT_MAX)?-1:mini;
    }
};

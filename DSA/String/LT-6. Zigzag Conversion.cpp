class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.length()){
            return s;
        }
        vector<string> str(numRows,"");
        int n=s.length();
        int d=1,idx=0;
        for(char ch:s){
            str[idx]+=ch;
            if(idx==0){
                d=1;
            }else if(idx==numRows-1){
                d=-1;
            }
            idx+=d;

        }
        string ans;
        ans=accumulate(begin(str),end(str),string{});
        return ans;
    }
};

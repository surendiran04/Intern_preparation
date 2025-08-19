// Input: strs = ["flower","flow","flight"]
// Output: "fl"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { //O(n^2)
        if(strs.empty()) 
            return "";
         string prefix=strs[0];
         for(string s:strs){
            while(s.find(prefix)!=0)
                prefix=prefix.substr(0,prefix.length()-1);
         }
         return prefix;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};

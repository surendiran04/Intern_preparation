class Solution {
public:
    string removeKdigits(string num, int k) {  //Got MLE at the last case
        int n=num.length();
        if(k==n){
            return "0";
        }
        string ans="";
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        if (i == ans.length()) {
            return "0"; // All zeros
        }
        return ans.substr(i);

    }
};

class Solution {
public:
    string removeKdigits(string num, int k) { //using string as stack approach
        int n=num.length();
        if(k==n){
            return "0";
        }
        string ans="";
        for(int i=0;i<n;i++){
            while(!ans.empty() && k>0 && (ans.back()-'0')>(num[i]-'0')){
                k--;
                ans.pop_back();
            }
            ans.push_back(num[i]);
        }
        while(k>0){
            ans.pop_back();
            k--;
        }
        int i=0;
        while(i<n && ans[i]=='0'){
            i++;
        }
        if (i == ans.length()) {
            return "0"; // All zeros
        }
        return ans.substr(i);

    }
};

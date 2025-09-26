// Input: s = "(u(love)i)"
// Output: "iloveu"
// s ="a(bcdefghijkl(mno)p)q"
// ans:"apmnolkjihgfedcbq"
class Solution {
public:
    string reverseParentheses(string s) {  //T:O(n^2) bcpz of reverse fn
        int n=s.length();
        stack<int> st; //recording  res length where i found an '(' and reverse the result until that point
        string res;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(res.length());
            }else if(s[i]==')'){
                int start=st.top();
                st.pop();
                reverse(begin(res)+start,end(res));
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};

class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int> st;
        vector<int> pair(n);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                int j=st.top();
                st.pop();
                pair[i]=j; //putting index of closing parantheses at '(' index
                pair[j]=i;
            }
        }
        string res;
        for(int curr=0,dir=1;curr<n;curr+=dir){  //iterating from reverse if saw a '(' instead of reversing and vice versa
            if(s[curr]=='(' || s[curr]==')'){
                curr=pair[curr];
                dir=-dir;
            }else{
                res+=s[curr];
            }
        }
        return res;
    }
};

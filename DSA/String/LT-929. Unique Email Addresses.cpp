// Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
// Output: 2
// Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.
// Example 2:

// Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
// Output: 3

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> map;
        int n=emails.size();
        for(int i=0;i<n;i++){
            string s=emails[i];
            string ch="";
            for(char c:s){
                if(c=='+' || c=='@'){
                    int pos=s.find("@");
                    ch+=s.substr(pos);
                    break;
                }
                if(c!='.'){
                    ch+=c;
                }
            }
            map[ch]++;
        }
        return map.size();

    }
};

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto x:emails){
            string local = "";
            string domain = "";
            bool ignore = false;
            int index = 0;

            for(int i=0;i<x.size();i++){
                if(x[i] != '.' and x[i] != '+' and x[i] != '@' and !ignore){
                    local += x[i];
                }
                else if(x[i] == '+')
                    ignore = true;
                
                else if(x[i] == '@'){
                    index = i;
                    ignore = true;
                }
            }
            domain += x.substr(index,x.size()-index);
            st.insert(local+domain);
        }
        return (int)st.size();
    }
};

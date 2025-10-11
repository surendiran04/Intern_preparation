class Solution {
public:
    string clearStars(string s) { //Got TLE on 1 case , O(n²) is possible due to min_element and erase
        vector<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='*'){
                if(!st.empty()){
                    auto ch=*min_element(st.begin(),st.end()); /
                    int k=st.size();
                    for(int j=k-1;j>=0;j--){
                        if(st[j]==ch){
                            st.erase(st.begin()+j);
                            break;
                        }
                    }
                }
            }else{
                st.push_back(c);
            }
        }
        return string(st.begin(),st.end());
    }
};

class Solution {
public:
    string clearStars(string s) {
    priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> minh;
    unordered_map<int,bool> mpp;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                mpp[-minh.top().second] = true;
                minh.pop();
            } else {
                minh.push({s[i], -i});
            }
        }
        string res;
        for(int i = 0; i < s.size(); i++) {
            if(mpp.count(i) || s[i] == '*') continue;
            res += s[i];
        }
        return res;
    }
};

class Solution {
public:
    string clearStars(string s) { //vector of stack  for 26 chars
        vector<stack<int>> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                cnt[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!cnt[j].empty()) {
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

class Solution { //better one
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<char, int>> sortedChars;
        for (const auto& entry : freq) {
            sortedChars.push_back({entry.first, entry.second});
        }
        sort(sortedChars.begin(), sortedChars.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) { //here if the characters has same frequency then order doesn't matter so it'll work
                 return a.second > b.second;
             });
        string res;
        for (const auto& p : sortedChars) {
            res += string(p.second, p.first);
        }
        return res;
    }
};

class Solution { //good space complexity approach
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto i:s)
            mpp[i]++;

        sort(s.begin(),s.end(),[&](char a,char b){
            if(mpp[a] != mpp[b])
                return mpp[a] > mpp[b];
            else
                return a>b;
        });

        return s;
    }
};

class Solution { //also takes O(nlogn)
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> map;
        vector<vector<char>> v(n + 1);
        for (char c : s) {
            map[c]++;
        }
        for (const pair<char, int> x : map) {
            v[x.second].push_back(x.first);
        }
        string res;
        for (int i = n; i >= 0; i--) {
            if (!v[i].empty()) {
                if (v[i].size() > 1) {
                    sort(v[i].begin(), v[i].end(),greater<char>());
                    for(int j=0;j<v[i].size();j++){
                        int k=0;
                        while(k<i){ //instead of doing this we can use - string res=string(2,'a');
                            res +=v[i][j];
                            k++;
                        } 
                    }
                } else {
                    for (int j = 0; j < i; j++) {
                        res += v[i][0];
                    }
                }
            }
        }
        return res;
    }
};

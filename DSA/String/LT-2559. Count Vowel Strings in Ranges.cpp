class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m=words.size();
        unordered_map<char,int> map;
        map['a']++;
        map['e']++;
        map['i']++;
        map['o']++;
        map['u']++;
        vector<int> prefix(m+1,0);
        for(int i=0;i<m;i++){
            if(map.find(words[i][0])!=map.end() && map.find(words[i][words[i].size()-1])!=map.end()){
                prefix[i+1]=prefix[i]+1;
            }else{
                prefix[i+1]=prefix[i];
            }
        }
        vector<int> res;
        int temp;
        for(auto q:queries){
            if(q[0]==0){
                temp=prefix[q[1]+1];
                res.push_back(temp);
            }else{
                temp=prefix[q[1]+1]-prefix[q[0]];
                res.push_back(temp);
            }
        }
        return res;
    }
};

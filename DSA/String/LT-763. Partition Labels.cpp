class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char,int> map;
        for(int i=0;i<n;i++){
            map[s[i]]=i;
        }
        vector<int> res;
        int maxi_idx=-1,l=0;
        for(int i=0;i<n;i++){
            if(maxi_idx==-1){
                maxi_idx=map[s[i]];
                l=i;
            }
            maxi_idx=max(maxi_idx,map[s[i]]);
            if(i==maxi_idx){
                res.push_back(i-l+1);
                maxi_idx=-1;
            }
        }
        return res;
    }
};

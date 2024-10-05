class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        if(n1>n2){
            return false;
        }
        vector<int> v1(26,0),v2(26,0);
        for(int i=0;i<n1;i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        for(int i=0;i<n2-n1;i++){
            if(v1==v2) return true;

            v2[s2[i]-'a']--;  //l--  - window decrease
            v2[s2[i+n1]-'a']++; //r++ - window increase
        }
        return v1==v2;
    }
};

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        istringstream s1(sentence1);
        istringstream s2(sentence2);
        vector<string> v1,v2;
        string n;
        while (s1 >> n) {
            v1.push_back(n);
        }
        while (s2 >> n) {
              v2.push_back(n);
        }
        int n1=v1.size();
        int n2=v2.size();
        if(n1<n2){   //n2 is always the smaller string
            swap(v1,v2);
            swap(n1,n2);
        }
        int s=0,r=0;
        while(s<n2 && v1[s]==v2[s]) s++;
        while(r<n2 && v1[n1-r-1]==v2[n2-r-1]) r++;
        return s+r>=n2;
    }
};

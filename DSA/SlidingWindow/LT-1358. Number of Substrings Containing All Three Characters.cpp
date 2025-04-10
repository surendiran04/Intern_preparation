// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", 
// "cab", "cabc" and "abc" (again). 
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Input: s = "abc"
// Output: 1
    
class Solution {
public:
    int numberOfSubstrings(string s) { //Time limit exceeded
    int cnt=0;
    int n = s.length();
    for(int i=0;i<n;i++){
        unordered_map<int,int> map = {{0,0},{1,0},{2,0}};
        for(int j=i;j<n;j++){
                map[s[j]-'a']=1;
                if(map[0]==1 && map[1]==1 && map[2]==1){
                    cnt++;
                }
        }
    }
    return cnt;
    }
};
class Solution { //failied in one case 'aaa*b*c'
public:
    int numberOfSubstrings(string s) {
    int cnt=0;
    int n = s.length();
    for(int i=0;i<n;i++){
        unordered_map<int,int> map = {{0,0},{1,0},{2,0}};
        for(int j=i;j<n;j++){
                map[s[j]-'a']=1;
                if(map[0]==1 && map[1]==1 && map[2]==1){
                    cnt=cnt+(n-j);
                    break;
                }
        }
    }
    return cnt;
    }
};
class Solution { //best approach 
public:
    int numberOfSubstrings(string s) {
    int cnt=0;
     int n = s.length();
    vector<int> lastseen(n,-1);
    for(int i=0;i<n;i++){
         lastseen[s[i]-'a']=i;
         if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
            cnt=cnt+(1+min(min(lastseen[0],lastseen[1]),lastseen[2]));
         }
       
    }
    return cnt;
    }
};

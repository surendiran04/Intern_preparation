class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> map;
        for(char c:s){
            if(map.find(c)!=map.end()){
                return c;
            }else{
                map[c]++;
            }
        }
        return ' ';
    }
};

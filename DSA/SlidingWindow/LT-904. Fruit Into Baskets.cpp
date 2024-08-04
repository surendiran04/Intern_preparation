class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxlen=0;
        unordered_map<int,int> map;
        while(r<fruits.size()){
            map[fruits[r]]++;
            if(map.size()>2){  //this is modified
                map[fruits[l]]--;
                if(map[fruits[l]]==0) map.erase(fruits[l]);
                l++;   
            }
            if(map.size()<3){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
class Solution { //TC - O(n+n) ,SC - O(3)
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxlen=0;
        unordered_map<int,int> map;
        while(r<fruits.size()){
            map[fruits[r]]++;
            while(map.size()>2){
                map[fruits[l]]--;
                if(map[fruits[l]]==0) map.erase(fruits[l]);
                l++;   
            }
            if(map.size()<3){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

//we can also use a set data structure by using two for loops and add set.insert(fruits[j) when set.size() < k 
//calculate the length or else break and start from next i

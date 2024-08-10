class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> map;
        int minlen=INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(map.find(cards[i])!=map.end()){
                minlen=min(minlen,i-map[cards[i]]+1);
                map[cards[i]]=i;
            }else{
                map[cards[i]]=i;
            }
        }
        return (minlen==INT_MAX)?-1:minlen;
    }
};

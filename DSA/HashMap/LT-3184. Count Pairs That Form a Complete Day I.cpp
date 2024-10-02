//Need to count the pairs which sum upto a whole day like 24,48,72
// Input: hours = [12,12,30,24,24]
// Output: 2
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((hours[i]+hours[j])%24==0){
                    count++;
                }
            }
        }
        return count;
    }
};
class Solution { //Hash Table approach
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        unordered_map<int,int> map;
        int count=0;
        for(int i=0;i<n;i++){
            int hr=hours[i]%24;   //key
            if(map.find((24-hr)%24)!=map.end()){  //(24-hr)%24 - needed pair
                count+=map[(24-hr)%24];           //If there are two 12 already and if the current hr is also 12 then i need to add map[(24-hr)%24] 
            }
            map[hr]++;
        }
        return count;
    }
};

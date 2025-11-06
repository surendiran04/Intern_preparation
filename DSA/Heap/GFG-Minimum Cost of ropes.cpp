class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i:arr){
            pq.push(i);
        }
        int cost=0;
        if(pq.size()<2){
            return cost;
        }
        while(!pq.empty() && pq.size()>=2){ //at min we need 2 ropes to connect if there is one rope then we don't need to connect
            int rope1=pq.top();pq.pop();
            int rope2=pq.top();pq.pop();
            cost+=rope1+rope2;
            pq.push(rope1+rope2);
        }
        return cost;
    }
};

class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses),end(courses),comp);
        priority_queue<int> pq;
        int total=0;
        for(auto c:courses){
            if(total+c[0]<=c[1]){//total+curr duration<=deadline
            pq.push(c[0]);
            total+=c[0];
            }else if(!pq.empty() && pq.top()>c[0]){
                total+=c[0]-pq.top();
                pq.pop();
                pq.push(c[0]);
            }
        }
        return pq.size();
    }
};

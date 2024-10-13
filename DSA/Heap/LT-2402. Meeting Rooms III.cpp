//Given n meeting rooms.Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.
// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
// Output: 0
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetcount(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>> avlrooms;
        for(int i=0;i<n;i++){
            avlrooms.push(i);
        } 
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> queue;
        for(auto meet:meetings){
            while(!queue.empty() && queue.top().first <= meet[0]){
                avlrooms.push(queue.top().second);
                queue.pop();
            }
            if(!avlrooms.empty()){ //if there enough rooms to hold meeting
                int room=avlrooms.top();
                avlrooms.pop();
                queue.push({meet[1],room});
                meetcount[room]++;
            }
            else{                   //if not pickup earlier ending meeting
                auto [roomavl,room]=queue.top();
                queue.pop();
                queue.push({roomavl+meet[1]-meet[0],room});  //queue.push({ending current meet time,room})
                meetcount[room]++;
            }
        }
        int maxMeetCount=0,maxMeetRoom=0;
        for(int i=0;i<n;i++){
            if(maxMeetCount<meetcount[i]){
                maxMeetCount=meetcount[i];
                maxMeetRoom=i;
            }
        }
        return maxMeetRoom;
    }
};

// we need to find out the way in how we can maximize the no of meetings, we can do that by conducting the shorter meeting first
// Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
class Solution {
  public:
    struct Meeting {
    int start;
    int end;
    int pos;
    };
    int maxMeetings(int n, int start[], int end[]) {
        vector<Meeting> data(n);
        for (size_t i = 0; i <n; ++i) {
            data[i].start=start[i];
            data[i].end=end[i];
            data[i].pos=i+1;  //if in interview ask about the order
        } 
        sort(data.begin(), data.end(), [](const Meeting& a, const Meeting& b) {
        return a.end < b.end;
        });
        int cnt=1;
        int prev_end=data[0].end;
        vector<int> order;
        order.push_back(data[0].pos);
        for(int i=1;i<n;i++){
            if(data[i].start>prev_end){ //if the previous meeting is finished before the starting of the next meeting we can conduct the next meeting
                prev_end=data[i].end;
                cnt++;
            }
        }
        return cnt;
    }
};



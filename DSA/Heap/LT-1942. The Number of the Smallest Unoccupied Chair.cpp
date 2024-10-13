// Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
// Output: 1
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) { //passed 49/65 cases
        int arr=times[targetFriend][0];
        sort(times.begin(),times.end());
        int count=0;
        for(int i=0;i<times.size();i++){
            if(times[i][0]==arr){
                return count;
            }else if(times[i][1]>arr){ //didn't take account of the friends who came and left earlier so he ended up taking the earlier chair instead of taking after chairs
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) { //brute force
        int n = times.size();
        vector<int> chairs(n, -1);
        int tar = times[targetFriend][0];
        sort(times.begin(), times.end());
        for (auto it : times) {
            int arr = it[0];
            int dep = it[1];
            for (int i = 0; i < n; i++) { //for every arrival again checking the from the 1st whether the previously arrived has left or not 
                if (arr >= chairs[i]) {
                    chairs[i] = dep;
                    if (arr == tar) //if left means check if it equal to the target
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
       int n = times.size();
        
        // Create a list of arrivals with friend index for tracking
        std::vector<std::pair<int, int>> arrivals;
        for (int i = 0; i < n; ++i) {
            arrivals.push_back({times[i][0], i});
        }
        
        // Sort friends based on their arrival time
        std::sort(arrivals.begin(), arrivals.end());
        
        // Min-Heap to track available chairs
        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); // All chairs start as available
        }

        // Priority queue to track when chairs are freed
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> leavingQueue;
        
        // Iterate through each friend based on arrival
        for (auto& arrival : arrivals) {
            int arrivalTime = arrival.first;
            int friendIndex = arrival.second;
            
            // Free chairs that are vacated before the current arrival time
            while (!leavingQueue.empty() && leavingQueue.top().first <= arrivalTime) {
                availableChairs.push(leavingQueue.top().second);
                leavingQueue.pop();
            }
            
            // Assign the smallest available chair
            int chair = availableChairs.top();
            availableChairs.pop();
            
            // If this is the target friend, return their chair number
            if (friendIndex == targetFriend) {
                return chair;
            }
            
            // Mark the chair as being used until the friend's leave time
            leavingQueue.push({times[friendIndex][1], chair});
        }
        
        return -1; // Should never reach here
    }
};

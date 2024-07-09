When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. 
The chef prepares food for customers in the order they were given in the input. Return the average waiting time of all customers.
    
Input: customers = [[1,2],[2,5],[4,3]]
Output: 5.00000
Explanation:
1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
So the average waiting time = (2 + 6 + 7) / 3 = 5.   
Input: customers = [[5,2],[5,4],[10,3],[20,1]]
Output: 3.25000
Explanation:
1) The first customer arrives at time 5, the chef takes his order and starts preparing it immediately at time 5, and finishes at time 7, so the waiting time of the first customer is 7 - 5 = 2.
2) The second customer arrives at time 5, the chef takes his order and starts preparing it at time 7, and finishes at time 11, so the waiting time of the second customer is 11 - 5 = 6.
3) The third customer arrives at time 10, the chef takes his order and starts preparing it at time 11, and finishes at time 14, so the waiting time of the third customer is 14 - 10 = 4.
4) The fourth customer arrives at time 20, the chef takes his order and starts preparing it immediately at time 20, and finishes at time 21, so the waiting time of the fourth customer is 21 - 20 = 1.
So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.

Approach:
ct - completion time(Exact time not duration)
1.Finding the completion time of every order.
2.If the new order is placed within the completion of previous order,
which means the order has arrived. So,after finishing the current order the next order starts so we can add only time needed for cooking.
if(i+1<N && customers[i+1][0] <= ct[i]){
                ct[i + 1] = ct[i] + customers[i+1][1];
}
3.If the new order is placed after the completion of previous order,
which means the order has not arrived until finishing the current order so we need to calculate completion by adding arrival time with time taken to complete the order.
else if (i+1< N && customers[i+1][0] > ct[i]  ) {
                ct[i + 1] = customers[i+1][0] + customers[i+1][1];
} 

class Solution { //beats 92% but uses extra space
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int N=customers.size();
        vector<int> ct(N,0);
        double sum = 0;
        ct[0] = customers[0][0] +  customers[0][1];
        for (int i = 0; i < N; i++) {
            sum += ct[i] - customers[i][0];
            if (i + 1 < N && customers[i+1][0] <= ct[i]){
                ct[i + 1] = ct[i] + customers[i+1][1];
            } else if (i + 1 < N && customers[i+1][0] > ct[i]  ) {
                ct[i + 1] = customers[i+1][0] + customers[i+1][1];
            } else {
                break;
            }
        }
        return sum / N;
    }
};
class Solution { //uses less space
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_waiting_time = 0;
        int current_time = 0;

        for (const auto& customer : customers) {
            int arrival = customer[0];
            int service = customer[1];
            if (current_time < arrival) {
                current_time = arrival;
            }
            total_waiting_time += current_time - arrival + service;
            current_time += service;
        }
        return total_waiting_time / customers.size();
    }
};

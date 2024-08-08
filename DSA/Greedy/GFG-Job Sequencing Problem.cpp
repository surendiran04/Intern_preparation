// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only
// if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.
// Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. 
//  Deadline of the job is the time on or before which job needs to be completed to earn the profit.
  
//   Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output: 2 60
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
// Input: N = 5, Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}
// Output: 2 127
// Explanation: 2 jobs can be done with maximum profit of 127 (100+27).

class Solution 
{
    public:
    bool static comp(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job a[], int n) 
    { 
        sort(a,a+n,comp);
        int maxi=a[0].dead;
        for(int i=1;i<n;i++){
            maxi=max(maxi,a[i].dead);
        }
        vector<int> slot(maxi+1,-1);
        int count=0,profit=0;
        for(int i=0;i<n;i++){
            for(int j=a[i].dead;j>0;j--){  //check for other available blocks if it is deadline is 1 and 1 is already done by some job with max profit then it cannot be done
                if(slot[j]==-1) //the slot is not booked
                {
                    slot[j]=i; //slot is booked
                    count++;
                    profit+=a[i].profit;
                    break;
                }
            }
        }
        return {count,profit};
        
    } 
};

// Program to find minimum number of platforms required on a railway station
// Input: n = 6, arr[] = {0900, 0940, 0950, 1100, 1500, 1800}, 
//               dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
// Explanation: There are three trains during the time 0940 to 1200. So we need minimum 3 platforms.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int cnt=0,maxcnt=INT_MIN;
    	int i=0,j=0;
    	while(i<n){
    	    if(arr[i]<=dep[j]){
    	        cnt++;
    	        i++;
    	    }
    	    else{
    	        cnt--;
    	        j++;
    	    }
    	    maxcnt=max(maxcnt,cnt);
    	}
    	return maxcnt;
    	
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}

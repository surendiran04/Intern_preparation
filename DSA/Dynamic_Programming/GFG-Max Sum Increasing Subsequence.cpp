// N = 5, arr[] = {1, 101, 2, 3, 100} 
// Output: 
// 106
// Explanation:
// The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100},

// if arr[j] < arr[i]
// dp[i]=max(dp[i],dp[j]+arr[i]) dp[j]+arr[i] is nothing but the subsequence sum
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n,0);
	    for(int i=0;i<n;i++){
	        dp[i]=arr[i];
	    }
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i] && dp[i]<dp[j]+arr[i]){
	                dp[i]=dp[j]+arr[i];

	            }
	        }
	    }
	    return *max_element(dp.begin(),dp.end());
	}  
};

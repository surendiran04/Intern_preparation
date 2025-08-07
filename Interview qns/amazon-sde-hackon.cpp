//1. given an array of stockprice overs months and an int k which is the k consecutive months we need to find k consecutive unique stocprice of months  that make up the max sum if not return -1
since the qns talks about uniqueness and we need to count freq (i.e duplicates can occur) we need a hashmap
then k consecutive is there then we canculde that is prblm is a sliding-window prblm

// testcases:
// arr=[1,2,7,7,4,3,6] k=3  ans (7,4,3)=14 that is max stockprice of window size 3
// arr=[1,2,4,4] k=4
// arr=[1,2,3,7,3,5] k=3

int maxSum(const vector<int>& stockPrice, int k) {
    int n = stockPrice.size();
    if (k > n) return -1;

    unordered_map<int, int> freq;
    int sum = 0, maxSum = -1;

    for (int i = 0; i < n; ++i) {
        int val = stockPrice[i];
        freq[val]++;
        sum += val;

        if (i >= k) {
            int remove = stockPrice[i - k];
            freq[remove]--;
            if (freq[remove] == 0) freq.erase(remove);
            sum -= remove;
        }

        if (i >= k - 1 && freq.size() == k) {
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}


//2. No of operation req to make the array balanced/unique where we need tp inc an element and dec other element at the same time 

// similiar problm link:https://leetcode.com/problems/minimum-operations-to-make-array-equal/description/

// testcases:
// arr=[1,3,2,5] ans:2  after 2 operation the array will become [1+1+1,3,2,5-1-1] = [3,3,2,3]
// arr=[4,4,4]  ans:0
// arr=[1,7] ans:3    [2,6] -> [3,5] -> [4,4]
 
int operationscnt(vector<int>& arr) {
    int n = stockPrice.size();
    int total = accumulate(arr.begin(),arr.end(),0);
    int avg=total/n,rem=total%n;
    int op=0;
    sort(arr.begin(),arr.end());  
    for (int i = 0; i < n; ++i) {
        int  target=(i<n-rem)?avg:avg+1;
        if (arr[i]>target) { //since inc and dec take 1 op we need to find out the elements that needs to be dec 
          op=op+arr[i]-target;   //here we doing how many times we can dec the larger no to avg
        }
    }

    return op;
}

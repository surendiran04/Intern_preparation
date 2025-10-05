int largestarea(int arr[], int n) { //bruteForce
  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int minHeight = INT_MAX;
    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, arr[j]);
      maxArea = max(maxArea, minHeight * (j - i + 1));
    }
  }
  return maxArea;
}
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { //We can compute nse and pse on the gone but that soln is hard to come up with
        int n=heights.size();
        vector<int> nse=nextSmallerElement(heights);
        vector<int> pse=prevSmallerElement(heights);
        int area=0;
        for(int i=0;i<n;i++){
            area=max(area,heights[i]*(nse[i]-pse[i]-1));
        }
        return area;
    }
    vector<int> nextSmallerElement(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> prevSmallerElement(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
};

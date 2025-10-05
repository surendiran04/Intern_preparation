class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int maxarea=0;
        for(int i=0;i<n;i++){  // Can use an prefix 2D array and compute for it as well
            for(int j=0;j<m;j++){
                heights[j]=(matrix[i][j]=='0')?0:heights[j]+=1;
            }
            maxarea=max(maxarea,largestRectangleArea(heights));
        }
        return maxarea;
    }
    int largestRectangleArea(vector<int>& heights) {
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

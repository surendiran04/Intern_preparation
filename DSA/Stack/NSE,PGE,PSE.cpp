#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr={1,4,6,1,8,5};
    //NGE:4,6,8,8,-1,-1
    //NSE:-1,1,1,-1,5,-1
    //PGE:-1,-1,-1,6,-1,8
    //PSE:-1,1,4,-1,1,1
    stack<int> st;
    int n=arr.size();
    vector<int> nse(n,-1);
    cout<<"Next smaller element: ";
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            nse[i]=st.top();
        }
        st.push(arr[i]);
    }
    for(int i:nse){
        cout<<i<<" ";
    }
    st=stack<int>();
    
    cout<<endl<<" Previous Greater element: ";
    vector<int> pge(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            pge[i]=st.top();
        }
        st.push(arr[i]);
    }
    for(int i:pge){
        cout<<i<<" ";
    }
     st=stack<int>();
    
    cout<<endl<<" Previous smaller element: ";
    vector<int> pse(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            pse[i]=st.top();
        }
        st.push(arr[i]);
    }
    for(int i:pse){
        cout<<i<<" ";
    }

}

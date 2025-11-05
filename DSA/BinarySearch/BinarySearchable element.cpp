#include<bits/stdc++.h>
using namespace std;

int howMany(vector<int> input) {
    int n=input.size();
    int ma[n];
    int mi[n];
    
    int maxi = INT_MIN;
    int mini = INT_MAX;
    
    for (int i = 0 ; i < n; i++){
        ma[i] = max(maxi, input[i]);
        maxi = ma[i];
    }
    for (int i = n-1 ; i >= 0; i--){
        mi[i] = min(mini, input[i]);
        mini = mi[i];
    }
    int count = 0;
    for( int i = 0; i< n ; i++){
        if(ma[i] == mi[i]) count++;
    }
    return count;
    
}
int main() {
    vector<int> input={1, 3, 2};//ans:1 
    cout<<howMany(input)<<endl;
    input={2, 1, 3, 5, 4, 6}; //ans:2
    cout<<howMany(input)<<endl;
    input={1, 5, 7, 11, 12, 18};//ans:6
    cout<<howMany(input)<<endl;
    input={5, 4, 3, 2, 1, 0}; // ans:0
    cout<<howMany(input)<<endl; 
    input= {1, 3, 2, 4, 5, 7, 6, 8 //ans:4
    cout<<howMany(input)<<endl;
    return 0;
} 


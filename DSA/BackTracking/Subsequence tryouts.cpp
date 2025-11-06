#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void comp(vector<int>& arr,int target,int idx,int sum,vector<int>& curr){
    if(idx==arr.size()){
        if(sum==target){
            res.push_back(curr);
        }
        return;
    }
    curr.push_back(arr[idx]);
    comp(arr,target,idx+1,sum+arr[idx],curr);
    curr.pop_back();
    comp(arr,target,idx+1,sum,curr);
}
int main() {
    vector<int> arr={1,1,3,5,2,4};
    int target=8;
    vector<int> curr;
    comp(arr,target,0,0,curr);
    for(auto i:res){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

bool comp(vector<int>& arr,int target,int idx,int sum,vector<int>& curr){ //only 1 subsequence
    if(idx==arr.size()){
        if(sum==target){
            res.push_back(curr);
            return true;
        }
        return false;
    }
    curr.push_back(arr[idx]);
    if(comp(arr,target,idx+1,sum+arr[idx],curr)){
        return true;
    }
    curr.pop_back();
    if(comp(arr,target,idx+1,sum,curr)){
        return true;
    }
    return false;
}
int main() {
    vector<int> arr={1,1,3,5,2,4};
    int target=8;
    vector<int> curr;
    comp(arr,target,0,0,curr);
    for(auto i:res){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
int comp(vector<int>& arr,int target,int idx,int sum,vector<int>& curr){
    if(idx==arr.size()){
        if(sum==target){
            res.push_back(curr);
            return 1;
        }
        return 0;
    }
    curr.push_back(arr[idx]);
    int l=comp(arr,target,idx+1,sum+arr[idx],curr);
    curr.pop_back();
    int r=comp(arr,target,idx+1,sum,curr);
    return l+r;
}
int main() {
    vector<int> arr={1,1,3,5,2,4};
    int target=8;
    vector<int> curr;
    int total=comp(arr,target,0,0,curr);
    cout<<"Total combinations: "<<total<<endl;
    for(auto i:res){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void comp(vector<int>& arr,int target,int idx,int sum,vector<int>& curr){ //It gives are the permutated combinations like multiples 2's even if 2 occurs 1 times in the array
    if(idx==arr.size()){
        if(sum==target){
            res.push_back(curr);
        }
        return;
    }
    if(arr[idx]<=target-sum){
        curr.push_back(arr[idx]);
        comp(arr,target,idx,sum+arr[idx],curr);
        curr.pop_back();
    }
    comp(arr,target,idx+1,sum,curr);
    
}
int main() {
    vector<int> arr={1,1,3,5,2,4};
    int target=8;
    vector<int> curr;
    comp(arr,target,0,0,curr);
    for(auto i:res){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

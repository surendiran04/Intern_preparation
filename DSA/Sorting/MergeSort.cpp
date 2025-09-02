#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& a,int l,int mid,int r){
    vector<int> left(a.begin()+l,a.begin()+mid+1);
    vector<int> right(a.begin()+mid+1,a.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<left.size() && j<right.size()){
        if(left[i]<=right[j]){
            a[k++]=left[i++];
        }else{
            a[k++]=right[j++];
        }
    }
    while(i<left.size()){
        a[k++]=left[i++];
    }
     while(j<right.size()){
        a[k++]=right[j++];
    }
}
void mergeSort(vector<int>& a,int l,int r){
    if(l>=r){
        return;
    }
    int mid=l+(r-l)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
}
int main() {
    vector<int> a={5,6,2,3,1,9,7};
    mergeSort(a,0,a.size()-1);
    for(int i:a){
        cout<<i<<" ";
    }

    return 0;
}

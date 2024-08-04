#include<bits/stdc++.h>
using namespace std;
int solution(string &S, string &T) {
    bool n1=false;
    bool n2=false;
    if(S[0]>T[0]){
        n1=true;
    }
    else{
        n2=true;
    }
    int swaps=0;
    char t;
    int n=S.length();
    for(int i=1;i<n;i++){
        if( (S[i]>T[i] && n1) || (T[i]>S[i] && n2)){
            t=S[i];
            S[i]=T[i];
            T[i]=t;
            swaps++;
        }
    }
    cout<<swaps<<","<<n-swaps<<endl;
    return min(swaps,n-swaps);
}
int main() {
    // string s="29162";
    // string t="10524";
    string s="2999";
    string t="1000";
    int res=solution(s,t); 
    cout<<"Minimum number of swaps required to make the smallest difference:"<<res<<endl;
    cout<<stoi(s)-stoi(t); //min difference after swap
    return 0;
}

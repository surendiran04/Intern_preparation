#include <bits/stdc++.h>
using namespace std;
int RomantoInt(string rom){
    int n=rom.size();
    unordered_map<char,int> map={{'I',1},{'V',5},{'X',10},{'L',50}};
    int value=0;
    for(int i=0;i<n;i++){
        if(i!=n-1 && map[rom[i]]<map[rom[i+1]]){
            value-=map[rom[i]];
        }else{
            value+=map[rom[i]];
        }
    }
    return value;
}
int main() {
	vector<string> s={"Mary IX","Mary XII","David X","David VIII","Mary XX","Steven I"}; //sort the name according to the name if same then according to the roman integer
	vector<pair<string,string>> t;
	string x,roman;
	for(auto name:s){
	    stringstream ss(name);
	    ss>>x>>roman;
	    t.push_back({x,roman});
	}
	sort(begin(t),end(t),[&](auto& a,auto& b){
	    if(a.first==b.first){
	        return RomantoInt(a.second)<RomantoInt(b.second); //instead of directly calling here use a struct store the roman int as a member and comapre here which reduce the time
	    }
	    return a.first<b.first;
	});
	for(auto p:t){
	    cout<<p.first<<" "<<p.second<<endl;
	}
	return 0;
}

LT-32. Longest valid paranthesis
Approach 1: using stack with -1 pre pushed and why ')' popping it initially then add a stack empty check and push the current index
            If not empty check max(maxi,i-st.top()) return maxi.
Approach 2:
           use a greedy approach loop form 0 -> n-1 check when '(' count and ')' count are equal add both in store it in maxi
            if suppose right>left make both left and right = 0.
           Similiar;ly from n-1 to 0 check if left>right and make both as 0. and check left==right and take the max(maxi,2*right)

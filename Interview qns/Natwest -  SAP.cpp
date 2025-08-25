// Spiral matrix both diagonal sum calculation
#include <bits/stdc++.h>  //IDFC
using namespace std;

int main() {
    int N;
    cin >> N;

    long long sum = 1; // center value
    for (int k = 3; k <= N; k += 2) {
        sum += 4LL * k * k - 6LL * (k - 1);
    }

    cout << sum << endl;
    return 0;
}
Input 5 → Output 101
Input 9 → Output 537


#include <iostream>
#include <vector>
using namespace std;

vector<int> commonFootSteps(int fatherPos, int martinPos, int velFather, int steps) { //SAP
    vector<int> answer(2, 0);
    vector<int> temp(steps + 1);

    // Precompute father's positions relative to martin
    for (int i = 0; i <= steps; i++)
        temp[i] = fatherPos + velFather * i - martinPos;

    // Find best velocity for Martin
    for (int i = 0; i <= steps; i++) {
        if (temp[i] <= 0)
            continue;

        int v2 = temp[i];
        int count = 0;

        for (int j = i; j <= steps; j++) {
            if (temp[j] % v2 == 0)
                count++;
        }

        if (answer[0] <= count) {
            answer[0] = count;
            answer[1] = v2;
        }
    }

    return answer;
}

int main() {
    vector<int> result = commonFootSteps(3, 2, 2, 20);

    for (int i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}

// given array of heights denoting the heights of the building we need to change the height of the building such that Kth building building needs to be lesser than A[k] building and no two buildings should not have the same height and change the array such that the sum of heights needs to be maximum. 
//   A=[9,4,3,7,7] ans: [9,4,3,6,7] or [9,4,3,7,6] A=[2,5,4,5,5] ans: [1,2,3,4,5] A=[1,2,3] ans:[1,2,3]
#include <bits/stdc++.h>
using namespace std;

vector<int> maximizeHeights(vector<int> A) {  //Natwest
    int n = A.size();
    vector<int> ans(n);
    unordered_set<int> used;
    
    for (int i = 0; i < n; i++) {
        int h = A[i];
        while (h > 0 && used.count(h)) {
            h--; // reduce until unique
        }
        ans[i] = h;
        used.insert(h);
    }
    return ans;
}

int main() {
    vector<vector<int>> tests = {
        {9,4,3,7,7},
        {2,5,4,5,5},
        {1,2,3}
    };
    for (auto &A : tests) {
        auto ans = maximizeHeights(A);
        cout << "[";
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << (i+1<ans.size()? ",":"");
        }
        cout << "]\n";
    }
}


// Given transaction between 2 bank accouts what will be min balance in both account if transder happenning bw A->B,B->A respectively
#include <bits/stdc++.h>
using namespace std;

vector<long long> minBalances(string R, vector<int> v) {  //
    long long A = 0, B = 0;       // running balances
    long long minA = 0, minB = 0; // track lowest seen
    
    for (int i = 0; i < (int)R.size(); i++) {
        if (R[i] == 'A') {
            A += v[i]; // A receives
            B -= v[i]; // B pays
        } else { // R[i] == 'B'
            B += v[i]; // B receives
            A -= v[i]; // A pays
        }
        minA = min(minA, A);
        minB = min(minB, B);
    }
    // need to "offset" the lowest negative dip
    return { -minA, -minB };
}

int main() {
    {
        string R = "BAABA";
        vector<int> v = {2,4,1,1,2};
        auto ans = minBalances(R, v);
        cout << "[" << ans[0] << "," << ans[1] << "]\n"; // [2,4]
    }
    {
        string R = "B";
        vector<int> v = {100};
        auto ans = minBalances(R, v);
        cout << "[" << ans[0] << "," << ans[1] << "]\n"; // [100,0]
    }
    {
        string R = "ABAB";
        vector<int> v = {10,5,10,15};
        auto ans = minBalances(R, v);
        cout << "[" << ans[0] << "," << ans[1] << "]\n"; // [0,15]
    }
}

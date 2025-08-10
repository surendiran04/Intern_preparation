#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    vector<char> lis;
    for (char c : S) {
        // Find position where 'c' can be placed in LIS (non-decreasing)
        auto it = upper_bound(lis.begin(), lis.end(), c);
        if (it == lis.end()) {
            lis.push_back(c);
        } else {
            *it = c;
        }
    }
    for(auto it:lis){
        cout<<it<<" ";
    }
    cout<<endl;
    return S.size() - (int)lis.size();
}

int main() {
    string S = "banana";
    cout << solution(S) << endl; // Output: 3
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> board;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int maxNum = 0;

void dfs(int x, int y, int depth, int num, vector<vector<bool>>& visited) {
    if (depth == 4) {
        maxNum = max(maxNum, num);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, depth + 1, num * 10 + board[nx][ny], visited);
            visited[nx][ny] = false;
        }
    }
}

int solution(vector<vector<int>>& Board) {
    N = Board.size();
    M = Board[0].size();
    board = Board;
    maxNum = 0;

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 0) { // start can't be 0
                visited[i][j] = true;
                dfs(i, j, 1, board[i][j], visited);
                visited[i][j] = false;
            }
        }
    }
    return maxNum;
}

int main() {
    vector<vector<int>> board1 = {
        {9, 1, 1, 0, 7},
        {1, 0, 2, 1, 0},
        {1, 9, 1, 1, 0}
    };
    vector<vector<int>> board2 = {
        {1, 1, 1},
        {1, 3, 4},
        {1, 4, 3}
    };
    vector<vector<int>> board3 = {
        {0, 1, 5, 0, 0}
    };

    cout << solution(board1) << endl; // Expected: 9121
    cout << solution(board2) << endl; // Expected: 4343
    cout << solution(board3) << endl; // Expected: 1500

    return 0;
}




// 2. return minimal swaps to achieve minimal possible absolute difference
#include <bits/stdc++.h>
using namespace std;
int sign_of(int x){
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}


int solution(const string &S, const string &T){
    int N = (int)S.size();
    // find first differing index
    int j = -1;
    for(int i = 0; i < N; ++i){
        if(S[i] != T[i]){ j = i; break; }
    }
    if(j == -1) return 0; // already equal

    // prepare sign array for later positions
    vector<int> sgn(N, 0); // sgn[k] = sign(S[k]-T[k])
    for(int k = j+1; k < N; ++k){
        sgn[k] = sign_of((S[k]-'0') - (T[k]-'0'));
    }

    int a = (S[j]-'0');
    int b = (T[j]-'0');
    int delta = a - b; // nonzero

    // Evaluate two cases: do not swap at j, or swap at j.
    auto count_swaps_for_initial_swap = [&](bool swap_at_j)->int{
        int swaps = 0;
        int cur_sign = sign_of(delta);
        if(swap_at_j){
            swaps += 1;
            cur_sign = -cur_sign; // swapping at j flips the sign of the first digit diff
        }
        int desired = -cur_sign; // for minimizing absolute difference we want later contributions to oppose cur_sign

        for(int k = j+1; k < N; ++k){
            // if digits equal (sgn[k]==0) they don't affect difference; don't swap to save swaps
            if(sgn[k] == 0) continue;
            // if sgn[k] == desired then leaving as-is (no-swap) produces contribution with desired sign
            // else we must swap at k to flip the contribution sign
            if(sgn[k] != desired) swaps += 1;
        }
        return swaps;
    };

    int ans = min(count_swaps_for_initial_swap(false), count_swaps_for_initial_swap(true));
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    if(!(cin >> S >> T)){
        S = "29162"; S="2999"
        T = "10524";  T="1000" //ans 1     //S="321" T="123" ans:0
        cout << solution(S,T) << "\n"; // prints 2
        return 0;
    }
    cout << solution(S, T) << "\n";
    return 0;
}

In the game of Restricted Pacman, an infinite linear path is given. Pacman has to start at position 0 and eat as many candies as possible.
In one move he can only jump a distance of either M or N. If M and N are coprime numbers, 
find how many candies will be left on the board after the game is over.
Note: The result is always finite as after a point X every index in the infinite path can be visited.

Input Format
The first line contains the integer t - number of testcases.
for each line of the test case, it contains 2 integers M and N.
Constraints
1 < M, N ≤ 5000
Output Format
Output the number of candies left.

Sample Input 0
1
2 5

Sample Output 0
2

Explanation 0
From index 0, the indices that can be visited are
0 + 2 = 2
0 + 2 + 2 = 4
0 + 5 = 5
0 + 2 + 2 + 2 = 6
0 + 2 + 5 = 7
0 + 2 + 2 + 2 + 2 = 8
0 + 2 + 2 + 5 = 9
0 + 5 + 5 = 10
and so on.
1 and 3 are the only indices that cannot be visited. Therefore the candies at these two positions will be left on the board.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     int t;
    cin >> t;
     while (t--) {
        int M, N;
        cin >> M >> N;
        cout << (((M-1)*(N-1))/2) << endl;
    }
    return 0;
}

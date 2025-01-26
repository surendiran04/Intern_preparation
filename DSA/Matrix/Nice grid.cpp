// Print the color of the cell at the R-th row from the top and C-th column from the left in the following grid with 15 vertical rows and 15 horizontal columns.
// 15x15 Grid
// Constraints
// 1 ≤ R, C ≤ 15
// R and C are integers.
// Input
// The input consists of two space-separated integers:
// R C
// Output
// In the grid above, if the color of the cell at the R-th row from the top and C-th column from the left is black, then print black; 
// if the cell is white, then print white. Note that the judge is case-sensitive.
// Examples
// Input
// 3 5
// Output
// black
// Input
// 4 5
// Output
// white

#include <bits/stdc++.h>  //distance from the closest edge let's say the innermost(15th layer) or the outermost(1st layer)
using namespace std;

int main() {
  int r,c;
  cin>>r>>c;
  int layer = min(min(r - 1, c - 1), min(15 - r, 15 - c));

    if (layer % 2 == 0) {
        cout << "black" << endl;
    } else {
        cout << "white" << endl;
    }

}

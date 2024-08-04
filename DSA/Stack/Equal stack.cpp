Find the maximum possible height of the stacks such that all of the stacks are exactly the same height.
This means you must remove zero or more cylinders from the top of zero or more of the three stacks until
they are all the same height, then return the height.

  //we have to remove elements from the top and all stacks should have the same total height and return the height
  
SampleInput: 
  Input:
STDIN       Function
-----       --------
5 3 4       h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4  
3 2 1 1 1   h1 = [3, 2, 1, 1, 1]
4 3 2       h2 = [4, 3, 2]
1 1 4 1     h3 = [1, 1, 4, 1]
 Output
     5
  
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate the total height of a stack
int calculateTotalHeight(const vector<int>& heights) {     
    int totalHeight = 0;
    for (int height : heights) {
        totalHeight += height;
    }
    return totalHeight;
}

int equalStacks(vector<int>& h1, vector<int>& h2, vector<int>& h3) {
    // Calculate initial heights of the stacks
    int height1 = calculateTotalHeight(h1);
    int height2 = calculateTotalHeight(h2);
    int height3 = calculateTotalHeight(h3);
    
    // Create stacks to store the heights
    stack<int> stack1, stack2, stack3;
    
    for (int i = h1.size() - 1; i >= 0; --i) {
        stack1.push(h1[i]);
    }
    for (int i = h2.size() - 1; i >= 0; --i) {
        stack2.push(h2[i]);
    }
    for (int i = h3.size() - 1; i >= 0; --i) {
        stack3.push(h3[i]);
    }
    
    // Adjust the heights until they are equal
    while (height1 != height2 || height1 != height3) {
        if (height1 >= height2 && height1 >= height3) {
            height1 -= stack1.top();
            stack1.pop();
        } else if (height2 >= height1 && height2 >= height3) {
            height2 -= stack2.top();
            stack2.pop();
        } else {
            height3 -= stack3.top();
            stack3.pop();
        }
    }
    
    return height1;
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1), h2(n2), h3(n3);
    for (int i = 0; i < n1; ++i) cin >> h1[i];
    for (int i = 0; i < n2; ++i) cin >> h2[i];
    for (int i = 0; i < n3; ++i) cin >> h3[i];
    
    cout << equalStacks(h1, h2, h3) << endl;
    
    return 0;
}

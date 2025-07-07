//No of unique BST that can be formed by N nodes
// Sample Testcase 1
// Testcase Input
// 3
// Testcase Output
// 5
#include <iostream>
#include<unordered_map>
using namespace std;

// Function to calculate the number of unique BSTs (using Catalan number formula) -  //2n^Cn/n+1
int numTrees(int n){
    int sum=1;
    for(int i=0;i<n;i++){
        sum=sum*2*(2*i+1)/(i+2); 
    }
    return sum;
}

int main() {
    int number_of_nodes;
    cin >> number_of_nodes;
    
    // Output the result: the total number of unique BSTs
    cout << numTrees(number_of_nodes) << endl;

    return 0;
}

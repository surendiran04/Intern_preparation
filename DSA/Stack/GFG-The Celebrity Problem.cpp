// Input: mat[][] = [[1, 1, 0],
//                 [0, 1, 0],
//                 [0, 1, 1]]
// Output: 1
// Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.
// Input: mat[][] = [[1, 1], 
//                 [1, 1]]
// Output: -1
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) { //Everyone knows him, But he knows NoOne
        int n=mat.size();
        vector<int> knowSomeone(n,0);
        vector<int> knownBySomeone(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j]==1){
                    knowSomeone[i]++;
                    knownBySomeone[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(knowSomeone[i]==0 && knownBySomeone[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int top=0,down=n-1;
        while(top<down){
            if(mat[top][down]){
                top++;
            }else if(mat[down][top]){
                down--;
            }else{
                top++;
                down--;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=top && mat[top][i]==0 && mat[i][top]==1){ //Checking if knows any one and all knows him
                continue;
            }else if(i!=top){  //If he knows anyone or anyone don't know him then he can't be a celebrity
                return -1;
            }
        }
        return top;
    }
};

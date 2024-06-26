Given a balanced parentheses string s, return the score of the string.
The score of a balanced parentheses string is based on the following rule:
"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Sample Input:
input: (()) 
output:2  1+1
  
Sample Input: 
input: ()() 
output:2  2*1
  
int score(string s) {
    stack<int> st;
    int score=0;
    for(char c:s){
        if(c=='('){
            st.push(score);
            score=0;
        }
        else{
            int prev_score=st.top();
            st.pop();
            score=prev_score + max(2*score,1);   //if the score is 0 which means '(' followed by '('
        }
        
    }
    return score;
}

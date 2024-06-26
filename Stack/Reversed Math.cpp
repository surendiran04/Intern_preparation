Sample Input:
input: 20-3+5*2
output: 2*5+3-20

sample Input:
 input: 5+2*56-2/4
 output: 4/2-56*2+5


string reverse(string s) {
     stack<char> st;
     string rev;
     for(char &c:s){
         if(c=='+' || c=='*' ||c=='/' ||c=='-'){
             st.push(c);
             c='.';
         }
     }
    int i=s.size()-1;
     while(i>=0){
         if(s[i]=='.'){
             rev+=st.top();
             st.pop();
             i--;
         }
         else if(s[i-1]!='.' && s[i]!='.' && i!=0){  //2-digit number reversing condition
             rev+=s[i-1]; 
             rev+=s[i];
             i-=2;
         }
         else{
             rev+=s[i];
             i--;
         }
         
     }
    return rev;
}

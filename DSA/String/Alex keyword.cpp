Alex is having a problem with his keyboard. If he is pressing any key, he is getting one or more occurrences of that character.
Example: If he wants to write hey, his keyboard may write hey, hhey, hheey, heey, hhheyyy, or some other combination of the characters pressed by him.
You are given a string s typed by Alex. Your task is to find out the number of possible strings Alex was trying to type and print the same. Output can be very large.
Print (number of ways % 109 + 7) Where % is the modular operator.
Hint: Use a larger integer type ( long long ) to avoid overflow.
Input
The first line contains the string s (1 ≤ |s| ≤ 105).
Output
Print the number of possible strings Alex was trying to type.
Examples
Input
audevvvdayyy
Output
9
Explanation:
For the string audevvvdayyy, Alex could have been trying to type:
audevday - The second and third 'v' and the second and third 'y' were duplicated.
audevvday - The third 'v' and the second and third 'y' were duplicated.
audevdayy - The second and third 'v' and the third 'y' were duplicated.
audevvdayy - The third 'v' and the third 'y' were duplicated.
audevdayyy - The second and third 'v' were duplicated.
audevvvday - The second and third 'y' were duplicated.
audevvdayyy - The third 'v' was duplicated.
audevvvdayy - The third 'y' was duplicated.
audevvvdayyy - This is exactly what Alex intended to type.
Thus, there are 9 possible original strings Alex could have been trying to type.

Input
dsssaa
Output
6
Explanation:
For the string dsssaa, Alex could have been trying to type:
dsa - In this case, the second and third 's' and the second 'a' were duplicated by the keyboard.
dssa - In this case, the third 's' and the second 'a' were duplicated.
dsssa - In this case, only the second 'a' was duplicated.
dsaa - In this case, the second and third 's' were duplicated.
dssaa - In this case, the third 's' was duplicated.
dsssaa - This is exactly what Alex intended to type.
Thus, there are 6 possible original strings Alex could have been trying to type.

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() {
  string s;
  cin>>s;
  long long res=1;
  int n=s.length(),count=1;
  
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1]){
      count++;
    }else{
      res =  (res* count)%mod;
      count=1;
    }
  }
  
  res =  (res* count)%mod;
  cout << res;

  return 0;

}

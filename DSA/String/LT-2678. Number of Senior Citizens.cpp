//11th and 12th digits were the age of the passenger
// Input: details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
// Output: 2
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        string s;
        for(string x:details){
            s="";
            s+=x[11]; //we can use substr to get the digits x.substr(11,2) , also we get 2 digits in 2 varibales '0' like single cgar conversion to int 
            s+=x[12];
            if(stoi(s)>60){
                count++;
            }
        }
        return count;
        
    }
};

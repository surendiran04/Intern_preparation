class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        deque<int> dq;
        int rem=1;
        for(int i=n-1;i>=0;i--){
            dq.push_front((rem+digits[i])%10);
            rem=(rem+digits[i])/10;
        }
        if(rem!=0){
            dq.push_front(rem);
        }
        return vector<int>(dq.begin(),dq.end());
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& v) { //In place
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                  v[i]++;
            }
            if(v[i]==10){
                v[i]=0;
                if(i!=0){
                    v[i-1]++;
                }
                else{
                    v.push_back(0);
                    v[i]=1;
                }
            }
        }
        return v;
    }
};

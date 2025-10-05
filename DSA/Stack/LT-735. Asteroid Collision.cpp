class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if(st.top()<abs(asteroids[i])) {
                    st.pop();
                    continue;
                }
                if(st.top()==abs(asteroids[i])){
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if(!destroyed){
                st.push(asteroids[i]); 
            }
               
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) { //striver's approach using vector instead of stack
        int n = asteroids.size();
        vector<int> ans;
        for (int a : asteroids) {
            if (a > 0) {
                ans.push_back(a);
            } else {
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(a)) {
                    ans.pop_back();
                }
                if (!ans.empty() && ans.back() == abs(a)) {
                    ans.pop_back();
                } else if (ans.empty() || ans.back() < 0) {
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
};

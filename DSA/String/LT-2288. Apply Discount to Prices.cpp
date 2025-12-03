class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream sen(sentence); 
        string x;
        string ans = "";
        while (sen >> x) {  //get mle error due to string stream
            if (check(x)) {
                long double num = stringToNum(x); 
                num = num-(num*discount)/100.0;
                // cout<< fixed << setprecision(4)<<num<<" ";
                stringstream ss;
                ss << fixed << setprecision(2) << (num);
                ans = ans + "$" + ss.str()+" ";
            } else {
                ans = ans + x + " ";
            }
        }
        ans.resize(ans.size()-1);
        return ans;
    }
    bool check(string x) {
        if (x[0] != '$') {
            return false;
        }
        int n=x.length();
        for (int i = 1; i < n; i++) {
            if (!isdigit(x[i])) {
                return false;
            }
        }
        return n>1;
    }
    long double stringToNum(string x) {
        long double num = 0;
        for (int i = 1; i < x.length(); i++) {
            num = num * 10 + (x[i] - '0');
        }
        return num;
    }
};

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int n = sentence.size();
        string ans;
        ans.reserve(n * 2); // prevent reallocation
        
        for (int i = 0; i < n; ) {
            // extract one word
            string word;
            while (i < n && sentence[i] != ' ') {
                word.push_back(sentence[i]);
                i++;
            }
            
            // process price
            if (isPrice(word)) {
                long double num = toNum(word);
                num -= (num * discount) / 100.0;

                // format
                ostringstream ss;
                ss << fixed << setprecision(2) << num;

                ans.push_back('$');
                ans.append(ss.str());
            } 
            else {
                ans.append(word);
            }

            // append space if exists
            if (i < n) ans.push_back(' ');
            i++;
        }
        return ans;
    }

    bool isPrice(const string &x) {
        if (x.size() < 2 || x[0] != '$') return false;
        for (int i = 1; i < x.size(); i++)
            if (!isdigit(x[i])) return false;
        return true;
    }

    long double toNum(const string &x) {
        long double num = 0;
        for (int i = 1; i < x.size(); i++)
            num = num * 10 + (x[i] - '0');
        return num;
    }
};

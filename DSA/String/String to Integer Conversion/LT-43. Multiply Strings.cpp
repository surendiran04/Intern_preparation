class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size() - 1, n2 = num2.size() - 1; //brute-force
        string res = "";
        int i = n1, j = n2;
        int product = 1, carry = 0;
        int digit = 0;
        vector<string> mul;
        while (j >= 0) {
            string im;
            for (int i = n1; i >= 0; i--) {
                product = (num2[j] - '0') * (num1[i] - '0') + carry;
                im.push_back((product % 10) + '0');
                carry = product / 10;
            }
            if (carry > 0) {
                im.push_back((carry + '0'));
            }
            carry = 0;
            cout << im << " ";
            mul.push_back(im); // stored num in reverse order
            j--;
        }
        unordered_map<int, int> map;
        int maxi = 0;
        for (int i = 0; i <= n2; i++) {
            int m = mul[i].size();
            for (int j = 0; j < m; j++) {
                map[i + j] += (mul[i][j] - '0');
                maxi = max(maxi, i + j);
            }
        }
        carry = 0;
        cout << endl;
        for (int i = 0; i <= maxi; i++) {
            cout << i << ": " << map[i] << endl;
            int digitsum = map[i] + carry;
            res.push_back(((digitsum % 10) + '0'));
            carry = (digitsum) / 10;
        }
        if (carry > 0) {
            res.push_back((carry + '0'));
        }
        reverse(begin(res), end(res));
        // long long num=stoll(res);   // caused out of range error
        // return to_string(num);
        size_t firstNonZero = res.find_first_not_of('0');

        // If all characters are '0' or the string is empty
        if (std::string::npos == firstNonZero) {
            return "0"; // Return "0" for strings like "000" or empty
        }

        // Erase characters from the beginning up to the first non-zero character
        res.erase(0, firstNonZero);
        return res;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) { //Optimised  Time: O(n.m) space:O(n+m)
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans = "";
        int i = 0;
        while (i < res.size() && res[i] == 0) i++;

        for (; i < res.size(); i++)
            ans.push_back(res[i] + '0');

        return ans;
    }
};

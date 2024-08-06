// word = "abcde"
// Output: 5
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// Total cost is 1 + 1 + 1 + 1 + 1 = 5.
// It can be shown that no other mapping can provide a lower cost.
// Input: word = "aabbccddeeffgghhiiiiii"                            For this case we can arrange only high freq elements in the first 8 index then followed by the less frq elements
// Output: 24
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// "f" -> one push on key 7
// "g" -> one push on key 8
// "h" -> two pushes on key 9
// "i" -> one push on key 9
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (char& c : word) {
            cnt[c - 'a']++;
        }
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += (i / 8 + 1) * cnt[i];  //index above 7 will have i/8>1 based on their count priority
        }
        return ans;
    }
};

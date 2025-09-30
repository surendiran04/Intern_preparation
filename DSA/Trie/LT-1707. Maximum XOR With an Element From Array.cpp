struct Node {
    Node* links[2];
    bool containsKey(int ch) { return links[ch] != NULL; }

    void put(int ch, Node* node) { links[ch] = node; }

    Node* get(int ch) { return links[ch]; }
};
class Trie {
private:
    Node* root;
    bool isEmpty;

public:
    Trie() {
        root = new Node();
        isEmpty = false;
    }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
        isEmpty = true;
    }

    int getMax(int num) {
        if (!isEmpty) {
            return -1;
        }
        int maxNum = 0;
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;         // taking ith bit
            if (node->containsKey(1 - bit)) { // picking out the max one
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit); // our maximum not available
            }
        }
        return maxNum;
    }
};
struct Triple {
    int a, b, c;
    Triple(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        sort(begin(nums), end(nums));
        vector<Triple> query;
        for (int i = 0; i < q; i++) {
            query.push_back(Triple(queries[i][1], queries[i][0], i));
        }
        sort(begin(query),end(query),[&](Triple& X,Triple& Y){
            return X.a<Y.a || (X.a==Y.a && X.b<Y.b); 
        });
        Trie t;
        vector<int> ans(q, -1);
        int maxExor;
        int i = 0, j = 0;
        while (j < q) {
            maxExor = -1;
            if (i<n && nums[i] <= query[j].a) {
                t.insert(nums[i]);
                i++;
            } else {
                    maxExor=max(maxExor,t.getMax(query[j].b));
                    ans[query[j].c]=maxExor;
                    j++;
            }
        }
        return ans;
    }
};

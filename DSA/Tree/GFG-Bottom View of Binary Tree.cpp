                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.
class Solution {
  public:
    vector <int> bottomView(Node *root) {
    vector<int> result;
    if (!root) return result;

    map<int, int> hdNodeMap;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*,int> node = q.front();
        q.pop();

        int hd=node.second;
        hdNodeMap[hd] = node.first->data;

        if (node.first->left) {
            q.push({node.first->left, hd - 1});
        }
        if (node.first->right) {
            q.push({node.first->right, hd + 1});
        }
    }

    for (const auto& pair : hdNodeMap) {
        result.push_back(pair.second);
    }

    return result;
    }
};

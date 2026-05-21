#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
    int N;
    cin >> N;

    vector<TreeNode*> nodes(N + 1);

    for (int i = 1; i <= N; i++)
        nodes[i] = new TreeNode(i);

    for (int i = 1; i <= N; i++) {
        int l, r;
        cin >> l >> r;

        if (l != -1) nodes[i]->left = nodes[l];
        if (r != -1) nodes[i]->right = nodes[r];
    }

    queue<TreeNode*> q;
    vector<int> res;

    q.push(nodes[1]); // root = 1

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* cur = q.front();
            q.pop();

            if (i == size - 1)
                res.push_back(cur->val);

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        if (i) cout << " ";
        cout << res[i];
    }

    return 0;
}
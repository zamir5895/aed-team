#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> v;
public:
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    vector<int> binarySearch(int x, int low, int high) {
        int min = -1;
        int max = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if (v[mid] == x) {
                return {v[mid], v[mid]};
            }
            if (v[mid] < x) {
                min = v[mid];
                low = mid + 1;
            } else {
                max = v[mid];
                high = mid - 1;
            }
        }

        return {min, max};
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        vector<vector<int>> ans;

        for (int i = 0; i < queries.size(); ++i) {
            ans.push_back(binarySearch(queries[i], 0, v.size() - 1));
        }

        return ans;
    }
};
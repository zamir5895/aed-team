struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isPossible(TreeNode* root, long long min, long long max) {
        if (root == nullptr) return true;
        if (root->val < max and root->val > min) {
            return isPossible(root->left, min, root->val) and isPossible(root->right, root->val, max);
        }
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int min = -10000000000;
        long long int max = 10000000000;
        return isPossible(root, min, max);
    }
};
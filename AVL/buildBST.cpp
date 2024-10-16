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
    vector<TreeNode*> vec;

public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        inorder(root);

        for (auto it = vec.begin(); it != vec.end(); ) {
            if ((*it)->val < low || (*it)->val > high) {
                it = vec.erase(it);
            } else {
                ++it;
            }
        }

        return buildBST(vec);
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vec.push_back(root);
        inorder(root->right);
    }

    TreeNode* buildBST(vector<TreeNode*> v) {
        TreeNode* tree = nullptr;
        for (TreeNode* node : v) {
            tree = insert(tree, node->val);
        }
        return tree;
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }
};

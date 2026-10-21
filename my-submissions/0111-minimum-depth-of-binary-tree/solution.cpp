/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int traverse(TreeNode *root) {
        if(!root) {
            return 0;
        }

        if(!root -> left && !root -> right) {
            return 1;
        }

        if(!root -> left) {
            return 1 + traverse(root -> right);
        }
        if(!root -> right) {
            return 1 + traverse(root -> left);
        }

        return 1 + min(traverse(root -> left), traverse(root -> right));
    }

    int minDepth(TreeNode* root) {
        return traverse(root);
    }
};

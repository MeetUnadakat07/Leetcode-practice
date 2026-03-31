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
    bool helper(TreeNode *root, int node) {
        if(root == NULL) return true;

        if(root -> val != node) return false;

        return (helper(root -> left, node) && helper(root -> right, node));
    }

    bool isUnivalTree(TreeNode* root) {
        return helper(root, root -> val);
    }
};

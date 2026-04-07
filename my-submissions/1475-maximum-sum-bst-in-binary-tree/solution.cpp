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
class NodeValue {
public:
    int min;
    int max;
    int sum;

    NodeValue(int min, int max, int sum) {
        this -> min = min;
        this -> max = max;
        this -> sum = sum;
    }
};

class Solution {
public:
    int maxSum = 0;
    NodeValue helper(TreeNode *root) {
        if(root == NULL) return {INT_MAX, INT_MIN, 0};

        auto left = helper(root -> left);
        auto right = helper(root -> right);

        if(left.max < root -> val && right.min > root -> val) {
            maxSum = max(maxSum, left.sum + right.sum + root -> val);
            return {min(root -> val, left.min), max(root -> val, right.max), 
            left.sum + right.sum + root -> val};
        } else {
            return {INT_MIN, INT_MAX, max(left.sum, right.sum)};
        }
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};

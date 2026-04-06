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
    void getInorder(TreeNode *root, vector<int> &inorder) {
        if(root == NULL) return;

        getInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        getInorder(root -> right, inorder);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1;
        vector<int> t2;
        vector<int> ans;

        getInorder(root1, t1);
        getInorder(root2, t2);

        int i = 0, j = 0;
        while(i < t1.size() && j < t2.size()) {
            if(t1[i] < t2[j]) {
                ans.push_back(t1[i]);
                i++;
            } else {
                ans.push_back(t2[j]);
                j++;
            }
        }
        while(i < t1.size()) {
                ans.push_back(t1[i]);
                i++;
        }
        while(j < t2.size()) {
                ans.push_back(t2[j]);
                j++;
        }
        return ans;
    }
};

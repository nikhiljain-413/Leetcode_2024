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
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        int root_val = root->val;
        int a = solve(root->left);
        int b = solve(root->right);
        return root_val==2? a|b : a&b;
    }
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};
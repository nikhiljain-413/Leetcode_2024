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
        if(root == NULL || (root->left==NULL && root->right == NULL)) return 0;
        int b = solve(root->right);
        if(root->left!=NULL && root->left->left == NULL && root->left->right == NULL) return b + root->left->val;
        int a = solve(root->left);
        return a + b;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root);
    }
};
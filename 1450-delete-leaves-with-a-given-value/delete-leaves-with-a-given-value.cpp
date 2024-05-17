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
    TreeNode* solve(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL && root->val==target) return NULL;
        TreeNode* left = solve(root->left, target);
        TreeNode* right = solve(root->right, target);
        if(left==NULL && right==NULL && root->val==target) return NULL;
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target);
        // return root;
    }
};
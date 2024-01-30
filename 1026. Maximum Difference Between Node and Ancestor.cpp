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
#define ll long long
class Solution {
public:
    pair<int,int> solve(TreeNode* root, int &mx){
        if(root==NULL){
            return {INT_MAX-1, INT_MIN+1};
        }
        if(root->left==NULL && root->right==NULL){
            return {root->val, root->val};
        }
        auto prl = solve(root->left, mx);
        auto prr = solve(root->right, mx);
        if(prl.first!=INT_MAX-1) mx = max({mx , abs(root->val-prl.second), abs(root->val-prl.first)});
        if(prr.first!=INT_MAX-1) mx = max({mx , abs(root->val-prr.second), abs(root->val-prr.first)});
        return {min({root->val, prl.first, prr.first}), max({root->val, prl.second, prr.second})};
    }
    int maxAncestorDiff(TreeNode* root) {
        int mx = 0;
        solve(root, mx);
        return mx;
    }
};

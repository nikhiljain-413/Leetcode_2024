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
    void solve(TreeNode* root, int &ans, int no){
        if(root==NULL){
            return;
        }
        int val = root->val;
        if(root->left == NULL && root->right==NULL) {
            cout<<no*10 + val<<" ";
            ans += (no*10 + val);
            return;
        }
        solve(root->left, ans, no*10 + val);
        solve(root->right, ans, no*10 + val);
    }
    int sumNumbers(TreeNode* root) {
        int no = 0;
        int ans = 0;
        solve(root, ans, no);
        return ans;
    }
};
// 495 + 491 + 401
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
    unordered_map<int,int> mp;
    int ans = 0;
    void solve(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            mp[root->val]++;
            int odd = 0;
            for(auto &pr: mp){
                if(pr.second&1) odd++;
                if(odd>1) break;
            }
            if(odd<=1) ans++;
            mp[root->val]--;
            return;
        }
        mp[root->val]++;
        if(root->left)
            solve(root->left);
        if(root->right)
            solve(root->right);
        mp[root->val]--;
        if( mp[root->val]==0) mp.erase(root->val);
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL) return 0;
        solve(root);
        return ans;
    }
};
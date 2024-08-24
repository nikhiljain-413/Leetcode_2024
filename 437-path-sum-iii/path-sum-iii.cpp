/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     ll val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long
class Solution {
public:
    map<ll,ll> mp;
    ll ans;
    void dfs(TreeNode* root, ll targetSum, ll sum){
        if(root==NULL){
            return;
        }
        sum+= root->val;
        ll to_find = sum-targetSum;
        ans += (mp.find(to_find)!=mp.end())?mp[to_find]:0;
        mp[sum]++;
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        dfs(root, targetSum, 0);
        return ans;
    }
};
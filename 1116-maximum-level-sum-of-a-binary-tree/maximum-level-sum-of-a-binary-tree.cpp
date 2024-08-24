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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int mx = root->val;
        int ans_level = 1;
        int level = 0;
        while(q.size()){
            int sz = q.size();
            int sum = 0;
            level++;
            while(sz--){
                TreeNode* top = q.front();
                q.pop();
                sum+=top->val;

                if(top->left!=NULL)q.push(top->left);
                if(top->right!=NULL)q.push(top->right);
            }
            cout<<sum<<" "<<level;
            if(sum>mx){
                mx = max(mx, sum);
                ans_level = level;
            }
        }
        return ans_level;
    }
};
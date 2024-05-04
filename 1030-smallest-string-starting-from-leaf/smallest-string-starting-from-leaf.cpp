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
    void dfs(TreeNode* root, string &s, string &small){
        char ch = 'a' + root->val;
        s.push_back(ch);
        if(root->left == NULL && root->right==NULL){
            string temp = s;
            reverse(temp.begin(), temp.end());
            small = min(small, temp);
            s.pop_back();
            return;
        }
        // s.push_back(ch);
        if(root->left){
            dfs(root->left, s, small);
        } 
        if(root->right){
            dfs(root->right, s, small);
        } 
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        string small = "";
        for(int i=0;i<8500;i++){
            small.push_back('z');
        }
        dfs(root, s, small);
        return small;
    }
};
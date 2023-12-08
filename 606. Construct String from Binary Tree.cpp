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
    string tree2str(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        else if(root->left==NULL && root->right==NULL){
            return to_string(root->val);
        }
        else if(root->left==NULL){
            return to_string(root->val).append("()").append("(").append(tree2str(root->right)).append(")");
        }
        else if(root->right==NULL){
            return to_string(root->val).append("(").append(tree2str(root->left)).append(")");
        }
        return to_string(root->val).append("(").append(tree2str(root->left)).append(")").append("(").append(tree2str(root->right)).append(")");
    }
    
};
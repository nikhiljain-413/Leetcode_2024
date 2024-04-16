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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        depth--;
        if(depth == 0){
            TreeNode* new_head = new TreeNode(val);
            new_head->left = root;
            return new_head;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() && depth){
            depth--;
            int sz = q.size();
            while(sz--){
                TreeNode* front = q.front();
                q.pop();
                if(depth == 0){
                    TreeNode* temp_left = front->left;
                    TreeNode* temp_right = front->right;
                    front->left = new TreeNode(val);
                    front->right = new TreeNode(val);

                    front->left->left = temp_left;
                    front->right->right = temp_right;
                    continue;
                }
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

        }
        return root;
    }
};
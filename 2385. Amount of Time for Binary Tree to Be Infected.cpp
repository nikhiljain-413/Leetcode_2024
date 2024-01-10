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
    map<int, vector<int>> adj;
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            int par = front->val;
            if(front->left){
                q.push(front->left);
                int child = front->left->val;
                adj[par].push_back(child);
                adj[child].push_back(par);
            }
            if(front->right){
                q.push(front->right);
                int child = front->right->val;
                adj[par].push_back(child);
                adj[child].push_back(par);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root->left==NULL && root->right==NULL) return 0;
        bfs(root);
        // return 0;
        queue<int> q;
        q.push(start);
        q.push(-1);
        unordered_map<int,int> vis;
        vis[start]=1;
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front == -1){
                cnt++;
                if(q.empty()) break;
                else q.push(-1);
                continue;
            }
            for(auto nd: adj[front]){
                if(!vis[nd]){
                    q.push(nd);
                    vis[nd]++;
                }
            }
        }
        return cnt-1;
    }
};
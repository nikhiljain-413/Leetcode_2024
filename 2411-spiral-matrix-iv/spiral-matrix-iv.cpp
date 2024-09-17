/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int start_row = 0;
        int end_row = m-1;
        int start_col = 0;
        int end_col = n-1;
        int cnt = 0;
        vector<vector<int>> ans(m, vector<int> (n));
        // return ans;
        int temp_col,temp_row;
        while(start_row<=end_row && start_col<=end_col){
            temp_col = start_col;
            while(temp_col<=end_col && start_row<=end_row){
                // cout<<ans[start_row][temp_col++];
                ans[start_row][temp_col++] = head?head->val:-1;
                if(head) head = head->next;
            }
            start_row++;
            temp_row = start_row;
            while(temp_row<=end_row && start_col<=end_col){
                // cout<<ans[temp_row++][end_col];
                ans[temp_row++][end_col] = head?head->val:-1;
                if(head) head = head->next;
            }
            end_col--;
            temp_col = end_col;
            while(temp_col>=start_col && start_row<=end_row){
                // cout<<ans[end_row][temp_col--];
                ans[end_row][temp_col--] = head?head->val:-1;
                if(head) head = head->next;
            }
            end_row--;
            temp_row = end_row;
            while(temp_row>=start_row && start_col<=end_col){
                // cout<<ans[temp_row--][start_col];
                ans[temp_row--][start_col] = head?head->val:-1;
                if(head) head = head->next;
            }
            start_col++;
        }
        return ans;
    }
};
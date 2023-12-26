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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* start = head;
        // vector<int> nodes;
        while(head!=NULL && head->val == val){
            head = head->next;
        }
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr!=NULL){
            if(curr->val==val){
                prev->next = curr->next;
                curr = curr->next;
            }else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        return head;
    }
};
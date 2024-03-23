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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* new_head = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL|| head->next->next==NULL) return;
        ListNode* first = head;
        ListNode* second = head;
        ListNode* ret_head = head;
        ListNode* prev_head = NULL;
        while(second!=NULL && second->next!=NULL && second->next->next!=NULL){
            prev_head = first;
            first = first->next;
            second = second->next->next;
        }
        // if(prev_head) prev_head->next = NULL;
        ListNode* new_head = reverse(first);
        ListNode* new_head_temp = new_head;
        ListNode* head_temp = head;

        int cnt = 0,tot=0;
        while(new_head_temp!=NULL){
            cout<<new_head_temp->val<<" ";
            new_head_temp = new_head_temp->next;
            cnt++;
        }
        cout<<endl;
        while(head_temp!=NULL){
            cout<<head_temp->val<<" ";
            head_temp = head_temp->next;
            cnt++;
        }
        cnt--;
        cout<<cnt<<endl;
        while(new_head != NULL && head!=NULL){
            ListNode* head_next = head->next;
            ListNode* new_head_next = new_head->next;
            head->next = new_head;
            tot++;
            // if(tot >= cnt){
            //     head = ret_head;
            //     return;
            // } 
            new_head->next = head_next;
            tot++;
            head = head_next;
            new_head = new_head_next;
        }
        // return ret_head;
        head_temp = ret_head;
        cout<<endl;
        while(head_temp!=NULL){
            cout<<head_temp->val<<" ";
            head_temp = head_temp->next;
        }
        head = ret_head;
    }
};

//  1 2
//  4 3 2
//  1 4 2 3 3

// 1 2 3
// 5 4 3
// 1 5 2 4 3
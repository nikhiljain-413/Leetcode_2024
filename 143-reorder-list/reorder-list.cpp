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
        
        while(second!=NULL && second->next!=NULL && second->next->next!=NULL){
            first = first->next;
            second = second->next->next;
        }

        ListNode* new_head = reverse(first);
        
        while(new_head != NULL && head!=NULL){
            ListNode* head_next = head->next;
            ListNode* new_head_next = new_head->next;
            head->next = new_head;
            new_head->next = head_next;
            head = head_next;
            new_head = new_head_next;
        }
    }
};

//  1 2
//  4 3 2
//  1 4 2 3 3

// 1 2 3
// 5 4 3
// 1 5 2 4 3
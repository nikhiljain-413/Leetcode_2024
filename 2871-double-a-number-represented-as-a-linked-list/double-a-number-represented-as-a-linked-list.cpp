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
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead = reverse(head);
        ListNode* temp = newHead;
        int carr = 0;
        while(temp!=NULL){
            // cout<<temp->val<<" ";
            int val = (temp->val)*2 + carr;
            temp->val = val%10;
            carr = val/10;
            if(temp->next==NULL) break;
            temp = temp->next;
        }
        while(carr){
            temp->next = new ListNode(carr%10);
            carr = carr/10;
            temp = temp->next;
        }
        return reverse(newHead);
    }
};
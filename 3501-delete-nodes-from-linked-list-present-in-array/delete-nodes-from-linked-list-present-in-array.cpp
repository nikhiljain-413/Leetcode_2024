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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(auto it: nums)st.insert(it);
        ListNode* trav = new ListNode(0);
        trav->next = head;
        head = trav;
        while(head->next!=NULL){
            ListNode* temp = head;
            int val = head->next->val;
            if(st.find(val)!=st.end()){
                cout<<val<<" ";
                head->next = head->next->next;
                // temp->next = head;
            }else{
                head = head->next;
                // temp = temp->next;
            }

        }
        return trav->next;
    }
};
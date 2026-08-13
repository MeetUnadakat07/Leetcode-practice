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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode *ptr = head;
        ListNode *nxt = head -> next;

        while(nxt) {
            if(ptr -> val == nxt -> val) {
                ptr -> next = nxt -> next;
                nxt = ptr -> next;
            } else {
                ptr = ptr -> next;
                nxt = nxt -> next;
            }
        }
        return head;
    }
};

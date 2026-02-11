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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        int carry = 0;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *curr = dummyNode;
        while(ptr1 || ptr2 || carry) {
            int sum = carry;
            if(ptr1) {
                sum += ptr1 -> val;
                ptr1 = ptr1 -> next;
            }
            if(ptr2) {
                sum += ptr2 -> val;
                ptr2 = ptr2 -> next;
            }
            ListNode *newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr -> next = newNode;
            curr = curr -> next;
        }
        return dummyNode -> next;
    }
};

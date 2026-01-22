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
    ListNode *reverse(ListNode *head) {
        ListNode *curr = head;
        ListNode *newHead = NULL;

        while(curr != NULL) {
            ListNode *newNode = new ListNode(curr -> val);
            newNode -> next = newHead;
            newHead = newNode;
            curr = curr -> next;
        }

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *newHead = reverse(head);
        ListNode *temp = head;

        while(temp != NULL && newHead != NULL) {
            if(temp -> val != newHead -> val) {
                return false;
            }
            temp = temp -> next;
            newHead = newHead -> next;
        }
        return true;
    }
};

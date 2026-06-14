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
    int pairSum(ListNode* head) {
        stack<int> s;

        ListNode *slow = head, *fast = head;

        while(fast != NULL && fast -> next != NULL) {
            s.push(slow -> val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        int maxSum = 0;
        while(!s.empty() && slow) {
            int sum = slow -> val + s.top();
            s.pop();
            slow = slow -> next;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a -> val > b -> val;     // min heap
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        for(auto head : lists) {
            if(head) {
                pq.push(head);
            }
        }

        ListNode *dummy = new ListNode, *temp = dummy;

        while(!pq.empty()) {
            ListNode *top = pq.top();
            pq.pop();

            temp -> next = top;
            temp = temp -> next;

            if(top -> next) {
                pq.push(top -> next);
            }
        }
        return dummy -> next;
    }
};

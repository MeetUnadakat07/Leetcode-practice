/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullprev) {}
 *     ListNode(int x) : val(x), next(nullprev) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head -> next || !head -> next -> next) {
            return {-1, -1};
        }
        ListNode *prev = head;
        ListNode *curr = head -> next;
        int idx = 1;

        int prevIdx = -1, firstIdx = -1;
        int mini = INT_MAX;
        int maxi = -1;
        while(curr -> next) {
            int prevVal = prev -> val;
            int currVal = curr -> val;
            int nextVal = curr -> next -> val;
            if((currVal > prevVal && nextVal < currVal) || (currVal < prevVal && nextVal > currVal)) {
                if(firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    mini = min(mini, idx - prevIdx);
                }
                prevIdx = idx;
            }
            prev = curr;
            curr = curr -> next;
            idx++;
        }
        if(firstIdx == prevIdx) {
            return {-1, -1};
        }
        maxi = prevIdx - firstIdx;
        return {mini, maxi};
    }
};

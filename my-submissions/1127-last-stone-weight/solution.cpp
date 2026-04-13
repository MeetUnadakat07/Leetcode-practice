class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();
            int ans = abs(max1 - max2);
            if(ans > 0) {
                pq.push(ans);
            } else {
                if(pq.size() == 0) return 0;
            }
        }
        return pq.top();
    }
};

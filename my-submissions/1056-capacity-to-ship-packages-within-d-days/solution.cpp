class Solution {
public:
    int reqDays(vector<int> weights, int capacity) {
        int days = 1, load = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(load + weights[i] > capacity) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxEle = 0, sum = 0;
        for(int ele : weights) {
            maxEle = max(maxEle, ele);
            sum += ele;
        }

        int st = maxEle, end = sum;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            int daysReq = reqDays(weights, mid);
            if(daysReq <= days) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};

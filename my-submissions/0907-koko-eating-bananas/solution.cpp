class Solution {
public:
    long long eatingTime(vector<int>& piles, int speed) {
        long long hours = 0;

        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / speed;
            if (piles[i] % speed != 0) {
                hours++;
            }
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());

        int st = 1, end = maxi;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(eatingTime(piles, mid) <= h) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};

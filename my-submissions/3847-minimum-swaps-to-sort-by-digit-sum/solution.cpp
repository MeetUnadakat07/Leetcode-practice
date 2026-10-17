class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> vec(n);
        for(int i = 0; i < nums.size(); i++) {
            vec[i] = {{digitSum(nums[i]), nums[i]}, i};
        }
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            if(a.first.first != b.first.first) {
                return a.first.first < b.first.first;
            }
            return a.first.second < b.first.second;
        });

        vector<bool> visited(n, false);
        int swaps = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] || vec[i].second == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;
            while(!visited[j]) {
                visited[j] = true;
                j = vec[j].second;
                cycleSize++;
            }

            if(cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }
        return swaps;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;  // sum, count
        m[0] = 1;
        int sum = 0;
        int ans = 0;

        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // agar mil gaya to frequency me add karo (sum - k == 0)
            if(m.count(sum - k)) {
                ans += m[sum - k];
            }
            // warna us sum ke liye frequency add kar do (agar nahi hai to 1 ho jayega)
            m[sum]++;
        }
        return ans;
    }
};

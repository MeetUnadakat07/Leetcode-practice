class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        int sum = 0;

        // evenCount = 1 because 0 is also even so empty subarray can also be there
        int evenCount = 1, oddCount = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            // Odd + Even = Odd
            if(sum % 2 == 0) {
                evenCount++;
                count = (count + oddCount) % MOD;
            } else {
                oddCount++;
                count = (count + evenCount) % MOD;
            }
        }
        return count % MOD;
    }
};

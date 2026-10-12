class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0, n = height.size();
        vector<int> prefixMax(n), suffixMax(n);
        prefixMax[0] = height[0];
        suffixMax[n - 1] = height[n - 1];

        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        for(int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        for(int i = 0; i < n; i++) {
            int lMax = prefixMax[i], rMax = suffixMax[i];
            if(height[i] < lMax && height[i] < rMax) {
                total += min(lMax, rMax) - height[i];
            }            
        }
        return total;
    }
};

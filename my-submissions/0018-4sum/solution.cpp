class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int st = j + 1, end = n - 1;
                while(st < end) {
                    long long sum = (long long)nums[i] + nums[j] + nums[st] + nums[end];
                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[st], nums[end]};
                        ans.push_back(temp);
                        st++;
                        end--;
                        while(st < end && nums[st] == nums[st - 1]) {
                            st++;
                        }
                        while(st < end && nums[end] == nums[end + 1]) {
                            end--;
                        }
                    } else if(sum < target) {
                        st++;
                    } else {
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        if(numbers.size() < 2) return ans;
        int st = 0, end = numbers.size() - 1;
        while(st < end) {
            int sum = numbers[st] + numbers[end];
            if(sum == target) {
                ans.push_back(st + 1);
                ans.push_back(end + 1);
                break;
            } else if(sum > target) {
                end--;
            } else {
                st++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    int index = n - 1; // Fill result array from the end
    
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }
        index--; // Move index towards the beginning
    }

    return result;
    }
};

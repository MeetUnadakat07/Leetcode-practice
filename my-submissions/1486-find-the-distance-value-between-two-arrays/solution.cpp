class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int count = 0;

        for(int ele : arr1) {
            // points to the first element >= ele - d
            auto it = lower_bound(arr2.begin(), arr2.end(), ele - d);

            if(it == arr2.end() || *it > ele + d) {
                count++;
            }
        }
        return count;
    }
};

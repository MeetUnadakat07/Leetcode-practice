class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0;
        int curr = 0;
        for(int ele : requests) {
            ans += abs(curr - ele);
            curr = ele;
        }
        return ans;
    }
};

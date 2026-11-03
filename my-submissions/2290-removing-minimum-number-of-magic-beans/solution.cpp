class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        long long sum = accumulate(beans.begin(), beans.end(), 0LL);
        long long ans = LLONG_MAX;

        for(int i = 0; i < n; i++) {
            long long oper = sum - 1LL * (n - i) * beans[i];
            ans = min(oper, ans);
        }
        return ans;
    }
};

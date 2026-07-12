class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> sorted(s.begin(), s.end());

        sort(sorted.begin(), sorted.end());

        int rank = 1;
        unordered_map<int, int> m;
        for(int ele : sorted) {
            m[ele] = rank;
            rank++;
        }

        vector<int> ans(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            ans[i] = m[arr[i]];
        }
        return ans;
    }
};

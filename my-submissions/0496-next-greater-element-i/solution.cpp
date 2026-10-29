class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> st;

        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                m[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> ans;

        for(int num : nums1) {
            if(m.count(num)) {
                ans.push_back(m[num]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;

        for(auto str : strs) {
            string s = str;
            sort(str.begin(), str.end());
            m[str].push_back(s);
        }

        vector<vector<string>> ans;
        for(pair<string, vector<string>> p : m) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

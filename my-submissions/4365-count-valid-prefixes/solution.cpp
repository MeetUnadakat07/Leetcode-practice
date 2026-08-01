class Solution {
public:
    int countValidPrefixes(string s) {
        int count0 = 0;
        int count1 = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                count0++;
            } else {
                count1++;
            }
            // cout << count0 << " " << count1 << endl;
            if (abs(count0 - count1) <= 1) {
                count++;
            }
        }
        return count;
    }
};

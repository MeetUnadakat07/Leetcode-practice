class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = 1e9, stIdx = -1, count = 0;
        unordered_map<char, int> m;

        // find the frequency of all the characters of t
        for(int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }

        // initial condition for sliding window
        int l = 0, r = 0;
        while(r < s.size()) {
            if(m[s[r]] > 0) {
                count++;
            }
            m[s[r]]--;

            // If all the characters are covered try shrinking the window
            while(count == t.size()) {
                // Update the minimum window if the current window is smaller than the previous best
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    stIdx = l;
                }

                // Remove the leftmost character from the window
                m[s[l]]++;

                // If its frequency becomes positive, the window is now missing a required character
                if(m[s[l]] > 0) count--;
                
                // Shrink the window by moving the left pointer
                l++;
            }
            // Expand the window by moving the right pointer
            r++;
        }
        // If no valid window was found, return an empty string
        if(stIdx == -1) return "";

        // Return the smallest substring containing all characters of t, including duplicate characters
        return s.substr(stIdx, minLen);
    }
};

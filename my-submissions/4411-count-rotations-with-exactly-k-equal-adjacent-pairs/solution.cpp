class Solution {
public:
    int countRotations(string s, int k) {
        string str = s;
        int score = 0;
        for(int i = 0; i < s.size(); i++) {
            int count = 0;
            for(int j = 1; j < str.size(); j++) {
                if(str[j - 1] == str[j]) {
                    count++;
                }
            }
            if(count == k) {
                score++;
            }
            str += str[0];
            str.erase(0, 1);
        }
        return score;
    }
};

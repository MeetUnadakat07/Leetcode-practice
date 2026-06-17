class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);

        const long long INF = 1e15 + 1;

        long long l = 0;

        for(int i = 0; i < n; i++) {
            char c = s[i];

            if(isalpha(c)) {
                l++;
            } else if(c == '*') {
                if(l > 0) l--;
            } else if(c == '#') {
                l = min(INF, l * 2);
            }
            len[i] = l;
        }

        if(k >= l) return '.';

        for(int i = n - 1; i >= 0; i--) {
            long long prevLen = (i == 0 ? 0 : len[i - 1]);

            char c = s[i];
            if(isalpha(c)) {
                // agar add hone wla hi character k pe hai to
                if(k == prevLen) return c;
            } else if(c == '#') {
                // jab string ko duplicate kar rahe hai to k ka value first half me bhejna hai same char par
                if(k >= prevLen) {
                    if(k >= prevLen) {
                        k -= prevLen;
                    }
                }
            } else if(c == '%') {
                // reverse hote time k ka position kese change ho raha hai
                if(prevLen > 0) {
                    k = prevLen - k - 1;
                }
            }
        }
        return '.';
    }
};

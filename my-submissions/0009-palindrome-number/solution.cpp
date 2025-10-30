class Solution {
public:
    bool isPalindrome(int x) {
        long int rev, cpy = x;
        int rem;
        while(x > 0) {
            rem = x % 10;
            rev = (rev * 10) + rem;
            x /= 10;
        }
        return cpy == rev;
    }
};
